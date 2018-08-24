import unittest
import utils


class TestCBackend(utils.CIFTestCase):
    def test_return_void(self):
        self.cif.run(cif_input='input/c-backend/return-void.c', aspect='aspect/empty.aspect', cif_output='work/return-void.c')
        self.compare(output='work/return-void.c', expected='output/c-backend/return-void.c')

    def test_main(self):
        self.cif.run(cif_input='input/c-backend/main.c', aspect='aspect/empty.aspect', cif_output='work/main.c')
        self.compare(output='work/main.c', expected='output/c-backend/main.c')

    def test_main_2(self):
        self.cif.run(cif_input='input/c-backend/main-2.c', aspect='aspect/empty.aspect', cif_output='work/main-2.c')
        self.compare(output='work/main-2.c', expected='output/c-backend/main-2.c')

    def test_main_3(self):
        self.cif.run(cif_input='input/c-backend/main-3.c', aspect='aspect/empty.aspect', cif_output='work/main-3.c')
        self.compare(output='work/main-3.c', expected='output/c-backend/main-3.c')
    
    def test_empty_initializer(self):
        self.cif.run(cif_input='input/c-backend/empty-initializer-list.c', aspect='aspect/empty.aspect', cif_output='work/empty-initializer-list.c')
        self.compare(output='work/empty-initializer-list.c', expected='output/c-backend/empty-initializer-list.c')

    def test_overflow_transform(self):
        self.cif.run(cif_input='input/c-backend/overflow-transform.c', aspect='aspect/empty.aspect', cif_output='work/overflow-transform.c')
        self.compare(output='work/overflow-transform.c', expected='output/c-backend/overflow-transform.c')

    def test_memref_transform(self):
        self.cif.run(cif_input='input/c-backend/memref-transform.c', aspect='aspect/empty.aspect', cif_output='work/memref-transform.c')
        self.compare(output='work/memref-transform.c', expected='output/c-backend/memref-transform.c')

    def test_transparent_union(self):
        self.cif.run(cif_input='input/c-backend/transparent_union.c', aspect='aspect/empty.aspect', cif_output='work/transparent_union.c')
        self.compare(output='work/transparent_union.c', expected='output/c-backend/transparent_union.c')

if __name__ == '__main__':
    unittest.main()
