.. _tutorial:

Tutorial
========

This section describes several typical cases of using CIF as well as current most vital limitations.
CIF has a bunch of command-line options that you can investigate by running it with *-h* or *\--help*.
In the given tutorial we will consider only the following ones:

* *\--in* -- a path to a C source file to be processed.
* *\--aspect* -- a path to an aspect file.
  Below there will be several examples of aspect files.
* *\--out* -- a path where a result will be placed.
* *\--back-end* -- a kind of a back-end to be used, e.g. 'src' or 'bin'.

If you are going to try provided examples, we recommend to change your current directory to :file:`docs/samples` within
the source tree root.
Hereinafter all file paths and commands will be relative to that directory.

For all use cases below we will consider as an input the C source file presented in :numref:`input-c-source-file`.
You can find it here: :file:`calculate-max-rectangle-square.c`.

.. literalinclude:: samples/calculate-max-rectangle-square.c
    :caption: Input C source file
    :name: input-c-source-file
    :language: c

Normal compilation and running of this program will result in the following output::

    $ gcc calculate-max-rectangle-square.c -o calculate-max-rectangle-square
    $ ./calculate-max-rectangle-square 2 5 7 3 4 4
    Maximum rectangle square is 21

Weaving function calls
----------------------

This is the most typical use case.
:numref:`weave-func-calculate-rectangle-square-aspect` provides an example of an appropriate aspect file located in
:file:`weave-func-calculate-rectangle-square.aspect`.

.. literalinclude:: samples/weave-func-calculate-rectangle-square.aspect
    :caption: Aspect file intended for weaving calls of function **calculate_rectangle_square()**
    :name: weave-func-calculate-rectangle-square-aspect
    :language: c

To weave in the target C source file with the given aspect you can run the following command::

    $ ../../inst/bin/cif --in calculate-max-rectangle-square.c --aspect weave-func-calculate-rectangle-square.aspect --out calculate-max-rectangle-square --back-end bin

Then you will get the following output when running the generated program binary::

    $ ./calculate-max-rectangle-square 2 5 7 3 4 4
    Calculated rectangle square is 10 (2 * 5)
    Calculated rectangle square is 21 (7 * 3)
    Calculated rectangle square is 16 (4 * 4)
    Maximum rectangle square is 21

This demonstrates debugging and logging facilities of CIF.
Probably by some reason you would not like to add an appropriate code directly to program's source files.
So you can use aspect files instead in a similar way.

The same aspect also enables extra checking.
Therefore, you can get the following warning if you will intentionally violate implicit assumptions regarding possible
multiplication overflows::

    $ ./calculate-max-rectangle-square 4317358 6927345
    After multiplication of 4317358 and 6927345 there will be overflow, so you can get invalid result
    Calculated rectangle square is 1971072462 (4317358 * 6927345)
    Maximum rectangle square is 1971072462

(the valid result should be 29907828354510).

Weaving macros
--------------

Sometimes it may be necessary to change macros.
CIF is capable to do that.
:file:`weave-macro-max.aspect` in :numref:`weave-macro-max-aspect` contains an example that add extra debugging for
macro *MAX*.

.. literalinclude:: samples/weave-macro-max.aspect
    :caption: Aspect file intended for weaving macro **MAX**
    :name: weave-macro-max-aspect
    :language: c

On executing following commands you will get the output as follows::

    $ ../../inst/bin/cif --in calculate-max-rectangle-square.c --aspect weave-macro-max.aspect --out calculate-max-rectangle-square --back-end bin
    $ ./calculate-max-rectangle-square 2 5 7 3 4 4
    Update maximum value from 0 to 10
    Update maximum value from 10 to 21
    Maximum rectangle square is 21

Weaving variables
-----------------

:numref:`weave-var-rectangles-num-aspect` shows how to weave in variable assignments.
The corresponding aspect file is :file:`weave-var-rectangles-num.aspect`.

.. literalinclude:: samples/weave-var-rectangles-num.aspect
    :caption: Aspect file intended for weaving assignments of variable **rectangles_num**
    :name: weave-var-rectangles-num-aspect
    :language: c

This aspect makes pretty artificial change (it excludes the last rectangle from calculations), but you can have some
more important things to do, e.g. you can dump all values assigned to a given variable.

To test this aspect you can run the following commands::

   $ ../../inst/bin/cif --in calculate-max-rectangle-square.c --aspect weave-var-rectangles-num.aspect --out calculate-max-rectangle-square --back-end bin
   $ ./calculate-max-rectangle-square 2 5 7 3 4 4 8 9
   Maximum rectangle square is 21

Weaving compound types
----------------------

CIF suggests means to modify compound types such as structures, unions and enumerations.
For instance, you can find an example of an appropriate aspect in :numref:`weave-struct-rectangle-aspect`
(:file:`weave-struct-rectangle.aspect` in :file:`docs/samples`).

.. literalinclude:: samples/weave-struct-rectangle.aspect
    :caption: Aspect file intended for weaving structure **rectangle**
    :name: weave-struct-rectangle-aspect
    :language: c

This aspect adds extra field *perimeter* to the definition of structure *rectangle*.
Besides, through weaving of function *calculate_rectangle_square()* it calculates, stores and prints out perimeters for
all rectangles.

To test this aspect you can run the following commands::

   $ ../../inst/bin/cif --in calculate-max-rectangle-square.c --aspect weave-struct-rectangle.aspect --out calculate-max-rectangle-square --back-end bin
   $ ./calculate-max-rectangle-square 2 5 7 3 4 4 8 9
   Calculated rectangle perimeter is 7 (2 * 5)
   Calculated rectangle perimeter is 10 (7 * 3)
   Calculated rectangle perimeter is 8 (4 * 4)
   Calculated rectangle perimeter is 17 (8 * 9)
   Maximum rectangle square is 72

Querying source code
--------------------

CIF can execute different queries to target source files.
For instance, you can use aspect :file:`query-func-calls.aspect` shown in :numref:`query-func-calls-aspect` to find out
all function calls.

.. literalinclude:: samples/query-func-calls.aspect
    :caption: Aspect file demonstrating source code queries
    :name: query-func-calls-aspect
    :language: c

This aspect file will not affect your program.
You will only get an extra file at the weaving stage.
For instance::

    $ ../../inst/bin/cif --in calculate-max-rectangle-square.c --aspect query-func-calls.aspect --out calculate-max-rectangle-square --stage instrumentation
    $ cat func-calls.txt
    Function calloc() is called at line 32
    Function atoi() is called at line 36
    Function atoi() is called at line 37
    Function calculate_rectangle_square() is called at line 38
    Function printf() is called at line 42

(we asked CIF to stop after stage *instrumentation* since we would not like to get the program binary in this case).

Invalid aspects
---------------

You can wonder how to track various issues with aspects.
First of all, CIF will fail and report appropriate errors if you will provide syntactically invalid aspects.
Sometimes, aspects can have valid syntax, but they might not work as expected.
:numref:`weave-invalid-func-decl-aspect` presents the content of :file:`weave-invalid-func-decl.aspect`.
Therein we deliberately specified invalid declaration for function *calculate_rectangle_square()*.

.. literalinclude:: samples/weave-invalid-func-decl.aspect
    :caption: Aspect file using invalid target function declaration
    :name: weave-invalid-func-decl-aspect
    :language: c

You will not get any warnings if you will run CIF as usual::

    $ ../../inst/bin/cif --in calculate-max-rectangle-square.c --aspect weave-invalid-func-decl.aspect --out calculate-max-rectangle-square --back-end bin

But if you will set environment variable :envvar:`LDV_PRINT_SIGNATURE_OF_MATCHED_BY_NAME` the situation will change::

    $ export LDV_PRINT_SIGNATURE_OF_MATCHED_BY_NAME=1
    $ ../../inst/bin/cif --in calculate-max-rectangle-square.c --aspect weave-invalid-func-decl.aspect --out calculate-max-rectangle-square --back-end bin

    These functions were matched by name but have different signatures:
      source function declaration: unsigned int calculate_rectangle_square (struct rectangle *r)
      aspect function declaration: struct rectangle *calculate_rectangle_square (unsigned int, unsigned int)

Getting woven source files
--------------------------

It may be useful for debugging and necessary for some applications to get woven source files rather than binaries as an
output.
For instance, you can slightly change the command for the first use case (note the change of *bin* to *src* for
command-line option *\--back-end*)::

    $ ../../inst/bin/cif --in calculate-max-rectangle-square.c --aspect weave-func-calculate-rectangle-square.aspect --out calculate-max-rectangle-square --back-end src

and investigate outputted file :file:`calculate-max-rectangle-square` that will be a C source file.

Further study
-------------

CIF has much more capabilities in addition to the ones that we presented in this tutorial.
You can read :ref:`aoc` that describes the aspect-oriented extension of the C programming language to study all possible
ways of using CIF.
Besides, you can find a lot of examples of aspects in projects `Klever <https://forge.ispras.ru/projects/klever>`__ (in
particular, `here <https://klever.readthedocs.io/en/latest/dev_common_api_models.html>`__ and
`here <https://klever.readthedocs.io/en/latest/dev_req_specs.html>`__) and `Clade <https://github.com/17451k/clade>`__
(`here <https://github.com/17451k/clade/blob/master/clade/extensions/info/info.aspect>`__).

Known issues
------------

CIF is not used very widely, so there is a lot of different issues with it.
You can find the known issues in the `official issue tracker <https://forge.ispras.ru/projects/cif/issues>`__.
The most vital ones are as follows:

* CIF does not have a command-line interface that is compatible with a compiler
  (`#6829 <https://forge.ispras.ru/issues/6829>`__).
  Thus, you can not easily incorporate it into your program's build process.
* CIF does not support multiple advices for the same join point (`#358 <https://forge.ispras.ru/issues/358>`__).
* CIF does not support well the entire C programming language with all `GCC <https://gcc.gnu.org/>`__ compiler
  extensions.
  Other compiler extensions are supported to the extent that it is done by GCC itself (you can find some related
  command-line options `here <https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html>`__).
* CIF is not particularly optimized.
  It is noticeable if it is called to handle hundreds or thousands of files.
