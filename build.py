import argparse
import os
import re
import shutil
import stat
import subprocess
import sys


def parse_args(argv):
    parser = argparse.ArgumentParser()

    parser.add_argument(
        "-b",
        "--build",
        help="path to the build directory",
        metavar="PATH",
        default=os.path.join(os.getcwd(), "cross-build"),
    )

    parser.add_argument(
        "-o",
        "--output",
        help="path to the output directory",
        metavar="PATH",
        default=os.path.join(os.getcwd(), "cif-archives"),
    )

    parser.add_argument(
        "-s",
        "--src",
        help="path to the CIF repositor",
        metavar="PATH",
        default=os.getcwd(),
    )

    parser.add_argument(
        dest="configs",
        nargs=argparse.REMAINDER,
        help="crosstool-ng configurations to use",
    )

    return parser.parse_args(argv)


def get_cif_version(cif_bin):
    version = "unknown"
    try:
        version = subprocess.check_output(
            [cif_bin, "--version"], stderr=subprocess.DEVNULL, universal_newlines=True
        ).strip()
    finally:
        return version


def copy_and_patch(cif_src, src, dst):
    with open(src, "r") as src_fh:
        config_lines = src_fh.readlines()

    with open(dst, "w") as dst_fh:
        for line in config_lines:
            m = re.search(r'"(.*?)/aspectator.*?"', line)

            if m:
                line = line.replace(m.group(1), cif_src)

            dst_fh.write(line)


def fix_permissions(path):
    for root, dirs, files in os.walk(path):
        for name in dirs + files:
            file_path = os.path.join(root, name)

            st = os.stat(file_path)
            os.chmod(file_path, st.st_mode | stat.S_IWRITE)


if __name__ == "__main__":
    args = parse_args(sys.argv[1:])

    config_dir = os.path.join(args.src, "config")

    for config_name in os.listdir(config_dir):
        if args.configs and config_name not in args.configs:
            print("Skipping {!r} configuration".format(config_name))
            continue

        config_file = os.path.join(config_dir, config_name)

        # Prepare build directory
        config_build_dir = os.path.join(args.build, config_name)
        os.makedirs(config_build_dir, exist_ok=True)

        # Copy configuration file for crosstool-ng and replace paths inside
        copy_and_patch(args.src, config_file, os.path.join(config_build_dir, ".config"))

        # Run crosstool-ng
        r = subprocess.run(["/home/builduser/src/crosstool-ng-1.24.0/ct-ng", "build"], cwd=config_build_dir)

        if r.returncode:
            print("Build failed")
            sys.exit(-1)

        # Name of the cif executable
        cif_name = config_name + "-cif"

        # Path to the directory that will contain proper cif distribution
        cif_dir = os.path.join(args.build, cif_name)

        # Copy cross-aspectator to cif_dir. TODO: replace by move?
        ct_ng_build_dir = os.path.join(os.path.expanduser("~"), "x-tools", config_name)
        aspectator_dir = os.path.join(cif_dir, cif_name)
        shutil.copytree(ct_ng_build_dir, aspectator_dir)

        # By default nobody can write to ct-ng build directory while we need this to copy cif binary
        subprocess.run(["chmod", "-R", "u+w", aspectator_dir], stdout=subprocess.DEVNULL)

        # Build cif binary
        subprocess.run(["make", "cif"], cwd=args.src, stdout=subprocess.DEVNULL)

        # Copy cif binary
        cif_bin_src = os.path.join(args.src, "build", "cif")
        cif_bin_dst = os.path.join(aspectator_dir, "bin", cif_name)
        shutil.copy(cif_bin_src, cif_bin_dst)

        # Create bin inside cif_dir
        cif_bin_dir = os.path.join(cif_dir, "bin")
        os.makedirs(cif_bin_dir, exist_ok=True)

        # Create cif simlink
        cif_path = os.path.join(cif_bin_dir, cif_name)
        subprocess.run([
            "ln",
            "-sf",
            os.path.join("..", cif_name, "bin", cif_name),
            cif_path
        ], cwd=cif_bin_dir)

        # Create aspectator simlink
        aspectator_name = config_name + "-aspectator"
        gcc_name = config_name + "-gcc"
        subprocess.run([
            "ln",
            "-sf",
            os.path.join("..", cif_name, "bin", gcc_name),
            os.path.join(cif_bin_dir, aspectator_name)
        ], cwd=cif_bin_dir)

        # Fixing permissions (chmod +w to everything inside cif_dir)
        fix_permissions(cif_dir)

        # Run tests
        test_env = os.environ.copy()
        test_env["CIF"] = cif_path
        subprocess.run(["make", "test"], cwd=args.src, env=test_env)

        # Final step: create .tar.xz archive
        archive_name = config_name + "-" + get_cif_version(cif_path) + ".tar.xz"
        os.makedirs(args.output, exist_ok=True)

        print("Create {!r} archive".format(archive_name))
        subprocess.run([
            "tar",
            "cJf",
            os.path.join(args.output, archive_name),
            "-C",
            cif_dir,
            "."
        ], cwd=args.build)
