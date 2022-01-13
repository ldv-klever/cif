import utils


class TestQueryDeclareFunc(utils.CIFTestCase):
    def test_simple_query_declare_func_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/query_declare_func_all.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_call_query_declare_func_all.txt')

    def test_query_pointer_to_struct_as_arg(self):
        self.cif.run(cif_input='input/pointer_to_struct_as_arg.c', aspect='aspect/query_pointer_to_struct_as_arg.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/query_pointer_to_struct_as_arg.txt')
