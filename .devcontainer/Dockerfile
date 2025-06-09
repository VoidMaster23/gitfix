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
    && rm -rf /var/lib/apt/lists/*


WORKDIR /workspace

COPY . .

RUN mkdir -p build

ENV LD_LIBRARY_PATH="/usr/local/lib:$LD_LIBRARY_PATH"

RUN cmake -S . -B build \ 
    -DOPENSSL_ROOT_DIR=/usr \
    -DOPENSSL_LIBRARIES=/usr/lib/x86_64-linux-gnu && \
    cmake --build build
