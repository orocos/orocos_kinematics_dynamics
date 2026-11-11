/*****************************************************************************
 * \file
 *      This file contains the definition of classes for a
 *      Rall Algebra of (subset of) the classes defined in frames,
 *      i.e. classes that contain a set (value,derivative,2nd derivative)
 *      and define operations on that set
 *      this classes are useful for automatic differentiation ( <-> symbolic diff ,
 *      <-> numeric diff).
 *      Defines VectorAcc, RotationAcc, FrameAcc, doubleAcc.
 *      Look at the corresponding classes Vector Rotation Frame Twist and
 *      Wrench for the semantics of the methods.
 *
 *      It also contains the 2nd derivative <-> RFrames.h
 *
 *  \author
 *      Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version
 *      ORO_Geometry V0.2
 *
 *  \par History
 *      - $log$
 *
 *  \par Release
 *      $Id: rrframes.h,v 1.1.1.1 2002/08/26 14:14:21 rmoreas Exp $
 *      $Name:  $
 ****************************************************************************/

#ifndef RRFRAMES_H
#define RRFRAMES_H


#include "utilities/rall2d.h"
#include "frames.hpp"


namespace KDL {

class TwistAcc;
using doubleAcc = Rall2d<double, double, double>;

// Equal is friend function, but default arguments for friends are forbidden (§8.3.6.4)
class FrameAcc;
class RotationAcc;
class VectorAcc;

bool Equal(const FrameAcc& r1,const FrameAcc& r2,double eps=epsilon);
bool Equal(const Frame& r1,const FrameAcc& r2,double eps=epsilon);
bool Equal(const FrameAcc& r1,const Frame& r2,double eps=epsilon);
bool Equal(const RotationAcc& r1,const RotationAcc& r2,double eps=epsilon);
bool Equal(const Rotation& r1,const RotationAcc& r2,double eps=epsilon);
bool Equal(const RotationAcc& r1,const Rotation& r2,double eps=epsilon);
bool Equal(const TwistAcc& a,const TwistAcc& b,double eps=epsilon);
bool Equal(const Twist& a,const TwistAcc& b,double eps=epsilon);
bool Equal(const TwistAcc& a,const Twist& b,double eps=epsilon);
bool Equal(const VectorAcc& r1,const VectorAcc& r2,double eps=epsilon);
bool Equal(const Vector& r1,const VectorAcc& r2,double eps=epsilon);
bool Equal(const VectorAcc& r1,const Vector& r2,double eps=epsilon);


class VectorAcc
{
public:
    Vector p;   //!< position vector
    Vector v;   //!< velocity vector
    Vector dv;  //!< acceleration vector
public:
    VectorAcc():p(),v(),dv() {}
    explicit VectorAcc(const Vector& _p):p(_p),v(Vector::Zero()),dv(Vector::Zero()) {}
    VectorAcc(const Vector& _p,const Vector& _v):p(_p),v(_v),dv(Vector::Zero()) {}
    VectorAcc(const Vector& _p,const Vector& _v,const Vector& _dv):
        p(_p),v(_v),dv(_dv) {}
    inline VectorAcc& operator = (const Vector& arg);
    VectorAcc& operator += (const VectorAcc& arg);
    VectorAcc& operator -= (const VectorAcc& arg);
    inline static VectorAcc Zero();
    inline void ReverseSign();
    //! The norm and its two derivatives; the derivatives are undefined (NaN) when p is exactly zero.
    doubleAcc Norm() const;
    friend VectorAcc operator + (const VectorAcc& r1,const VectorAcc& r2);
    friend VectorAcc operator - (const VectorAcc& r1,const VectorAcc& r2);
    friend VectorAcc operator + (const Vector& r1,const VectorAcc& r2);
    friend VectorAcc operator - (const Vector& r1,const VectorAcc& r2);
    friend VectorAcc operator + (const VectorAcc& r1,const Vector& r2);
    friend VectorAcc operator - (const VectorAcc& r1,const Vector& r2);
    friend VectorAcc operator * (const VectorAcc& r1,const VectorAcc& r2);
    friend VectorAcc operator * (const VectorAcc& r1,const Vector& r2);
    friend VectorAcc operator * (const Vector& r1,const VectorAcc& r2);
    friend VectorAcc operator * (const VectorAcc& r1,double r2);
    friend VectorAcc operator * (double r1,const VectorAcc& r2);
    friend VectorAcc operator * (const doubleAcc& r1,const VectorAcc& r2);
    friend VectorAcc operator * (const VectorAcc& r2,const doubleAcc& r1);
    friend VectorAcc operator*(const Rotation& R,const VectorAcc& x);

    friend VectorAcc operator / (const VectorAcc& r1,double r2);
    friend VectorAcc operator / (const VectorAcc& r2,const doubleAcc& r1);


    friend bool Equal(const VectorAcc& r1,const VectorAcc& r2,double eps);
    friend bool Equal(const Vector& r1,const VectorAcc& r2,double eps);
    friend bool Equal(const VectorAcc& r1,const Vector& r2,double eps);
    inline friend VectorAcc operator - (const VectorAcc& r);
    friend doubleAcc dot(const VectorAcc& lhs,const VectorAcc& rhs);
    friend doubleAcc dot(const VectorAcc& lhs,const Vector& rhs);
    friend doubleAcc dot(const Vector& lhs,const VectorAcc& rhs);
};


class RotationAcc
{
public:
    Rotation R;     //!< rotation matrix
    Vector   w;     //!< angular velocity vector
    Vector   dw;    //!< angular acceration vector
public:
    RotationAcc():R(),w() {}
    explicit RotationAcc(const Rotation& _R):R(_R),w(Vector::Zero()){}
    RotationAcc(const Rotation& _R,const Vector& _w,const Vector& _dw):
        R(_R),w(_w),dw(_dw) {}
    inline RotationAcc& operator = (const Rotation& arg);
    inline static RotationAcc Identity();
    RotationAcc Inverse() const;
    VectorAcc Inverse(const VectorAcc& arg) const;
    VectorAcc Inverse(const Vector& arg) const;
    VectorAcc operator*(const VectorAcc& arg) const;
    VectorAcc operator*(const Vector& arg) const;

    //  Rotations
    // The SetRot.. functions set the value of *this to the appropriate rotation matrix.
    // The Rot... static functions give the value of the appropriate rotation matrix back.
    // The DoRot... functions apply a rotation R to *this,such that *this = *this * R.
    // inline void DoRotX(const doubleAcc& angle);
    // inline void DoRotY(const doubleAcc& angle);
    // inline void DoRotZ(const doubleAcc& angle);
    // inline static RRotation RotX(const doubleAcc& angle);
    // inline static RRotation RotY(const doubleAcc& angle);
    // inline static RRotation RotZ(const doubleAcc& angle);

    // inline void SetRot(const Vector& rotaxis,const doubleAcc& angle);
    // Along an arbitrary axes.  The norm of rotvec is neglected.
    // inline static RotationAcc Rot(const Vector& rotvec,const doubleAcc& angle);
    // rotvec has arbitrary norm
    // rotation around a constant vector !
    // inline static RotationAcc Rot2(const Vector& rotvec,const doubleAcc& angle);
    // rotvec is normalized.
    // rotation around a constant vector !

    friend RotationAcc operator* (const RotationAcc& r1,const RotationAcc& r2);
    friend RotationAcc operator* (const Rotation& r1,const RotationAcc& r2);
    friend RotationAcc operator* (const RotationAcc& r1,const Rotation& r2);
    friend bool Equal(const RotationAcc& r1,const RotationAcc& r2,double eps);
    friend bool Equal(const Rotation& r1,const RotationAcc& r2,double eps);
    friend bool Equal(const RotationAcc& r1,const Rotation& r2,double eps);
    TwistAcc Inverse(const TwistAcc& arg) const;
    TwistAcc Inverse(const Twist& arg) const;
    TwistAcc operator * (const TwistAcc& arg) const;
    TwistAcc operator * (const Twist& arg) const;
};


class FrameAcc
{
public:
    RotationAcc M;   //!< Rotation,angular velocity, and angular acceleration of frame.
    VectorAcc   p;   //!< Translation, velocity and acceleration of origin.
public:
    FrameAcc(){}
    explicit FrameAcc(const Frame& _T):M(_T.M),p(_T.p) {}
    FrameAcc(const Frame& _T,const Twist& _t,const Twist& _dt):
        M(_T.M,_t.rot,_dt.rot),p(_T.p,_t.vel,_dt.vel) {}
    FrameAcc(const RotationAcc& _M,const VectorAcc& _p):M(_M),p(_p) {}

    inline FrameAcc& operator = (const Frame& arg);
    inline static FrameAcc Identity();
    FrameAcc Inverse() const;
    VectorAcc Inverse(const VectorAcc& arg) const;
    VectorAcc operator*(const VectorAcc& arg) const;
    VectorAcc operator*(const Vector& arg) const;
    VectorAcc Inverse(const Vector& arg) const;
    inline Frame GetFrame() const;
    inline Twist GetTwist() const;
    Twist GetAccTwist() const;
    friend FrameAcc operator * (const FrameAcc& f1,const FrameAcc& f2);
    friend FrameAcc operator * (const Frame& f1,const FrameAcc& f2);
    friend FrameAcc operator * (const FrameAcc& f1,const Frame& f2);
    friend bool Equal(const FrameAcc& r1,const FrameAcc& r2,double eps);
    friend bool Equal(const Frame& r1,const FrameAcc& r2,double eps);
    friend bool Equal(const FrameAcc& r1,const Frame& r2,double eps);

    TwistAcc  Inverse(const TwistAcc& arg) const;
    TwistAcc  Inverse(const Twist& arg) const;
    TwistAcc operator * (const TwistAcc& arg) const;
    TwistAcc operator * (const Twist& arg) const;
};


//very similar to Wrench class.
class TwistAcc
{
public:
    VectorAcc vel;       //!< translational velocity and its 1st and 2nd derivative
    VectorAcc rot;       //!< rotational velocity and its 1st and 2nd derivative
public:

     TwistAcc():vel(),rot() {};
     TwistAcc(const VectorAcc& _vel,const VectorAcc& _rot):vel(_vel),rot(_rot) {};

     TwistAcc& operator-=(const TwistAcc& arg);
     TwistAcc& operator+=(const TwistAcc& arg);

     friend TwistAcc operator*(const TwistAcc& lhs,double rhs);
     friend TwistAcc operator*(double lhs,const TwistAcc& rhs);
     friend TwistAcc operator/(const TwistAcc& lhs,double rhs);

     friend TwistAcc operator*(const TwistAcc& lhs,const doubleAcc& rhs);
     friend TwistAcc operator*(const doubleAcc& lhs,const TwistAcc& rhs);
     friend TwistAcc operator/(const TwistAcc& lhs,const doubleAcc& rhs);

     friend TwistAcc operator+(const TwistAcc& lhs,const TwistAcc& rhs);
     friend TwistAcc operator-(const TwistAcc& lhs,const TwistAcc& rhs);
     inline friend TwistAcc operator-(const TwistAcc& arg);

     inline friend void SetToZero(TwistAcc& v);

     static inline TwistAcc Zero();

     inline void ReverseSign();

     TwistAcc RefPoint(const VectorAcc& v_base_AB);
     // Changes the reference point of the RTwist.
     // The RVector v_base_AB is expressed in the same base as the RTwist
     // The RVector v_base_AB is a RVector from the old point to
     // the new point.
     // Complexity : 6M+6A

     friend bool Equal(const TwistAcc& a,const TwistAcc& b,double eps);
     friend bool Equal(const Twist& a,const TwistAcc& b,double eps);
     friend bool Equal(const TwistAcc& a,const Twist& b,double eps);


     inline Twist GetTwist() const;
     Twist GetTwistDot() const;

    friend class RotationAcc;
    friend class FrameAcc;

};

/////////////////// VectorAcc /////////////////////////////////////

VectorAcc operator + (const VectorAcc& r1,const VectorAcc& r2);
VectorAcc operator - (const VectorAcc& r1,const VectorAcc& r2);
VectorAcc operator + (const Vector& r1,const VectorAcc& r2);
VectorAcc operator - (const Vector& r1,const VectorAcc& r2);
VectorAcc operator + (const VectorAcc& r1,const Vector& r2);
VectorAcc operator - (const VectorAcc& r1,const Vector& r2);

// unary -
inline VectorAcc operator - (const VectorAcc& r) {
    return VectorAcc(-r.p,-r.v,-r.dv);
}

// cross prod.
VectorAcc operator * (const VectorAcc& r1,const VectorAcc& r2);
VectorAcc operator * (const VectorAcc& r1,const Vector& r2);
VectorAcc operator * (const Vector& r1,const VectorAcc& r2);

// scalar mult.
VectorAcc operator * (double r1,const VectorAcc& r2);
VectorAcc operator * (const VectorAcc& r1,double r2);
VectorAcc operator * (const doubleAcc& r1,const VectorAcc& r2);
VectorAcc operator * (const VectorAcc& r2,const doubleAcc& r1);

inline VectorAcc& VectorAcc::operator = (const Vector& arg) {
    p=arg;
    v=Vector::Zero();
    dv=Vector::Zero();
    return *this;
}

inline VectorAcc VectorAcc::Zero() {
    return VectorAcc(Vector::Zero(),Vector::Zero(),Vector::Zero());
}

inline void VectorAcc::ReverseSign() {
    p.ReverseSign();
    v.ReverseSign();
    dv.ReverseSign();
}

doubleAcc dot(const VectorAcc& lhs,const VectorAcc& rhs);
doubleAcc dot(const VectorAcc& lhs,const Vector& rhs);
doubleAcc dot(const Vector& lhs,const VectorAcc& rhs);
VectorAcc operator / (const VectorAcc& r1,double r2);
VectorAcc operator / (const VectorAcc& r2,const doubleAcc& r1);

/////////////////// RotationAcc /////////////////////////////////////

RotationAcc operator* (const RotationAcc& r1,const RotationAcc& r2);
RotationAcc operator* (const Rotation& r1,const RotationAcc& r2);
RotationAcc operator* (const RotationAcc& r1,const Rotation& r2);

inline RotationAcc& RotationAcc::operator = (const Rotation& arg) {
    R = arg;
    w = Vector::Zero();
    dw = Vector::Zero();
    return *this;
}

inline RotationAcc RotationAcc::Identity() {
    return RotationAcc(Rotation::Identity(),Vector::Zero(),Vector::Zero());
}

VectorAcc operator*(const Rotation& R,const VectorAcc& x);

// Methods and operators related to FrameAcc
// They all delegate most of the work to RotationAcc and VectorAcc
inline FrameAcc FrameAcc::Identity() {
    return FrameAcc(RotationAcc::Identity(),VectorAcc::Zero());
}

FrameAcc operator *(const FrameAcc& lhs,const FrameAcc& rhs);
FrameAcc operator *(const FrameAcc& lhs,const Frame& rhs);
FrameAcc operator *(const Frame& lhs,const FrameAcc& rhs);

inline FrameAcc& FrameAcc::operator =(const Frame & arg)
{ 
    M = arg.M;
    p = arg.p;
    return *this;
}

inline Frame FrameAcc::GetFrame() const {
    return Frame(M.R,p.p);
}

inline Twist FrameAcc::GetTwist() const {
    return Twist(p.v,M.w);
}

inline TwistAcc TwistAcc::Zero()
{
    return TwistAcc(VectorAcc::Zero(),VectorAcc::Zero());
}

inline void TwistAcc::ReverseSign()
{   
    vel.ReverseSign();
    rot.ReverseSign();
}

TwistAcc operator*(const TwistAcc& lhs,double rhs);
TwistAcc operator*(double lhs,const TwistAcc& rhs);
TwistAcc operator/(const TwistAcc& lhs,double rhs);
TwistAcc operator*(const TwistAcc& lhs,const doubleAcc& rhs);
TwistAcc operator*(const doubleAcc& lhs,const TwistAcc& rhs);
TwistAcc operator/(const TwistAcc& lhs,const doubleAcc& rhs);

// addition of TwistAcc's
TwistAcc operator+(const TwistAcc& lhs,const TwistAcc& rhs);
TwistAcc operator-(const TwistAcc& lhs,const TwistAcc& rhs);

// unary -
inline TwistAcc operator-(const TwistAcc& arg) 
{
    return TwistAcc(-arg.vel,-arg.rot);
}

inline Twist TwistAcc::GetTwist() const {
    return Twist(vel.p,rot.p);
}

} // namespace KDL

template<> struct std::hash<KDL::doubleAcc>
{
    std::size_t operator()(KDL::doubleAcc const& da) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, da.t);
        KDL::hash_combine(seed, da.d);
        KDL::hash_combine(seed, da.dd);
        return seed;
    }
};

template<> struct std::hash<KDL::VectorAcc>
{
    std::size_t operator()(KDL::VectorAcc const& va) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, va.p);
        KDL::hash_combine(seed, va.v);
        KDL::hash_combine(seed, va.dv);
        return seed;
    }
};

template<> struct std::hash<KDL::RotationAcc>
{
    std::size_t operator()(KDL::RotationAcc const& ra) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, ra.R);
        KDL::hash_combine(seed, ra.w);
        KDL::hash_combine(seed, ra.dw);
        return seed;
    }
};

template<> struct std::hash<KDL::FrameAcc>
{
    std::size_t operator()(KDL::FrameAcc const& fa) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, fa.M);
        KDL::hash_combine(seed, fa.p);
        return seed;
    }
};

template<> struct std::hash<KDL::TwistAcc>
{
    std::size_t operator()(KDL::TwistAcc const& ta) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, ta.vel);
        KDL::hash_combine(seed, ta.rot);
        return seed;
    }
};

#endif
