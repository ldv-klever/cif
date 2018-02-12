BIN_DIR = bin
BUILD_DIR = build
# Directories with Aspectator prerequisites, sources, objects and executables.
ASPECTATOR_PREREQUISITES = aspectator-prerequisites
ASPECTATOR_SRC_DIR = aspectator
ASPECTATOR_BIN_DIR = $(BIN_DIR)/aspectator-bin

# Standard directory for installation of executables.
INSTALL_BIN_DIR = $(prefix)/bin

.PHONY: all install test clean

# Before build install prerequisites.
all: $(BIN_DIR)/cif $(ASPECTATOR_SRC_DIR)/gmp $(ASPECTATOR_SRC_DIR)/mpc $(ASPECTATOR_SRC_DIR)/mpfr
	mkdir -p $(BUILD_DIR)
	if [ ! -f $(BUILD_DIR)/Makefile ]; then \
	  echo "Patch GCC source code to avoid build error"; \
	  patch -p1 -d $(ASPECTATOR_SRC_DIR) < linux-unwind.patch; \
	  echo "Configure Aspectator for the first time"; \
	  cd $(BUILD_DIR); \
	  ../$(ASPECTATOR_SRC_DIR)/configure --prefix=$(shell readlink -f $(ASPECTATOR_BIN_DIR)) --enable-languages=c --disable-nls $(ASPECTATOR_CONFIGURE_OPTS); \
	fi
	@echo "Begin to (re)build Aspectator"
	make -C $(BUILD_DIR)
	make -C $(BUILD_DIR) install
	@echo "Create symlinks for CIF and Aspectator binaries for convinience"
	ln -sf "$(CURDIR)/$(BIN_DIR)/cif" $(BIN_DIR)/compiler
	ln -sf "$(CURDIR)/$(ASPECTATOR_BIN_DIR)/bin/gcc" $(BIN_DIR)/aspectator

$(BIN_DIR)/cif: cif.c
	mkdir -p $(BIN_DIR)
	gcc -Wall -Werror cif.c -o $@

$(ASPECTATOR_SRC_DIR)/gmp: $(ASPECTATOR_PREREQUISITES)/gmp.tar.bz2 $(ASPECTATOR_PREREQUISITES)/gmp-nodoc.patch
	@echo "Remove GMP source code from '$(ASPECTATOR_SRC_DIR)'"
	rm -rf $@
	@echo "Extract GMP source code to '$(ASPECTATOR_SRC_DIR)'"
	tar -xamf $(ASPECTATOR_PREREQUISITES)/gmp.tar.bz2 -C $(ASPECTATOR_SRC_DIR)
	@echo "Patch GMP source code to disable documentation building"
	patch -p1 -d $@ < $(ASPECTATOR_PREREQUISITES)/gmp-nodoc.patch

$(ASPECTATOR_SRC_DIR)/mpc: $(ASPECTATOR_PREREQUISITES)/mpc.tar.bz2 $(ASPECTATOR_PREREQUISITES)/mpc-nodoc.patch
	@echo "Remove MPC source code from '$(ASPECTATOR_SRC_DIR)'"
	rm -rf $@
	@echo "Extract MPC source code to '$(ASPECTATOR_SRC_DIR)'"
	tar -xamf $(ASPECTATOR_PREREQUISITES)/mpc.tar.bz2 -C $(ASPECTATOR_SRC_DIR)
	@echo "Patch MPC source code to disable documentation building"
	patch -p1 -d $@ < $(ASPECTATOR_PREREQUISITES)/mpc-nodoc.patch

$(ASPECTATOR_SRC_DIR)/mpfr: $(ASPECTATOR_PREREQUISITES)/mpfr.tar.bz2
	@echo "Remove MPFR source code from '$(ASPECTATOR_SRC_DIR)'"
	rm -rf $@
	@echo "Extract MPFR source code to '$(ASPECTATOR_SRC_DIR)'"
	tar -xamf $(ASPECTATOR_PREREQUISITES)/mpfr.tar.bz2 -C $(ASPECTATOR_SRC_DIR)

# Before installation check prefix and perform build.
install: check_prefix
	mkdir -p $(INSTALL_BIN_DIR)
	@echo "Install CIF to '$(INSTALL_BIN_DIR)'"
	cp -u $(BIN_DIR)/cif $(INSTALL_BIN_DIR)
	@echo "Install Aspectator to '$(INSTALL_BIN_DIR)'"
	cp -ru $(ASPECTATOR_BIN_DIR) $(INSTALL_BIN_DIR)
	@echo "Create symlinks for CIF and Aspectator binaries for convinience"
	ln -sf $(INSTALL_BIN_DIR)/cif $(INSTALL_BIN_DIR)/compiler
	ln -sf $(INSTALL_BIN_DIR)/$(ASPECTATOR_BIN_DIR)/bin/gcc $(INSTALL_BIN_DIR)/aspectator

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
	rm -rf $(ASPECTATOR_SRC_DIR)/gmp $(ASPECTATOR_SRC_DIR)/mpfr $(ASPECTATOR_SRC_DIR)/mpc $(BUILD_DIR) $(BIN_DIR)
