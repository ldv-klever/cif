import unittest
import utils


class TestInfoExpand(utils.CIFTestCase):
    def test_simple_info_expand_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_expand_all.aspect', stage='instrumentation')
        self.skip_os_specific_defines('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_call_info_expand_all.txt')


if __name__ == '__main__':
    unittest.main()
