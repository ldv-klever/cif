import unittest
import utils


class TestInfoExpand(utils.CIFTestCase):
    def test_simple_info_expand_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_expand_all.aspect', stage='instrumentation')
        self.skip_os_specific_defines('work/info.txt')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_call_info_expand_all.txt')

    def test_macro_actual_args(self):
        self.cif.run(cif_input='input/macro_actual_args.c', aspect='aspect/macro_actual_args.aspect', stage='instrumentation')
        self.skip_os_specific_defines('work/info.txt')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/macro_actual_args.txt')


if __name__ == '__main__':
    unittest.main()
