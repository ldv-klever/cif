import unittest
import utils


class TestLegacy(utils.CIFTestCase):
    def test_kind(self):
        self.cif.run(cif_input='input/legacy_kind.c', aspect='aspect/legacy_kind.aspect', cif_output='work/legacy_kind.c')
        self.compare(output='work/legacy_kind.c', expected='output/legacy_kind.c')


if __name__ == '__main__':
    unittest.main()
