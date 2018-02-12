import unittest
import utils


class TestInfoCall(utils.CIFTestCase):
    def test_simple_info_call_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_call_all.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/simple_info_call_all.txt')
    def test_simple_info_call_args(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_call_args.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/simple_info_call_args.txt')


if __name__ == '__main__':
    unittest.main()
