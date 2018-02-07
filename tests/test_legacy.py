import unittest
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

    def test_variable(self):
        self.cif.run(cif_input='input/legacy_variable.c', aspect='aspect/legacy_variable.aspect', cif_output='work/legacy_variable.c')
        self.compare(output='work/legacy_variable.c', expected='output/legacy_variable.c')

    def test_empty(self):
        self.cif.run(cif_input='input/legacy_empty.c', aspect='aspect/legacy_empty.aspect', cif_output='work/legacy_empty.c')
        self.compare(output='work/legacy_empty.c', expected='output/legacy_empty.c')

    def not_test_any_params(self):
        # Aspectator failed at '4' stage
        self.cif.run(cif_input='input/legacy_any_params.c', aspect='aspect/legacy_any_params.aspect', cif_output='work/legacy_any_params.c')
        self.compare(output='work/legacy_any_params.c', expected='output/legacy_any_params.c')

    def not_test_simple(self):
        # Aspectator failed at '4' stage
        self.cif.run(cif_input='input/legacy_simple.c', aspect='aspect/legacy_simple.aspect', cif_output='work/legacy_simple.c')
        self.compare(output='work/legacy_simple.c', expected='output/legacy_simple.c')

    def not_test_function(self):
        # Aspect file has incorrect syntax
        self.cif.run(cif_input='input/legacy_function.c', aspect='aspect/legacy_function.aspect', cif_output='work/legacy_function.c')
        self.compare(output='work/legacy_function.c', expected='output/legacy_function.c')


if __name__ == '__main__':
    unittest.main()
