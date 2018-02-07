import os
import sys
import unittest


if not os.path.isdir('../bin') or not os.path.isfile('../bin/aspectator'):
    sys.exit('You must compile the project before running tests.')

tests = unittest.TestLoader().discover('.', 'test*.py', '.')
result = unittest.TextTestRunner().run(tests)
sys.exit(0 if result.wasSuccessful() else 1)
