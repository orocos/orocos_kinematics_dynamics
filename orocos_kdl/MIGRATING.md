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
`operator==`/`!=`, the `double` and `Vel` arithmetic, and `Rotation::RotX/RotY/RotZ`.
`Rotation * Rotation` and `operator==(Rotation, Rotation)` became inline too. These now live
in the library:

- functions that call `sin`/`cos`/`atan2`/`sqrt` or convert between rotation representations,
  such as `Rotation::DoRotX/DoRotY/DoRotZ`, `Rotation2::Rot`,
  `Frame::Integrate`, `RotationVel::Rot*`, `VectorVel::Norm`, and `diff`/`addDelta` of
  rotations and frames
- the tolerant `Equal` overloads of all frame types
- `random` and `posrandom`
- the `VectorAcc`, `RotationAcc`, `FrameAcc` and `TwistAcc` arithmetic

What this means for you:

- Source compatible, unless you include an `.inl` yourself. The matching `.hpp` provides
  everything, so drop the include
  (`sed -i -E '/#include *[<"](kdl\/)?(frames|framevel|frameacc)\.inl[">]/d'`).
- Binary incompatible: the library exports 135 new functions and no longer exports
  `operator*(const Rotation&, const Rotation&)` or `operator==(const Rotation&, const Rotation&)`.
  Rebuild against 2.0.

## `operator==` is exact, `Equal` is tolerant and scaled

`operator==` and `operator!=` now compare exactly, member by member, for `Vector`,
`Rotation`, `Frame`, `Twist`, `Wrench`, `Vector2`, the `Vel` types (`VectorVel`,
`RotationVel`, `FrameVel`, `TwistVel`, including their comparisons with the double types),
`doubleVel`, `doubleAcc`, `JntArray`, `Jacobian` and `JntSpaceInertiaMatrix`. In 1.x they
called `Equal` with the default tolerance. Exact equality is transitive and consistent with
`std::hash` and PyKDL's `__hash__` (`+0.0 == -0.0`, and both hash alike); tolerant equality
is neither, so it cannot back hashing or sorting. This is the Eigen/`std` convention.

Code that relied on `a == b` meaning "within 1e-6" must call `Equal(a, b)` (or
`Equal(a, b, eps)`) instead. In PyKDL, `assertEqual(a, b)` on computed frames becomes
`assertTrue(Equal(a, b))`. A pickled `Rotation` round-trips through roll, pitch and yaw, so
the unpickled value is `Equal` to, but generally not `==`, the original.

`Equal` itself changed too:

- **Scalar rule:** `Equal(a, b, eps)` is true when `a == b`, or when `a - b` is finite and
  `|a - b| <= eps * max(1, |a|, |b|)`. The tolerance is absolute up to magnitude 1 (so
  rotations, unit vectors and angles behave as before) and relative above it. `eps = 0`
  means exact, `+-inf` equals only itself, and `NaN` never equals anything. In 1.x the test
  was the strict, purely absolute `|a - b| < eps` for the frame types (so `Equal(1.0, 1.0, 0.0)`
  was false and two values of 1e9 one ulp apart could be unequal) and `<= eps` for the arrays.
- **Geometric types scale per physical quantity:** every component satisfies `a[i] == b[i]` or
  `|a[i] - b[i]| <= eps * S`, where `S = max(1, largest finite |a[i]|, |b[i]| of that
  quantity)`. `Frame` compares `p` and `M` separately, `Twist` compares `vel` and `rot`,
  `Wrench` compares `force` and `torque`, `Frame2` compares `p` and `M`, `Rotation2` its
  cosine and sine, and the `Vel`/`Acc` types compare each member separately. A large
  translation therefore never loosens the rotation check, and an infinite component never
  loosens the others.
- **Arrays compare per element** with the scalar rule (`JntArray`, `JntArrayVel`,
  `JntArrayAcc`, `Jacobian`, `JntSpaceInertiaMatrix`), because their elements carry different
  units.

## `epsilon`, `PI` and the other constants are immutable

`KDL::epsilon`, `PI`, `PI_2`, `PI_4`, `deg2rad` and `rad2deg` are now `inline constexpr double`
in `utilities/utility.h` instead of `extern` globals, with unchanged values (`epsilon` is still
`1e-6`). They are usable in constant expressions, and reading them no longer races with a
writer.

- Assigning to `KDL::epsilon` no longer compiles. Pass the tolerance explicitly instead:
  `Equal(a, b, eps)`, `v.Normalize(eps)`, `R.GetRotAngle(axis, eps)`.
- Binary incompatible: the library no longer exports the data symbols `KDL::epsilon`,
  `KDL::PI`, `KDL::PI_2`, `KDL::PI_4`, `KDL::deg2rad` and `KDL::rad2deg`. Rebuild against 2.0.

## `Norm()` takes no argument and is 0 only for the zero vector

`Vector::Norm()`, `Vector2::Norm()`, `VectorVel::Norm()` and `VectorAcc::Norm()` lost their
`eps` parameter (`VectorAcc::Norm()` is now also `const`). They return 0 only for the exact
zero vector. In 1.x, `Vector(5e-7, 0, 0).Norm()` returned 0 while `Vector(0, 5e-7, 0).Norm()`
returned 5e-7, because the cutoff was only checked when x was the largest component; `Vector2`
had the same defect. The overflow- and underflow-safe scaling is unchanged, and
`Normalize(eps)` keeps its degeneracy threshold. PyKDL's `Vector.Norm()` and
`VectorVel.Norm()` no longer accept `eps` either.

- Drop the argument: `sed -i -E 's/\.Norm\([^()]+\)/.Norm()/g'` (check the result: it also
  matches other `Norm(...)` calls with an argument).
- Binary incompatible: the mangled names of the four `Norm` functions changed. Rebuild
  against 2.0.
