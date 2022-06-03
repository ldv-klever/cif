import utils


class TestPointcuts(utils.CIFTestCase):
    def test_same_name(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/pointcuts_with_same_name.aspect', stage='instrumentation', expected_fail=True)
