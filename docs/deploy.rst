Deployment
==========

Build dependencies
------------------

To build CIF you need to install the following packages:

* make
* gcc
* g++
* flex
* bison

Build and install
-----------------

First you need to download archives with the source code of prerequisites needed by GCC (*gmp*, *mpfr*, *mpc* and
*isl*)::

    $ cd aspectator
    $ ./contrib/download_prerequisites

Then return back to the root of the repository and execute *make*::

    $ cd ..
    $ make

You can use option *-jN* for *make* to significantly speed up building, e.g.::

    $ make -j16

In addition, you can speed up building further by disabling bootstrap::

    $ ASPECTATOR_CONFIGURE_OPTS="--disable-bootstrap" make -j16

After successful build you can install CIF, e.g.::

    $ sudo make install

You can specify the alternative directory where CIF will be installed, e.g.::

    $ DESTDIR=/home/user/cif make install

Automatic testing
-----------------

You can run the following command for automatic testing of CIF::

    $ make test

Uninstall
---------

You can uninstall CIF by running the following command::

    $ sudo make uninstall

If CIF was installed into an alternative directory with the *DESTDIR* option then you need to use it again::

    $ DESTDIR=/home/user/cif make uninstall

Cleanup
-------

You should run the following command to remove build directories::

    $ make clean

Building debug version of Aspectator
------------------------------------

To build a debug version of Aspectator you can either run the following command::

    $ make -j16 debug

or make the appropriate actions by hand.
The first action is to create a separate directory for it, say::

    $ mkdir build-debug
    $ cd build-debug

Then you need to configure Aspectator::

    $ MAKEINFO=missing ../aspectator/configure --enable-languages=c --disable-multilib --disable-nls --enable-checking=release

and make its debug version::

    $ make STAGE1_CXXFLAGS="-g -O0" all-stage1

You can use option *-jN* for *make* to essentially speed up building, but it can cause failures (just invoke the command
several times to overcome this)::

    $ make -j16 STAGE1_CXXFLAGS="-g -O0" all-stage1

After making some changes to files starting with *ldv-* prefix it is strongly recommended to rebuild the debug version
of Aspectator with *-Werror* flag to treat all warnings as errors::

    $ make STAGE1_CXXFLAGS="-g -O0 -Werror" all-stage1

To debug Aspectator you can use *gdb* or *ddd*::

    $ ddd gcc/cc1 &

To debug instrumentation you need to set the following environment variables::

    set env LDV_STAGE=3
    set env LDV_ASPECT_FILE=$ABS_PATH_TO_ASPECT_FILE
    set env LDV_OUT=out.c

To debug C back-end you need to set the following environment variables::

    set env LDV_STAGE=4
    set env LDV_C_BACKEND_OUT=out.c


.. note:: These instructions were adapted from http://gcc.gnu.org/wiki/DebuggingGCC.

Profiling Aspectator
--------------------

Sometimes developers need to track whether some memory issues (e.g. memory leaks, use after free, etc.) were introduced
and to measure algorithms complexity.

Tracking memory issues of Aspectator
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

First of all you need to build a debug version of Aspectator.

Then you need to run Aspectator under *valgrind* (do not specify *--suppressions* if you do not have them)::

    LDV_ASPECT_FILE=$PATH_TO_ASPECT_FILE \
    LDV_STAGE=$STAGE \
    LDV_OUT=$PATH_TO_OUT \
    valgrind \
    --tool=memcheck \
    --leak-check=yes \
    --suppressions=gcc.supp \
    --num-callers=500 \
    --xml=yes \
    --xml-file=output.xml \
    $PATH_TO_ASPECTATOR_BUILD_DEBUG/gcc/cc1 \
    $PATH_TO_INPUT_FILE


After that you can either inspect *output.xml* manually or use *valkyrie*::

    $ valkyrie -l output.xml

Tracking CPU time issues of Aspectator
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

First of all you need to build a debug version of Aspectator.

Then you need to run Aspectator under valgrind::

    LDV_ASPECT_FILE=$PATH_TO_ASPECT_FILE \
    LDV_STAGE=$STAGE \
    LDV_OUT=$PATH_TO_OUT \
    valgrind \
    --tool=callgrind \
    $PATH_TO_ASPECTATOR_PROFILED_DEBUG/gcc/cc1 \
    $PATH_TO_INPUT_FILE

After that you can either inspect files *callgrind.out.** manually or use some tool, e.g. *kcachegrind*::

    $ kcachegrind -l callgrind.out.*
