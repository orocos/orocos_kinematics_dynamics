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

## Bug fixes that change results

These functions gave wrong results in 1.x. Code that worked around them must drop the
workaround.

- `Vector::Set2DPlane(F, v)` now sets the vector to `F * Vector(v.x(), v.y(), 0)`, as
  documented. It used to leave the vector unchanged.
- `Rotation2::operator()(i, j)`, and through it `Frame2::operator()(i, j)`, now return the
  entries of the rotation matrix (`R(0, 1) == -sin(angle)`). They used to return its
  transpose. `Rotation2 * Vector2` was already correct.
- `posrandom(Frame&)` now draws both the rotation and the origin with `posrandom`, like the
  other `posrandom` overloads. It used to call `random`, so the origin could be negative.
- `RotationVel::RotY(angle)` now rotates about Y. Its rotation matrix used to be
  `Rotation::RotX(angle.value())`, with the angular velocity of a Y rotation.
- `diff(const FrameVel&, const FrameVel&, dt)` (and PyKDL's `diff(FrameVel, FrameVel)`) now
  returns the translational part in `vel` and the rotational part in `rot`, like
  `diff(Frame, Frame)` and as `addDelta(FrameVel, TwistVel)` expects. The two used to be
  swapped.
