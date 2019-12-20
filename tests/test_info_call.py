import unittest
import utils


class TestInfoCall(utils.CIFTestCase):
    def test_simple_info_call_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_call_all.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_info_call_all.txt')

    def test_simple_info_call_args(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_call_args.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_info_call_args.txt')

    def test_actual_arg_func_names(self):
        self.cif.run(cif_input='input/actual_arg_func_names.c', aspect='aspect/actual_arg_func_names.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/actual_arg_func_names.txt')


if __name__ == '__main__':
    unittest.main()
