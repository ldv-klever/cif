import unittest
import utils


class TestFuncs(utils.CIFTestCase):
    def test_func_calls(self):
        self.cif.run(cif_input='input/func-calls.c', aspect='aspect/func-calls.aspect', cif_output='work/func-calls.c')
        self.compare(output='work/func-calls.c', expected='output/func-calls.c')

if __name__ == '__main__':
    unittest.main()
