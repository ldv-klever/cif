import utils


class TestInfoCallp(utils.CIFTestCase):
    def test_simple_info_callp_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_callp_all.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_info_callp_all.txt')
