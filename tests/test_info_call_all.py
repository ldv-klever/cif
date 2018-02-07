import unittest
import utils


class TestInfoCallAll(utils.CIFTestCase):
    def test_simple_func_context_path(self):
        self.cif.run(cif_input='tests/input/simple_call.c', aspect='tests/aspect/info_call_all_func_context_path.aspect', stage='instrumentation')

        self.compare(output='tests/work/info.txt', expected='tests/output/test_simple_func_context_path.txt')

    def test_simple_func_context_name(self):
        self.cif.run(cif_input='tests/input/simple_call.c', aspect='tests/aspect/info_call_all_func_context_name.aspect', stage='instrumentation')

        self.compare(output='tests/work/info.txt', expected='tests/output/test_simple_func_context_name.txt')

    def test_simple_func_name(self):
        self.cif.run(cif_input='tests/input/simple_call.c', aspect='tests/aspect/info_call_all_func_name.aspect', stage='instrumentation')

        self.compare(output='tests/work/info.txt', expected='tests/output/test_simple_func_name.txt')

    def test_simple_call_line(self):
        self.cif.run(cif_input='tests/input/simple_call.c', aspect='tests/aspect/info_call_all_call_line.aspect', stage='instrumentation')

        self.compare(output='tests/work/info.txt', expected='tests/output/test_simple_call_line.txt')


if __name__ == '__main__':
    unittest.main()
