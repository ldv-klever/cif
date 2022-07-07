FROM debian:9 as builder
LABEL stage=builder

ENV CIF_SRC=/usr/src/cif/
ENV CIF_INST=/usr/local/

# Install dependencies and prepare environment
RUN apt-get update && \
    apt-get install -y make gcc g++ flex bison git rsync python3 python3-pip curl
RUN pip3 install pytest

# Copy CIF source code
COPY cif.cpp Makefile $CIF_SRC
COPY aspectator $CIF_SRC/aspectator
COPY .git $CIF_SRC/.git
COPY tests $CIF_SRC/tests

# Download prerequisites
WORKDIR $CIF_SRC/aspectator
RUN ./contrib/download_prerequisites

# Build and install CIF
WORKDIR $CIF_SRC
RUN make clean
RUN make -j`nproc`
RUN DESTDIR=$CIF_INST make install

# Test CIF
RUN make test

# Final image, stripped from unnecessary layers
FROM debian:9

ENV CIF_INST=/usr/local/

COPY --from=builder $CIF_INST/bin $CIF_INST/bin
COPY --from=builder $CIF_INST/cif $CIF_INST/cif

# Set working directory
VOLUME /root
WORKDIR /root
