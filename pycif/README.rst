============
Introduction
============

pycif is a Python API for CIF.

Prerequisites:

- Python 3 (>= 3.5)
- CIF_

Optional dependencies:

- pytest_ for running test suite

============
Installation
============

To install the latest version directly from the repository just run the
following commands:

.. code-block:: bash

    $ cd pycif
    $ python3 -m pip install .

.. You can check that pycif works as expected on your machine by installing it
.. and then running the test suite from the pycif folder:

.. .. code-block:: bash

..     $ pytest

.. Tests assume that there is *cif* binary available in the PATH.

=====
Usage
=====

Not yet written...

===========
Development
===========

To develop pycif it is required to adhere to some rules:

- Docstrings must be written in the `Google Style`_.
- All source files must be formatted using Black_.

.. _CIF: https://github.com/17451k/cif
.. _pytest: https://docs.pytest.org/en/stable/
.. _Black: https://black.readthedocs.io/en/stable/the_black_code_style.html
.. _`Google Style`: https://github.com/google/styleguide/blob/gh-pages/pyguide.md#38-comments-and-docstrings
