import pytest
import utils


class TestLegacy(utils.CIFTestCase):
    def test_kind(self):
        self.cif.run(cif_input='input/legacy_kind.c', aspect='aspect/legacy_kind.aspect', cif_output='work/legacy_kind.c')
        self.compare(output='work/legacy_kind.c', expected='output/legacy_kind.c')

    def test_macro(self):
        self.cif.run(cif_input='input/legacy_macro.c', aspect='aspect/legacy_macro.aspect', cif_output='work/legacy_macro.c')
        self.compare(output='work/legacy_macro.c', expected='output/legacy_macro.c')

    def test_type(self):
        self.cif.run(cif_input='input/legacy_type.c', aspect='aspect/legacy_type.aspect', cif_output='work/legacy_type.c')
        self.compare(output='work/legacy_type.c', expected='output/legacy_type.c')

    def test_function(self):
        self.cif.run(cif_input='input/legacy_function.c', aspect='aspect/legacy_function.aspect', cif_output='work/legacy_function.c')
        self.compare(output='work/legacy_function.c', expected='output/legacy_function.c')

    def test_variable(self):
        self.cif.run(cif_input='input/legacy_variable.c', aspect='aspect/legacy_variable.aspect', cif_output='work/legacy_variable.c')
        self.compare(output='work/legacy_variable.c', expected='output/legacy_variable.c')

    def test_empty(self):
        self.cif.run(cif_input='input/legacy_empty.c', aspect='aspect/empty.aspect', cif_output='work/legacy_empty.c')
        self.compare(output='work/legacy_empty.c', expected='output/legacy_empty.c')

    def test_any_params(self):
        self.cif.run(cif_input='input/legacy_any_params.c', aspect='aspect/legacy_any_params.aspect', cif_output='work/legacy_any_params.c')
        self.compare(output='work/legacy_any_params.c', expected='output/legacy_any_params.c')

    @pytest.mark.skip()
    def test_simple(self):
        self.cif.run(cif_input='input/legacy_simple.c', aspect='aspect/legacy_simple.aspect', cif_output='work/legacy_simple.c')
        self.compare(output='work/legacy_simple.c', expected='output/legacy_simple.c')

    def test_aux_funcs(self):
        self.cif.run(cif_input='input/aux-funcs.c', aspect='aspect/aux-funcs.aspect', cif_output='work/aux-funcs.c')
        self.compare(output='work/aux-funcs.c', expected='output/aux-funcs.c')

    @pytest.mark.x86_64
    def test_va_funcs(self):
        self.cif.run(cif_input='input/va-funcs.c', aspect='aspect/va-funcs.aspect', cif_output='work/va-funcs.c')
        self.compare(output='work/va-funcs.c', expected='output/va-funcs.c')

    @pytest.mark.arm
    @pytest.mark.aarch64
    def test_va_funcs_arm(self):
        self.cif.run(cif_input='input/va-funcs.c', aspect='aspect/va-funcs.aspect', cif_output='work/va-funcs-arm.c')
        self.compare(output='work/va-funcs-arm.c', expected='output/va-funcs-arm.c')

    def test_gnu_inline(self):
        self.cif.run(cif_input='input/gnu_inline.c', aspect='aspect/gnu_inline.aspect', cif_output='work/gnu_inline.c')
        self.compare(output='work/gnu_inline.c', expected='output/gnu_inline.c')
