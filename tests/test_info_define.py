import unittest
import utils


class TestInfoDefine(utils.CIFTestCase):
    def test_simple_info_define_all(self):
        self.cif.run(cif_input='input/simple.c', aspect='aspect/info_define_all.aspect', stage='instrumentation')
        with open('work/info.txt') as fp:
            lines = fp.readlines()
        with open('work/info.txt', 'w') as fp:
            # Skip OS specific defines.
            for line in lines:
                if not line.startswith('/usr/include/stdc-predef.h'):
                    fp.write(line)
        self.compare(output='work/info.txt', expected='output/simple_call_info_define_all.txt')


if __name__ == '__main__':
    unittest.main()
