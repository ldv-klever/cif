# Directories with Aspectator prerequisites, sources, objects and executables.
ASPECTATOR_PREREQUISITES = aspectator-prerequisites
ASPECTATOR_SRC_DIR = aspectator
ASPECTATOR_BUILD_DIR = aspectator-build
ASPECTATOR_BIN_DIR = aspectator-bin

# Standard directories for installation of executables and manuals.
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
mandir = ${prefix}/man

.PHONY: all install test clean

# Before build install prerequisites.
all: $(ASPECTATOR_SRC_DIR)/gmp $(ASPECTATOR_SRC_DIR)/mpc $(ASPECTATOR_SRC_DIR)/mpfr
	mkdir -p $(ASPECTATOR_BUILD_DIR)
	if [ ! -f $(ASPECTATOR_BUILD_DIR)/Makefile ]; then \
	  echo "Configure Aspectator for the first time"; \
	  cd $(ASPECTATOR_BUILD_DIR); \
	  ../$(ASPECTATOR_SRC_DIR)/configure --prefix=$(shell readlink -f $(ASPECTATOR_BIN_DIR)) --enable-languages=c --disable-nls; \
	fi
	@echo "Begin to (re)build Aspectator"
	make -C $(ASPECTATOR_BUILD_DIR)
	make -C $(ASPECTATOR_BUILD_DIR) install

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

# Before installation perform build.
install: all
	mkdir -p $(bindir)
	mkdir -p $(mandir)
	@echo "Install CIF to '$(bindir)'"
	cp -u cif $(bindir)
	@echo "Install Aspectator to '$(bindir)'"
	cp -ru $(ASPECTATOR_BIN_DIR) $(bindir)
	@echo "Create symlinks for CIF and Aspectator binaries for convinience"
	ln -sf $(bindir)/cif $(bindir)/compiler
	ln -sf $(bindir)/$(ASPECTATOR_BIN_DIR)/bin/gcc $(bindir)/aspectator

test:
	@echo "CIF hasn't tests at the moment" 

# Remove all directories created during Aspectator build.
clean:
	rm -rf $(ASPECTATOR_SRC_DIR)/gmp $(ASPECTATOR_SRC_DIR)/mpfr $(ASPECTATOR_SRC_DIR)/mpc $(ASPECTATOR_BUILD_DIR) $(ASPECTATOR_BIN_DIR)