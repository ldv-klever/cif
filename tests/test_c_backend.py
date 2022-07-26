import os
import pytest
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

    @pytest.mark.not_arm
    def test_array(self):
        self.cif.run(cif_input='input/c-backend/array.c', stage='C-backend', cif_output='work/array.c')
        self.compare(output='work/array.c', expected='output/c-backend/array.c')

    @pytest.mark.arm
    def test_array_arm(self):
        self.cif.run(cif_input='input/c-backend/array.c', stage='C-backend', cif_output='work/array-arm.c')
        self.compare(output='work/array-arm.c', expected='output/c-backend/array-arm.c')

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

    @pytest.mark.not_arm
    def test_builtin_overflow(self):
        self.cif.run(cif_input='input/c-backend/builtin-overflow.c', stage='C-backend', cif_output='work/builtin-overflow.c')
        self.compare(output='work/builtin-overflow.c', expected='output/c-backend/builtin-overflow.c')

    @pytest.mark.arm
    def test_builtin_overflow_arm(self):
        self.cif.run(cif_input='input/c-backend/builtin-overflow.c', stage='C-backend', cif_output='work/builtin-overflow-arm.c')
        self.compare(output='work/builtin-overflow-arm.c', expected='output/c-backend/builtin-overflow-arm.c')

    @pytest.mark.not_arm
    def test_skip_save_expr(self):
        self.cif.run(cif_input='input/c-backend/skip-save-expr.c', stage='C-backend', cif_output='work/skip-save-expr.c', aspectator_opts=['-Os'])
        self.compare(output='work/skip-save-expr.c', expected='output/c-backend/skip-save-expr.c')

    @pytest.mark.arm
    def test_skip_save_expr_arm(self):
        self.cif.run(cif_input='input/c-backend/skip-save-expr.c', stage='C-backend', cif_output='work/skip-save-expr-arm.c', aspectator_opts=['-Os'])
        self.compare(output='work/skip-save-expr-arm.c', expected='output/c-backend/skip-save-expr-arm.c')

    @pytest.mark.x86_64
    def test_floatn(self):
        self.cif.run(cif_input='input/c-backend/floatn.c', stage='C-backend', cif_output='work/floatn.c')
        self.compare(output='work/floatn.c', expected='output/c-backend/floatn.c')

    @pytest.mark.arm
    def test_floatn_arm(self):
        self.cif.run(cif_input='input/c-backend/floatn.c', stage='C-backend', cif_output='work/floatn-arm.c')
        self.compare(output='work/floatn-arm.c', expected='output/c-backend/floatn-arm.c')

    @pytest.mark.aarch64
    def test_floatn_aarch64(self):
        self.cif.run(cif_input='input/c-backend/floatn.c', stage='C-backend', cif_output='work/floatn-aarch64.c')
        self.compare(output='work/floatn-aarch64.c', expected='output/c-backend/floatn-aarch64.c')

    @pytest.mark.x86_64
    def test_wide_char_str(self):
        self.cif.run(cif_input='input/c-backend/wide-char-str.c', stage='C-backend', cif_output='work/wide-char-str.c', aspectator_opts=['-DWCHAR_T=int'])
        self.compare(output='work/wide-char-str.c', expected='output/c-backend/wide-char-str.c')

    def test_short_wide_char_str(self):
        self.cif.run(cif_input='input/c-backend/wide-char-str.c', stage='C-backend', cif_output='work/short-wide-char-str.c', aspectator_opts=['-DWCHAR_T=unsigned short int', '-fshort-wchar'])
        self.compare(output='work/short-wide-char-str.c', expected='output/c-backend/short-wide-char-str.c')

    def test_escape_sequence_str(self):
        self.cif.run(cif_input='input/c-backend/escape-sequence-str.c', stage='C-backend', cif_output='work/escape-sequence-str.c')
        self.compare(output='work/escape-sequence-str.c', expected='output/c-backend/escape-sequence-str.c')

    @pytest.mark.skip(reason="Vector types are not supported")
    def test_vector_type(self):
        self.cif.run(cif_input='input/c-backend/vector-type.c', stage='C-backend', cif_output='work/vector-type.c')
        self.compare(output='work/vector-type.c', expected='output/c-backend/vector-type.c')

    def test_multiple_decls(self):
        self.cif.run(cif_input='input/c-backend/multiple-decls.c', stage='C-backend', cif_output='work/multiple-decls.c')
        self.compare(output='work/multiple-decls.c', expected='output/c-backend/multiple-decls.c')

    def test_typedef_pointer(self):
        self.cif.run(cif_input='input/c-backend/typedef-pointer.c', stage='C-backend', cif_output='work/typedef-pointer.c')
        self.compare(output='work/typedef-pointer.c', expected='output/c-backend/typedef-pointer.c')

    def test_cast_to_anon_struct(self):
        self.cif.run(cif_input='input/c-backend/cast-to-anon-struct.c', stage='C-backend', cif_output='work/cast-to-anon-struct.c')
        self.compare(output='work/cast-to-anon-struct.c', expected='output/c-backend/cast-to-anon-struct.c')

    def test_type_attrs(self):
        self.cif.run(cif_input='input/c-backend/type-attrs.c', stage='C-backend', cif_output='work/type-attrs.c')
        self.compare(output='work/type-attrs.c', expected='output/c-backend/type-attrs.c')

    def test_llongmin(self):
        self.cif.run(cif_input='input/c-backend/llongmin.c', stage='C-backend', cif_output='work/llongmin.c')
        self.compare(output='work/llongmin.c', expected='output/c-backend/llongmin.c')

    @pytest.mark.not_arm
    def test_container_of(self):
        self.cif.run(cif_input='input/c-backend/container-of.c', stage='C-backend', cif_output='work/container-of.c')
        self.compare(output='work/container-of.c', expected='output/c-backend/container-of.c')

    @pytest.mark.arm
    def test_container_of_arm(self):
        self.cif.run(cif_input='input/c-backend/container-of.c', stage='C-backend', cif_output='work/container-of-arm.c')
        self.compare(output='work/container-of-arm.c', expected='output/c-backend/container-of-arm.c')

    def test_may_alias(self):
        self.cif.run(cif_input='input/c-backend/may-alias.c', stage='C-backend', cif_output='work/may-alias.c')
        self.compare(output='work/may-alias.c', expected='output/c-backend/may-alias.c')

    def test_fallthrough(self):
        self.cif.run(cif_input='input/c-backend/fallthrough.c', stage='C-backend', cif_output='work/fallthrough.c')
        self.compare(output='work/fallthrough.c', expected='output/c-backend/fallthrough.c')

    def test___func__(self):
        self.cif.run(cif_input='input/c-backend/__func__.c', stage='C-backend', cif_output='work/__func__.c')
        self.compare(output='work/__func__.c', expected='output/c-backend/__func__.c')

    def test_typedef_array(self):
        self.cif.run(cif_input='input/c-backend/typedef-array.c', stage='C-backend', cif_output='work/typedef-array.c')
        self.compare(output='work/typedef-array.c', expected='output/c-backend/typedef-array.c')

    @pytest.mark.not_arm
    def test_cast_ptr_arithm(self):
        self.cif.run(cif_input='input/c-backend/cast-ptr-arithm.c', stage='C-backend', cif_output='work/cast-ptr-arithm.c')
        self.compare(output='work/cast-ptr-arithm.c', expected='output/c-backend/cast-ptr-arithm.c')

    @pytest.mark.arm
    def test_cast_ptr_arithm_arm(self):
        self.cif.run(cif_input='input/c-backend/cast-ptr-arithm-arm.c', stage='C-backend', cif_output='work/cast-ptr-arithm-arm.c')
        self.compare(output='work/cast-ptr-arithm-arm.c', expected='output/c-backend/cast-ptr-arithm-arm.c')

    def test_cast_ptr_void(self):
        self.cif.run(cif_input='input/c-backend/cast-ptr-void.c', stage='C-backend', cif_output='work/cast-ptr-void.c')
        self.compare(output='work/cast-ptr-void.c', expected='output/c-backend/cast-ptr-void.c')

    def test_bitfield_access(self):
        self.cif.run(cif_input='input/c-backend/bitfield-access.c', stage='C-backend', cif_output='work/bitfield-access.c')
        self.compare(output='work/bitfield-access.c', expected='output/c-backend/bitfield-access.c')

    def test_atomic_type_qual(self):
        self.cif.run(cif_input='input/c-backend/atomic-type-qual.c', stage='C-backend', cif_output='work/atomic-type-qual.c')
        self.compare(output='work/atomic-type-qual.c', expected='output/c-backend/atomic-type-qual.c')

    def test_omit_type_quals(self):
        env = dict(os.environ)
        env['LDV_C_BACKEND_OMIT_TYPE_QUALS'] = "1"
        self.cif.run(cif_input='input/c-backend/omit-type-quals.c', stage='C-backend', cif_output='work/omit-type-quals.c', env=env)
        self.compare(output='work/omit-type-quals.c', expected='output/c-backend/omit-type-quals.c')

    def test_decls_and_stmts_intermix(self):
        self.cif.run(cif_input='input/c-backend/decls-and-stmts-intermix.c', stage='C-backend', cif_output='work/decls-and-stmts-intermix.c')
        self.compare(output='work/decls-and-stmts-intermix.c', expected='output/c-backend/decls-and-stmts-intermix.c')

    def test_implicit_func_decls(self):
        self.cif.run(cif_input='input/c-backend/implicit-func-decls.c', stage='C-backend', cif_output='work/implicit-func-decls.c')
        self.compare(output='work/implicit-func-decls.c', expected='output/c-backend/implicit-func-decls.c')

    def test_while(self):
        self.cif.run(cif_input='input/c-backend/while.c', stage='C-backend', cif_output='work/while.c')
        self.compare(output='work/while.c', expected='output/c-backend/while.c')

    def test_do_while(self):
        self.cif.run(cif_input='input/c-backend/do_while.c', stage='C-backend', cif_output='work/do_while.c')
        self.compare(output='work/do_while.c', expected='output/c-backend/do_while.c')

    def test_for(self):
        self.cif.run(cif_input='input/c-backend/for.c', stage='C-backend', cif_output='work/for.c')
        self.compare(output='work/for.c', expected='output/c-backend/for.c')

    def test_inc_dec(self):
        self.cif.run(cif_input='input/c-backend/inc_dec.c', stage='C-backend', cif_output='work/inc_dec.c')
        self.compare(output='work/inc_dec.c', expected='output/c-backend/inc_dec.c')

    def test_array_of_chars_init(self):
        self.cif.run(cif_input='input/c-backend/array-of-chars-init.c', stage='C-backend', cif_output='work/array-of-chars-init.c')
        self.compare(output='work/array-of-chars-init.c', expected='output/c-backend/array-of-chars-init.c')

    def test_anonymous_union_init(self):
        self.cif.run(cif_input='input/c-backend/anonymous-union-init.c', stage='C-backend', cif_output='work/anonymous-union-init.c')
        self.compare(output='work/anonymous-union-init.c', expected='output/c-backend/anonymous-union-init.c')

    def test_abs_expr(self):
        self.cif.run(cif_input='input/c-backend/abs-expr.c', stage='C-backend', cif_output='work/abs-expr.c')
        self.compare(output='work/abs-expr.c', expected='output/c-backend/abs-expr.c')

    def test_min_max_expr(self):
        self.cif.run(cif_input='input/c-backend/min-max-expr.c', stage='C-backend', cif_output='work/min-max-expr.c')
        self.compare(output='work/min-max-expr.c', expected='output/c-backend/min-max-expr.c')

    def test_expr_recursion_limit(self):
        self.cif.run(cif_input='input/c-backend/expr-recursion-limit.c', stage='C-backend', cif_output='work/expr-recursion-limit.c')
        self.compare(output='work/expr-recursion-limit.c', expected='output/c-backend/expr-recursion-limit.c')

    def test_var_decl_storage_classes(self):
        self.cif.run(cif_input='input/c-backend/var-decl-storage-classes.c', stage='C-backend', cif_output='work/var-decl-storage-classes.c')
        self.compare(output='work/var-decl-storage-classes.c', expected='output/c-backend/var-decl-storage-classes.c')
