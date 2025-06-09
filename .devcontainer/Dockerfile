FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-22.04

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
       vim \
       astyle \
       curl \
       wget \
       gnupg \
       python3 \
       python3-pip \
       python3-venv \
       python3-setuptools \
       openssl \
       libssl-dev \
       cmake \
       build-essential \
       pkg-config \
       libtool \
       autoconf \
       cpplint \
       libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

# Build and install the GTest static libraries from the libgtest-dev package
RUN cd /usr/src/googletest \
    && mkdir -p build && cd build \
    && cmake .. \
    && make -j"$(nproc)" \
    && cp lib/*.a /usr/lib/ \
    && ldconfig

WORKDIR /workspace

COPY . .

RUN mkdir -p build

ENV LD_LIBRARY_PATH="/usr/local/lib:$LD_LIBRARY_PATH"

RUN make build
