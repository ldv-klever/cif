import unittest
import utils


class TestCBackend(utils.CIFTestCase):
    def test_return_void(self):
        self.cif.run(cif_input='input/c-backend/return-void.c', aspect='aspect/empty.aspect', cif_output='work/return-void.c')
        self.compare(output='work/return-void.c', expected='output/c-backend/return-void.c')

if __name__ == '__main__':
    unittest.main()
