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

## Removed configuration macros

`utilities/kdl-config.h` is gone, together with the macros it defined and the ones that
depended on them. KDL is always built with inline methods, so none of these can be set any
more.

- `IMETHOD` and `INLINE` are removed. Use `inline`
  (`sed -i 's/\bIMETHOD\b/inline/g; s/\bINLINE\b/inline/g'`).
- `KDL_INLINE`, `KDL_USE_EQUAL`, `KDL_INDEX_CHECK` and `KDL_FRAME_WIDTH` are removed.
  `#include <kdl/utilities/kdl-config.h>` no longer works; drop it.
- `FRAMES_CHECKI(x)` is removed. Index checks are plain `assert(x)`, so they follow `NDEBUG`:
  they are active in Debug builds and compiled out in Release builds.

## Frame types are trivially copyable (ABI change)

The user-written copy constructors and copy assignment operators of `Vector`, `Rotation`,
`Frame`, `Vector2`, `Rotation2`, `Frame2`, `VectorVel`, `RotationVel`, `FrameVel`,
`VectorAcc`, `RotationAcc`, `FrameAcc`, `Rall1d` and `Rall2d` are gone. The implicit ones do
the same member-wise copy, so the frame types, `Twist`, `Wrench`, `doubleVel` and `doubleAcc`
are now `std::is_trivially_copyable`: they can be copied with `memcpy`, and the ABI can pass
them in registers.

- Source compatible: copying, assigning and passing by value behave as before. The
  converting assignments such as `FrameVel& operator=(const Frame&)` are unchanged.
- Binary incompatible: the copy operations are no longer emitted as functions and the
  calling convention of these types changes. Rebuild everything that uses them against 2.0.

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

## The `.inl` files are gone (ABI change)

`frames.inl`, `framevel.inl` and `frameacc.inl` are no longer installed. Each function they
defined now lives either in `frames.hpp`, `framevel.hpp` or `frameacc.hpp`, still `inline`, or
in the library. Small, hot functions stay inline: constructors, accessors, the exact
`operator==`/`!=`, and the `double` and `Vel` arithmetic. `Rotation * Rotation` and
`operator==(Rotation, Rotation)` became inline too. These now live in the library:

- functions that call `sin`/`cos`/`atan2`/`sqrt` or convert between rotation representations,
  such as `Rotation::RotX/RotY/RotZ`, `Rotation::DoRotX/DoRotY/DoRotZ`, `Rotation2::Rot`,
  `Frame::Integrate`, `RotationVel::Rot*`, `VectorVel::Norm`, and `diff`/`addDelta` of
  rotations and frames
- the tolerant `Equal` overloads of all frame types
- `random` and `posrandom`
- the `VectorAcc`, `RotationAcc`, `FrameAcc` and `TwistAcc` arithmetic

What this means for you:

- Source compatible, unless you include an `.inl` yourself. The matching `.hpp` provides
  everything, so drop the include
  (`sed -i -E '/#include *[<"](kdl\/)?(frames|framevel|frameacc)\.inl[">]/d'`).
- Binary incompatible: the library exports 138 new functions and no longer exports
  `operator*(const Rotation&, const Rotation&)` or `operator==(const Rotation&, const Rotation&)`.
  Rebuild against 2.0.
