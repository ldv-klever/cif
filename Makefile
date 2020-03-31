DESTDIR ?= /usr/local

CIF_VERSION := $(shell git rev-parse --short HEAD || echo unknown)
ASPECTATOR_VERSION := $(shell cd aspectator && git rev-parse --short HEAD || echo unknown)


# Workaround for "cannot find crti.o" error (only for x86-64 Ubuntu systems).
UBUNTU_LIB = /usr/lib/x86_64-linux-gnu

# System headers are no longer located in /usr/include in macOS >= Mojave.
ifeq ($(shell uname), Darwin)
	CONFIGURE_ARGS_MACOS = --with-native-system-header-dir=/usr/include
	CONFIGURE_ARGS_MACOS += --with-sysroot=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk
else
	CONFIGURE_ARGS_MACOS =
endif

ifeq ($(shell uname), Darwin)
	LN_FLAGS = "-sf"
else
	LN_FLAGS = "-srf"
endif

.PHONY: all uninstall-previous-instances install-keep-previous-instances install test clean

all: build/cif
	@if [ ! -f build/Makefile ]; then \
	  echo "Configure Aspectator for the first time"; \
	  cd build; \
	  MAKEINFO=missing ../aspectator/configure --prefix=/ --enable-languages=c \
	    --disable-libsanitizer --disable-multilib --disable-nls\
	    --enable-checking=release --with-pkgversion=$(ASPECTATOR_VERSION) \
	    --with-bugurl="https://forge.ispras.ru/projects/cif/issues" \
	    $(CONFIGURE_ARGS_MACOS) $(ASPECTATOR_CONFIGURE_OPTS); \
	fi
	@echo "Begin to (re)build Aspectator"
	@if [[ -d $(UBUNTU_LIB) && ! -z LIBRARY_PATH ]]; then export LIBRARY_PATH=$(UBUNTU_LIB); fi
	$(MAKE) -C build

build/cif: cif.c
	mkdir -p build
	gcc -Wall -Werror -D CIF_VERSION=\"$(CIF_VERSION)\" cif.c -o $@

uninstall-previous-instances:
	rm -rf "$(DESTDIR)/bin/cif" "$(DESTDIR)/bin/aspectator" "$(DESTDIR)"/cif*

# Install Aspectator (GCC) within dedicated directory to simplify its uninstall.
install-keep-previous-instances:
	$(MAKE) DESTDIR="$(DESTDIR)/cif-$(CIF_VERSION)" -C build install
	cp build/cif "$(DESTDIR)/cif-$(CIF_VERSION)/bin/cif"
	mkdir -p "$(DESTDIR)/bin"
	ln $(LN_FLAGS) "$(DESTDIR)/cif-$(CIF_VERSION)/bin/cif" "$(DESTDIR)/bin/cif"
	ln $(LN_FLAGS) "$(DESTDIR)/cif-$(CIF_VERSION)/bin/gcc" "$(DESTDIR)/bin/aspectator"

install: uninstall-previous-instances install-keep-previous-instances

test:
	$(MAKE) DESTDIR="$(shell pwd -P)"/tests/cif install
	cd tests && pytest

clean:
	rm -rf build
