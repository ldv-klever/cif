import os
import utils


class TestMacros(utils.CIFTestCase):
    def test_matched_by_name_debug(self):
        os.environ['LDV_PRINT_SIGNATURE_OF_MATCHED_BY_NAME'] = '1'
        self.cif.run(cif_input='input/macros.c', aspect='aspect/invalid-macros.aspect', cif_output='work/invalid-macros.c')
        del os.environ['LDV_PRINT_SIGNATURE_OF_MATCHED_BY_NAME']
        self.compare(output='work/invalid-macros.c', expected='output/invalid-macros.c')
        self.compare_log(expected='output/invalid-macros.log')
