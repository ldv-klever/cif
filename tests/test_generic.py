import pytest
import utils


class TestGeneric(utils.CIFTestCase):
    # Indeed, cif.cpp does not require to escape double quotes unlike it was for cif.c.
    @pytest.mark.xfail
    def test_escaping_double_quotes(self):
        self.cif.run(cif_input='input/generic.c', stage='C-backend', cif_output='work/simple.c', aspectator_opts=['-DDOUBLE_QUOTES=\\"double quotes\\"'])
