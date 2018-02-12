import unittest
import utils


class TestInfoExecution(utils.CIFTestCase):
    def test_simple_info_execution_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_execution_all.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/simple_call_info_execution_all.txt')


if __name__ == '__main__':
    unittest.main()
