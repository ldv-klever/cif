BIN_DIR = bin
BUILD_DIR = build
ASPECTATOR_SRC_DIR = aspectator
ASPECTATOR_BIN_DIR = aspectator-bin

# Standard directory for installation of executables.
INSTALL_BIN_DIR = $(prefix)/bin

# Workaround for "cannot find crti.o" error (only for x86-64 Ubuntu systems)
UBUNTU_LIB = /usr/lib/x86_64-linux-gnu

LN_FLAGS = "-srf"
ifeq ($(shell uname), Darwin)
	LN_FLAGS = "-sf"
endif

.PHONY: all install test clean

# Before build install prerequisites.
all: $(BIN_DIR)/cif
	mkdir -p $(BUILD_DIR)
	if [ ! -f $(BUILD_DIR)/Makefile ]; then \
	  echo "Configure Aspectator for the first time"; \
	  cd $(BUILD_DIR); \
	  MAKEINFO=missing ../$(ASPECTATOR_SRC_DIR)/configure --prefix=$(CURDIR)/$(BIN_DIR)/$(ASPECTATOR_BIN_DIR) --enable-languages=c --disable-libsanitizer --disable-multilib --enable-checking=release $(ASPECTATOR_CONFIGURE_OPTS); \
	fi
	@echo "Begin to (re)build Aspectator"
	@if [[ -d $(UBUNTU_LIB) && ! -z LIBRARY_PATH ]]; then export LIBRARY_PATH=$(UBUNTU_LIB); fi
	$(MAKE) -C $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR) install
	@echo "Create symlinks for C Instrumentation Framework and Aspectator binaries for convinience"
	cd $(BIN_DIR); ln $(LN_FLAGS) cif compiler
	cd $(BIN_DIR); ln $(LN_FLAGS) "$(ASPECTATOR_BIN_DIR)/bin/gcc" aspectator

$(BIN_DIR)/cif: cif.c
	mkdir -p $(BIN_DIR)
	gcc -Wall -Werror cif.c -o $@

# Before installation check prefix.
install: check_prefix
	mkdir -p $(INSTALL_BIN_DIR)
	@echo "Install C Instrumentation Framework and Aspecator to '$(INSTALL_BIN_DIR)'"
	cp -ru $(BIN_DIR)/* $(INSTALL_BIN_DIR)

check_prefix:
	@echo "Check that prefix where tools to be installed is specified"
	@case "$(prefix)" in \
	  /*) prefix_abs=1 ;; \
	  *) prefix_abs=0 ;; \
	esac; \
	if [ -z "$(prefix)" -o $$prefix_abs -eq 0 ]; then \
	  echo "For installation you should specify prefix: 'prefix=install_dir_abs make install'!"; \
	  exit 1; \
	else echo "C Instrumentation Framework and Aspectator will be installed to '$(prefix)'"; \
	fi

test:
	cd tests && python3 all_tests.py

# Remove all directories created during CIF and Aspectator build.
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
