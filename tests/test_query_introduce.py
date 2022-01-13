import utils


class TestQueryIntroduce(utils.CIFTestCase):
    def test_simple_query_introduce_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/query_introduce_all.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/simple_call_query_introduce_all.txt')

    def test_query_introduce_multiple_decls(self):
        self.cif.run(cif_input='input/multiple-decls.c', aspect='aspect/query_introduce_all.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/query_introduce_multiple_decls.txt')
