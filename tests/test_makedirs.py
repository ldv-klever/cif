import os
import unittest
import utils


class TestMakedirs(utils.CIFTestCase):
    def test_makedirs(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/makedirs.aspect', stage='instrumentation')
        self.compare(output=os.path.join('work' + os.getcwd(), 'input', 'simple.c'), expected='output/makedirs.txt')


if __name__ == '__main__':
    unittest.main()
