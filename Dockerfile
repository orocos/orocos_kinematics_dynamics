FROM arm64-toolchain:latest

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    libeigen3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

COPY orocos_kdl ./orocos_kdl

# Native build (assumed amd64)
ENV TARGET_ARCH=amd64

RUN mkdir -p build_$TARGET_ARCH && \
      cd build_$TARGET_ARCH && \
      cmake ../orocos_kdl \
            -DCMAKE_BUILD_TYPE=Release \
            -DENABLE_TESTS=OFF \
            -DENABLE_EXAMPLES=OFF && \
      make -j$(nproc)

WORKDIR /workspace/build_amd64

RUN mkdir -p /tmp/kdl-install-$TARGET_ARCH
RUN make install DESTDIR=/tmp/kdl-install-$TARGET_ARCH
RUN cpack

WORKDIR /workspace

# Cross compilation
ENV TARGET_ARCH=arm64

RUN . ./setup-environment.sh && \
      mkdir -p build_$TARGET_ARCH && \
      cd build_$TARGET_ARCH && \
      cmake ../orocos_kdl \
            -DCMAKE_BUILD_TYPE=Release \
            -DENABLE_TESTS=OFF \
            -DENABLE_EXAMPLES=OFF && \
      make -j$(nproc)


WORKDIR /workspace/build_arm64

RUN mkdir -p /tmp/kdl-install-$TARGET_ARCH
RUN make install DESTDIR=/tmp/kdl-install-$TARGET_ARCH
RUN cpack

