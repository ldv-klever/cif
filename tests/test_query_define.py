import utils


class TestQueryDefine(utils.CIFTestCase):
    def test_simple_query_define_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/query_define_all.aspect', stage='instrumentation')
        self.skip_os_specific_defines('work/info.txt')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_call_query_define_all.txt')
