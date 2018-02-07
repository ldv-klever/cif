import os
import sys
import unittest


if not os.path.isdir('tests'):
    sys.exit('Tests must be executed from the project root directory.')

if not os.path.isdir('bin') or not os.path.isfile('bin/aspectator'):
    sys.exit('You must compile the project before running tests.')

tests = unittest.TestLoader().discover('tests', 'test*.py', 'tests')
result = unittest.TextTestRunner().run(tests)
sys.exit(0 if result.wasSuccessful() else 1)
