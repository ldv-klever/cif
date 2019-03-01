import unittest
import utils


class TestInfoDeclareFunc(utils.CIFTestCase):
    def test_simple_info_declare_func_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_declare_func_all.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_call_info_declare_func_all.txt')


if __name__ == '__main__':
    unittest.main()
