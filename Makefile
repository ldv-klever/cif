DESTDIR ?= /usr/local

GIT_HASH = $(shell git rev-parse --short HEAD)

# Workaround for "cannot find crti.o" error (only for x86-64 Ubuntu systems).
UBUNTU_LIB = /usr/lib/x86_64-linux-gnu

# System headers are no longer located in /usr/include in macOS >= Mojave.
ifeq ($(shell uname), Darwin)
	CONFIGURE_ARGS_MACOS = --with-native-system-header-dir=/usr/include
	CONFIGURE_ARGS_MACOS += --with-sysroot=/Library/Developer/CommandLineTools/SDKs/MacOSX10.14.sdk
else
	CONFIGURE_ARGS_MACOS =
endif

.PHONY: all uninstall-previous-instances install-keep-previous-instances install test clean

all: build/cif
	@if [ ! -f build/Makefile ]; then \
	  echo "Configure Aspectator for the first time"; \
	  cd build; \
	  MAKEINFO=missing ../aspectator/configure --prefix=/ --enable-languages=c \
	    --disable-libsanitizer --disable-multilib \
	    --enable-checking=release --with-pkgversion=CIF \
	    --with-bugurl="https://forge.ispras.ru/projects/cif/issues" \
	    $(CONFIGURE_ARGS_MACOS) $(ASPECTATOR_CONFIGURE_OPTS); \
	fi
	@echo "Begin to (re)build Aspectator"
	@if [[ -d $(UBUNTU_LIB) && ! -z LIBRARY_PATH ]]; then export LIBRARY_PATH=$(UBUNTU_LIB); fi
	$(MAKE) -C build

build/cif: cif.c
	mkdir -p build
	gcc -Wall -Werror cif.c -o $@

uninstall-previous-instances:
	rm -rf "$(DESTDIR)/bin/cif" "$(DESTDIR)/bin/aspectator" "$(DESTDIR)"/cif*

# Install Aspectator (GCC) within dedicated directory to simplify its uninstall.
install-keep-previous-instances:
	mkdir -p "$(DESTDIR)/bin"
	mkdir -p "$(DESTDIR)/cif-$(GIT_HASH)/bin"
	cp build/cif "$(DESTDIR)/cif-$(GIT_HASH)/bin/cif"
	ln -sf "$(DESTDIR)/cif-$(GIT_HASH)/bin/cif" "$(DESTDIR)/bin/cif"
	$(MAKE) DESTDIR="$(DESTDIR)/cif-$(GIT_HASH)" -C build install
	ln -sf "$(DESTDIR)/cif-$(GIT_HASH)/bin/gcc" "$(DESTDIR)/bin/aspectator"

install: uninstall-previous-instances install-keep-previous-instances

test:
	$(MAKE) DESTDIR="$(shell readlink -f tests/cif)" install
	cd tests && pytest

clean:
	rm -rf build
