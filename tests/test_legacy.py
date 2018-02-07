import unittest
import utils


class TestLegacy(utils.CIFTestCase):
    def test_kind(self):
        self.cif.run(cif_input='tests/input/legacy_kind.c', aspect='tests/aspect/legacy_kind.aspect', cif_output='tests/work/legacy_kind.c')

        self.compare(output='tests/work/legacy_kind.c', expected='tests/output/legacy_kind.c')


if __name__ == '__main__':
    unittest.main()
