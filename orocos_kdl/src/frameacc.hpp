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
typedef Rall2d<double,double,double> doubleAcc;

// Equal is friend function, but default arguments for friends are forbidden (§8.3.6.4)
class FrameAcc;
class RotationAcc;
class VectorAcc;

inline bool Equal(const FrameAcc& r1,const FrameAcc& r2,double eps=epsilon);
inline bool Equal(const Frame& r1,const FrameAcc& r2,double eps=epsilon);
inline bool Equal(const FrameAcc& r1,const Frame& r2,double eps=epsilon);
inline bool Equal(const RotationAcc& r1,const RotationAcc& r2,double eps=epsilon);
inline bool Equal(const Rotation& r1,const RotationAcc& r2,double eps=epsilon);
inline bool Equal(const RotationAcc& r1,const Rotation& r2,double eps=epsilon);
inline bool Equal(const TwistAcc& a,const TwistAcc& b,double eps=epsilon);
inline bool Equal(const Twist& a,const TwistAcc& b,double eps=epsilon);
inline bool Equal(const TwistAcc& a,const Twist& b,double eps=epsilon);
inline bool Equal(const VectorAcc& r1,const VectorAcc& r2,double eps=epsilon);
inline bool Equal(const Vector& r1,const VectorAcc& r2,double eps=epsilon);
inline bool Equal(const VectorAcc& r1,const Vector& r2,double eps=epsilon);


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
    inline VectorAcc& operator += (const VectorAcc& arg);
    inline VectorAcc& operator -= (const VectorAcc& arg);
    inline static VectorAcc Zero();
    inline void ReverseSign();
    inline doubleAcc Norm(double eps=epsilon);
    inline friend VectorAcc operator + (const VectorAcc& r1,const VectorAcc& r2);
    inline friend VectorAcc operator - (const VectorAcc& r1,const VectorAcc& r2);
    inline friend VectorAcc operator + (const Vector& r1,const VectorAcc& r2);
    inline friend VectorAcc operator - (const Vector& r1,const VectorAcc& r2);
    inline friend VectorAcc operator + (const VectorAcc& r1,const Vector& r2);
    inline friend VectorAcc operator - (const VectorAcc& r1,const Vector& r2);
    inline friend VectorAcc operator * (const VectorAcc& r1,const VectorAcc& r2);
    inline friend VectorAcc operator * (const VectorAcc& r1,const Vector& r2);
    inline friend VectorAcc operator * (const Vector& r1,const VectorAcc& r2);
    inline friend VectorAcc operator * (const VectorAcc& r1,double r2);
    inline friend VectorAcc operator * (double r1,const VectorAcc& r2);
    inline friend VectorAcc operator * (const doubleAcc& r1,const VectorAcc& r2);
    inline friend VectorAcc operator * (const VectorAcc& r2,const doubleAcc& r1);
    inline friend VectorAcc operator*(const Rotation& R,const VectorAcc& x);

    inline friend VectorAcc operator / (const VectorAcc& r1,double r2);
    inline friend VectorAcc operator / (const VectorAcc& r2,const doubleAcc& r1);


    inline friend bool Equal(const VectorAcc& r1,const VectorAcc& r2,double eps);
    inline friend bool Equal(const Vector& r1,const VectorAcc& r2,double eps);
    inline friend bool Equal(const VectorAcc& r1,const Vector& r2,double eps);
    inline friend VectorAcc operator - (const VectorAcc& r);
    inline friend doubleAcc dot(const VectorAcc& lhs,const VectorAcc& rhs);
    inline friend doubleAcc dot(const VectorAcc& lhs,const Vector& rhs);
    inline friend doubleAcc dot(const Vector& lhs,const VectorAcc& rhs);
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
    inline RotationAcc Inverse() const;
    inline VectorAcc Inverse(const VectorAcc& arg) const;
    inline VectorAcc Inverse(const Vector& arg) const;
    inline VectorAcc operator*(const VectorAcc& arg) const;
    inline VectorAcc operator*(const Vector& arg) const;

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

    inline friend RotationAcc operator* (const RotationAcc& r1,const RotationAcc& r2);
    inline friend RotationAcc operator* (const Rotation& r1,const RotationAcc& r2);
    inline friend RotationAcc operator* (const RotationAcc& r1,const Rotation& r2);
    inline friend bool Equal(const RotationAcc& r1,const RotationAcc& r2,double eps);
    inline friend bool Equal(const Rotation& r1,const RotationAcc& r2,double eps);
    inline friend bool Equal(const RotationAcc& r1,const Rotation& r2,double eps);
    inline TwistAcc Inverse(const TwistAcc& arg) const;
    inline TwistAcc Inverse(const Twist& arg) const;
    inline TwistAcc operator * (const TwistAcc& arg) const;
    inline TwistAcc operator * (const Twist& arg) const;
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
    inline FrameAcc Inverse() const;
    inline VectorAcc Inverse(const VectorAcc& arg) const;
    inline VectorAcc operator*(const VectorAcc& arg) const;
    inline VectorAcc operator*(const Vector& arg) const;
    inline VectorAcc Inverse(const Vector& arg) const;
    inline Frame GetFrame() const;
    inline Twist GetTwist() const;
    inline Twist GetAccTwist() const;
    inline friend FrameAcc operator * (const FrameAcc& f1,const FrameAcc& f2);
    inline friend FrameAcc operator * (const Frame& f1,const FrameAcc& f2);
    inline friend FrameAcc operator * (const FrameAcc& f1,const Frame& f2);
    inline friend bool Equal(const FrameAcc& r1,const FrameAcc& r2,double eps);
    inline friend bool Equal(const Frame& r1,const FrameAcc& r2,double eps);
    inline friend bool Equal(const FrameAcc& r1,const Frame& r2,double eps);

    inline TwistAcc  Inverse(const TwistAcc& arg) const;
    inline TwistAcc  Inverse(const Twist& arg) const;
    inline TwistAcc operator * (const TwistAcc& arg) const;
    inline TwistAcc operator * (const Twist& arg) const;
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

     inline TwistAcc& operator-=(const TwistAcc& arg);
     inline TwistAcc& operator+=(const TwistAcc& arg);

     inline friend TwistAcc operator*(const TwistAcc& lhs,double rhs);
     inline friend TwistAcc operator*(double lhs,const TwistAcc& rhs);
     inline friend TwistAcc operator/(const TwistAcc& lhs,double rhs);

     inline friend TwistAcc operator*(const TwistAcc& lhs,const doubleAcc& rhs);
     inline friend TwistAcc operator*(const doubleAcc& lhs,const TwistAcc& rhs);
     inline friend TwistAcc operator/(const TwistAcc& lhs,const doubleAcc& rhs);

     inline friend TwistAcc operator+(const TwistAcc& lhs,const TwistAcc& rhs);
     inline friend TwistAcc operator-(const TwistAcc& lhs,const TwistAcc& rhs);
     inline friend TwistAcc operator-(const TwistAcc& arg);

     inline friend void SetToZero(TwistAcc& v);

     static inline TwistAcc Zero();

     inline void ReverseSign();

     inline TwistAcc RefPoint(const VectorAcc& v_base_AB);
     // Changes the reference point of the RTwist.
     // The RVector v_base_AB is expressed in the same base as the RTwist
     // The RVector v_base_AB is a RVector from the old point to
     // the new point.
     // Complexity : 6M+6A

     inline friend bool Equal(const TwistAcc& a,const TwistAcc& b,double eps);
     inline friend bool Equal(const Twist& a,const TwistAcc& b,double eps);
     inline friend bool Equal(const TwistAcc& a,const Twist& b,double eps);


     inline Twist GetTwist() const;
     inline Twist GetTwistDot() const;

    friend class RotationAcc;
    friend class FrameAcc;

};

#include "frameacc.inl"

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
