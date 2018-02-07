import unittest
import utils


class TestInfoExecutionAll(utils.CIFTestCase):
    def test_path(self):
        self.cif.run(cif_input='input/simple_call.c', aspect='aspect/info_execution_all_path.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/simple_call_info_execution_all_path.txt')

    def test_func_name(self):
        self.cif.run(cif_input='input/simple_call.c', aspect='aspect/info_execution_all_func_name.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/simple_call_info_execution_all_func_name.txt')

    def test_decl_line(self):
        self.cif.run(cif_input='input/simple_call.c', aspect='aspect/info_execution_all_decl_line.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/simple_call_info_execution_all_decl_line.txt')


if __name__ == '__main__':
    unittest.main()
