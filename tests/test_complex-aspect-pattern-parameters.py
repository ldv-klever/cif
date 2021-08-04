import os
import unittest
import utils


class TestComplexAspectPatternParameters(utils.CIFTestCase):
    def test_multiple_strings(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/multiple-strings-aspect-pattern-parameters.aspect', stage='instrumentation')
        self.compare(output='work/info.txt', expected='output/multiple-strings-aspect-pattern-parameters.txt')

    def test_strings_with_aspect_pattern_string_parameters(self):
        os.environ['PREFIX'] = 'pre'
        self.cif.run(cif_input='input/simple.c', aspect='aspect/strings-with-aspect-pattern-string-parameters.aspect', stage='instrumentation')
        self.make_relpath('work/pre-pre-SOMETHING.txt')
        self.compare(output='work/pre-pre-SOMETHING.txt', expected='output/strings-with-aspect-pattern-string-parameters1.txt')
        self.make_relpath('work/pre-pre-CONST.txt')
        self.compare(output='work/pre-pre-CONST.txt', expected='output/strings-with-aspect-pattern-string-parameters2.txt')


if __name__ == '__main__':
    unittest.main()
