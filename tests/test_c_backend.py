import unittest
import utils


class TestCBackend(utils.CIFTestCase):
    def test_return_void(self):
        self.cif.run(cif_input='input/c-backend/return-void.c', aspect='aspect/empty.aspect', cif_output='work/return-void.c')
        self.compare(output='work/return-void.c', expected='output/c-backend/return-void.c')
    
    def test_empty_initializer(self):
        self.cif.run(cif_input='input/c-backend/empty-initializer-list.c', aspect='aspect/empty.aspect', cif_output='work/empty-initializer-list.c')
        self.compare(output='work/empty-initializer-list.c', expected='output/c-backend/empty-initializer-list.c')

    def test_overflow_transform(self):
        self.cif.run(cif_input='input/c-backend/overflow-transform.c', aspect='aspect/empty.aspect', cif_output='work/overflow-transform.c')
        self.compare(output='work/overflow-transform.c', expected='output/c-backend/overflow-transform.c')

if __name__ == '__main__':
    unittest.main()
