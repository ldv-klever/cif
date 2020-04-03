import os
import unittest
import utils


class TestCBackend(utils.CIFTestCase):
    def test_return_void(self):
        self.cif.run(cif_input='input/c-backend/return-void.c', stage='C-backend', cif_output='work/return-void.c')
        self.compare(output='work/return-void.c', expected='output/c-backend/return-void.c')

    def test_main(self):
        self.cif.run(cif_input='input/c-backend/main.c', stage='C-backend', cif_output='work/main.c')
        self.compare(output='work/main.c', expected='output/c-backend/main.c')

    def test_main_2(self):
        self.cif.run(cif_input='input/c-backend/main-2.c', stage='C-backend', cif_output='work/main-2.c')
        self.compare(output='work/main-2.c', expected='output/c-backend/main-2.c')

    def test_main_3(self):
        self.cif.run(cif_input='input/c-backend/main-3.c', stage='C-backend', cif_output='work/main-3.c')
        self.compare(output='work/main-3.c', expected='output/c-backend/main-3.c')

    def test_empty_initializer(self):
        self.cif.run(cif_input='input/c-backend/empty-initializer-list.c', stage='C-backend', cif_output='work/empty-initializer-list.c')
        self.compare(output='work/empty-initializer-list.c', expected='output/c-backend/empty-initializer-list.c')

    def test_overflow_transform(self):
        self.cif.run(cif_input='input/c-backend/overflow-transform.c', stage='C-backend', cif_output='work/overflow-transform.c')
        self.compare(output='work/overflow-transform.c', expected='output/c-backend/overflow-transform.c')

    def test_memref_transform(self):
        self.cif.run(cif_input='input/c-backend/memref-transform.c', stage='C-backend', cif_output='work/memref-transform.c')
        self.compare(output='work/memref-transform.c', expected='output/c-backend/memref-transform.c')

    # TODO: this test case needs additional compilation option -O2.
    def test_memref_transform2(self):
        self.cif.run(cif_input='input/c-backend/memref-transform2.c', stage='C-backend', cif_output='work/memref-transform2.c')
        self.compare(output='work/memref-transform2.c', expected='output/c-backend/memref-transform2.c')

    def test_array(self):
        self.cif.run(cif_input='input/c-backend/array.c', stage='C-backend', cif_output='work/array.c')
        self.compare(output='work/array.c', expected='output/c-backend/array.c')

    def test_array_zero_lenght(self):
        self.cif.run(cif_input='input/c-backend/array-zero-lenght.c', stage='C-backend', cif_output='work/array-zero-lenght.c')
        self.compare(output='work/array-zero-lenght.c', expected='output/c-backend/array-zero-lenght.c')

    def test_array_no_size(self):
        self.cif.run(cif_input='input/c-backend/array-no-size.c', stage='C-backend', cif_output='work/array-no-size.c')
        self.compare(output='work/array-no-size.c', expected='output/c-backend/array-no-size.c')

    def test_transparent_union(self):
        self.cif.run(cif_input='input/c-backend/transparent_union.c', stage='C-backend', cif_output='work/transparent_union.c')
        self.compare(output='work/transparent_union.c', expected='output/c-backend/transparent_union.c')

    def test_extern_func_decl_without_params(self):
        self.cif.run(cif_input='input/c-backend/extern-func-decl-without-params.c', stage='C-backend', cif_output='work/extern-func-decl-without-params.c')
        self.compare(output='work/extern-func-decl-without-params.c', expected='output/c-backend/extern-func-decl-without-params.c')

    def test_float_expr(self):
        self.cif.run(cif_input='input/c-backend/float-expr.c', stage='C-backend', cif_output='work/float-expr.c')
        self.compare(output='work/float-expr.c', expected='output/c-backend/float-expr.c')

    def test_rdiv_expr(self):
        self.cif.run(cif_input='input/c-backend/rdiv-expr.c', stage='C-backend', cif_output='work/rdiv-expr.c')
        self.compare(output='work/rdiv-expr.c', expected='output/c-backend/rdiv-expr.c')

    def test_fix_trunc_expr(self):
        self.cif.run(cif_input='input/c-backend/fix-trunc-expr.c', stage='C-backend', cif_output='work/fix-trunc-expr.c')
        self.compare(output='work/fix-trunc-expr.c', expected='output/c-backend/fix-trunc-expr.c')

    def test_inline_asm_stub(self):
        os.environ['LDV_INLINE_ASM_STUB'] = ''
        self.cif.run(cif_input='input/c-backend/inline-asm-stub.c', stage='C-backend', cif_output='work/inline-asm-stub.c')
        del os.environ['LDV_INLINE_ASM_STUB']
        self.compare(output='work/inline-asm-stub.c', expected='output/c-backend/inline-asm-stub.c')

    def test_build_builtin_overflow(self):
        self.cif.run(cif_input='input/c-backend/builtin-overflow.c', stage='C-backend', cif_output='work/builtin-overflow.c')
        self.compare(output='work/builtin-overflow.c', expected='output/c-backend/builtin-overflow.c')

    def test_skip_save_expr(self):
        self.cif.run(cif_input='input/c-backend/skip-save-expr.c', stage='C-backend', cif_output='work/skip-save-expr.c', aspectator_opts=['-Os'])
        self.compare(output='work/skip-save-expr.c', expected='output/c-backend/skip-save-expr.c')

    def test_floatn(self):
        self.cif.run(cif_input='input/c-backend/floatn.c', stage='C-backend', cif_output='work/floatn.c')
        self.compare(output='work/floatn.c', expected='output/c-backend/floatn.c')

    def test_wide_char_str(self):
        self.cif.run(cif_input='input/c-backend/wide-char-str.c', stage='C-backend', cif_output='work/wide-char-str.c', aspectator_opts=['-DWCHAR_T=int'])
        self.compare(output='work/wide-char-str.c', expected='output/c-backend/wide-char-str.c')

    def test_short_wide_char_str(self):
        self.cif.run(cif_input='input/c-backend/wide-char-str.c', stage='C-backend', cif_output='work/short-wide-char-str.c', aspectator_opts=['-DWCHAR_T=unsigned short int', '-fshort-wchar'])
        self.compare(output='work/short-wide-char-str.c', expected='output/c-backend/short-wide-char-str.c')

    # Let's support vector types one day later.
    def _test_vector_type(self):
        self.cif.run(cif_input='input/c-backend/vector-type.c', stage='C-backend', cif_output='work/vector-type.c')
        self.compare(output='work/vector-type.c', expected='output/c-backend/vector-type.c')

    def test_multiple_decls(self):
        self.cif.run(cif_input='input/c-backend/multiple-decls.c', stage='C-backend', cif_output='work/multiple-decls.c')
        self.compare(output='work/multiple-decls.c', expected='output/c-backend/multiple-decls.c')

    def test_typedef_pointer(self):
        self.cif.run(cif_input='input/c-backend/typedef-pointer.c', stage='C-backend', cif_output='work/typedef-pointer.c')
        self.compare(output='work/typedef-pointer.c', expected='output/c-backend/typedef-pointer.c')

    def test_include1(self):
        self.cif.run(cif_input='input/c-backend/include.c', stage='C-backend', cif_output='work/include1.c', aspectator_opts=['-include', 'input/c-backend/include1.h'])
        self.compare(output='work/include1.c', expected='output/c-backend/include1.c')

    def test_include2(self):
        self.cif.run(cif_input='input/c-backend/include.c', stage='C-backend', cif_output='work/include2.c', aspectator_opts=['-include', 'input/c-backend/include1.h', '-include', 'input/c-backend/include2.h'])
        self.compare(output='work/include2.c', expected='output/c-backend/include2.c')

    def test_pretty_func(self):
        self.cif.run(cif_input='input/c-backend/pretty-func.c', stage='C-backend', cif_output='work/pretty-func.c')
        self.compare(output='work/pretty-func.c', expected='output/c-backend/pretty-func.c')

    def test_cast_to_anon_struct(self):
        self.cif.run(cif_input='input/c-backend/cast-to-anon-struct.c', stage='C-backend', cif_output='work/cast-to-anon-struct.c')
        self.compare(output='work/cast-to-anon-struct.c', expected='output/c-backend/cast-to-anon-struct.c')

    def test_packed(self):
        self.cif.run(cif_input='input/c-backend/packed.c', stage='C-backend', cif_output='work/packed.c')
        self.compare(output='work/packed.c', expected='output/c-backend/packed.c')


if __name__ == '__main__':
    unittest.main()
