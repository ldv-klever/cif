import utils


class TestQueryCallp(utils.CIFTestCase):
    def test_simple_query_callp_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/query_callp_all.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_query_callp_all.txt')
