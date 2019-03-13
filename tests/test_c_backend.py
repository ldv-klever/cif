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

    # TODO: this test case needs additional compilation option -O2.
    def test_memref_transform2(self):
        self.cif.run(cif_input='input/c-backend/memref-transform2.c', aspect='aspect/empty.aspect', cif_output='work/memref-transform2.c')
        self.compare(output='work/memref-transform2.c', expected='output/c-backend/memref-transform2.c')

    def test_array(self):
        self.cif.run(cif_input='input/c-backend/array.c', aspect='aspect/empty.aspect', cif_output='work/array.c')
        self.compare(output='work/array.c', expected='output/c-backend/array.c')

    def test_array_zero_lenght(self):
        self.cif.run(cif_input='input/c-backend/array-zero-lenght.c', aspect='aspect/empty.aspect', cif_output='work/array-zero-lenght.c')
        self.compare(output='work/array-zero-lenght.c', expected='output/c-backend/array-zero-lenght.c')

    def test_array_no_size(self):
        self.cif.run(cif_input='input/c-backend/array-no-size.c', aspect='aspect/empty.aspect', cif_output='work/array-no-size.c')
        self.compare(output='work/array-no-size.c', expected='output/c-backend/array-no-size.c')

    def test_transparent_union(self):
        self.cif.run(cif_input='input/c-backend/transparent_union.c', aspect='aspect/empty.aspect', cif_output='work/transparent_union.c')
        self.compare(output='work/transparent_union.c', expected='output/c-backend/transparent_union.c')

    def test_extern_func_decl_without_params(self):
        self.cif.run(cif_input='input/c-backend/extern-func-decl-without-params.c', aspect='aspect/empty.aspect', cif_output='work/extern-func-decl-without-params.c')
        self.compare(output='work/extern-func-decl-without-params.c', expected='output/c-backend/extern-func-decl-without-params.c')

    def test_float_expr(self):
        self.cif.run(cif_input='input/c-backend/float-expr.c', aspect='aspect/empty.aspect', cif_output='work/float-expr.c')
        self.compare(output='work/float-expr.c', expected='output/c-backend/float-expr.c')

    def test_rdiv_expr(self):
        self.cif.run(cif_input='input/c-backend/rdiv-expr.c', aspect='aspect/empty.aspect', cif_output='work/rdiv-expr.c')
        self.compare(output='work/rdiv-expr.c', expected='output/c-backend/rdiv-expr.c')

    def test_fix_trunc_expr(self):
        self.cif.run(cif_input='input/c-backend/fix-trunc-expr.c', aspect='aspect/empty.aspect', cif_output='work/fix-trunc-expr.c')
        self.compare(output='work/fix-trunc-expr.c', expected='output/c-backend/fix-trunc-expr.c')

    # Let's support vector types one day later.
    def _test_vector_type(self):
        self.cif.run(cif_input='input/c-backend/vector-type.c', aspect='aspect/empty.aspect', cif_output='work/vector-type.c')
        self.compare(output='work/vector-type.c', expected='output/c-backend/vector-type.c')

    def test_multiple_decls(self):
        self.cif.run(cif_input='input/c-backend/multiple-decls.c', aspect='aspect/empty.aspect', cif_output='work/multiple-decls.c')
        self.compare(output='work/multiple-decls.c', expected='output/c-backend/multiple-decls.c')

if __name__ == '__main__':
    unittest.main()
