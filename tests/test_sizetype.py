import utils


class TestSizetype(utils.CIFTestCase):
    def test_sizetype(self):
        self.cif.run(cif_input='input/sizetype.c', aspect='aspect/empty.aspect', cif_output='work/sizetype.c')
