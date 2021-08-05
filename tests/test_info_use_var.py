import utils


class TestInfoUseVar(utils.CIFTestCase):
    def test_simple_info_use_var_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_use_var_all.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_call_info_use_var_all.txt')
