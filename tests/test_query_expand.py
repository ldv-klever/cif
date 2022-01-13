import utils


class TestQueryExpand(utils.CIFTestCase):
    def test_simple_query_expand_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/query_expand_all.aspect', stage='instrumentation')
        self.skip_os_specific_defines('work/info.txt')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_call_query_expand_all.txt')

    def test_query_macro_actual_args(self):
        self.cif.run(cif_input='input/macro_actual_args.c', aspect='aspect/query_macro_actual_args.aspect', stage='instrumentation')
        self.skip_os_specific_defines('work/info.txt')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/query_macro_actual_args.txt')
