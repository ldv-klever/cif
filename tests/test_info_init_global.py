import unittest
import utils


class TestInfoInitGlobal(utils.CIFTestCase):
    def test_simple_info_init_global_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_init_global_all.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/simple_call_info_init_global_all.txt')


if __name__ == '__main__':
    unittest.main()
