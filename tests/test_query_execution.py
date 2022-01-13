import utils


class TestQueryExecution(utils.CIFTestCase):
    def test_simple_query_execution_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/query_execution_all.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/simple_call_query_execution_all.txt')
