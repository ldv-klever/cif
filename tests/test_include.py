import utils


class TestInclude(utils.CIFTestCase):
    def test_include1(self):
        self.cif.run(cif_input='input/include.c', aspect='aspect/empty.aspect', cif_output='work/include1.c', aspectator_opts=['-include', 'input/include1.h'])
        self.compare(output='work/include1.c', expected='output/include1.c')

    def test_include2(self):
        self.cif.run(cif_input='input/include.c', aspect='aspect/empty.aspect', cif_output='work/include2.c', aspectator_opts=['-include', 'input/include1.h', '-include', 'input/include2.h'])
        self.compare(output='work/include2.c', expected='output/include2.c')

    def test_include3(self):
        self.cif.run(cif_input='input/include.c', aspect='aspect/empty.aspect', cif_output='work/include3.c', aspectator_opts=['-includeinput/include1.h', '-includeinput/include2.h'])
        self.compare(output='work/include3.c', expected='output/include3.c')
