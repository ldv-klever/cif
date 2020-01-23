# C Instrumentation Framework

## Build dependencies

To build CIF you will need the following packages:

* make
* lbzip2
* patch
* gcc
* g++
* flex
* bison
* libc6-dev-i386

## Build and Install

First you need to download archives with the source code of some prerequisites needed by GCC (gmp, mpfr, mpc and isl):

    $ cd aspectator
    $ ./contrib/download_prerequisites

Then return back to the root of the repository and simply execute _make_:

    $ cd ..
    $ make

You can use option _-jN_ for _make_ to significantly speed up building, e.g.:

    $ make -j16

After successful build you may install CIF, e.g.:

    $ sudo make DESTDIR=/usr/local install

## Building Debug Version of Aspectator

To build a debug version of Aspectator one needs create a separate directory for
it, say:

    $ mkdir build-debug
    $ cd build-debug

Then configure Aspectator as usual:

    $ MAKEINFO=missing ../aspectator/configure --enable-languages=c --disable-multilib --disable-nls --enable-checking=release

and make the debug version of Aspectator:

    $ make STAGE1_CXXFLAGS="-g -O0" all-stage1

You can use option _-jN_ for _make_ to essentially speed up building, but it
can cause failures (just invoke the command several times to overcome this):

    $ make -j16 STAGE1_CXXFLAGS="-g -O0" all-stage1

After making some changes to files starting with _ldv-_ prefix it is strongly
recommended to rebuild the debug version of Aspectator with +-Werror+ flag to
treat all warnings as errors:

    $ make STAGE1_CXXFLAGS="-g -O0 -Werror" all-stage1

To debug Aspectator you can use _gdb_ or _ddd_:

    $ ddd gcc/cc1 &

> NOTE: These instructions were adapted from http://gcc.gnu.org/wiki/DebuggingGCC.

## Profiling Aspectator

Sometimes developers need to track whether some memory issues (e.g. memory
leaks, use after free, etc.) were introduced and to measure algorithms
complexity.

### Tracking memory issues of Aspectator

First of all you need to build a debug version of Aspectator.

Then you need to run Aspectator under valgrind (do not specify "--suppressions"
if you do not have them):

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


After that you can either inspect output.xml manually or use valkyrie:

    $ valkyrie -l output.xml


### Tracking CPU time issues of Aspectator

First of all you need to build a debug version of Aspectator.

Then you need to run Aspectator under valgrind:

    LDV_ASPECT_FILE=$PATH_TO_ASPECT_FILE \
    LDV_STAGE=$STAGE \
    LDV_OUT=$PATH_TO_OUT \
    valgrind \
    --tool=callgrind \
    $PATH_TO_ASPECTATOR_PROFILED_DEBUG/gcc/cc1 \
    $PATH_TO_INPUT_FILE

After that you can either inspect callgrind.out.* manually or use kcachegrind:

    $ kcachegrind -l callgrind.out.*
