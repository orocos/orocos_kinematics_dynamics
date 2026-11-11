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
`kdl/framevel.hpp`, and `kdl/utilities/rallNd.hpp` is now a valid, standalone header (its
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
  was false) and `<= eps` for the arrays. Because the tolerance was absolute, values around
  1e9 that were about 17 ulp apart (about 2e-6) were unequal in 1.x and are `Equal` in 2.0.
- **`-ffast-math`:** the scalar `Equal(double, double, eps)` is `inline`, so it is compiled
  into consumer code. Under `-ffast-math` or `-ffinite-math-only`, `isfinite()` folds to
  true and `Equal(inf, x)` may return true. Do not rely on the infinity and NaN handling of
  `Equal` with those flags.
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
in `utilities/utility.hpp` instead of `extern` globals, with unchanged values (`epsilon` is still
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
had the same defect. `VectorVel::Norm()` returned `(0, 0)` (value and derivative) for every
`|p| < 1e-6`, on all axes; it now returns the true norm except for the exact zero vector. The overflow- and underflow-safe scaling is unchanged, and
`Normalize(eps)` keeps its degeneracy threshold. PyKDL's `Vector.Norm()` and
`VectorVel.Norm()` no longer accept `eps` either.

- Drop the argument: `sed -i -E 's/\.Norm\([^()]+\)/.Norm()/g'` (check the result: it also
  matches other `Norm(...)` calls with an argument).
- Binary incompatible: the mangled names of the four `Norm` functions changed. Rebuild
  against 2.0.

## `scoped_ptr` and `ChainIdSolver_Vereshchagin` are removed

- `utilities/scoped_ptr.hpp` (`KDL::scoped_ptr`) was an internal helper, installed by accident.
  Use `std::unique_ptr` from `<memory>`; it offers the same `get()`, `reset()`, `release()`,
  `operator*` and `operator->`:
  `sed -i -E 's@#include *[<"](kdl/)?utilities/scoped_ptr\.hpp[>"]@#include <memory>@; s/KDL::scoped_ptr/std::unique_ptr/g; s/\bscoped_ptr\b/std::unique_ptr/g'`
  (the include is rewritten first and always becomes `<memory>`; the qualified `KDL::scoped_ptr`
  is handled before the bare name; a `using namespace KDL;` and `scoped_ptr` used unqualified
  are covered, but check the result).
- `chainidsolver_vereshchagin.hpp` and the `ChainIdSolver_Vereshchagin` class were a
  deprecated alias, which printed a warning on construction. Use `ChainHdSolver_Vereshchagin`
  from `chainhdsolver_vereshchagin.hpp`:
  `sed -i 's/ChainIdSolver_Vereshchagin/ChainHdSolver_Vereshchagin/g; s/chainidsolver_vereshchagin/chainhdsolver_vereshchagin/g'`
- Binary incompatible: the library no longer exports the `ChainIdSolver_Vereshchagin` symbols.
  Rebuild against 2.0.

## Every header is `.hpp`; the `.h` names are deprecated

All installed headers now end in `.hpp`. These were renamed:

- `kdl/config.h` -> `kdl/config.hpp`
- `kdl/utilities/error.h`, `error_stack.h`, `hash_combine.h`, `rall1d.h`, `rall1d_io.h`,
  `rall2d.h`, `rall2d_io.h`, `rallNd.h`, `traits.h`, `utility.h` and `utility_io.h` ->
  the same names with `.hpp`

The old names are still installed as stubs for the 2.x series. Each includes the new header
and emits a compiler warning (`#warning`, or `#pragma message` on MSVC), so code built with
`-Werror` fails until it switches to the new name:
`sed -i -E 's#(kdl/(config|utilities/(error|error_stack|hash_combine|rall1d|rall1d_io|rall2d|rall2d_io|rallNd|traits|utility|utility_io)))\.h([">])#\1.hpp\4#'`
(this matches includes spelled with the `kdl/` prefix; adapt it for includes relative to
`kdl/`).

The source tree now has the install layout: the headers live in `orocos_kdl/include/kdl/`
instead of next to the sources in `orocos_kdl/src/`. A project that builds KDL as a
subproject (`add_subdirectory`) and links the `orocos-kdl` target includes
`<kdl/frames.hpp>`, as it would against an installed KDL; adding `orocos_kdl/src` to the
include path and writing `#include <frames.hpp>` no longer works.

## Supporting both KDL 1.x and 2.x

A package that must build against both series can detect the version at compile time.
`kdl/config.hpp` only exists in 2.x, and `kdl/config.h` still works there but is a deprecated
stub that emits a `#warning`, which breaks `-Werror` builds (MoveIt's `kdl_kinematics_plugin`,
for example, includes it). Pick the header with `__has_include` so neither series warns:

```cpp
#if __has_include(<kdl/config.hpp>)
#include <kdl/config.hpp>  // KDL 2.x
#else
#include <kdl/config.h>    // KDL 1.x
#endif
```

Then branch on `KDL_VERSION_MAJOR`. Prefer it over `KDL_VERSION`: in 1.x, `KDL_VERSION` is not
parenthesised, so `#if KDL_VERSION >= 0x020000` is always true there. The same
`__has_include` recipe works for the renamed `kdl/utilities/*.h` headers.

The two most common divergences:

- `Norm(eps)` lost its argument in 2.x. `Norm()` without an argument works in both series;
  where 1.x code relies on the cutoff, keep the argument only there:
  ```cpp
  #if KDL_VERSION_MAJOR >= 2
    const double n = v.Norm();
  #else
    const double n = v.Norm(eps);
  #endif
  ```
- `operator==` is exact in 2.x and was tolerant in 1.x. Code that means "within a tolerance"
  calls `KDL::Equal(a, b)` or `KDL::Equal(a, b, eps)`, which exists with the same signature in
  both series, so it needs no `#if`.

## Packaging: SONAME 2.0, one KDL per process

The library's SONAME is `liborocos-kdl.so.2.0`, and the Debian package is `liborocos-kdl2.0`
(it was `liborocos-kdl1.5`), so the two can be installed side by side.

The CMake package version file uses `AnyNewerVersion`, so `find_package(orocos_kdl 1.4)` (or
any other 1.x minimum) still finds 2.0. Such a consumer then builds against 2.0 and must
compile with the changes listed above.

Never load 1.x and 2.x into one process. Both define the same `KDL::` symbols, so objects built
against one series silently call into the other, with a different ABI. This happens, for
example, when a workspace overlays a source build of KDL 2.0 on binary `kdl_parser` or
`robot_state_publisher` packages that link `liborocos-kdl.so.1.5`: a node then loads both.
Rebuild every KDL consumer in the overlay against 2.0.
