FROM debian:jessie

# Install dependencies and prepare environment.
RUN apt-get update && \
    apt-get install -y make lbzip2 patch gcc flex libc6-dev-i386
RUN ln -s /usr/lib/x86_64-linux-gnu/crt*.o /usr/lib

# Prepare directory for CIF source code.
RUN mkdir /src

# Copy CIF source code.
COPY aspectator /src/aspectator
COPY aspectator-prerequisites /src/aspectator-prerequisites
COPY siginfo.patch cif.c Makefile /src/

# Make and install CIF.
RUN make -C /src all
RUN make -C /src prefix=/ install

# TODO: remove sources containing build directories.

# Create and move to working directory.
VOLUME /work
WORKDIR /work

