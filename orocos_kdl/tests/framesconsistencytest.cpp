// Consistency tests for the frame core: every function of frames.hpp/.inl/.cpp,
// framevel.hpp/.inl, frameacc.hpp/.inl and utilities/utility.h is checked against
// a reference that does not go through KDL:
//
//  - the double types against Eigen (Vector <-> Vector3d, Rotation <-> Matrix3d,
//    Frame <-> 4x4 homogeneous, Twist/Wrench <-> 6-vectors and 6x6 adjoints);
//  - the rotation parameterizations against closed forms built from
//    Eigen::AngleAxisd / Eigen::Quaterniond, plus their round trips;
//  - the Vel and Acc types by finite differences of the plain double operation
//    along a trajectory whose derivatives are the Vel/Acc derivative parts.
//
// The tests encode the behaviour at the time they were written, so that later
// refactorings (moving functions between headers and .cpp files, changing
// macros) can be checked against them.

#include "framesconsistencytest.hpp"

#include <frameacc.hpp>
#include <frames.hpp>
#include <framevel.hpp>
#include <utilities/utility.h>

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <Eigen/LU>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <string>
#include <type_traits>
#include <vector>

CPPUNIT_TEST_SUITE_REGISTRATION(FramesConsistencyTest);

using namespace KDL;

#define CHECK(cond) CPPUNIT_ASSERT_MESSAGE(#cond, (cond))

namespace {

using Eigen::Matrix2d;
using Eigen::Matrix3d;
using Eigen::Matrix4d;
using Eigen::Vector2d;
using Eigen::Vector3d;
using Eigen::Vector4d;
using Eigen::VectorXd;
using Matrix6d = Eigen::Matrix<double, 6, 6>;
using Vector6d = Eigen::Matrix<double, 6, 1>;

const int iterations = 100;

// Double types against Eigen, and parameterization round trips. The inputs are
// O(1), so 1e-12 leaves a margin of ~1e3 over the rounding of a few flops.
const double tol = 1e-12;

// Vel types: the value part repeats the double operation on the same inputs, so
// only reordering of flops can differ. The derivative is compared with a
// central difference of step h, whose truncation error is O(h^2) = 1e-12 and
// whose rounding error is O(1e-16/h) = 1e-10.
const double tolValue = 1e-14;
const double hVel = 1e-6;
const double tolDeriv = 1e-7;

// Acc types: second central difference with step h has truncation error
// O(h^2) = 1e-8 and rounding error O(1e-16/h^2) = 1e-8.
const double hAcc = 1e-4;
const double tolDeriv2 = 1e-5;

// Perturbation that must make two O(1) values unequal, both under the absolute
// tolerance epsilon = 1e-6 and under a tolerance scaled by max(1, |x|).
const double perturbation = 1e-3;

// ---------------------------------------------------------------------------
// KDL <-> Eigen, through the public data members only
// ---------------------------------------------------------------------------

Vector3d E(const Vector& v) { return Vector3d(v.data[0], v.data[1], v.data[2]); }

Matrix3d E(const Rotation& R)
{
    Matrix3d m;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m(i, j) = R.data[3 * i + j];
    return m;
}

Matrix4d hom(const Matrix3d& R, const Vector3d& p)
{
    Matrix4d m = Matrix4d::Identity();
    m.topLeftCorner<3, 3>() = R;
    m.topRightCorner<3, 1>() = p;
    return m;
}

Matrix4d E(const Frame& F) { return hom(E(F.M), E(F.p)); }

Vector6d E(const Twist& t)
{
    Vector6d x;
    x << E(t.vel), E(t.rot);
    return x;
}

Vector6d E(const Wrench& w)
{
    Vector6d x;
    x << E(w.force), E(w.torque);
    return x;
}

Vector2d E(const Vector2& v) { return Vector2d(v.x(), v.y()); }

// The KDL type of an Eigen expression, chosen by its size: 3x1 Vector, 2x1
// Vector2, 3x3 Rotation, 4x4 Frame (homogeneous).
template <class D>
auto K(const Eigen::MatrixBase<D>& expr)
{
    constexpr int rows = D::RowsAtCompileTime, cols = D::ColsAtCompileTime;
    const typename D::PlainObject m = expr;
    if constexpr (rows == 3 && cols == 1)
        return Vector(m(0), m(1), m(2));
    else if constexpr (rows == 2 && cols == 1)
        return Vector2(m(0), m(1));
    else if constexpr (rows == 3 && cols == 3)
        return Rotation(m(0, 0), m(0, 1), m(0, 2),
                        m(1, 0), m(1, 1), m(1, 2),
                        m(2, 0), m(2, 1), m(2, 2));
    else {
        static_assert(rows == 4 && cols == 4, "no KDL type of this size");
        return Frame(K(m.template topLeftCorner<3, 3>()), K(m.template topRightCorner<3, 1>()));
    }
}

// Twist or Wrench from a 6-vector (first three, last three).
template <class T>
T to6(const VectorXd& x)
{
    return T(K(Vector3d(x.head<3>())), K(Vector3d(x.tail<3>())));
}

Matrix2d rot2(double angle)
{
    Matrix2d m;
    m << std::cos(angle), -std::sin(angle),
         std::sin(angle),  std::cos(angle);
    return m;
}

// Rotation2 from a 2x2 rotation matrix, through the (cos, sin) constructor.
Rotation2 toRotation2(const Matrix2d& m) { return Rotation2(m(0, 0), m(1, 0)); }

Matrix3d hom2(const Matrix2d& R, const Vector2d& p)
{
    Matrix3d m = Matrix3d::Identity();
    m.topLeftCorner<2, 2>() = R;
    m.topRightCorner<2, 1>() = p;
    return m;
}

Frame2 toFrame2(const Matrix3d& m)
{
    return Frame2(toRotation2(m.topLeftCorner<2, 2>()), K(Vector2d(m.topRightCorner<2, 1>())));
}

// ---------------------------------------------------------------------------
// Lie-group references
// ---------------------------------------------------------------------------

Matrix3d skew(const Vector3d& v)
{
    Matrix3d m;
    m <<     0, -v.z(),  v.y(),
         v.z(),      0, -v.x(),
        -v.y(),  v.x(),      0;
    return m;
}

// Vector of the skew-symmetric part of m.
Vector3d vee(const Matrix3d& m)
{
    return 0.5 * Vector3d(m(2, 1) - m(1, 2), m(0, 2) - m(2, 0), m(1, 0) - m(0, 1));
}

Matrix3d expso3(const Vector3d& phi)
{
    const double n = phi.norm();
    if (n == 0)
        return Matrix3d::Identity();
    return Eigen::AngleAxisd(n, phi / n).toRotationMatrix();
}

Vector3d logso3(const Matrix3d& R)
{
    const Eigen::AngleAxisd aa(R);
    return aa.angle() * aa.axis();
}

Matrix3d axisRotation(double angle, const Vector3d& axis)
{
    return Eigen::AngleAxisd(angle, axis).toRotationMatrix();
}

Matrix6d blockDiag(const Matrix3d& R)
{
    Matrix6d m = Matrix6d::Zero();
    m.topLeftCorner<3, 3>() = R;
    m.bottomRightCorner<3, 3>() = R;
    return m;
}

// Frame * Twist (velocity first): [[R, [p]x R], [0, R]].
Matrix6d twistAdjoint(const Matrix4d& F)
{
    const Matrix3d R = F.topLeftCorner<3, 3>();
    Matrix6d m = blockDiag(R);
    m.topRightCorner<3, 3>() = skew(F.topRightCorner<3, 1>()) * R;
    return m;
}

// Frame * Wrench (force first): [[R, 0], [[p]x R, R]].
Matrix6d wrenchAdjoint(const Matrix4d& F)
{
    const Matrix3d R = F.topLeftCorner<3, 3>();
    Matrix6d m = blockDiag(R);
    m.bottomLeftCorner<3, 3>() = skew(F.topRightCorner<3, 1>()) * R;
    return m;
}

// Spatial motion cross product t x . (velocity first).
Matrix6d motionCross(const Twist& t)
{
    Matrix6d m = Matrix6d::Zero();
    m.topLeftCorner<3, 3>() = skew(E(t.rot));
    m.topRightCorner<3, 3>() = skew(E(t.vel));
    m.bottomRightCorner<3, 3>() = skew(E(t.rot));
    return m;
}

Vector3d homApply(const Matrix4d& F, const Vector3d& v) { return (F * Vector4d(v.x(), v.y(), v.z(), 1)).head<3>(); }

Vector2d homApply(const Matrix3d& F, const Vector2d& v) { return (F * Eigen::Vector3d(v.x(), v.y(), 1)).head<2>(); }

Matrix4d transl(double x, double y, double z) { return hom(Matrix3d::Identity(), Vector3d(x, y, z)); }

// ---------------------------------------------------------------------------
// Random inputs, from KDL::random (uniform in [-0.99, 0.99] per component)
// ---------------------------------------------------------------------------

template <class T = double>
T rnd()
{
    T x;
    KDL::random(x);
    return x;
}

template <class T>
T rndPos()
{
    T x;
    KDL::posrandom(x);
    return x;
}

// Divisors and dt: in [0.51, 2.49].
double rndScale() { return 1.5 + rnd(); }

// Angles in (-PI, PI).
double rndAngle() { return PI * rnd(); }

// ---------------------------------------------------------------------------
// Step 1: the double types against Eigen
// ---------------------------------------------------------------------------

void vectorAgainstEigen()
{
    const double x = rnd(), y = rnd(), z = rnd(), s = rndScale();
    const Vector a(x, y, z), b = rnd<Vector>();
    const Vector3d ea(x, y, z), eb = E(b);

    // construction, copy, element access
    CHECK(E(Vector()) == Vector3d::Zero());
    CHECK(E(a) == ea);
    const Vector copy(a);
    CHECK(E(copy) == ea);
    Vector assigned;
    assigned = a;
    CHECK(E(assigned) == ea);
    Vector byIndex, byBracket, bySetter;
    for (int i = 0; i < 3; ++i) {
        CHECK(a(i) == ea(i));
        CHECK(a[i] == ea(i));
        byIndex(i) = eb(i);
        byBracket[i] = eb(i);
    }
    CHECK(E(byIndex) == eb);
    CHECK(E(byBracket) == eb);
    CHECK(a.x() == x && a.y() == y && a.z() == z);
    bySetter.x(x);
    bySetter.y(y);
    bySetter.z(z);
    CHECK(E(bySetter) == ea);

    // arithmetic
    CHECK(Equal(a + b, K(ea + eb), tol));
    CHECK(Equal(a - b, K(ea - eb), tol));
    CHECK(Equal(a * s, K(ea * s), tol));
    CHECK(Equal(s * a, K(s * ea), tol));
    CHECK(Equal(a / s, K(ea / s), tol));
    CHECK(Equal(a * b, K(ea.cross(eb)), tol));
    CHECK(Equal(-a, K(-ea), tol));
    CHECK(Equal(dot(a, b), ea.dot(eb), tol));
    Vector t = a;
    t += b;
    CHECK(Equal(t, K(ea + eb), tol));
    t = a;
    t -= b;
    CHECK(Equal(t, K(ea - eb), tol));
    t = a;
    t.ReverseSign();
    CHECK(Equal(t, K(-ea), tol));
    t = a;
    SetToZero(t);
    CHECK(E(t) == Vector3d::Zero());
    CHECK(E(Vector::Zero()) == Vector3d::Zero());

    // norm
    CHECK(Equal(a.Norm(), ea.norm(), tol));
    t = a;
    CHECK(Equal(t.Normalize(), ea.norm(), tol));
    CHECK(Equal(t, K(ea.normalized()), tol));
    t = Vector::Zero();
    CHECK(t.Normalize() == 0.0);
    CHECK(E(t) == Vector3d::UnitX());

    // 2D embeddings
    const double u = rnd(), w = rnd();
    const Vector2 v2(u, w);
    t = b;
    t.Set2DXY(v2);
    CHECK(E(t) == Vector3d(u, w, 0));
    t = b;
    t.Set2DYZ(v2);
    CHECK(E(t) == Vector3d(0, u, w));
    t = b;
    t.Set2DZX(v2);
    CHECK(E(t) == Vector3d(w, 0, u));
    const Frame F = rnd<Frame>();
    t = b;
    t.Set2DPlane(F, v2);
    // BUG: Set2DPlane computed the result into a local and left *this unchanged;
    // fixed in "(KDL) make Vector::Set2DPlane set the vector".
    CHECK(Equal(t, K(homApply(E(F), Vector3d(u, w, 0))), tol));
}

void rotationAgainstEigen()
{
    const Rotation R = rnd<Rotation>(), R2 = rnd<Rotation>();
    const Matrix3d eR = E(R), eR2 = E(R2), eRinv = eR.inverse();
    const Vector v = rnd<Vector>();
    const Twist t = rnd<Twist>();
    const Wrench w = rnd<Wrench>();

    // construction, copy, element access
    const Rotation byEntries(eR(0, 0), eR(0, 1), eR(0, 2),
                             eR(1, 0), eR(1, 1), eR(1, 2),
                             eR(2, 0), eR(2, 1), eR(2, 2));
    CHECK(E(byEntries) == eR);
    const Rotation byColumns(K(Vector3d(eR.col(0))), K(Vector3d(eR.col(1))), K(Vector3d(eR.col(2))));
    CHECK(E(byColumns) == eR);
    const Rotation copy(R);
    CHECK(E(copy) == eR);
    Rotation assigned;
    assigned = R;
    CHECK(E(assigned) == eR);
    Rotation written;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            CHECK(R(i, j) == eR(i, j));
            written(i, j) = eR(i, j);
        }
    CHECK(E(written) == eR);
    CHECK(E(Rotation::Identity()) == Matrix3d::Identity());

    // columns
    CHECK(E(R.UnitX()) == eR.col(0));
    CHECK(E(R.UnitY()) == eR.col(1));
    CHECK(E(R.UnitZ()) == eR.col(2));
    Rotation byUnits;
    byUnits.UnitX(K(Vector3d(eR.col(0))));
    byUnits.UnitY(K(Vector3d(eR.col(1))));
    byUnits.UnitZ(K(Vector3d(eR.col(2))));
    CHECK(E(byUnits) == eR);

    // products and inverses
    CHECK(Equal(R * v, K(eR * E(v)), tol));
    CHECK(Equal(R * R2, K(eR * eR2), tol));
    CHECK(Equal(R * t, to6<Twist>(blockDiag(eR) * E(t)), tol));
    CHECK(Equal(R * w, to6<Wrench>(blockDiag(eR) * E(w)), tol));
    CHECK(Equal(R.Inverse(), K(eRinv), tol));
    Rotation inverted = R;
    inverted.SetInverse();
    CHECK(Equal(inverted, K(eRinv), tol));
    CHECK(Equal(R.Inverse(v), K(eRinv * E(v)), tol));
    CHECK(Equal(R.Inverse(t), to6<Twist>(blockDiag(eR).inverse() * E(t)), tol));
    CHECK(Equal(R.Inverse(w), to6<Wrench>(blockDiag(eR).inverse() * E(w)), tol));
}

void frameAgainstEigen()
{
    const Frame F = rnd<Frame>(), F2 = rnd<Frame>();
    const Matrix4d eF = E(F), eF2 = E(F2), eFinv = eF.inverse();
    const Vector v = rnd<Vector>();
    const Twist t = rnd<Twist>();
    const Wrench w = rnd<Wrench>();

    // construction, copy, element access
    CHECK(E(Frame(F.M, F.p)) == eF);
    CHECK(E(Frame(F.p)) == hom(Matrix3d::Identity(), E(F.p)));
    CHECK(E(Frame(F.M)) == hom(E(F.M), Vector3d::Zero()));
    Frame copy(F);
    CHECK(E(copy) == eF);
    Frame assigned;
    assigned = F;
    CHECK(E(assigned) == eF);
    CHECK(E(Frame::Identity()) == Matrix4d::Identity());
    double d[16];
    copy.Make4x4(d);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            CHECK(d[4 * i + j] == eF(i, j));
            CHECK(F(i, j) == eF(i, j));
            CHECK(copy(i, j) == eF(i, j));
        }

    // products and inverses
    CHECK(Equal(F * v, K(homApply(eF, E(v))), tol));
    CHECK(Equal(F * F2, K(Matrix4d(eF * eF2)), tol));
    CHECK(Equal(F * t, to6<Twist>(twistAdjoint(eF) * E(t)), tol));
    CHECK(Equal(F * w, to6<Wrench>(wrenchAdjoint(eF) * E(w)), tol));
    CHECK(Equal(F.Inverse(), K(eFinv), tol));
    CHECK(Equal(F.Inverse(v), K(homApply(eFinv, E(v))), tol));
    CHECK(Equal(F.Inverse(t), to6<Twist>(twistAdjoint(eF).inverse() * E(t)), tol));
    CHECK(Equal(F.Inverse(w), to6<Wrench>(wrenchAdjoint(eF).inverse() * E(w)), tol));
}

// The operations Twist and Wrench share.
template <class T>
void screwAgainstEigen()
{
    const T a = rnd<T>(), b = rnd<T>();
    const Vector6d ea = E(a), eb = E(b);
    const double s = rndScale();

    // construction, copy, element access
    CHECK(E(T()) == Vector6d::Zero());
    CHECK(E(to6<T>(ea)) == ea);
    T byIndex, byBracket;
    for (int i = 0; i < 6; ++i) {
        CHECK(a(i) == ea(i));
        CHECK(a[i] == ea(i));
        byIndex(i) = eb(i);
        byBracket[i] = eb(i);
    }
    CHECK(E(byIndex) == eb);
    CHECK(E(byBracket) == eb);

    // arithmetic
    CHECK(Equal(a + b, to6<T>(ea + eb), tol));
    CHECK(Equal(a - b, to6<T>(ea - eb), tol));
    CHECK(Equal(a * s, to6<T>(ea * s), tol));
    CHECK(Equal(s * a, to6<T>(s * ea), tol));
    CHECK(Equal(a / s, to6<T>(ea / s), tol));
    CHECK(Equal(-a, to6<T>(-ea), tol));
    T c = a;
    c += b;
    CHECK(Equal(c, to6<T>(ea + eb), tol));
    c = a;
    c -= b;
    CHECK(Equal(c, to6<T>(ea - eb), tol));
    c = a;
    c.ReverseSign();
    CHECK(Equal(c, to6<T>(-ea), tol));
    c = a;
    SetToZero(c);
    CHECK(E(c) == Vector6d::Zero());
    CHECK(E(T::Zero()) == Vector6d::Zero());
}

void twistWrenchSpecificsAgainstEigen()
{
    const Twist t = rnd<Twist>(), t2 = rnd<Twist>();
    const Wrench w = rnd<Wrench>();
    const Vector v = rnd<Vector>();

    CHECK(Equal(dot(t, w), E(t).dot(E(w)), tol));
    CHECK(Equal(dot(w, t), E(t).dot(E(w)), tol));

    // spatial cross products: motion (crm) and force (crf = -crm^T)
    CHECK(Equal(t * t2, to6<Twist>(motionCross(t) * E(t2)), tol));
    CHECK(Equal(t * w, to6<Wrench>(-motionCross(t).transpose() * E(w)), tol));

    // change of reference point
    CHECK(Equal(t.RefPoint(v), Twist(K(E(t.vel) + E(t.rot).cross(E(v))), t.rot), tol));
    CHECK(Equal(w.RefPoint(v), Wrench(w.force, K(E(w.torque) + E(w.force).cross(E(v)))), tol));
}

void vector2AgainstEigen()
{
    const double x = rnd(), y = rnd(), s = rndScale();
    const Vector2 a(x, y), b(rnd(), rnd());
    const Vector2d ea(x, y), eb = E(b);

    // construction, copy, element access
    CHECK(a.x() == x && a.y() == y);
    CHECK(E(Vector2()) == Vector2d::Zero());
    const Vector2 copy(a);
    CHECK(E(copy) == ea);
    Vector2 assigned;
    assigned = a;
    CHECK(E(assigned) == ea);
    Vector2 byIndex, byBracket, bySetter;
    for (int i = 0; i < 2; ++i) {
        CHECK(a(i) == ea(i));
        CHECK(a[i] == ea(i));
        byIndex(i) = eb(i);
        byBracket[i] = eb(i);
    }
    CHECK(E(byIndex) == eb);
    CHECK(E(byBracket) == eb);
    bySetter.x(x);
    bySetter.y(y);
    CHECK(E(bySetter) == ea);

    // arithmetic
    CHECK(Equal(a + b, K(ea + eb), tol));
    CHECK(Equal(a - b, K(ea - eb), tol));
    CHECK(Equal(a * s, K(ea * s), tol));
    CHECK(Equal(s * a, K(s * ea), tol));
    CHECK(Equal(a / s, K(ea / s), tol));
    CHECK(Equal(-a, K(-ea), tol));
    Vector2 t = a;
    t += b;
    CHECK(Equal(t, K(ea + eb), tol));
    t = a;
    t -= b;
    CHECK(Equal(t, K(ea - eb), tol));
    t = a;
    t.ReverseSign();
    CHECK(Equal(t, K(-ea), tol));
    t = a;
    SetToZero(t);
    CHECK(E(t) == Vector2d::Zero());
    CHECK(E(Vector2::Zero()) == Vector2d::Zero());

    // norm
    CHECK(Equal(a.Norm(), ea.norm(), tol));
    t = a;
    CHECK(Equal(t.Normalize(), ea.norm(), tol));
    CHECK(Equal(t, K(Vector2d(ea.normalized())), tol));
    t = Vector2::Zero();
    CHECK(t.Normalize() == 0.0);
    CHECK(E(t) == Vector2d::UnitX());

    // projections of a 3D vector
    const Vector v = rnd<Vector>();
    t.Set3DXY(v);
    CHECK(E(t) == Vector2d(v.data[0], v.data[1]));
    t.Set3DYZ(v);
    CHECK(E(t) == Vector2d(v.data[1], v.data[2]));
    t.Set3DZX(v);
    CHECK(E(t) == Vector2d(v.data[2], v.data[0]));
    const Frame F = rnd<Frame>();
    t.Set3DPlane(F, v);
    CHECK(Equal(t, K(Vector2d(homApply(Matrix4d(E(F).inverse()), E(v)).head<2>())), tol));
}

void rotation2AgainstEigen()
{
    const double a = rndAngle(), a2 = rndAngle();
    const Matrix2d m = rot2(a), m2 = rot2(a2), minv = m.inverse();
    const Rotation2 R(a), R2(a2);
    const Vector2 v(rnd(), rnd());
    const Vector2d ev = E(v);

    // construction, copy, element access
    CHECK(Equal(R, toRotation2(m), tol));
    CHECK(Equal(Rotation2(), toRotation2(Matrix2d::Identity()), tol));
    const Rotation2 copy(R);
    CHECK(Equal(copy, R, tol));
    Rotation2 assigned;
    assigned = R;
    CHECK(Equal(assigned, R, tol));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            // BUG: Rotation2::operator() returned the transpose; fixed in
            // "(KDL) make Rotation2::operator() return the matrix, not its transpose".
            CHECK(Equal(R(i, j), m(i, j), tol));

    // products and inverses
    CHECK(Equal(R * v, K(Vector2d(m * ev)), tol));
    CHECK(Equal(R * R2, toRotation2(m * m2), tol));
    CHECK(Equal(R.Inverse(), toRotation2(minv), tol));
    Rotation2 inverted = R;
    inverted.SetInverse();
    CHECK(Equal(inverted, toRotation2(minv), tol));
    CHECK(Equal(R.Inverse(v), K(Vector2d(minv * ev)), tol));
    Rotation2 identity = R;
    identity.SetIdentity();
    CHECK(Equal(identity, toRotation2(Matrix2d::Identity()), tol));
    CHECK(Equal(Rotation2::Identity(), toRotation2(Matrix2d::Identity()), tol));
}

void frame2AgainstEigen()
{
    const double a = rndAngle(), a2 = rndAngle();
    const Vector2 p(rnd(), rnd()), p2(rnd(), rnd()), v(rnd(), rnd());
    const Frame2 F(Rotation2(a), p), F2(Rotation2(a2), p2);
    const Matrix3d eF = hom2(rot2(a), E(p)), eF2 = hom2(rot2(a2), E(p2)), eFinv = eF.inverse();

    // construction, copy, element access
    CHECK(Equal(F, toFrame2(eF), tol));
    CHECK(Equal(Frame2(p), toFrame2(hom2(Matrix2d::Identity(), E(p))), tol));
    CHECK(Equal(Frame2(Rotation2(a)), toFrame2(hom2(rot2(a), Vector2d::Zero())), tol));
    CHECK(Equal(Frame2(), toFrame2(Matrix3d::Identity()), tol));
    Frame2 copy(F);
    CHECK(Equal(copy, F, tol));
    Frame2 assigned;
    assigned = F;
    CHECK(Equal(assigned, F, tol));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            // BUG: the rotation block came out transposed, through Rotation2::operator().
            CHECK(Equal(F(i, j), eF(i, j), tol));
            CHECK(Equal(copy(i, j), eF(i, j), tol));
        }

    // products and inverses
    CHECK(Equal(F * v, K(homApply(eF, E(v))), tol));
    CHECK(Equal(F * F2, toFrame2(eF * eF2), tol));
    CHECK(Equal(F.Inverse(), toFrame2(eFinv), tol));
    Frame2 inverted = F;
    inverted.SetInverse();
    CHECK(Equal(inverted, toFrame2(eFinv), tol));
    CHECK(Equal(F.Inverse(v), K(homApply(eFinv, E(v))), tol));
    Frame2 identity = F;
    identity.SetIdentity();
    CHECK(Equal(identity, toFrame2(Matrix3d::Identity()), tol));
    CHECK(Equal(Frame2::Identity(), toFrame2(Matrix3d::Identity()), tol));
}

void diffAddDeltaAgainstEigen()
{
    const double dt = rndScale();
    const Vector a = rnd<Vector>(), b = rnd<Vector>(), dv = rnd<Vector>();
    const Rotation Ra = rnd<Rotation>(), Rb = rnd<Rotation>();
    const Frame Fa = rnd<Frame>(), Fb = rnd<Frame>();
    const Twist ta = rnd<Twist>(), tb = rnd<Twist>(), dtw = rnd<Twist>();
    const Wrench wa = rnd<Wrench>(), wb = rnd<Wrench>(), dw = rnd<Wrench>();

    // diff: the displacement from a to b per dt; rotations as a rotation vector
    // in the base frame
    CHECK(Equal(diff(a, b, dt), K((E(b) - E(a)) / dt), tol));
    CHECK(Equal(diff(Ra, Rb, dt), K(logso3(E(Rb) * E(Ra).transpose()) / dt), tol));
    CHECK(Equal(diff(Fa, Fb, dt),
                Twist(K((E(Fb.p) - E(Fa.p)) / dt), K(logso3(E(Fb.M) * E(Fa.M).transpose()) / dt)), tol));
    CHECK(Equal(diff(ta, tb, dt), to6<Twist>((E(tb) - E(ta)) / dt), tol));
    CHECK(Equal(diff(wa, wb, dt), to6<Wrench>((E(wb) - E(wa)) / dt), tol));

    // addDelta: the inverse
    CHECK(Equal(addDelta(a, dv, dt), K(E(a) + E(dv) * dt), tol));
    CHECK(Equal(addDelta(Ra, dv, dt), K(Matrix3d(expso3(E(dv) * dt) * E(Ra))), tol));
    CHECK(Equal(addDelta(Fa, dtw, dt),
                Frame(K(Matrix3d(expso3(E(dtw.rot) * dt) * E(Fa.M))), K(E(Fa.p) + E(dtw.vel) * dt)), tol));
    CHECK(Equal(addDelta(ta, dtw, dt), to6<Twist>(E(ta) + E(dtw) * dt), tol));
    CHECK(Equal(addDelta(wa, dw, dt), to6<Wrench>(E(wa) + E(dw) * dt), tol));

    // round trips
    CHECK(Equal(addDelta(a, diff(a, b, dt), dt), b, tol));
    CHECK(Equal(addDelta(Ra, diff(Ra, Rb, dt), dt), Rb, tol));
    CHECK(Equal(addDelta(Fa, diff(Fa, Fb, dt), dt), Fb, tol));
    CHECK(Equal(addDelta(ta, diff(ta, tb, dt), dt), tb, tol));
    CHECK(Equal(addDelta(wa, diff(wa, wb, dt), dt), wb, tol));

    // the free function Rot(rotation vector)
    CHECK(Equal(Rot(dv), K(expso3(E(dv))), tol));
}

// ---------------------------------------------------------------------------
// Steps 3 and 4: finite differences
// ---------------------------------------------------------------------------

// Trajectories x(t) of the double types whose value and derivatives at t = 0
// are the parts of a Vel/Acc value; plain double types are constants.
double at(double x, double) { return x; }
Vector at(const Vector& x, double) { return x; }
Rotation at(const Rotation& x, double) { return x; }
Frame at(const Frame& x, double) { return x; }
Twist at(const Twist& x, double) { return x; }

double at(const doubleVel& x, double t) { return x.t + t * x.grad; }
Vector at(const VectorVel& x, double t) { return K(E(x.p) + t * E(x.v)); }
// R(t) = Rot(w t) R, with w in the base frame
Rotation at(const RotationVel& x, double t) { return t == 0 ? x.R : K(Matrix3d(expso3(t * E(x.w)) * E(x.R))); }
Frame at(const FrameVel& x, double t) { return Frame(at(x.M, t), at(x.p, t)); }
Twist at(const TwistVel& x, double t) { return Twist(at(x.vel, t), at(x.rot, t)); }

double at(const doubleAcc& x, double t) { return x.t + t * x.d + t * t / 2 * x.dd; }
Vector at(const VectorAcc& x, double t) { return K(E(x.p) + t * E(x.v) + t * t / 2 * E(x.dv)); }
// R(t) = Rot(w t + dw t^2/2) R; the Magnus correction is O(t^3) and cancels in
// the symmetric differences.
Rotation at(const RotationAcc& x, double t)
{
    return t == 0 ? x.R : K(Matrix3d(expso3(t * E(x.w) + t * t / 2 * E(x.dw)) * E(x.R)));
}
Frame at(const FrameAcc& x, double t) { return Frame(at(x.M, t), at(x.p, t)); }
Twist at(const TwistAcc& x, double t) { return Twist(at(x.vel, t), at(x.rot, t)); }

// Outputs as flat vectors, to difference them...
VectorXd flat(double x) { return VectorXd::Constant(1, x); }
VectorXd flat(const Vector& v) { return E(v); }
VectorXd flat(const Rotation& R) { return Eigen::Map<const Eigen::Matrix<double, 9, 1>>(R.data); }
VectorXd flat(const Frame& F)
{
    VectorXd x(12);
    x << E(F.p), flat(F.M);
    return x;
}
VectorXd flat(const Twist& t) { return E(t); }

// ...and the difference of the flat vector at y0 as the derivative in the
// Vel/Acc convention. Rotations: dR R^T = [w]x for the first derivative; for the
// second, ddR R^T = [dw]x + [w]x^2 and [w]x^2 is symmetric, so both are the vector
// of the skew-symmetric part.
double tangent(double, const VectorXd& d) { return d(0); }
Vector tangent(const Vector&, const VectorXd& d) { return K(Vector3d(d)); }
Vector tangent(const Rotation& R, const VectorXd& d)
{
    const Matrix3d dR = Eigen::Map<const Eigen::Matrix<double, 3, 3, Eigen::RowMajor>>(d.data());
    return K(vee(dR * E(R).transpose()));
}
Twist tangent(const Frame& F, const VectorXd& d)
{
    return Twist(K(Vector3d(d.head<3>())), tangent(F.M, d.tail<9>()));
}
Twist tangent(const Twist&, const VectorXd& d) { return to6<Twist>(d); }

// Value and derivatives of the Vel/Acc types, read from their data members.
double val(const doubleVel& x) { return x.t; }
double d1(const doubleVel& x) { return x.grad; }
Vector val(const VectorVel& x) { return x.p; }
Vector d1(const VectorVel& x) { return x.v; }
Rotation val(const RotationVel& x) { return x.R; }
Vector d1(const RotationVel& x) { return x.w; }
Frame val(const FrameVel& x) { return Frame(x.M.R, x.p.p); }
Twist d1(const FrameVel& x) { return Twist(x.p.v, x.M.w); }
Twist val(const TwistVel& x) { return Twist(x.vel.p, x.rot.p); }
Twist d1(const TwistVel& x) { return Twist(x.vel.v, x.rot.v); }

double val(const doubleAcc& x) { return x.t; }
double d1(const doubleAcc& x) { return x.d; }
double d2(const doubleAcc& x) { return x.dd; }
Vector val(const VectorAcc& x) { return x.p; }
Vector d1(const VectorAcc& x) { return x.v; }
Vector d2(const VectorAcc& x) { return x.dv; }
Rotation val(const RotationAcc& x) { return x.R; }
Vector d1(const RotationAcc& x) { return x.w; }
Vector d2(const RotationAcc& x) { return x.dw; }
Frame val(const FrameAcc& x) { return Frame(x.M.R, x.p.p); }
Twist d1(const FrameAcc& x) { return Twist(x.p.v, x.M.w); }
Twist d2(const FrameAcc& x) { return Twist(x.p.dv, x.M.dw); }
Twist val(const TwistAcc& x) { return Twist(x.vel.p, x.rot.p); }
Twist d1(const TwistAcc& x) { return Twist(x.vel.v, x.rot.v); }
Twist d2(const TwistAcc& x) { return Twist(x.vel.dv, x.rot.dv); }

// Checks gJet(x...) against the double operation g on the trajectories of x...:
// value, first derivative and, for the Acc types, second derivative.
template <class GJet, class G, class... X>
void fdVelSplit(const std::string& what, GJet gJet, G g, const X&... x)
{
    const auto y = gJet(x...);
    const auto y0 = g(at(x, 0.0)...);
    CPPUNIT_ASSERT_MESSAGE(what + ": value", Equal(val(y), y0, tolValue));
    const VectorXd d = (flat(g(at(x, hVel)...)) - flat(g(at(x, -hVel)...))) / (2 * hVel);
    CPPUNIT_ASSERT_MESSAGE(what + ": derivative", Equal(d1(y), tangent(y0, d), tolDeriv));
}

template <class G, class... X>
void fdVel(const std::string& what, G g, const X&... x)
{
    fdVelSplit(what, g, g, x...);
}

template <class GJet, class G, class... X>
void fdAccSplit(const std::string& what, GJet gJet, G g, const X&... x)
{
    fdVelSplit(what, gJet, g, x...);
    const auto y = gJet(x...);
    const auto y0 = g(at(x, 0.0)...);
    const VectorXd dd = (flat(g(at(x, hAcc)...)) - 2 * flat(y0) + flat(g(at(x, -hAcc)...))) / (hAcc * hAcc);
    CPPUNIT_ASSERT_MESSAGE(what + ": second derivative", Equal(d2(y), tangent(y0, dd), tolDeriv2));
}

template <class G, class... X>
void fdAcc(const std::string& what, G g, const X&... x)
{
    fdAccSplit(what, g, g, x...);
}

// Operations written once and applied both to the Vel/Acc types and to the
// double types.
const auto add = [](const auto& a, const auto& b) { return a + b; };
const auto sub = [](const auto& a, const auto& b) { return a - b; };
const auto mul = [](const auto& a, const auto& b) { return a * b; };
const auto divide = [](const auto& a, const auto& b) { return a / b; };
const auto neg = [](const auto& a) { return -a; };
const auto addAssign = [](auto a, const auto& b) { a += b; return a; };
const auto subAssign = [](auto a, const auto& b) { a -= b; return a; };
const auto assign = [](const auto& a) { std::decay_t<decltype(a)> r; r = a; return r; };
const auto reverseSign = [](auto a) { a.ReverseSign(); return a; };
const auto setToZero = [](auto a) { SetToZero(a); return a; };
const auto norm = [](auto a) { return a.Norm(); };
const auto dotOf = [](const auto& a, const auto& b) { return dot(a, b); };
const auto inverse = [](const auto& a) { return a.Inverse(); };
const auto inverseOf = [](const auto& a, const auto& b) { return a.Inverse(b); };
const auto refPoint = [](auto a, const auto& b) { return a.RefPoint(b); };
const auto unitX = [](const auto& R) { return R.UnitX(); };
const auto unitY = [](const auto& R) { return R.UnitY(); };
const auto unitZ = [](const auto& R) { return R.UnitZ(); };
const auto doRotX = [](auto R, const auto& angle) { R.DoRotX(angle); return R; };
const auto doRotY = [](auto R, const auto& angle) { R.DoRotY(angle); return R; };
const auto doRotZ = [](auto R, const auto& angle) { R.DoRotZ(angle); return R; };
const double dtDiff = 0.7;
const auto diffOf = [](const auto& a, const auto& b) { return diff(a, b, dtDiff); };
const auto addDeltaOf = [](const auto& a, const auto& b) { return addDelta(a, b, dtDiff); };
const auto same = [](const auto& a) { return a; };

// Assignment from the double type: the derivatives become zero.
template <class Jet>
const auto assignFrom = [](const auto& a) { Jet r; r = a; return r; };

// ---------------------------------------------------------------------------
// Step 5: fields of every type, for the Equal/==/hash/random checks
// ---------------------------------------------------------------------------

using Fields = std::vector<double*>;

Fields cat(Fields a, const Fields& b)
{
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

Fields fields(double& x) { return {&x}; }
Fields fields(Vector& v) { return {&v.data[0], &v.data[1], &v.data[2]}; }
Fields fields(Rotation& R)
{
    Fields f;
    for (double& x : R.data)
        f.push_back(&x);
    return f;
}
Fields fields(Frame& F) { return cat(fields(F.p), fields(F.M)); }
Fields fields(Twist& t) { return cat(fields(t.vel), fields(t.rot)); }
Fields fields(Wrench& w) { return cat(fields(w.force), fields(w.torque)); }
Fields fields(Vector2& v) { return {&v(0), &v(1)}; }
Fields fields(doubleVel& x) { return {&x.t, &x.grad}; }
Fields fields(VectorVel& x) { return cat(fields(x.p), fields(x.v)); }
Fields fields(RotationVel& x) { return cat(fields(x.R), fields(x.w)); }
Fields fields(FrameVel& x) { return cat(fields(x.M), fields(x.p)); }
Fields fields(TwistVel& x) { return cat(fields(x.vel), fields(x.rot)); }
Fields fields(doubleAcc& x) { return {&x.t, &x.d, &x.dd}; }
Fields fields(VectorAcc& x) { return cat(cat(fields(x.p), fields(x.v)), fields(x.dv)); }
Fields fields(RotationAcc& x) { return cat(cat(fields(x.R), fields(x.w)), fields(x.dw)); }
Fields fields(FrameAcc& x) { return cat(fields(x.M), fields(x.p)); }
Fields fields(TwistAcc& x) { return cat(fields(x.vel), fields(x.rot)); }

// Fields that are not entries of a rotation matrix.
Fields linearFields(double& x) { return fields(x); }
Fields linearFields(Vector& v) { return fields(v); }
Fields linearFields(Rotation&) { return {}; }
Fields linearFields(Frame& F) { return fields(F.p); }
Fields linearFields(Twist& t) { return fields(t); }
Fields linearFields(Wrench& w) { return fields(w); }
Fields linearFields(doubleVel& x) { return fields(x); }
Fields linearFields(VectorVel& x) { return fields(x); }
Fields linearFields(RotationVel& x) { return fields(x.w); }
Fields linearFields(FrameVel& x) { return cat(linearFields(x.M), fields(x.p)); }
Fields linearFields(TwistVel& x) { return fields(x); }

// The rotation matrices inside a value.
std::vector<const Rotation*> rotations(const double&) { return {}; }
std::vector<const Rotation*> rotations(const Vector&) { return {}; }
std::vector<const Rotation*> rotations(const Rotation& R) { return {&R}; }
std::vector<const Rotation*> rotations(const Frame& F) { return {&F.M}; }
std::vector<const Rotation*> rotations(const Twist&) { return {}; }
std::vector<const Rotation*> rotations(const Wrench&) { return {}; }
std::vector<const Rotation*> rotations(const doubleVel&) { return {}; }
std::vector<const Rotation*> rotations(const VectorVel&) { return {}; }
std::vector<const Rotation*> rotations(const RotationVel& x) { return {&x.R}; }
std::vector<const Rotation*> rotations(const FrameVel& x) { return {&x.M.R}; }
std::vector<const Rotation*> rotations(const TwistVel&) { return {}; }

bool isRotation(const Rotation& R)
{
    const Matrix3d m = E(R);
    return (m.transpose() * m - Matrix3d::Identity()).cwiseAbs().maxCoeff() < tol
        && std::abs(m.determinant() - 1) < tol;
}

// random and posrandom: finite, proper rotations; posrandom is non-negative
// outside the rotation matrices.
template <class T>
void checkRandom(const std::string& what)
{
    T a = rnd<T>(), p = rndPos<T>();
    for (double* f : fields(a))
        CPPUNIT_ASSERT_MESSAGE(what + ": random is finite", std::isfinite(*f));
    for (double* f : fields(p))
        CPPUNIT_ASSERT_MESSAGE(what + ": posrandom is finite", std::isfinite(*f));
    for (const Rotation* R : rotations(a))
        CPPUNIT_ASSERT_MESSAGE(what + ": random gives a rotation", isRotation(*R));
    for (const Rotation* R : rotations(p))
        CPPUNIT_ASSERT_MESSAGE(what + ": posrandom gives a rotation", isRotation(*R));
    // BUG: posrandom(Frame) drew a random, not a positive, origin; fixed in
    // "(KDL) make posrandom(Frame) draw a positive origin".
    for (double* f : linearFields(p))
        CPPUNIT_ASSERT_MESSAGE(what + ": posrandom is non-negative", *f >= 0);
}

template <class... T>
void checkRandoms(const char* const (&names)[sizeof...(T)])
{
    int i = 0;
    (checkRandom<T>(names[i++]), ...);
}

// Equal(a, b) for b equal to a, and for b perturbed in each field in turn, in
// both argument orders.
template <class A, class B>
void checkEqual(const std::string& what, const A& a, B b)
{
    CPPUNIT_ASSERT_MESSAGE(what + ": equal", Equal(a, b) && Equal(b, a));
    CPPUNIT_ASSERT_MESSAGE(what + ": equal at 1e-12", Equal(a, b, tol) && Equal(b, a, tol));
    for (double* f : fields(b)) {
        const double keep = *f;
        *f += perturbation;
        CPPUNIT_ASSERT_MESSAGE(what + ": perturbed", !Equal(a, b) && !Equal(b, a));
        *f = keep;
    }
}

// operator== and operator!= the same way.
template <class A, class B>
void checkOperatorEq(const std::string& what, const A& a, B b)
{
    CPPUNIT_ASSERT_MESSAGE(what + ": ==", a == b && b == a && !(a != b) && !(b != a));
    for (double* f : fields(b)) {
        const double keep = *f;
        *f += perturbation;
        CPPUNIT_ASSERT_MESSAGE(what + ": != perturbed", a != b && b != a && !(a == b) && !(b == a));
        *f = keep;
    }
}

// std::hash: equal for a copy, different after perturbing any field.
template <class T>
void checkHash(const std::string& what, const T& a)
{
    T b = a;
    CPPUNIT_ASSERT_MESSAGE(what + ": hash of a copy", std::hash<T>{}(a) == std::hash<T>{}(b));
    for (double* f : fields(b)) {
        const double keep = *f;
        *f += perturbation;
        CPPUNIT_ASSERT_MESSAGE(what + ": hash of a perturbed value", std::hash<T>{}(a) != std::hash<T>{}(b));
        *f = keep;
    }
}

// The types that define operator== and operator!=.
template <class T>
constexpr bool hasOperatorEq =
    std::is_same_v<T, Vector> || std::is_same_v<T, Rotation> || std::is_same_v<T, Frame> ||
    std::is_same_v<T, Twist> || std::is_same_v<T, Wrench> || std::is_same_v<T, Vector2> ||
    std::is_same_v<T, VectorVel> || std::is_same_v<T, RotationVel> ||
    std::is_same_v<T, FrameVel> || std::is_same_v<T, TwistVel>;

// Same-type Equal, ==/!= (where defined) and hash.
template <class T>
void checkComparisons(const std::string& what, const T& a)
{
    checkEqual(what, a, a);
    checkHash(what, a);
    if constexpr (hasOperatorEq<T>)
        checkOperatorEq(what, a, a);
}

VectorAcc rndVectorAcc() { return VectorAcc(rnd<Vector>(), rnd<Vector>(), rnd<Vector>()); }
RotationAcc rndRotationAcc() { return RotationAcc(rnd<Rotation>(), rnd<Vector>(), rnd<Vector>()); }
FrameAcc rndFrameAcc() { return FrameAcc(rndRotationAcc(), rndVectorAcc()); }
TwistAcc rndTwistAcc() { return TwistAcc(rndVectorAcc(), rndVectorAcc()); }
doubleAcc rndDoubleAcc() { return doubleAcc(rnd(), rnd(), rnd()); }

}  // namespace

void FramesConsistencyTest::setUp()
{
    // KDL::random uses rand(): seed it so that every run sees the same inputs.
    srand(42);
}

void FramesConsistencyTest::tearDown()
{
}

void FramesConsistencyTest::TestDoubleTypesAgainstEigen()
{
    for (int i = 0; i < iterations; ++i) {
        vectorAgainstEigen();
        rotationAgainstEigen();
        frameAgainstEigen();
        screwAgainstEigen<Twist>();
        screwAgainstEigen<Wrench>();
        twistWrenchSpecificsAgainstEigen();
        vector2AgainstEigen();
        rotation2AgainstEigen();
        frame2AgainstEigen();
        diffAddDeltaAgainstEigen();
    }
}

void FramesConsistencyTest::TestParameterizationRoundTrips()
{
    const Vector3d X = Vector3d::UnitX(), Y = Vector3d::UnitY(), Z = Vector3d::UnitZ();
    for (int i = 0; i < iterations; ++i) {
        // elementary rotations: closed form, and right-multiplication by it
        const double a = rndAngle();
        const Rotation R = rnd<Rotation>();
        CHECK(Equal(Rotation::RotX(a), K(axisRotation(a, X)), tol));
        CHECK(Equal(Rotation::RotY(a), K(axisRotation(a, Y)), tol));
        CHECK(Equal(Rotation::RotZ(a), K(axisRotation(a, Z)), tol));
        Rotation r = R;
        r.DoRotX(a);
        CHECK(Equal(r, K(Matrix3d(E(R) * axisRotation(a, X))), tol));
        r = R;
        r.DoRotY(a);
        CHECK(Equal(r, K(Matrix3d(E(R) * axisRotation(a, Y))), tol));
        r = R;
        r.DoRotZ(a);
        CHECK(Equal(r, K(Matrix3d(E(R) * axisRotation(a, Z))), tol));

        // axis-angle, away from the singular angles 0 and PI
        const Vector axis = rnd<Vector>();
        const double angle = 1.5 + 1.4 * rnd();
        const Vector3d u = E(axis).normalized();
        const Rotation Raa = K(axisRotation(angle, u));
        CHECK(Equal(Rotation::Rot(axis, angle), Raa, tol));
        CHECK(Equal(Rotation::Rot2(K(u), angle), Raa, tol));
        CHECK(Equal(Raa.GetRot(), K(angle * u), tol));
        Vector gotAxis;
        const double gotAngle = Raa.GetRotAngle(gotAxis);
        CHECK(Equal(gotAngle, angle, tol));
        CHECK(Equal(gotAxis, K(u), tol));
        CHECK(Equal(Rotation::Rot(gotAxis, gotAngle), Raa, tol));
        CHECK(Equal(Rot(Raa.GetRot()), Raa, tol));

        // RPY / EulerZYX, away from pitch = +-PI/2
        const double roll = rndAngle(), pitch = 1.4 * rnd(), yaw = rndAngle();
        const Rotation Rrpy = K(Matrix3d(axisRotation(yaw, Z) * axisRotation(pitch, Y) * axisRotation(roll, X)));
        CHECK(Equal(Rotation::RPY(roll, pitch, yaw), Rrpy, tol));
        CHECK(Equal(Rotation::EulerZYX(yaw, pitch, roll), Rrpy, tol));
        double p1, p2, p3;
        Rrpy.GetRPY(p1, p2, p3);
        CHECK(Equal(p1, roll, tol) && Equal(p2, pitch, tol) && Equal(p3, yaw, tol));
        Rrpy.GetEulerZYX(p1, p2, p3);
        CHECK(Equal(p1, yaw, tol) && Equal(p2, pitch, tol) && Equal(p3, roll, tol));

        // EulerZYZ, away from beta = 0 and beta = PI
        const double alpha = rndAngle(), beta = PI_2 + 1.4 * rnd(), gamma = rndAngle();
        const Rotation Rzyz = K(Matrix3d(axisRotation(alpha, Z) * axisRotation(beta, Y) * axisRotation(gamma, Z)));
        CHECK(Equal(Rotation::EulerZYZ(alpha, beta, gamma), Rzyz, tol));
        Rzyz.GetEulerZYZ(p1, p2, p3);
        CHECK(Equal(p1, alpha, tol) && Equal(p2, beta, tol) && Equal(p3, gamma, tol));

        // Quaternion (x, y, z, w); q and -q are the same rotation and
        // GetQuaternion chooses the sign itself
        Vector4d q(rnd(), rnd(), rnd(), rnd());
        q.normalize();
        const Rotation Rq = K(Eigen::Quaterniond(q(3), q(0), q(1), q(2)).toRotationMatrix());
        CHECK(Equal(Rotation::Quaternion(q(0), q(1), q(2), q(3)), Rq, tol));
        Vector4d got;
        Rq.GetQuaternion(got(0), got(1), got(2), got(3));
        if (got.dot(q) < 0)
            got = -got;
        for (int k = 0; k < 4; ++k)
            CHECK(Equal(got(k), q(k), tol));

        // Denavit-Hartenberg
        const double dhA = rnd(), dhAlpha = rndAngle(), dhD = rnd(), dhTheta = rndAngle();
        const Matrix4d rotX = hom(axisRotation(dhAlpha, X), Vector3d::Zero());
        const Matrix4d rotZ = hom(axisRotation(dhTheta, Z), Vector3d::Zero());
        CHECK(Equal(Frame::DH(dhA, dhAlpha, dhD, dhTheta),
                    K(Matrix4d(rotZ * transl(0, 0, dhD) * transl(dhA, 0, 0) * rotX)), tol));
        CHECK(Equal(Frame::DH_Craig1989(dhA, dhAlpha, dhD, dhTheta),
                    K(Matrix4d(rotX * transl(dhA, 0, 0) * rotZ * transl(0, 0, dhD))), tol));

        // Integrate: one step of 1/f along the twist, expressed in the moving frame
        const Frame F = rnd<Frame>();
        const Twist t = rnd<Twist>();
        const double f = 50 + 40 * rnd();
        Frame integrated = F;
        integrated.Integrate(t, f);
        CHECK(Equal(integrated, K(Matrix4d(E(F) * hom(expso3(E(t.rot) / f), E(t.vel) / f))), tol));
        // a rotation below epsilon only translates
        integrated = F;
        integrated.Integrate(Twist(t.vel, Vector::Zero()), f);
        CHECK(Equal(integrated, K(Matrix4d(E(F) * transl(t.vel.data[0] / f, t.vel.data[1] / f, t.vel.data[2] / f))), tol));

        // Rotation2
        const double a2 = rndAngle();
        CHECK(Equal(Rotation2::Rot(a2), toRotation2(rot2(a2)), tol));
        Rotation2 r2;
        r2.SetRot(a2);
        CHECK(Equal(r2, toRotation2(rot2(a2)), tol));
        CHECK(Equal(r2.GetRot(), a2, tol));
        CHECK(Equal(Rotation2::Rot(a2).GetRot(), a2, tol));
    }
}

void FramesConsistencyTest::TestVelTypesByFiniteDifference()
{
    for (int i = 0; i < iterations; ++i) {
        const double s = rndScale();
        const doubleVel ds(rndScale(), rnd()), da = rnd<doubleVel>(), db = rnd<doubleVel>();
        const Vector v = rnd<Vector>();
        const Vector u = K(E(rnd<Vector>()).normalized());
        const Rotation r = rnd<Rotation>();
        const Frame f = rnd<Frame>();
        const Twist tw = rnd<Twist>();
        const VectorVel a = rnd<VectorVel>(), b = rnd<VectorVel>();
        const RotationVel R1 = rnd<RotationVel>(), R2 = rnd<RotationVel>();
        const FrameVel F1 = rnd<FrameVel>(), F2 = rnd<FrameVel>();
        const TwistVel T1 = rnd<TwistVel>(), T2 = rnd<TwistVel>();

        // doubleVel
        fdVel("diff(doubleVel)", diffOf, da, db);
        fdVel("addDelta(doubleVel)", addDeltaOf, da, db);

        // VectorVel
        fdVel("VectorVel+VectorVel", add, a, b);
        fdVel("Vector+VectorVel", add, v, a);
        fdVel("VectorVel+Vector", add, a, v);
        fdVel("VectorVel-VectorVel", sub, a, b);
        fdVel("Vector-VectorVel", sub, v, a);
        fdVel("VectorVel-Vector", sub, a, v);
        fdVel("-VectorVel", neg, a);
        fdVel("VectorVel*VectorVel", mul, a, b);
        fdVel("VectorVel*Vector", mul, a, v);
        fdVel("Vector*VectorVel", mul, v, a);
        fdVel("VectorVel*double", mul, a, s);
        fdVel("double*VectorVel", mul, s, a);
        fdVel("doubleVel*VectorVel", mul, ds, a);
        fdVel("VectorVel*doubleVel", mul, a, ds);
        fdVel("Rotation*VectorVel", mul, r, a);
        fdVel("VectorVel/double", divide, a, s);
        fdVel("VectorVel/doubleVel", divide, a, ds);
        fdVel("VectorVel+=", addAssign, a, b);
        fdVel("VectorVel-=", subAssign, a, b);
        fdVel("VectorVel=VectorVel", assign, a);
        fdVelSplit("VectorVel=Vector", assignFrom<VectorVel>, same, v);
        fdVelSplit("VectorVel::Zero", [] { return VectorVel::Zero(); }, [] { return Vector::Zero(); });
        fdVel("VectorVel::ReverseSign", reverseSign, a);
        fdVel("SetToZero(VectorVel)", setToZero, a);
        fdVel("VectorVel::Norm", norm, a);
        fdVel("dot(VectorVel,VectorVel)", dotOf, a, b);
        fdVel("dot(VectorVel,Vector)", dotOf, a, v);
        fdVel("dot(Vector,VectorVel)", dotOf, v, a);
        fdVel("diff(VectorVel)", diffOf, a, b);
        fdVel("addDelta(VectorVel)", addDeltaOf, a, b);
        CHECK(Equal(VectorVel(Vector::Zero(), v).Norm(), doubleVel(0, 0), tol));

        // RotationVel
        fdVel("RotationVel=RotationVel", assign, R1);
        fdVelSplit("RotationVel=Rotation", assignFrom<RotationVel>, same, r);
        fdVel("RotationVel::UnitX", unitX, R1);
        fdVel("RotationVel::UnitY", unitY, R1);
        fdVel("RotationVel::UnitZ", unitZ, R1);
        fdVelSplit("RotationVel::Identity", [] { return RotationVel::Identity(); },
                   [] { return Rotation::Identity(); });
        fdVel("RotationVel::Inverse()", inverse, R1);
        fdVel("RotationVel::Inverse(VectorVel)", inverseOf, R1, a);
        fdVel("RotationVel::Inverse(Vector)", inverseOf, R1, v);
        fdVel("RotationVel*VectorVel", mul, R1, a);
        fdVel("RotationVel*Vector", mul, R1, v);
        fdVel("RotationVel::DoRotX", doRotX, R1, ds);
        fdVel("RotationVel::DoRotY", doRotY, R1, ds);
        fdVel("RotationVel::DoRotZ", doRotZ, R1, ds);
        fdVelSplit("RotationVel::RotX", [](const doubleVel& x) { return RotationVel::RotX(x); },
                   [](double x) { return Rotation::RotX(x); }, ds);
        // BUG: RotationVel::RotY built Rotation::RotX; fixed in
        // "(KDL) make RotationVel::RotY rotate about Y".
        fdVelSplit("RotationVel::RotY", [](const doubleVel& x) { return RotationVel::RotY(x); },
                   [](double x) { return Rotation::RotY(x); }, ds);
        fdVelSplit("RotationVel::RotZ", [](const doubleVel& x) { return RotationVel::RotZ(x); },
                   [](double x) { return Rotation::RotZ(x); }, ds);
        fdVelSplit("RotationVel::Rot", [](const Vector& ax, const doubleVel& x) { return RotationVel::Rot(ax, x); },
                   [](const Vector& ax, double x) { return Rotation::Rot(ax, x); }, v, ds);
        fdVelSplit("RotationVel::Rot2", [](const Vector& ax, const doubleVel& x) { return RotationVel::Rot2(ax, x); },
                   [](const Vector& ax, double x) { return Rotation::Rot2(ax, x); }, u, ds);
        fdVel("RotationVel*RotationVel", mul, R1, R2);
        fdVel("Rotation*RotationVel", mul, r, R1);
        fdVel("RotationVel*Rotation", mul, R1, r);
        fdVel("RotationVel::Inverse(TwistVel)", inverseOf, R1, T1);
        fdVel("RotationVel::Inverse(Twist)", inverseOf, R1, tw);
        fdVel("RotationVel*TwistVel", mul, R1, T1);
        fdVel("RotationVel*Twist", mul, R1, tw);

        // FrameVel
        fdVel("FrameVel=FrameVel", assign, F1);
        fdVelSplit("FrameVel=Frame", assignFrom<FrameVel>, same, f);
        fdVelSplit("FrameVel::Identity", [] { return FrameVel::Identity(); }, [] { return Frame::Identity(); });
        fdVel("FrameVel::Inverse()", inverse, F1);
        fdVel("FrameVel::Inverse(VectorVel)", inverseOf, F1, a);
        fdVel("FrameVel::Inverse(Vector)", inverseOf, F1, v);
        fdVel("FrameVel*VectorVel", mul, F1, a);
        fdVel("FrameVel*Vector", mul, F1, v);
        fdVel("FrameVel*FrameVel", mul, F1, F2);
        fdVel("Frame*FrameVel", mul, f, F1);
        fdVel("FrameVel*Frame", mul, F1, f);
        fdVel("FrameVel::Inverse(TwistVel)", inverseOf, F1, T1);
        fdVel("FrameVel::Inverse(Twist)", inverseOf, F1, tw);
        fdVel("FrameVel*TwistVel", mul, F1, T1);
        fdVel("FrameVel*Twist", mul, F1, tw);

        // TwistVel
        fdVel("TwistVel+=", addAssign, T1, T2);
        fdVel("TwistVel-=", subAssign, T1, T2);
        fdVel("TwistVel*double", mul, T1, s);
        fdVel("double*TwistVel", mul, s, T1);
        fdVel("TwistVel/double", divide, T1, s);
        fdVel("TwistVel*doubleVel", mul, T1, ds);
        fdVel("doubleVel*TwistVel", mul, ds, T1);
        fdVel("TwistVel/doubleVel", divide, T1, ds);
        fdVel("TwistVel+TwistVel", add, T1, T2);
        fdVel("TwistVel-TwistVel", sub, T1, T2);
        fdVel("-TwistVel", neg, T1);
        fdVel("SetToZero(TwistVel)", setToZero, T1);
        fdVelSplit("TwistVel::Zero", [] { return TwistVel::Zero(); }, [] { return Twist::Zero(); });
        fdVel("TwistVel::ReverseSign", reverseSign, T1);
        fdVel("TwistVel::RefPoint", refPoint, T1, a);

        // diff/addDelta of RotationVel and FrameVel are not differentiated
        // operations: they act on the value and on the derivative separately
        // (displacement of the values, difference of the derivatives), which is
        // what makes addDelta(a, diff(a, b)) == b hold for both parts.
        const double dt = rndScale();
        const VectorVel dR = diff(R1, R2, dt);
        CHECK(Equal(dR.p, diff(R1.R, R2.R, dt), tol));
        CHECK(Equal(dR.v, K((E(R2.w) - E(R1.w)) / dt), tol));
        const RotationVel R1R2 = addDelta(R1, dR, dt);
        CHECK(Equal(R1R2.R, R2.R, tol) && Equal(R1R2.w, R2.w, tol));
        const RotationVel R1dR = addDelta(R1, a, dt);
        CHECK(Equal(R1dR.R, addDelta(R1.R, a.p, dt), tol));
        CHECK(Equal(R1dR.w, K(E(R1.w) + E(a.v) * dt), tol));
        const TwistVel dF = diff(F1, F2, dt);
        // BUG: diff(FrameVel) returned the rotational part as vel and the
        // translational part as rot; fixed in
        // "(KDL) put the translation of diff(FrameVel) in vel and the rotation in rot".
        CHECK(Equal(dF.vel.p, diff(F1.p.p, F2.p.p, dt), tol) && Equal(dF.vel.v, diff(F1.p.v, F2.p.v, dt), tol));
        CHECK(Equal(dF.rot.p, diff(F1.M.R, F2.M.R, dt), tol) && Equal(dF.rot.v, diff(F1.M.w, F2.M.w, dt), tol));
        const FrameVel F1F2 = addDelta(F1, dF, dt);
        CHECK(Equal(val(F1F2), val(F2), tol) && Equal(d1(F1F2), d1(F2), tol));
        const FrameVel F1dF = addDelta(F1, T1, dt);
        CHECK(Equal(val(F1dF), addDelta(val(F1), val(T1), dt), tol));
        CHECK(Equal(d1(F1dF), to6<Twist>(E(d1(F1)) + E(d1(T1)) * dt), tol));
    }

    // constructors and conversions
    const Vector p = rnd<Vector>(), v = rnd<Vector>();
    const Rotation R = rnd<Rotation>();
    const Frame F = rnd<Frame>();
    const Twist t = rnd<Twist>(), dt = rnd<Twist>();

    CHECK(E(VectorVel().p) == Vector3d::Zero() && E(VectorVel().v) == Vector3d::Zero());
    const VectorVel pv(p, v), pOnly(p);
    CHECK(E(pv.p) == E(p) && E(pv.v) == E(v));
    CHECK(E(pOnly.p) == E(p) && E(pOnly.v) == Vector3d::Zero());
    CHECK(E(pv.value()) == E(p) && E(pv.deriv()) == E(v));

    CHECK(E(RotationVel().w) == Vector3d::Zero());
    const RotationVel Rw(R, v), ROnly(R);
    CHECK(E(Rw.R) == E(R) && E(Rw.w) == E(v));
    CHECK(E(ROnly.R) == E(R) && E(ROnly.w) == Vector3d::Zero());
    CHECK(E(Rw.value()) == E(R) && E(Rw.deriv()) == E(v));

    const FrameVel Ft(F, t), FOnly(F), FParts(Rw, pv);
    CHECK(E(FrameVel().p.p) == Vector3d::Zero() && E(FrameVel().M.w) == Vector3d::Zero());
    CHECK(E(Ft.value()) == E(F) && E(Ft.deriv()) == E(t));
    CHECK(E(FOnly.value()) == E(F) && E(FOnly.deriv()) == Vector6d::Zero());
    CHECK(E(FParts.M.R) == E(R) && E(FParts.M.w) == E(v) && E(FParts.p.p) == E(p) && E(FParts.p.v) == E(v));
    CHECK(E(Ft.GetFrame()) == E(F) && E(Ft.GetTwist()) == E(t));

    const TwistVel Ttd(t, dt), TOnly(t), TParts(pv, VectorVel(v, p));
    CHECK(E(TwistVel().value()) == Vector6d::Zero() && E(TwistVel().deriv()) == Vector6d::Zero());
    CHECK(E(Ttd.value()) == E(t) && E(Ttd.deriv()) == E(dt));
    CHECK(E(TOnly.value()) == E(t) && E(TOnly.deriv()) == Vector6d::Zero());
    CHECK(E(TParts.vel.p) == E(p) && E(TParts.vel.v) == E(v) && E(TParts.rot.p) == E(v) && E(TParts.rot.v) == E(p));
    CHECK(E(Ttd.GetTwist()) == E(t) && E(Ttd.GetTwistDot()) == E(dt));
}

void FramesConsistencyTest::TestAccTypesByFiniteDifference()
{
    for (int i = 0; i < iterations; ++i) {
        const double s = rndScale();
        const doubleAcc ds(rndScale(), rnd(), rnd());
        const Vector v = rnd<Vector>();
        const Rotation r = rnd<Rotation>();
        const Frame f = rnd<Frame>();
        const Twist tw = rnd<Twist>();
        const VectorAcc a = rndVectorAcc(), b = rndVectorAcc();
        const RotationAcc R1 = rndRotationAcc(), R2 = rndRotationAcc();
        const FrameAcc F1 = rndFrameAcc(), F2 = rndFrameAcc();
        const TwistAcc T1 = rndTwistAcc(), T2 = rndTwistAcc();

        // VectorAcc
        fdAcc("VectorAcc+VectorAcc", add, a, b);
        fdAcc("Vector+VectorAcc", add, v, a);
        fdAcc("VectorAcc+Vector", add, a, v);
        fdAcc("VectorAcc-VectorAcc", sub, a, b);
        fdAcc("Vector-VectorAcc", sub, v, a);
        fdAcc("VectorAcc-Vector", sub, a, v);
        fdAcc("-VectorAcc", neg, a);
        fdAcc("VectorAcc*VectorAcc", mul, a, b);
        fdAcc("VectorAcc*Vector", mul, a, v);
        fdAcc("Vector*VectorAcc", mul, v, a);
        fdAcc("VectorAcc*double", mul, a, s);
        fdAcc("double*VectorAcc", mul, s, a);
        fdAcc("doubleAcc*VectorAcc", mul, ds, a);
        fdAcc("VectorAcc*doubleAcc", mul, a, ds);
        fdAcc("Rotation*VectorAcc", mul, r, a);
        fdAcc("VectorAcc/double", divide, a, s);
        fdAcc("VectorAcc/doubleAcc", divide, a, ds);
        fdAcc("VectorAcc+=", addAssign, a, b);
        fdAcc("VectorAcc-=", subAssign, a, b);
        fdAcc("VectorAcc=VectorAcc", assign, a);
        fdAccSplit("VectorAcc=Vector", assignFrom<VectorAcc>, same, v);
        fdAccSplit("VectorAcc::Zero", [] { return VectorAcc::Zero(); }, [] { return Vector::Zero(); });
        fdAcc("VectorAcc::ReverseSign", reverseSign, a);
        fdAcc("VectorAcc::Norm", norm, a);
        fdAcc("dot(VectorAcc,VectorAcc)", dotOf, a, b);
        fdAcc("dot(VectorAcc,Vector)", dotOf, a, v);
        fdAcc("dot(Vector,VectorAcc)", dotOf, v, a);

        // RotationAcc
        fdAcc("RotationAcc=RotationAcc", assign, R1);
        fdAccSplit("RotationAcc=Rotation", assignFrom<RotationAcc>, same, r);
        fdAccSplit("RotationAcc::Identity", [] { return RotationAcc::Identity(); },
                   [] { return Rotation::Identity(); });
        fdAcc("RotationAcc::Inverse()", inverse, R1);
        fdAcc("RotationAcc::Inverse(VectorAcc)", inverseOf, R1, a);
        fdAcc("RotationAcc::Inverse(Vector)", inverseOf, R1, v);
        fdAcc("RotationAcc*VectorAcc", mul, R1, a);
        fdAcc("RotationAcc*Vector", mul, R1, v);
        fdAcc("RotationAcc*RotationAcc", mul, R1, R2);
        fdAcc("Rotation*RotationAcc", mul, r, R1);
        fdAcc("RotationAcc*Rotation", mul, R1, r);
        fdAcc("RotationAcc::Inverse(TwistAcc)", inverseOf, R1, T1);
        fdAcc("RotationAcc::Inverse(Twist)", inverseOf, R1, tw);
        fdAcc("RotationAcc*TwistAcc", mul, R1, T1);
        fdAcc("RotationAcc*Twist", mul, R1, tw);

        // FrameAcc
        fdAcc("FrameAcc=FrameAcc", assign, F1);
        fdAccSplit("FrameAcc=Frame", assignFrom<FrameAcc>, same, f);
        fdAccSplit("FrameAcc::Identity", [] { return FrameAcc::Identity(); }, [] { return Frame::Identity(); });
        fdAcc("FrameAcc::Inverse()", inverse, F1);
        fdAcc("FrameAcc::Inverse(VectorAcc)", inverseOf, F1, a);
        fdAcc("FrameAcc::Inverse(Vector)", inverseOf, F1, v);
        fdAcc("FrameAcc*VectorAcc", mul, F1, a);
        fdAcc("FrameAcc*Vector", mul, F1, v);
        fdAcc("FrameAcc*FrameAcc", mul, F1, F2);
        fdAcc("Frame*FrameAcc", mul, f, F1);
        fdAcc("FrameAcc*Frame", mul, F1, f);
        fdAcc("FrameAcc::Inverse(TwistAcc)", inverseOf, F1, T1);
        fdAcc("FrameAcc::Inverse(Twist)", inverseOf, F1, tw);
        fdAcc("FrameAcc*TwistAcc", mul, F1, T1);
        fdAcc("FrameAcc*Twist", mul, F1, tw);

        // TwistAcc
        fdAcc("TwistAcc+=", addAssign, T1, T2);
        fdAcc("TwistAcc-=", subAssign, T1, T2);
        fdAcc("TwistAcc*double", mul, T1, s);
        fdAcc("double*TwistAcc", mul, s, T1);
        fdAcc("TwistAcc/double", divide, T1, s);
        fdAcc("TwistAcc*doubleAcc", mul, T1, ds);
        fdAcc("doubleAcc*TwistAcc", mul, ds, T1);
        fdAcc("TwistAcc/doubleAcc", divide, T1, ds);
        fdAcc("TwistAcc+TwistAcc", add, T1, T2);
        fdAcc("TwistAcc-TwistAcc", sub, T1, T2);
        fdAcc("-TwistAcc", neg, T1);
        fdAccSplit("TwistAcc::Zero", [] { return TwistAcc::Zero(); }, [] { return Twist::Zero(); });
        fdAcc("TwistAcc::ReverseSign", reverseSign, T1);
        fdAcc("TwistAcc::RefPoint", refPoint, T1, a);
    }

    // constructors and conversions
    const Vector p = rnd<Vector>(), v = rnd<Vector>(), dv = rnd<Vector>();
    const Rotation R = rnd<Rotation>();
    const Frame F = rnd<Frame>();
    const Twist t = rnd<Twist>(), dt = rnd<Twist>();

    const VectorAcc a0, a1(p), a2(p, v), a3(p, v, dv);
    CHECK(E(a0.p) == Vector3d::Zero() && E(a0.v) == Vector3d::Zero() && E(a0.dv) == Vector3d::Zero());
    CHECK(E(a1.p) == E(p) && E(a1.v) == Vector3d::Zero() && E(a1.dv) == Vector3d::Zero());
    CHECK(E(a2.p) == E(p) && E(a2.v) == E(v) && E(a2.dv) == Vector3d::Zero());
    CHECK(E(a3.p) == E(p) && E(a3.v) == E(v) && E(a3.dv) == E(dv));

    const RotationAcc R0, R1(R), R3(R, v, dv);
    CHECK(E(R0.w) == Vector3d::Zero() && E(R0.dw) == Vector3d::Zero());
    CHECK(E(R1.R) == E(R) && E(R1.w) == Vector3d::Zero() && E(R1.dw) == Vector3d::Zero());
    CHECK(E(R3.R) == E(R) && E(R3.w) == E(v) && E(R3.dw) == E(dv));

    const FrameAcc F0, F1(F), F3(F, t, dt), FParts(R3, a3);
    CHECK(E(F0.p.p) == Vector3d::Zero() && E(F0.M.w) == Vector3d::Zero());
    CHECK(E(val(F1)) == E(F) && E(d1(F1)) == Vector6d::Zero() && E(d2(F1)) == Vector6d::Zero());
    CHECK(E(val(F3)) == E(F) && E(d1(F3)) == E(t) && E(d2(F3)) == E(dt));
    CHECK(E(FParts.M.R) == E(R) && E(FParts.M.w) == E(v) && E(FParts.p.dv) == E(dv));
    CHECK(E(F3.GetFrame()) == E(F) && E(F3.GetTwist()) == E(t) && E(F3.GetAccTwist()) == E(dt));

    const TwistAcc T0, T2(a3, VectorAcc(dv, p, v));
    CHECK(E(val(T0)) == Vector6d::Zero() && E(d1(T0)) == Vector6d::Zero() && E(d2(T0)) == Vector6d::Zero());
    CHECK(E(T2.vel.p) == E(p) && E(T2.vel.dv) == E(dv) && E(T2.rot.p) == E(dv) && E(T2.rot.dv) == E(v));
    CHECK(E(T2.GetTwist()) == E(val(T2)) && E(T2.GetTwistDot()) == E(d1(T2)));
}

void FramesConsistencyTest::TestHelpers()
{
    static const char* const randomNames[] = {
        "double", "Vector", "Twist", "Wrench", "Rotation", "Frame",
        "doubleVel", "VectorVel", "TwistVel", "RotationVel", "FrameVel"};

    for (int i = 0; i < iterations; ++i) {
        // random/posrandom
        checkRandoms<double, Vector, Twist, Wrench, Rotation, Frame,
                     doubleVel, VectorVel, TwistVel, RotationVel, FrameVel>(randomNames);
        double x = rnd(), y = rndPos<double>();
        CHECK(-0.99 <= x && x <= 0.99);
        CHECK(0.001 <= y && y <= 0.991);

        // Equal, ==/!= and hash of every type
        checkComparisons("Vector", rnd<Vector>());
        checkComparisons("Rotation", rnd<Rotation>());
        checkComparisons("Frame", rnd<Frame>());
        checkComparisons("Twist", rnd<Twist>());
        checkComparisons("Wrench", rnd<Wrench>());
        checkComparisons("Vector2", Vector2(rnd(), rnd()));
        checkComparisons("doubleVel", rnd<doubleVel>());
        checkComparisons("VectorVel", rnd<VectorVel>());
        checkComparisons("RotationVel", rnd<RotationVel>());
        checkComparisons("FrameVel", rnd<FrameVel>());
        checkComparisons("TwistVel", rnd<TwistVel>());
        checkComparisons("doubleAcc", rndDoubleAcc());
        checkComparisons("VectorAcc", rndVectorAcc());
        checkComparisons("RotationAcc", rndRotationAcc());
        checkComparisons("FrameAcc", rndFrameAcc());
        checkComparisons("TwistAcc", rndTwistAcc());

        // a double type against the Vel/Acc type with zero derivatives
        const Vector v = rnd<Vector>();
        const Rotation R = rnd<Rotation>();
        const Frame F = rnd<Frame>();
        const Twist t = rnd<Twist>();
        checkEqual("Vector/VectorVel", v, VectorVel(v));
        checkEqual("Rotation/RotationVel", R, RotationVel(R));
        checkEqual("Frame/FrameVel", F, FrameVel(F));
        checkEqual("Twist/TwistVel", t, TwistVel(t));
        checkEqual("Vector/VectorAcc", v, VectorAcc(v));
        checkEqual("Rotation/RotationAcc", R, RotationAcc(R));
        checkEqual("Frame/FrameAcc", F, FrameAcc(F));
        checkEqual("Twist/TwistAcc", t, TwistAcc(VectorAcc(t.vel), VectorAcc(t.rot)));
        checkOperatorEq("Vector/VectorVel", v, VectorVel(v));
        checkOperatorEq("Rotation/RotationVel", R, RotationVel(R));
        checkOperatorEq("Frame/FrameVel", F, FrameVel(F));
        checkOperatorEq("Twist/TwistVel", t, TwistVel(t));

        // Rotation2 and Frame2 keep their data private: perturb through the constructors
        const double a = rndAngle(), c = std::cos(a), s = std::sin(a);
        const Rotation2 r2(c, s);
        const Vector2 p2(rnd(), rnd());
        const Frame2 f2(r2, p2);
        CHECK(Equal(r2, Rotation2(c, s)) && Equal(r2, Rotation2(c, s), tol));
        CHECK(!Equal(r2, Rotation2(c + perturbation, s)) && !Equal(r2, Rotation2(c, s + perturbation)));
        CHECK(Equal(f2, Frame2(r2, p2)) && Equal(f2, Frame2(r2, p2), tol));
        CHECK(!Equal(f2, Frame2(Rotation2(c + perturbation, s), p2)));
        CHECK(!Equal(f2, Frame2(r2, Vector2(p2.x() + perturbation, p2.y()))));
        CHECK(!Equal(f2, Frame2(r2, Vector2(p2.x(), p2.y() + perturbation))));
        CHECK(std::hash<Rotation2>{}(r2) == std::hash<Rotation2>{}(Rotation2(c, s)));
        CHECK(std::hash<Rotation2>{}(r2) != std::hash<Rotation2>{}(Rotation2(a + perturbation)));
        CHECK(std::hash<Frame2>{}(f2) == std::hash<Frame2>{}(Frame2(r2, p2)));
        CHECK(std::hash<Frame2>{}(f2) != std::hash<Frame2>{}(Frame2(Rotation2(a + perturbation), p2)));
        CHECK(std::hash<Frame2>{}(f2) != std::hash<Frame2>{}(Frame2(r2, Vector2(p2.x() + perturbation, p2.y()))));

        // scalar helpers of utility.h
        const double b = rnd(), alfa = rnd(), beta = rnd(), dt = rndScale();
        x = rnd();
        CHECK(Equal(x, x) && Equal(x, x, tol));
        CHECK(!Equal(x, x + perturbation) && !Equal(x + perturbation, x));
        CHECK(Equal(sqr(x), x * x, tol));
        CHECK(sign(x) == (x < 0 ? -1.0 : 1.0));
        CHECK(KDL::max(x, b) == std::max(x, b) && KDL::min(x, b) == std::min(x, b));
        CHECK(Equal(LinComb(alfa, x, beta, b), alfa * x + beta * b, tol));
        double result = 0;
        LinCombR(alfa, x, beta, b, result);
        CHECK(Equal(result, alfa * x + beta * b, tol));
        CHECK(Equal(KDL::Norm(x), std::abs(x), tol));
        CHECK(Equal(diff(x, b, dt), (b - x) / dt, tol));
        CHECK(Equal(addDelta(x, b, dt), x + b * dt, tol));
        CHECK(Equal(addDelta(x, diff(x, b, dt), dt), b, tol));
        y = x;
        SetToZero(y);
        CHECK(y == 0.0);
        SetToIdentity(y);
        CHECK(y == 1.0);
    }
    CHECK(sign(0.0) == 1.0 && sign(-0.0) == 1.0);
}
