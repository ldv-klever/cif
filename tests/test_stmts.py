import os
import utils


# Test traversing of different statements within function bodies.
class TestStmts(utils.CIFTestCase):
    def test_if_else(self):
        self.cif.run(cif_input='input/stmts/if-else.c', aspect='aspect/func-calls.aspect', cif_output='work/if-else.c')
        self.compare(output='work/if-else.c', expected='output/stmts/if-else.c')

    def test_elvis(self):
        self.cif.run(cif_input='input/stmts/elvis.c', aspect='aspect/func-calls.aspect', cif_output='work/elvis.c')
        self.compare(output='work/elvis.c', expected='output/stmts/elvis.c')

    def test_switch(self):
        self.cif.run(cif_input='input/stmts/switch.c', aspect='aspect/func-calls.aspect', cif_output='work/switch.c')
        self.compare(output='work/switch.c', expected='output/stmts/switch.c')

    def test_while(self):
        self.cif.run(cif_input='input/stmts/while.c', aspect='aspect/func-calls.aspect', cif_output='work/while.c')
        self.compare(output='work/while.c', expected='output/stmts/while.c')

    def test_for(self):
        self.cif.run(cif_input='input/stmts/for.c', aspect='aspect/func-calls.aspect', cif_output='work/for.c')
        self.compare(output='work/for.c', expected='output/stmts/for.c')

    def test_do_while(self):
        self.cif.run(cif_input='input/stmts/do-while.c', aspect='aspect/func-calls.aspect', cif_output='work/do-while.c')
        self.compare(output='work/do-while.c', expected='output/stmts/do-while.c')
