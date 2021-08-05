import utils


class TestWildcard(utils.CIFTestCase):
    def test_func_arg_types_wildcard(self):
        self.cif.run(cif_input='input/arg-types-wildcard.c', aspect='aspect/arg-types-wildcard.aspect', cif_output='work/arg-types-wildcard.c')
        self.compare(output='work/arg-types-wildcard.c', expected='output/arg-types-wildcard.c')
