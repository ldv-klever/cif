import utils


class TestAspectPreprocessing(utils.CIFTestCase):
    def test_aspect_defines_and_conditionals(self):
        self.cif.run(cif_input='input/aspect-preprocessor-directives.c', aspect='aspect/aspect-defines-and-conditionals.aspect', stage='instrumentation')
        self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/aspect-defines-and-conditionals.txt')

    def test_aspect_includes(self):
        self.cif.run(cif_input='input/aspect-preprocessor-directives.c', aspect='aspect/aspect-includes.aspect', stage='instrumentation')
        # self.make_relpath('work/info.txt')
        self.compare(output='work/info.txt', expected='output/aspect-includes.txt')
