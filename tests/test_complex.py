import utils


class TestComplex(utils.CIFTestCase):
    # Test for REALPART_EXPR and IMAGPART_EXPR - only up to instrumentation stage.
    # These nodes represent respectively the real and the imaginary parts of complex numbers (their sole argument).
    # Compilation stage with "src" back-end require support for these expressions in c-backend.
    def test_realpart_expr(self):
        self.cif.run(cif_input='input/complex.c', aspect='aspect/empty.aspect', stage='instrumentation')
