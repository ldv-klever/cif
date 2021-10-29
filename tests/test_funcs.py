import os
import utils


class TestFuncs(utils.CIFTestCase):
    def test_func_calls(self):
        self.cif.run(cif_input='input/func-calls.c', aspect='aspect/func-calls.aspect', cif_output='work/func-calls.c')
        self.compare(output='work/func-calls.c', expected='output/func-calls.c')

    def test_matched_by_name_debug(self):
        os.environ['LDV_PRINT_SIGNATURE_OF_MATCHED_BY_NAME'] = '1'
        self.cif.run(cif_input='input/func-calls.c', aspect='aspect/invalid-func-calls.aspect', cif_output='work/invalid-func-calls.c')
        del os.environ['LDV_PRINT_SIGNATURE_OF_MATCHED_BY_NAME']
        self.compare(output='work/invalid-func-calls.c', expected='output/invalid-func-calls.c')
        self.compare_log(expected='output/invalid-func-calls.log')
