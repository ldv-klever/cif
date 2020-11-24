# Copyright (c) 2020 ISP RAS (http://www.ispras.ru)
# Ivannikov Institute for System Programming of the Russian Academy of Sciences
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import re
import shutil
import subprocess

from typing import Dict, List, Optional

from pycif.opts import filter_opts


class CIF:
    def __init__(
        self,
        cif: str = "cif",
        aspectator: Optional[str] = None,
        aspect: Optional[str] = None,
        back_end: str = "src",
        debug: str = "ALL",
        stage: str = "compilation",
        keep: bool = False,
        keep_prepared_file: bool = False,
        capture_output: bool = True,
        filter_opts: bool = True,
    ):
        """Create object of CIF class and specify some settings that are unlikely to change between different launches

        Args:
            cif: either name of the CIF binary that can be found in PATH, or absolute path to it
            aspectator: either name of the Aspectator binary that can be found in PATH, or absolute path to it
            aspect: path to the .aspect file to be used for instrumentation. It is mandatory except for stage 'C-backend'
            back_end: back end to produce output at 'compilation' stage. Following back-ends available: 'bin', 'asm', 'obj' and 'src'
            debug: debug level may be 'QUIET', 'NORMAL', 'DEBUG' or 'ALL'
        """
        self.cif = cif
        self.aspectator = aspectator
        self.aspect = aspect
        self.back_end = back_end
        self.debug = debug
        self.stage = stage
        self.keep = keep
        self.keep_prepared_file = keep_prepared_file

        self.capture_output = capture_output
        self.filter_opts = filter_opts

        # object that stores results of last CIF run
        self.last_run: Optional[subprocess.CompletedProcess] = None

        self.__check_cif_args()

    def __check_cif_args(self):
        if not self.cif or not shutil.which(self.cif):
            raise RuntimeError("Specified CIF is not found")

        if self.aspectator and not shutil.which(self.aspectator):
            raise RuntimeError("Specified Aspectator is not found")

        if self.aspect and not os.path.exists(self.aspect):
            raise RuntimeError(
                "Specified aspect file {!r} does not exist".format(self.aspect)
            )

        if self.stage not in [
            "aspect preprocessing",
            "file preparation",
            "macro instrumentation",
            "instrumentation",
            "compilation",
            'C-backend'
        ]:
            raise RuntimeError(
                "Specified stage {!r} is not supported".format(self.stage)
            )

        if self.back_end not in ["bin", "asm", "obj", "src"]:
            raise RuntimeError(
                "Specified back-end {!r} is not supported".format(self.back_end)
            )

        if self.debug not in ["QUIET", "NORMAL", "DEBUG", "ALL"]:
            raise RuntimeError(
                "Specified debug level {!r} is not supported".format(self.debug)
            )

    def setup(
        self,
        cif=None,
        aspectator=None,
        aspect=None,
        back_end=None,
        debug=None,
        stage=None,
        keep=None,
        keep_prepared_file=None,
        capture_output=None,
        filter_opts=None,
    ):
        """Change some CIF settings specified during the creation of this object"""
        if cif:
            self.cif = cif

        if aspectator:
            self.aspectator = aspectator

        if aspect:
            self.aspect = aspect

        if back_end:
            self.back_end = back_end

        if debug:
            self.debug = debug

        if stage:
            self.stage = stage

        # bool options require special treatment
        if keep is not None:
            self.keep = keep

        if keep_prepared_file is not None:
            self.keep_prepared_file = keep_prepared_file

        if capture_output is not None:
            self.capture_output = capture_output

        if filter_opts is not None:
            self.filter_opts = filter_opts

        self.__check_cif_args()

    def run(
        self,
        in_file: str,
        out_file: str,
        cwd: str = os.getcwd(),
        env: Optional[Dict[str, str]] = None,
        opts: Optional[List[str]] = None,
        aspect_preprocessing_opts: Optional[List[str]] = None,
        file_preparation_opts: Optional[List[str]] = None,
        macro_instrumentation_opts: Optional[List[str]] = None,
        instrumentation_opts: Optional[List[str]] = None,
        compilation_opts: Optional[List[str]] = None,
        general_opts: Optional[List[str]] = None,
    ) -> subprocess.CompletedProcess:
        """Run CIF with specified parameters

        Args:
            in_file: input file
            out_file: output file
            cwd: working directory where CIF will be launched
            env: option environment variables that will be passed to Aspectator
            opts: optional options that will be passed directly to Aspectator
            aspect_preprocessing_opts: optional options that will be used at 'aspect preprocessing' stage
            file_preparation_opts: optional options that will be used at 'file preparation' stage
            macro_instrumentation_opts: optional options that will be used at 'macro instrumentation' stage
            instrumentation_opts: optional options that will be used at 'instrumentation' stage
            compilation_opts: optional options that will be used at 'compilation' stage
            general_opts: optional options that will be used at all stages

        Returns:
            subprocess.CompletedProcess object
        """
        if not os.path.exists(in_file):
            raise FileNotFoundError("Input file {!r} does not exist".format(in_file))

        # fmt: off
        cif_args = [
            self.cif,
            "--debug", self.debug,
            "--in", in_file,
            "--aspect", self.aspect,
            "--back-end", self.back_end,
            "--stage", self.stage,
            "--out", out_file
        ]
        # fmt: on

        if self.keep:
            cif_args.append("--keep")

        if self.keep_prepared_file:
            cif_args.append("--keep-prepared-file")

        if self.aspectator:
            cif_args.extend(["--aspectator", self.aspectator])

        if aspect_preprocessing_opts:
            cif_args.append("--aspect-preprocessing-opts")
            cif_args.extend(aspect_preprocessing_opts)

        if file_preparation_opts:
            cif_args.append("--file-preparation-opts")
            cif_args.extend(file_preparation_opts)

        if macro_instrumentation_opts:
            cif_args.append("--macro-instrumentation-opts")
            cif_args.extend(macro_instrumentation_opts)

        if instrumentation_opts:
            cif_args.append("--instrumentation-opts")
            cif_args.extend(instrumentation_opts)

        if compilation_opts:
            cif_args.append("--compilation-opts")
            cif_args.extend(compilation_opts)

        if general_opts:
            cif_args.append("--general-opts")
            cif_args.extend(general_opts)

        if opts:
            if self.filter_opts:
                opts = filter_opts(opts)
            opts = [re.sub(r"\"", r'\\"', opt) for opt in opts]
            cif_args.append("--")
            cif_args.extend(opts)

        self.__makedirs(cwd)
        self.__makedirs(os.path.dirname(out_file))

        if self.capture_output:
            stdout = subprocess.PIPE
            stderr = subprocess.STDOUT
        else:
            stdout = None
            stderr = None

        cif_env = env
        if cif_env:
            # Copy env to avoid modifying original dictionary
            cif_env = env.copy()
            cif_env.update(os.environ)

        self.last_run = subprocess.run(
            cif_args,
            cwd=cwd,
            universal_newlines=True,
            stdout=stdout,
            stderr=stderr,
            env=cif_env,
        )
        return self.last_run

    def run_aspectator(
        self,
        args: List[str],
        cwd: str = os.getcwd(),
        env: Optional[Dict[str, str]] = None,
    ) -> subprocess.CompletedProcess:
        """Run Aspectator with specified parameters

        Args:
            args: list of arguments
            cwd: working directory where Aspectator will be launched
            env: option environment variables that will be passed to Aspectator

        Returns:
            subprocess.CompletedProcess object
        """
        if not self.aspectator or not shutil.which(self.aspectator):
            raise RuntimeError("Specified Aspectator is not found")

        if self.capture_output:
            stdout = subprocess.PIPE
            stderr = subprocess.STDOUT
        else:
            stdout = None
            stderr = None

        aspectator_env = env
        if aspectator_env:
            # Copy env to avoid modifying original dictionary
            aspectator_env = env.copy()
            aspectator_env.update(os.environ)

        self.last_run = subprocess.run(
            args,
            cwd=cwd,
            universal_newlines=True,
            stdout=stdout,
            stderr=stderr,
            env=aspectator_env,
        )
        return self.last_run

    def get_last_log(self) -> str:
        """Get output of the last launch"""
        if not self.capture_output:
            raise RuntimeError("capture_output option is not enabled")

        if not self.last_run:
            raise RuntimeError("CIF or Aspectator was not yet launched")

        return self.last_run.stdout

    def get_last_args(self) -> List[str]:
        """Get arguments of the last launch"""
        if not self.last_run:
            raise RuntimeError("CIF or Aspectator was not yet launched")

        return self.last_run.args

    def get_last_returncode(self) -> int:
        """Get return code of the last launch"""
        if not self.last_run:
            raise RuntimeError("CIF or Aspectator was not yet launched")

        return self.last_run.returncode

    def get_cif_version(self, cwd: str = os.getcwd()) -> str:
        """Get CIF version"""
        if not self.cif or not shutil.which(self.cif):
            raise RuntimeError("Specified CIF is not found")

        return subprocess.run(
            [self.cif, "-v"],
            cwd=cwd,
            universal_newlines=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
        ).stdout.strip()

    def __makedirs(self, path, exist_ok=True):
        if path:
            os.makedirs(path, exist_ok=exist_ok)
