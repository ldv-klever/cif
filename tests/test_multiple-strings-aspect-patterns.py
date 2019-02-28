import unittest
import utils


class TestMultipleStringsAspectPatterns(utils.CIFTestCase):
    def test_multiple_strings_aspect_patterns(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/multiple-strings-aspect-patterns.aspect', stage='instrumentation')
        self.skip_os_specific_defines('work/info.txt')
        self.compare(output='work/info.txt', expected='output/multiple-strings-aspect-patterns.txt')

if __name__ == '__main__':
    unittest.main()
