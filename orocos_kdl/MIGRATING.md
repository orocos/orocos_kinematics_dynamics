# Migrating to KDL 2.0

This file lists every API and ABI change in KDL 2.0, with the replacement and, where
possible, a `sed` one-liner to apply it.

## C++17 required

KDL and every program that includes its headers must now be compiled as C++17 or newer
(GCC >= 8, Clang >= 7). The `orocos-kdl` CMake target carries
`INTERFACE_COMPILE_FEATURES cxx_std_17`, so consumers that link it get `-std=gnu++17`
automatically, even when they set a lower `CMAKE_CXX_STANDARD`. Consumers that do not use
the CMake target must pass `-std=c++17` themselves.

All installed headers are now self-contained: `kdl/framevel_io.hpp` includes
`kdl/framevel.hpp`, and `kdl/utilities/rallNd.h` is now a valid, standalone header (its
templates live in `namespace KDL`).
