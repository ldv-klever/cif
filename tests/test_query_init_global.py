import utils


class TestQueryInitGlobal(utils.CIFTestCase):
    def test_simple_query_init_global_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/query_init_global_all.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_call_query_init_global_all.txt')

    def test_simple_query_init_list(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/query_init_list.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/simple_call_query_init_list.txt')

    def test_complex_struct_query_init_list(self):
        self.cif.run(cif_input='input/complex_struct.c', aspect='aspect/query_init_list.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/complex_struct_call_query_init_list.txt')

    def test_large_array_query_init_list(self):
        self.cif.run(cif_input='input/large_array.c', aspect='aspect/query_init_list.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/large_array_call_query_init_list.txt')
