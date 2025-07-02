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

# Add Ubuntu Toolchain PPA and install GCC-13 and G++-13
RUN apt-get update && \
    apt-get install -y software-properties-common && \
    add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
    apt-get update && \
    apt-get install -y gcc-13 g++-13 && \
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-13 100 && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 100

WORKDIR /workspace

COPY . .

RUN mkdir -p build

ENV LD_LIBRARY_PATH="/usr/local/lib:$LD_LIBRARY_PATH"

RUN make build
