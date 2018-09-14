import os
import subprocess
import shutil
import unittest

WORK_DIR = 'work'


class CIFTestCase(unittest.TestCase):
    class CIF():
        def run(self, cif_input, aspect, cif_output=WORK_DIR + '/a.out', stage='compilation', back_end='src'):
            self.cmd = ['../bin/cif',
                        '--in', cif_input,
                        '--aspect', aspect,
                        '--back-end', back_end,
                        '--stage', stage,
                        '--out', cif_output,
                        '--debug', 'ALL',
                        '--keep']

            proc = subprocess.Popen(self.cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
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

        output_str = self._read_file_to_str(output)
        expected_str = self._read_file_to_str(expected)

        self.assertEqual(expected_str, output_str)

    def check_cif_status(self):
        if self.cif and self.cif.status is not 0:
            print('\n', 'CMD:', self.cif.cmd, '\n')
            print('LOG:', self.cif.log, '\n')
            self.assertEqual(self.cif.status, 0)

    def skip_os_specific_defines(self, output):
        self.check_cif_status()

        with open(output) as fp:
            lines = fp.readlines()
        with open(output, 'w') as fp:
            for line in lines:
                if not line.startswith('/usr/include/stdc-predef.h'):
                    fp.write(line)

    def _read_file_to_str(self, file):
        if not os.path.exists(file):
            self.fail('File {} does not exist.'.format(file))

        with open(file, 'r') as file_fh:
            return ''.join(file_fh.readlines())

    def _backup_work_dir(self):
        self.backup = 'backup/' + self._testMethodName

        if os.path.exists(self.backup):
            shutil.rmtree(self.backup)

        shutil.copytree(WORK_DIR, self.backup)
