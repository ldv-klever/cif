import utils


class TestInfoIntroduce(utils.CIFTestCase):
    def test_simple_info_introduce_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_introduce_all.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/simple_call_info_introduce_all.txt')

    def test_info_introduce_multiple_decls(self):
        self.cif.run(cif_input='input/multiple-decls.c', aspect='aspect/info_introduce_all.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/info_introduce_multiple_decls.txt')
