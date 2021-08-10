import os
import re
import subprocess
import shutil
import unittest

WORK_DIR = 'work'


class CIFTestCase(unittest.TestCase):
    class CIF():
        def run(self, cif_input, aspect=None, cif_output=WORK_DIR + '/a.out', stage='compilation', back_end='src', aspectator_opts=None, env=None):
            self.cmd = [os.environ.get('CIF', '../inst/bin/cif'),
                        '--in', cif_input,
                        '--back-end', back_end,
                        '--stage', stage,
                        '--out', cif_output,
                        '--debug', 'ALL',
                        '--keep']

            if aspect:
                self.cmd.extend(['--aspect', aspect])

            if aspectator_opts:
                self.cmd.append('--')
                self.cmd.extend(aspectator_opts)

            proc = subprocess.Popen(self.cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, env=env)
            stdout, stderr = proc.communicate()

            self.log = (stdout.decode('utf-8') + stderr.decode('utf-8')).strip()
            self.status = proc.returncode

            self.cif_output = cif_output
            self.instrumented = cif_output + '.instrumented'
            self.macroinstrumented = cif_output + '.instrumented'
            self.prepared = cif_output + '.prepared'

    def __init__(self, *arguments):
        self.cif = CIFTestCase.CIF()

        super().__init__(*arguments)

    def setUp(self):
        """setUp called immediately before calling the test method"""
        if os.path.exists(WORK_DIR):
            shutil.rmtree(WORK_DIR)

        os.makedirs(WORK_DIR)

        # assertEqual can't produce large diffs without setting maxDiff to None
        self.maxDiff = None

    def tearDown(self):
        """ tearDown called immediately after the test method has been called"""

        if os.path.exists(WORK_DIR):
            self._backup_work_dir()

            shutil.rmtree(WORK_DIR)

    def compare(self, output, expected):
        self.check_cif_status()

        if 'OVERRIDE' in os.environ:
            shutil.copy(output, expected)
            return

        output_str_list = self._read_file_to_str_list(output)
        expected_str_list = self._read_file_to_str_list(expected)

        # ignore line directives since they may contain absolute paths
        output_str_list = [line for line in output_str_list if not line.startswith("#line")]
        expected_str_list = [line for line in expected_str_list if not line.startswith("#line")]

        output_str = ''.join(output_str_list)
        expected_str = ''.join(expected_str_list)

        self.assertEqual(expected_str, output_str)

    def check_cif_status(self):
        if self.cif and self.cif.status != 0:
            print('\nCMD: {!r}'.format(' '.join(self.cif.cmd)))
            print('LOG:', self.cif.log, '\n')
            self.assertEqual(self.cif.status, 0)

    def skip_os_specific_defines(self, output):
        self.check_cif_status()

        with open(output, encoding='utf8') as fp:
            lines = fp.readlines()
        with open(output, 'w', encoding='utf8') as fp:
            for line in lines:
                if line.find('/usr/include/stdc-predef.h') == -1:
                    fp.write(line)

    def replace_gotos(self, output):
        self.check_cif_status()

        with open(output, encoding='utf8') as fp:
            lines = fp.readlines()

        goto_ids = dict()
        counter = 1
        for line in lines:
            m = re.search(r"goto ldv_(\d*);", line)

            if not m:
                continue

            old_id = m.group(1)

            if old_id not in goto_ids:
                goto_ids[old_id] = str(counter)
                counter += 1

        with open(output, 'w', encoding='utf8') as fp:
            for line in lines:
                m = re.search(r"ldv_(\d*)[;:]", line)

                if m:
                    old_id = m.group(1)
                    line = line.replace(old_id, goto_ids[old_id])

                fp.write(line)

    def make_relpath(self, output):
        with open(output, encoding='utf8') as fp:
            lines = fp.readlines()
        with open(output, 'w', encoding='utf8') as fp:
            for line in lines:
                fp.write(line.replace(os.getcwd() + os.path.sep, ''))

    def _read_file_to_str_list(self, file):
        if not os.path.exists(file):
            self.fail('File {} does not exist.'.format(file))

        with open(file, 'r', encoding='utf8') as file_fh:
            return file_fh.readlines()

    def _backup_work_dir(self):
        self.backup = 'backup/' + self._testMethodName

        if os.path.exists(self.backup):
            shutil.rmtree(self.backup)

        shutil.copytree(WORK_DIR, self.backup)
