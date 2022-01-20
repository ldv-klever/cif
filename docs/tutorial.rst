.. _tutorial:

Tutorial
========

This section describes several typical use cases of using CIF as well as current limitations.
CIF has a bunch of command-line options that you can investigate by running it with *-h* or *--help*.
In the given tutorial we will consider only the following ones:

* *--in* -- a path to a C source file to be processed.
* *--aspect* -- a path to an aspect file (below there will be several examples, but you can read :ref:`aspects` for more
  details).
* *--out* - a path where a result will be placed.
* *--back-end* - a kind of a back-end to be used, e.g. 'src' or 'bin'.

If you are going to try provided examples, we recommend to change your current directory to :file:`docs/samples`.
Hereinafter all file paths and commands will be relative to that directory.

For all use cases below we will consider as an input the C source file presented in :numref:`input-c-source-file`. You
can find it here: :file:`calculate-max-rectangle-square.c`.

.. literalinclude:: samples/calculate-max-rectangle-square.c
    :caption: Input C source file
    :name: input-c-source-file
    :language: c

Weaving function calls
----------------------

This is the most typical case of using aspect-oriented programming. 
:numref:`weave-func-calculate-rectangle-square-aspect` provides an example of an appropriate aspect file.

.. literalinclude:: samples/weave-func-calculate-rectangle-square.aspect
    :caption: Aspect file intended for weaving calls to function calculate_rectangle_square()
    :name: weave-func-calculate-rectangle-square-aspect
    :language: c
