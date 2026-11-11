/***************************************************************************
                        frames.hpp `-  description
                       -------------------------
    begin                : June 2006
    copyright            : (C) 2006 Erwin Aertbelien
    email                : firstname.lastname@mech.kuleuven.be

 History (only major changes)( AUTHOR-Description ) :

 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/

/**
 * \file
 * \warning
 *       Efficienty can be improved by writing p2 = A*(B*(C*p1))) instead of
 *          p2=A*B*C*p1
 *
 * \par PROPOSED NAMING CONVENTION FOR FRAME-like OBJECTS
 *
 * \verbatim
 *      A naming convention of objects of the type defined in this file :
 *          (1) Frame : F...
 *              Rotation : R ...
 *          (2) Twist    : T ...
 *              Wrench   : W ...
 *              Vector   : V ...
 *      This prefix is followed by :
 *      for category (1) :
 *          F_A_B : w.r.t. frame A, frame B expressed
 *          ( each column of F_A_B corresponds to an axis of B,
 *            expressed w.r.t. frame A )
 *          in mathematical convention :
 *                   A
 *         F_A_B ==    F
 *                   B
 *
 *      for category (2) :
 *          V_B   : a vector expressed w.r.t. frame B
 *
 *      This can also be prepended by a name :
 *          e.g. : temporaryV_B
 *
 *      With this convention one can write :
 *
 *      F_A_B = F_B_A.Inverse();
 *      F_A_C = F_A_B * F_B_C;
 *      V_B   = F_B_C * V_C;    // both translation and rotation
 *      V_B   = R_B_C * V_C;    // only rotation
 * \endverbatim
 *
 * \par CONVENTIONS FOR WHEN USED WITH ROBOTS :
 *
 * \verbatim
 *       world : represents the frame ([1 0 0,0 1 0,0 0 1],[0 0 0]')
 *       mp    : represents mounting plate of a robot
 *               (i.e. everything before MP is constructed by robot manufacturer
 *                    everything after MP is tool )
 *       tf    : represents task frame of a robot
 *               (i.e. frame in which motion and force control is expressed)
 *       sf    : represents sensor frame of a robot
 *               (i.e. frame at which the forces measured by the force sensor
 *               are expressed )
 *
 *          Frame F_world_mp=...;
 *          Frame F_mp_sf(..)
 *          Frame F_mp_tf(,.)
 *
 *          Wrench are measured in sensor frame SF, so one could write :
 *                Wrench_tf = F_mp_tf.Inverse()* ( F_mp_sf * Wrench_sf );
 * \endverbatim
 *
 * \par CONVENTIONS REGARDING UNITS :
 *      Any consistent series of units can be used, e.g. N,mm,Nmm,..mm/sec
 *
 * \par Twist and Wrench transformations
 * 3 different types of transformations do exist for the twists
 * and wrenches.
 *
 * \verbatim
 *      1) Frame * Twist or Frame * Wrench :
 *              this transforms both the velocity/force reference point
 *             and the basis to which the twist/wrench are expressed.
 *      2) Rotation * Twist or Rotation * Wrench :
 *              this transforms the basis to which the twist/wrench are
 *              expressed, but leaves the reference point intact.
 *      3) Twist.RefPoint(v_base_AB) or Wrench.RefPoint(v_base_AB)
 *              this transforms only the reference point. v is expressed
 *              in the same base as the twist/wrench and points from the
 *              old reference point to the new reference point.
 * \endverbatim
 *
 *\par Spatial cross products
 * Let m be a 6D motion vector (Twist) and f be a 6D force vector (Wrench) 
 * attached to a rigid body moving with a certain velocity v (Twist). Then
 *\verbatim
 *     1) m_dot = v cross m or Twist=Twist*Twist
 *     2) f_dot = v cross f or Wrench=Twist*Wrench
 *\endverbatim
 *
 * \par Complexity
 *  Sometimes the amount of work is given in the documentation
 *  e.g. 6M+3A means 6 multiplications and 3 additions.
 *
 *  \author
 *      Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 ****************************************************************************/
#ifndef KDL_FRAMES_H
#define KDL_FRAMES_H


#include "utilities/utility.h"
#include "utilities/hash_combine.h"

#include <cassert>
#include <functional>

/////////////////////////////////////////////////////////////

namespace KDL {


class Vector;
class Rotation;
class Frame;
class Wrench;
class Twist;
class Vector2;
class Rotation2;
class Frame2;


// Equal is friend function, but default arguments for friends are forbidden (§8.3.6.4)
bool Equal(const Vector& a,const Vector& b,double eps=epsilon);
bool Equal(const Frame& a,const Frame& b,double eps=epsilon);
bool Equal(const Twist& a,const Twist& b,double eps=epsilon);
bool Equal(const Wrench& a,const Wrench& b,double eps=epsilon);
bool Equal(const Vector2& a,const Vector2& b,double eps=epsilon);
bool Equal(const Rotation2& a,const Rotation2& b,double eps=epsilon);
bool Equal(const Frame2& a,const Frame2& b,double eps=epsilon);


/**
 * \brief A concrete implementation of a 3 dimensional vector class
 */
class Vector
{
public:
    double data[3];
     //! Does not initialise the Vector to zero. use Vector::Zero() or SetToZero for that
     inline Vector() {data[0]=data[1]=data[2] = 0.0;}

     //! Constructs a vector out of the three values x, y and z
     inline Vector(double x,double y, double z);

     //! Access to elements, range checked when NDEBUG is not set, from 0..2
     inline double operator()(int index) const;

     //! Access to elements, range checked when NDEBUG is not set, from 0..2
     inline double& operator() (int index);

	 //! Equivalent to double operator()(int index) const
     double operator[] ( int index ) const
       {
	 return this->operator() ( index );
       }

	 //! Equivalent to double& operator()(int index)
     double& operator[] ( int index )
       {
	 return this->operator() ( index );
       }

     inline double x() const;
     inline double y() const;
     inline double z() const;
     inline void x(double);
     inline void y(double);
     inline void z(double);

     //! Reverses the sign of the Vector object itself
     inline void ReverseSign();


     //! subtracts a vector from the Vector object itself
     inline Vector& operator-=(const Vector& arg);


     //! Adds a vector from the Vector object itself
     inline Vector& operator +=(const Vector& arg);

     //! Scalar multiplication is defined
     inline friend Vector operator*(const Vector& lhs,double rhs);
     //! Scalar multiplication is defined
     inline friend Vector operator*(double lhs,const Vector& rhs);
     //! Scalar division is defined

     inline friend Vector operator/(const Vector& lhs,double rhs);
     inline friend Vector operator+(const Vector& lhs,const Vector& rhs);
     inline friend Vector operator-(const Vector& lhs,const Vector& rhs);
     inline friend Vector operator*(const Vector& lhs,const Vector& rhs);
     inline friend Vector operator-(const Vector& arg);
     inline friend double dot(const Vector& lhs,const Vector& rhs);

     //! To have a uniform operator to put an element to zero, for scalar values
     //! and for objects.
     inline friend void SetToZero(Vector& v);

     //! @return a zero vector
     inline static Vector Zero();

   /** Normalizes this vector and returns it norm
	* makes v a unitvector and returns the norm of v.
	* if v is smaller than eps, Vector(1,0,0) is returned with norm 0.
	* if this is not good, check the return value of this method.
	*/
     double Normalize(double eps=epsilon);

     //!    @return the norm of the vector
     double Norm(double eps=epsilon) const;



     //! a 3D vector where the 2D vector v is put in the XY plane
     inline void Set2DXY(const Vector2& v);
     //! a 3D vector where the 2D vector v is put in the YZ plane
     inline void Set2DYZ(const Vector2& v);
     //! a 3D vector where the 2D vector v is put in the ZX plane
     inline void Set2DZX(const Vector2& v);
     //! a 3D vector where the 2D vector v_XY is put in the XY plane of the frame F_someframe_XY.
     inline void Set2DPlane(const Frame& F_someframe_XY,const Vector2& v_XY);


     //! do not use operator == because the definition of Equal(.,.) is slightly
     //! different.  It compares whether the 2 arguments are equal in an eps-interval
     friend bool Equal(const Vector& a,const Vector& b,double eps);

	 //! The literal equality operator==(), also identical.
     inline friend bool operator==(const Vector& a,const Vector& b);
	 //! The literal inequality operator!=().
     inline friend bool operator!=(const Vector& a,const Vector& b);

     friend class Rotation;
     friend class Frame;
};


/**
  \brief represents rotations in 3 dimensional space.

  This class represents a rotation matrix with the following
  conventions :
 \verbatim
     Suppose V2 = R*V,                                    (1)
     V is expressed in frame B
     V2 is expressed in frame A
     This matrix R consists of 3 columns [ X,Y,Z ],
     X,Y, and Z contain the axes of frame B, expressed in frame A
     Because of linearity expr(1) is valid.
 \endverbatim
   This class only represents rotational_interpolation, not translation
 Two interpretations are possible for rotation angles.
 * if you rotate with angle around X frame A to have frame B,
   then the result of SetRotX is equal to frame B expressed wrt A.
     In code:
 \verbatim
      Rotation R;
      F_A_B = R.SetRotX(angle);
 \endverbatim
 * Secondly, if you take the following code :
 \verbatim
      Vector p,p2; Rotation R;
      R.SetRotX(angle);
      p2 = R*p;
 \endverbatim
   then the frame p2 is rotated around X axis with (-angle).
   Analogue reasonings can be applyd to SetRotY,SetRotZ,SetRot
 \par type
  Concrete implementation
*/
class Rotation
{
public:
    double data[9];

    inline Rotation() {
		*this = Rotation::Identity();
	}
    inline Rotation(double Xx,double Yx,double Zx,
                double Xy,double Yy,double Zy,
                double Xz,double Yz,double Zz);
    inline Rotation(const Vector& x,const Vector& y,const Vector& z);


     //!  Defines a multiplication R*V between a Rotation R and a Vector V.
     //! Complexity : 9M+6A
     inline Vector operator*(const Vector& v) const;

     //!    Access to elements 0..2,0..2, bounds are checked when NDEBUG is not set
     inline double& operator()(int i,int j);

     //!    Access to elements 0..2,0..2, bounds are checked when NDEBUG is not set
     inline double operator() (int i,int j) const;

     inline friend Rotation operator *(const Rotation& lhs,const Rotation& rhs);

     //! Sets the value of *this to its inverse.
     inline void SetInverse();

     //! Gives back the inverse rotation matrix of *this.
     inline Rotation Inverse() const;

     //! The same as R.Inverse()*v but more efficient.
     inline Vector Inverse(const Vector& v) const;

     //! The same as R.Inverse()*arg but more efficient.
     inline Wrench Inverse(const Wrench& arg) const;

     //! The same as R.Inverse()*arg but more efficient.
     inline Twist Inverse(const Twist& arg) const;

     //! Gives back an identity rotaton matrix
     inline static Rotation Identity();


// = Rotations
    //! The Rot... static functions give the value of the appropriate rotation matrix back.
    static Rotation RotX(double angle);
    //! The Rot... static functions give the value of the appropriate rotation matrix back.
    static Rotation RotY(double angle);
    //! The Rot... static functions give the value of the appropriate rotation matrix back.
    static Rotation RotZ(double angle);
    //! The DoRot... functions apply a rotation R to *this,such that *this = *this * Rot..
    //! DoRot... functions are only defined when they can be executed more efficiently
    void DoRotX(double angle);
    //! The DoRot... functions apply a rotation R to *this,such that *this = *this * Rot..
    //! DoRot... functions are only defined when they can be executed more efficiently
    void DoRotY(double angle);
    //! The DoRot... functions apply a rotation R to *this,such that *this = *this * Rot..
    //! DoRot... functions are only defined when they can be executed more efficiently
    void DoRotZ(double angle);

    //! Along an arbitrary axes.  It is not necessary to normalize rotvec.
    //! returns identity rotation matrix in the case that the norm of rotvec
    //! is to small to be used.
    // @see Rot2 if you want to handle this error in another way.
    static Rotation Rot(const Vector& rotvec,double angle);

    //! Along an arbitrary axes.  rotvec should be normalized.
    static Rotation Rot2(const Vector& rotvec,double angle);

    //! Returns a vector with the direction of the equiv. axis
    //! and its norm is angle
    Vector GetRot() const;

	/** Returns the rotation angle around the equiv. axis
	 * @param axis the rotation axis is returned in this variable
	 * @param eps :  in the case of angle == 0 : rot axis is undefined and chosen
	 *                                         to be +/- Z-axis
	 *               in the case of angle == PI : 2 solutions, positive Z-component
	 *                                            of the axis is chosen.
	 * @result returns the rotation angle (between [0..PI] )
	 */
	double GetRotAngle(Vector& axis,double eps=epsilon) const;


/**     Gives back a rotation matrix specified with EulerZYZ convention :
	 *       - First rotate around Z with alfa,
	 *       - then around the new Y with beta,
	 *	     - then around new Z with gamma.
	 *  Invariants:
	 *  	- EulerZYX(alpha,beta,gamma) == EulerZYX(alpha +/- PHI, -beta, gamma +/- PI)
	 *  	- (angle + 2*k*PI)
	 **/
    static Rotation EulerZYZ(double Alfa,double Beta,double Gamma);

	/** Gives back the EulerZYZ convention description of the rotation matrix :
	 First rotate around Z with alpha,
	 then around the new Y with beta, then around
	 new Z with gamma.

	 Variables are bound by:
	 - (-PI <  alpha  <= PI),
	 - (0   <= beta  <= PI),
	 - (-PI <  gamma <= PI)

	 if beta==0 or beta==PI, then alpha and gamma are not unique, in this case gamma is chosen to be zero.
	 Invariants:
	   - EulerZYX(alpha,beta,gamma) == EulerZYX(alpha +/- PI, -beta, gamma +/- PI)
	   - angle + 2*k*PI
	 */
    void GetEulerZYZ(double& alpha,double& beta,double& gamma) const;

    //! Gives back a rotation matrix specified with Quaternion convention
    //! the norm of (x,y,z,w) should be equal to 1
    static Rotation Quaternion(double x,double y,double z, double w);
    
    //! Get the quaternion of this matrix
    //! \post the norm of (x,y,z,w) is 1
    void GetQuaternion(double& x,double& y,double& z, double& w) const;

    /**
     *
     * Gives back a rotation matrix specified with RPY convention:
     * first rotate around X with roll, then around the
     *              old Y with pitch, then around old Z with yaw
     *
     * Invariants:
     *  - RPY(roll,pitch,yaw) == RPY( roll +/- PI, PI-pitch, yaw +/- PI )
     *  - angles + 2*k*PI
     */
    static Rotation RPY(double roll,double pitch,double yaw);

/**  Gives back a vector in RPY coordinates, variables are bound by
     -  -PI <= roll <= PI
     -   -PI <= Yaw  <= PI
     -  -PI/2 <= PITCH <= PI/2

	 convention :
	 - first rotate around X with roll,
	 - then around the old Y with pitch,
	 - then around old Z with yaw

	 if pitch == PI/2 or pitch == -PI/2, multiple solutions for gamma and alpha exist.  The solution where roll==0
	 is chosen.

	 Invariants:
	 - RPY(roll,pitch,yaw) == RPY( roll +/- PI, PI-pitch, yaw +/- PI )
	 - angles + 2*k*PI

**/
    void GetRPY(double& roll,double& pitch,double& yaw) const;


    /**  EulerZYX constructs a Rotation from the Euler ZYX parameters:
     *   -  First rotate around Z with alfa,
     *   - then around the new Y with beta,
     *   - then around new X with gamma.
     *
     *  Closely related to RPY-convention.
     *
     *  Invariants:
     *  	- EulerZYX(alpha,beta,gamma) == EulerZYX(alpha +/- PI, PI-beta, gamma +/- PI)
     *  	- (angle + 2*k*PI)
     **/
    inline static Rotation EulerZYX(double Alfa,double Beta,double Gamma) {
        return RPY(Gamma,Beta,Alfa);
    }

    /**   GetEulerZYX gets the euler ZYX parameters of a rotation :
     *   First rotate around Z with alfa,
     *   then around the new Y with beta, then around
     *   new X with gamma.
     *
     *  Range of the results of GetEulerZYX :
     *  -  -PI <= alfa <= PI
     *  -   -PI <= gamma <= PI
     *  -  -PI/2 <= beta <= PI/2
     *
     *  if beta == PI/2 or beta == -PI/2, multiple solutions for gamma and alpha exist.  The solution where gamma==0
     *  is chosen.
     *
     *
     *  Invariants:
     *  	- EulerZYX(alpha,beta,gamma) == EulerZYX(alpha +/- PI, PI-beta, gamma +/- PI)
     *  	- and also (angle + 2*k*PI)
     *
     *  Closely related to RPY-convention.
     **/
    inline void GetEulerZYX(double& Alfa,double& Beta,double& Gamma) const {
        GetRPY(Gamma,Beta,Alfa);
    }

     //! Transformation of the base to which the twist is expressed.
     //! Complexity : 18M+12A
     //! @see Frame*Twist for a transformation that also transforms
     //! the velocity reference point.
     inline Twist operator * (const Twist& arg) const;

     //! Transformation of the base to which the wrench is expressed.
     //! Complexity : 18M+12A
     //! @see Frame*Wrench for a transformation that also transforms
     //! the force reference point.
     inline Wrench operator * (const Wrench& arg) const;

     //! Access to the underlying unitvectors of the rotation matrix
     inline Vector UnitX() const {
         return Vector(data[0],data[3],data[6]);
     }

     //! Access to the underlying unitvectors of the rotation matrix
     inline void UnitX(const Vector& X) {
        data[0] = X(0);
        data[3] = X(1);
        data[6] = X(2);
     }

     //! Access to the underlying unitvectors of the rotation matrix
     inline Vector UnitY() const {
         return Vector(data[1],data[4],data[7]);
     }

     //! Access to the underlying unitvectors of the rotation matrix
     inline void UnitY(const Vector& X) {
        data[1] = X(0);
        data[4] = X(1);
        data[7] = X(2);
     }

     //! Access to the underlying unitvectors of the rotation matrix
     inline Vector UnitZ() const {
         return Vector(data[2],data[5],data[8]);
     }

     //! Access to the underlying unitvectors of the rotation matrix
     inline void UnitZ(const Vector& X) {
        data[2] = X(0);
        data[5] = X(1);
        data[8] = X(2);
     }

     //! do not use operator == because the definition of Equal(.,.) is slightly
     //! different.  It compares whether the 2 arguments are equal in an eps-interval
     friend bool Equal(const Rotation& a,const Rotation& b,double eps);

	 //! The literal equality operator==(), also identical.
     inline friend bool operator==(const Rotation& a,const Rotation& b);
	 //! The literal inequality operator!=()
     inline friend bool operator!=(const Rotation& a,const Rotation& b);

     friend class Frame;
};
    inline bool operator==(const Rotation& a,const Rotation& b);
    bool Equal(const Rotation& a,const Rotation& b,double eps=epsilon);



/**
	\brief represents a frame transformation in 3D space (rotation + translation)

    if V2 = Frame*V1 (V2 expressed in frame A, V1 expressed in frame B)
    then V2 = Frame.M*V1+Frame.p

    Frame.M contains columns that represent the axes of frame B wrt frame A
    Frame.p contains the origin of frame B expressed in frame A.
*/
class Frame {
public:
    Vector p;       //!< origine of the Frame
    Rotation M;     //!< Orientation of the Frame

public:

     inline Frame(const Rotation& R,const Vector& V);

     //! The rotation matrix defaults to identity
     explicit inline Frame(const Vector& V);
     //! The position matrix defaults to zero
     explicit inline Frame(const Rotation& R);

     inline Frame() {}
     //! Reads data from an double array
     //\TODO should be formulated as a constructor
     void Make4x4(double* d);

     //!  Treats a frame as a 4x4 matrix and returns element i,j
     //!  Access to elements 0..3,0..3, bounds are checked when NDEBUG is not set
     inline double operator()(int i,int j);

     //!  Treats a frame as a 4x4 matrix and returns element i,j
     //!    Access to elements 0..3,0..3, bounds are checked when NDEBUG is not set
     inline double operator() (int i,int j) const;

// = Inverse
     //! Gives back inverse transformation of a Frame
     inline Frame Inverse() const;

     //! The same as p2=R.Inverse()*p but more efficient.
     inline Vector Inverse(const Vector& arg) const;

     //! The same as p2=R.Inverse()*p but more efficient.
     inline Wrench Inverse(const Wrench& arg) const;

     //! The same as p2=R.Inverse()*p but more efficient.
     inline Twist  Inverse(const Twist& arg) const;


     //! Transformation of the base to which the vector
     //! is expressed.
     inline Vector operator * (const Vector& arg) const;

     //! Transformation of both the force reference point
     //! and of the base to which the wrench is expressed.
     //! look at Rotation*Wrench operator for a transformation
     //! of only the base to which the twist is expressed.
     //!
     //! Complexity : 24M+18A
     inline Wrench operator * (const Wrench& arg) const;

     //! Transformation of both the velocity reference point
     //! and of the base to which the twist is expressed.
     //! look at Rotation*Twist for a transformation of only the
     //! base to which the twist is expressed.
     //!
     //! Complexity : 24M+18A
     inline Twist operator * (const Twist& arg) const;

     //! Composition of two frames.
     inline friend Frame operator *(const Frame& lhs,const Frame& rhs);

     //! @return the identity transformation Frame(Rotation::Identity(),Vector::Zero()).
     inline static Frame Identity();

     //! The twist <t_this> is expressed wrt the current
     //! frame.  This frame is integrated into an updated frame with
     //! <samplefrequency>.  Very simple first order integration rule.
     void Integrate(const Twist& t_this,double frequency);

    /*
    // DH_Craig1989 : constructs a transformationmatrix
    // T_link(i-1)_link(i) with the Denavit-Hartenberg convention as
    // described in the Craigs book: Craig, J. J.,Introduction to
    // Robotics: Mechanics and Control, Addison-Wesley,
    // isbn:0-201-10326-5, 1986.
    //
    // Note that the frame is a redundant way to express the information
    // in the DH-convention.
    // \verbatim
    // Parameters in full : a(i-1),alpha(i-1),d(i),theta(i)
    //
    //  axis i-1 is connected by link i-1 to axis i numbering axis 1
    //  to axis n link 0 (immobile base) to link n
    //
    //  link length a(i-1) length of the mutual perpendicular line
    //  (normal) between the 2 axes.  This normal runs from (i-1) to
    //  (i) axis.
    //
    //  link twist alpha(i-1): construct plane perpendicular to the
    //  normal project axis(i-1) and axis(i) into plane angle from
    //  (i-1) to (i) measured in the direction of the normal
    //
    //  link offset d(i) signed distance between normal (i-1) to (i)
    //  and normal (i) to (i+1) along axis i joint angle theta(i)
    //  signed angle between normal (i-1) to (i) and normal (i) to
    //  (i+1) along axis i
    //
    //   First and last joints : a(0)= a(n) = 0
    //   alpha(0) = alpha(n) = 0
    //
    //   PRISMATIC : theta(1) = 0 d(1) arbitrarily
    //
    //   REVOLUTE : theta(1) arbitrarily d(1) = 0
    //
    //   Not unique : if intersecting joint axis 2 choices for normal
    //   Frame assignment of the DH convention : Z(i-1) follows axis
    //   (i-1) X(i-1) is the normal between axis(i-1) and axis(i)
    //   Y(i-1) follows out of Z(i-1) and X(i-1)
    //
    //     a(i-1)     = distance from Z(i-1) to Z(i) along X(i-1)
    //     alpha(i-1) = angle between Z(i-1) to Z(i) along X(i-1)
    //     d(i)       = distance from X(i-1) to X(i) along Z(i)
    //     theta(i)   = angle between X(i-1) to X(i) along X(i)
    // \endverbatim
    */
     static Frame DH_Craig1989(double a,double alpha,double d,double theta);

    // DH : constructs a transformationmatrix T_link(i-1)_link(i) with
    // the Denavit-Hartenberg convention as described in the original
    // publictation: Denavit, J. and Hartenberg, R. S., A kinematic
    // notation for lower-pair mechanisms based on matrices, ASME
    // Journal of Applied Mechanics, 23:215-221, 1955.

     static Frame DH(double a,double alpha,double d,double theta);


     //! do not use operator == because the definition of Equal(.,.) is slightly
     //! different.  It compares whether the 2 arguments are equal in an eps-interval
     friend bool Equal(const Frame& a,const Frame& b,double eps);

	 //! The literal equality operator==(), also identical.
     inline friend bool operator==(const Frame& a,const Frame& b);
	 //! The literal inequality operator!=().
     inline friend bool operator!=(const Frame& a,const Frame& b);
};


/**
 * \brief represents both translational and rotational velocities.
 *
 * This class represents a twist.  A twist is the combination of translational
 * velocity and rotational velocity applied at one point.
*/
class Twist {
public:
    Vector vel; //!< The velocity of that point
    Vector rot; //!< The rotational velocity of that point.
public:

    //! The default constructor initialises to Zero via the constructor of Vector.
    Twist():vel(),rot() {};

    Twist(const Vector& _vel,const Vector& _rot):vel(_vel),rot(_rot) {};

    inline Twist& operator-=(const Twist& arg);
    inline Twist& operator+=(const Twist& arg);
    //! index-based access to components, first vel(0..2), then rot(3..5)
    inline double& operator()(int i);

    //! index-based access to components, first vel(0..2), then rot(3..5)
    //! For use with a const Twist
    inline double operator()(int i) const;

     double operator[] ( int index ) const
       {
	 return this->operator() ( index );
       }

     double& operator[] ( int index )
       {
	 return this->operator() ( index );
       }

     inline friend Twist operator*(const Twist& lhs,double rhs);
     inline friend Twist operator*(double lhs,const Twist& rhs);
     inline friend Twist operator/(const Twist& lhs,double rhs);
     inline friend Twist operator+(const Twist& lhs,const Twist& rhs);
     inline friend Twist operator-(const Twist& lhs,const Twist& rhs);
     inline friend Twist operator-(const Twist& arg);
     inline friend double dot(const Twist& lhs,const Wrench& rhs);
     inline friend double dot(const Wrench& rhs,const Twist& lhs);
     inline friend void SetToZero(Twist& v);
    /// Spatial cross product for 6d motion vectors, beware all of them have to be expressed in the same reference frame/point
    inline friend Twist operator*(const Twist& lhs,const Twist& rhs);
    /// Spatial cross product for 6d force vectors, beware all of them have to be expressed in the same reference frame/point
    inline friend Wrench operator*(const Twist& lhs,const Wrench& rhs);

     //! @return a zero Twist : Twist(Vector::Zero(),Vector::Zero())
     static inline Twist Zero();

     //! Reverses the sign of the twist
     inline void ReverseSign();

     //! Changes the reference point of the twist.
     //! The vector v_base_AB is expressed in the same base as the twist
     //! The vector v_base_AB is a vector from the old point to
     //! the new point.
     //!
     //! Complexity : 6M+6A
     inline Twist RefPoint(const Vector& v_base_AB) const;


     //! do not use operator == because the definition of Equal(.,.) is slightly
     //! different.  It compares whether the 2 arguments are equal in an eps-interval
     friend bool Equal(const Twist& a,const Twist& b,double eps);

	 //! The literal equality operator==(), also identical.
     inline friend bool operator==(const Twist& a,const Twist& b);
	 //! The literal inequality operator!=().
     inline friend bool operator!=(const Twist& a,const Twist& b);

// = Friends
    friend class Rotation;
    friend class Frame;
};


/**
 * 	\brief represents both translational and rotational acceleration.
 *
 * 	This class represents an acceleration twist.  A acceleration twist is
 * 	the combination of translational
 *	acceleration and rotational acceleration applied at one point.
*/
/*
class AccelerationTwist {
public:
    Vector trans; //!< The translational acceleration of that point
    Vector rot; //!< The rotational acceleration of that point.
public:

    //! The default constructor initialises to Zero via the constructor of Vector.
    AccelerationTwist():trans(),rot() {};

    AccelerationTwist(const Vector& _trans,const Vector& _rot):trans(_trans),rot(_rot) {};

    inline AccelerationTwist& operator-=(const AccelerationTwist& arg);
    inline AccelerationTwist& operator+=(const AccelerationTwist& arg);
    //! index-based access to components, first vel(0..2), then rot(3..5)
    inline double& operator()(int i);

    //! index-based access to components, first vel(0..2), then rot(3..5)
    //! For use with a const AccelerationTwist
    inline double operator()(int i) const;

    double operator[] ( int index ) const
    {
    	return this->operator() ( index );
	}

     double& operator[] ( int index )
     {
    	 return this->operator() ( index );
     }

     inline friend AccelerationTwist operator*(const AccelerationTwist& lhs,double rhs);
     inline friend AccelerationTwist operator*(double lhs,const AccelerationTwist& rhs);
     inline friend AccelerationTwist operator/(const AccelerationTwist& lhs,double rhs);
     inline friend AccelerationTwist operator+(const AccelerationTwist& lhs,const AccelerationTwist& rhs);
     inline friend AccelerationTwist operator-(const AccelerationTwist& lhs,const AccelerationTwist& rhs);
     inline friend AccelerationTwist operator-(const AccelerationTwist& arg);
     //inline friend double dot(const AccelerationTwist& lhs,const Wrench& rhs);
     //inline friend double dot(const Wrench& rhs,const AccelerationTwist& lhs);
     inline friend void SetToZero(AccelerationTwist& v);


     //! @return a zero AccelerationTwist : AccelerationTwist(Vector::Zero(),Vector::Zero())
     static inline AccelerationTwist Zero();

     //! Reverses the sign of the AccelerationTwist
     inline void ReverseSign();

     //! Changes the reference point of the AccelerationTwist.
     //! The vector v_base_AB is expressed in the same base as the AccelerationTwist
     //! The vector v_base_AB is a vector from the old point to
     //! the new point.
     //!
     //! Complexity : 6M+6A
     inline AccelerationTwist RefPoint(const Vector& v_base_AB) const;


     //! do not use operator == because the definition of Equal(.,.) is slightly
     //! different.  It compares whether the 2 arguments are equal in an eps-interval
     inline friend bool Equal(const AccelerationTwist& a,const AccelerationTwist& b,double eps=epsilon);

	 //! The literal equality operator==(), also identical.
     inline friend bool operator==(const AccelerationTwist& a,const AccelerationTwist& b);
	 //! The literal inequality operator!=().
     inline friend bool operator!=(const AccelerationTwist& a,const AccelerationTwist& b);

// = Friends
    friend class Rotation;
    friend class Frame;

};
*/
/**
 * \brief represents the combination of a force and a torque.
 *
 * This class represents a Wrench.  A Wrench is the force and torque applied at a point
 */
class Wrench
{
public:
    Vector force;       //!< Force that is applied at the origin of the current ref frame
    Vector torque;      //!< Torque that is applied at the origin of the current ref frame
public:

    //! Does  initialise force and torque to zero via the underlying constructor of Vector
    Wrench():force(),torque() {};
    Wrench(const Vector& _force,const Vector& _torque):force(_force),torque(_torque) {};

// = Operators
     inline Wrench& operator-=(const Wrench& arg);
     inline Wrench& operator+=(const Wrench& arg);

     //! index-based access to components, first force(0..2), then torque(3..5)
     inline double& operator()(int i);

     //! index-based access to components, first force(0..2), then torque(3..5)
     //! for use with a const Wrench
     inline double operator()(int i) const;

     double operator[] ( int index ) const
       {
	 return this->operator() ( index );
       }

     double& operator[] ( int index )
       {
	 return this->operator() ( index );
       }

     //! Scalar multiplication
     inline friend Wrench operator*(const Wrench& lhs,double rhs);
     //! Scalar multiplication
     inline friend Wrench operator*(double lhs,const Wrench& rhs);
     //! Scalar division
     inline friend Wrench operator/(const Wrench& lhs,double rhs);

     inline friend Wrench operator+(const Wrench& lhs,const Wrench& rhs);
     inline friend Wrench operator-(const Wrench& lhs,const Wrench& rhs);

     //! An unary - operator
     inline friend Wrench operator-(const Wrench& arg);

     //! Sets the Wrench to Zero, to have a uniform function that sets an object or
     //! double to zero.
     inline friend void SetToZero(Wrench& v);

     //! @return a zero Wrench
     static inline Wrench Zero();

     //! Reverses the sign of the current Wrench
     inline void ReverseSign();

     //! Changes the reference point of the wrench.
     //! The vector v_base_AB is expressed in the same base as the twist
     //! The vector v_base_AB is a vector from the old point to
     //! the new point.
     //!
     //! Complexity : 6M+6A
     inline Wrench RefPoint(const Vector& v_base_AB) const;


     //! do not use operator == because the definition of Equal(.,.) is slightly
     //! different.  It compares whether the 2 arguments are equal in an eps-interval
     friend bool Equal(const Wrench& a,const Wrench& b,double eps);

	 //! The literal equality operator==(), also identical.
     inline friend bool operator==(const Wrench& a,const Wrench& b);
	 //! The literal inequality operator!=().
     inline friend bool operator!=(const Wrench& a,const Wrench& b);

    friend class Rotation;
    friend class Frame;
};


//! 2D version of Vector
class Vector2
{
    double data[2];
public:
     //! Does not initialise to Zero().
     Vector2() {data[0]=data[1] = 0.0;}
     inline Vector2(double x,double y);

     //! Access to elements, range checked when NDEBUG is not set, from 0..1
     inline double operator()(int index) const;

     //! Access to elements, range checked when NDEBUG is not set, from 0..1
     inline double& operator() (int index);

    //! Equivalent to double operator()(int index) const
	double operator[] ( int index ) const
	{
		return this->operator() ( index );
	}

	//! Equivalent to double& operator()(int index)
	double& operator[] ( int index )
	{
		return this->operator() ( index );
	}

	inline double x() const;
	inline double y() const;
	inline void x(double);
	inline void y(double);

     inline void ReverseSign();
     inline Vector2& operator-=(const Vector2& arg);
     inline Vector2& operator +=(const Vector2& arg);


     inline friend Vector2 operator*(const Vector2& lhs,double rhs);
     inline friend Vector2 operator*(double lhs,const Vector2& rhs);
     inline friend Vector2 operator/(const Vector2& lhs,double rhs);
     inline friend Vector2 operator+(const Vector2& lhs,const Vector2& rhs);
     inline friend Vector2 operator-(const Vector2& lhs,const Vector2& rhs);
     inline friend Vector2 operator*(const Vector2& lhs,const Vector2& rhs);
     inline friend Vector2 operator-(const Vector2& arg);
     inline friend void SetToZero(Vector2& v);

     //! @return a zero 2D vector.
     inline static Vector2 Zero();

   /** Normalizes this vector and returns it norm
	* makes v a unitvector and returns the norm of v.
	* if v is smaller than eps, Vector(1,0,0) is returned with norm 0.
	* if this is not good, check the return value of this method.
	*/
     double Normalize(double eps=epsilon);

     //!  @return the norm of the vector
     double Norm(double eps=epsilon) const;

     //! projects v in its XY plane, and sets *this to these values
     inline void Set3DXY(const Vector& v);

     //! projects v in its YZ plane, and sets *this to these values
     inline void Set3DYZ(const Vector& v);

     //! projects v in its ZX plane, and sets *this to these values
     inline void Set3DZX(const Vector& v);

     //! projects v_someframe in the XY plane of F_someframe_XY,
     //! and sets *this to these values
     //! expressed wrt someframe.
     inline void Set3DPlane(const Frame& F_someframe_XY,const Vector& v_someframe);


     //! do not use operator == because the definition of Equal(.,.) is slightly
     //! different.  It compares whether the 2 arguments are equal in an eps-interval
     friend bool Equal(const Vector2& a,const Vector2& b,double eps);

	//! The literal equality operator==(), also identical.
	inline friend bool operator==(const Vector2& a,const Vector2& b);
	//! The literal inequality operator!=().
	inline friend bool operator!=(const Vector2& a,const Vector2& b);

    friend class Rotation2;
};


//! A 2D Rotation class, for conventions see Rotation. For further documentation
//! of the methods see Rotation class.
class Rotation2
{
    double s,c;
    //! c,s represent  cos(angle), sin(angle), this also represents first col. of rot matrix
    //! from outside, this class behaves as if it would store the complete 2x2 matrix.
public:
    //! Default constructor does NOT initialise to Zero().
    Rotation2() {c=1.0;s=0.0;}

    explicit Rotation2(double angle_rad):s(sin(angle_rad)),c(cos(angle_rad)) {}

    Rotation2(double ca,double sa):s(sa),c(ca){}

     inline Vector2 operator*(const Vector2& v) const;
     //!    Access to elements 0..1,0..1, bounds are checked when NDEBUG is not set
     inline double operator() (int i,int j) const;

     inline friend Rotation2 operator *(const Rotation2& lhs,const Rotation2& rhs);

     inline void SetInverse();
     inline Rotation2 Inverse() const;
     inline Vector2 Inverse(const Vector2& v) const;

     inline void SetIdentity();
     inline static Rotation2 Identity();


     //! The SetRot.. functions set the value of *this to the appropriate rotation matrix.
     void SetRot(double angle);

     //! The Rot... static functions give the value of the appropriate rotation matrix bac
     static Rotation2 Rot(double angle);

     //! Gets the angle (in radians)
     double GetRot() const;

     //! do not use operator == because the definition of Equal(.,.) is slightly
     //! different.  It compares whether the 2 arguments are equal in an eps-interval
     friend bool Equal(const Rotation2& a,const Rotation2& b,double eps);
};


//! A 2D frame class, for further documentation see the Frames class
//! for methods with unchanged semantics.
class Frame2
 {
public:
    Vector2 p;          //!< origine of the Frame
    Rotation2 M;        //!< Orientation of the Frame

public:

     inline Frame2(const Rotation2& R,const Vector2& V);
     explicit inline Frame2(const Vector2& V);
     explicit inline Frame2(const Rotation2& R);
     inline Frame2(void);
     inline void Make4x4(double* d);

     //!  Treats a frame as a 3x3 matrix and returns element i,j
     //!    Access to elements 0..2,0..2, bounds are checked when NDEBUG is not set
     inline double operator()(int i,int j);

     //!  Treats a frame as a 4x4 matrix and returns element i,j
     //!  Access to elements 0..3,0..3, bounds are checked when NDEBUG is not set
     inline double operator() (int i,int j) const;

     inline void SetInverse();
     inline Frame2 Inverse() const;
     inline Vector2 Inverse(const Vector2& arg) const;
     inline Vector2 operator * (const Vector2& arg) const;
     inline friend Frame2 operator *(const Frame2& lhs,const Frame2& rhs);
     inline void SetIdentity();
     inline void Integrate(const Twist& t_this,double frequency);
     inline static Frame2 Identity() {
        Frame2 tmp;
        tmp.SetIdentity();
        return tmp;
     }
     friend bool Equal(const Frame2& a,const Frame2& b,double eps);
};

/**
 * determines the difference of vector b with vector a.
 *
 * see diff for Rotation matrices for further background information.
 *
 * \param p_w_a start vector a expressed to some frame w
 * \param p_w_b end vector   b expressed to some frame w .
 * \param dt [optional][obsolete] time interval over which the numerical differentiation takes place.
 * \return the difference (b-a) expressed to the frame w.
 */
inline Vector diff(const Vector& p_w_a,const Vector& p_w_b,double dt=1);


/**
 * determines the (scaled) rotation axis necessary to rotate from b1 to b2.  
 *
 * This rotation axis is expressed w.r.t. frame a.  The rotation axis is scaled
 * by the necessary rotation angle. The rotation angle is always in the 
 * (inclusive) interval \f$ [0 , \pi] \f$.
 *
 * This definition is chosen in this way to facilitate numerical differentiation.
 * With this definition diff(a,b) == -diff(b,a).
 *
 * The diff() function is overloaded for all classes in frames.hpp and framesvel.hpp, such that 
 * numerical differentiation, equality checks with tolerances, etc.  can be performed 
 * without caring exactly on which type the operation is performed.  
 *  
 * \param R_a_b1: The rotation matrix \f$ _a^{b1} R  \f$ of b1 with respect to frame a. 
 * \param R_a_b2: The Rotation matrix \f$ _a^{b2} R \f$ of b2 with respect to frame a. 
 * \param dt [optional][obsolete] time interval over which the numerical differentiation takes place. By default this is set to 1.0.
 * \return rotation axis to rotate from b1 to b2, scaled by the rotation angle, expressed in frame a.
 * \warning - The result is not a rotational vector, i.e. it is not a mathematical vector.
 *          (no communitative addition). 
 *
 * \warning - When used in the context of numerical differentiation, with the frames b1 and b2 very
 *           close to each other, the semantics correspond to the twist, scaled by the time. 
 *
 * \warning - For angles equal to \f$ \pi \f$, The negative of the
 *          return value is equally valid. 
 */
Vector diff(const Rotation& R_a_b1,const Rotation& R_a_b2,double dt=1);

/**
 * determines the rotation axis necessary to rotate the frame b1 to the same orientation as frame b2 and the vector
 * necessary to translate the origin of b1 to the origin of b2, and stores the result in a Twist datastructure.   
 * \param F_a_b1 frame b1 expressed with respect to some frame a. 
 * \param F_a_b2 frame b2 expressed with respect to some frame a. 
 * \warning The result is not a Twist!  
 * see diff() for Rotation and Vector arguments for further detail on the semantics.
 */
Twist diff(const Frame& F_a_b1,const Frame& F_a_b2,double dt=1);

/**
 * determines the difference between two twists i.e. the difference between
 * the underlying velocity vectors and rotational velocity vectors. 
 */
inline Twist diff(const Twist& a,const Twist& b,double dt=1);

/**
 * determines the difference between two wrenches i.e. the difference between
 * the underlying torque vectors and force vectors. 
 */
inline Wrench diff(const Wrench& W_a_p1,const Wrench& W_a_p2,double dt=1);

/**
 * \brief adds vector da to vector a.
 * see also the corresponding diff() routine.
 * \param p_w_a vector a expressed to some frame w.
 * \param p_w_da vector da expressed to some frame w.
 * \returns the vector resulting from the displacement of vector a by vector da, expressed in the frame w.
 */
inline Vector addDelta(const Vector& p_w_a,const Vector& p_w_da,double dt=1);

/**
 * returns the rotation matrix resulting from the rotation of frame a by the axis and angle
 * specified with da_w.  
 *
 * see also the corresponding diff() routine.
 *
 * \param R_w_a Rotation matrix of frame a expressed to some frame w.
 * \param da_w  axis and angle of the rotation expressed to some frame w.
 * \returns the rotation matrix resulting from the rotation of frame a by the axis and angle
 *          specified with da.   The resulting rotation matrix is expressed with respect to
 *          frame w.
 */
Rotation addDelta(const Rotation& R_w_a,const Vector& da_w,double dt=1);

/**
 * returns the frame resulting from the rotation of frame a by the axis and angle
 * specified in da_w and the translation of the origin (also specified in da_w). 
 *
 * see also the corresponding diff() routine.
 * \param R_w_a Rotation matrix of frame a expressed to some frame w.
 * \param da_w  axis and angle of the rotation (da_w.rot), together with a displacement vector for the origin (da_w.vel),  expressed to some frame w.
 * \returns the frame resulting from the rotation of frame a by the axis and angle
 *          specified with da.rot, and the translation of the origin da_w.vel .  The resulting frame is expressed with respect to frame w.
 */
Frame addDelta(const Frame& F_w_a,const Twist& da_w,double dt=1);

/**
 * \brief adds the twist da to the twist a.
 * see also the corresponding diff() routine.
 * \param a a twist wrt some frame
 * \param da a twist difference wrt some frame
 * \returns The twist (a+da) wrt the corresponding frame.
 */
inline Twist addDelta(const Twist& a,const Twist&da,double dt=1);


/**
 * \brief adds the wrench da to the wrench w.
 * see also the corresponding diff() routine.
 * see also the corresponding diff() routine.
 * \param a a wrench wrt some frame
 * \param da a wrench difference wrt some frame
 * \returns the wrench (a+da) wrt the corresponding frame.
 */
inline Wrench addDelta(const Wrench& a,const Wrench&da,double dt=1);

inline Vector::Vector(double x,double y, double z)
{
        data[0]=x;data[1]=y;data[2]=z;
}

inline Vector operator +(const Vector & lhs,const Vector& rhs)
{
    Vector tmp;
    tmp.data[0] = lhs.data[0]+rhs.data[0];
    tmp.data[1] = lhs.data[1]+rhs.data[1];
    tmp.data[2] = lhs.data[2]+rhs.data[2];
    return tmp;
}

inline Vector operator -(const Vector & lhs,const Vector& rhs)
{
    Vector tmp;
    tmp.data[0] = lhs.data[0]-rhs.data[0];
    tmp.data[1] = lhs.data[1]-rhs.data[1];
    tmp.data[2] = lhs.data[2]-rhs.data[2];
    return tmp;
}

inline double Vector::x() const { return data[0]; }
inline double Vector::y() const { return data[1]; }
inline double Vector::z() const { return data[2]; }

inline void Vector::x( double _x ) { data[0] = _x; }
inline void Vector::y( double _y ) { data[1] = _y; }
inline void Vector::z( double _z ) { data[2] = _z; }

inline Vector operator *(const Vector& lhs,double rhs) 
{
    Vector tmp;
    tmp.data[0] = lhs.data[0]*rhs;
    tmp.data[1] = lhs.data[1]*rhs;
    tmp.data[2] = lhs.data[2]*rhs;
    return tmp;
}

inline Vector operator *(double lhs,const Vector& rhs) 
{
    Vector tmp;
    tmp.data[0] = lhs*rhs.data[0];
    tmp.data[1] = lhs*rhs.data[1];
    tmp.data[2] = lhs*rhs.data[2];
    return tmp;
}

inline Vector operator /(const Vector& lhs,double rhs) 
{
    Vector tmp;
    tmp.data[0] = lhs.data[0]/rhs;
    tmp.data[1] = lhs.data[1]/rhs;
    tmp.data[2] = lhs.data[2]/rhs;
    return tmp;
}

inline Vector operator *(const Vector & lhs,const Vector& rhs)
// Complexity : 6M+3A
{
    Vector tmp;
    tmp.data[0] = lhs.data[1]*rhs.data[2]-lhs.data[2]*rhs.data[1];
    tmp.data[1] = lhs.data[2]*rhs.data[0]-lhs.data[0]*rhs.data[2];
    tmp.data[2] = lhs.data[0]*rhs.data[1]-lhs.data[1]*rhs.data[0];
    return tmp;
}

inline Vector& Vector::operator +=(const Vector & arg)
// Complexity : 3A
{
    data[0]+=arg.data[0];
    data[1]+=arg.data[1];
    data[2]+=arg.data[2];
    return *this;
}

inline Vector& Vector::operator -=(const Vector & arg)
// Complexity : 3A
{
    data[0]-=arg.data[0];
    data[1]-=arg.data[1];
    data[2]-=arg.data[2];
    return *this;
}

inline Vector Vector::Zero()
{
    return Vector(0,0,0);
}

inline double Vector::operator()(int index) const {
    assert((0<=index)&&(index<=2));
    return data[index];
}

inline double& Vector::operator () (int index)
{
    assert((0<=index)&&(index<=2));
    return data[index];
}

inline Wrench Frame::operator * (const Wrench& arg) const
// Complexity : 24M+18A
{
    Wrench tmp;
    tmp.force  = M*arg.force;
    tmp.torque = M*arg.torque + p*tmp.force;
    return tmp;
}

inline Wrench Frame::Inverse(const Wrench& arg) const
{
    Wrench tmp;
    tmp.force =  M.Inverse(arg.force);
    tmp.torque = M.Inverse(arg.torque-p*arg.force);
    return tmp;
}

inline Wrench Rotation::Inverse(const Wrench& arg) const
{
    return Wrench(Inverse(arg.force),Inverse(arg.torque));
}

inline Twist Rotation::Inverse(const Twist& arg) const
{
    return Twist(Inverse(arg.vel),Inverse(arg.rot));
}

inline Wrench Wrench::Zero()
{
    return Wrench(Vector::Zero(),Vector::Zero());
}

inline void Wrench::ReverseSign()
{   
    torque.ReverseSign();
    force.ReverseSign();
}

inline Wrench Wrench::RefPoint(const Vector& v_base_AB) const
     // Changes the reference point of the Wrench.
     // The vector v_base_AB is expressed in the same base as the twist
     // The vector v_base_AB is a vector from the old point to
     // the new point.
{
    return Wrench(this->force,
                  this->torque+this->force*v_base_AB
                  );
}

inline Wrench& Wrench::operator-=(const Wrench& arg)
{
    torque-=arg.torque;
    force -=arg.force;
    return *this;
}

inline Wrench& Wrench::operator+=(const Wrench& arg)
{
    torque+=arg.torque;
    force +=arg.force;
    return *this;
}

inline double& Wrench::operator()(int i)
{
    // assert((0<=i)&&(i<6)); done by underlying routines
    if (i<3) 
        return force(i);
    else
        return torque(i-3);
}

inline double Wrench::operator()(int i) const
{
    // assert((0<=i)&&(i<6)); done by underlying routines
    if (i<3) 
        return force(i);
    else
        return torque(i-3);
}

inline Wrench operator*(const Wrench& lhs,double rhs)
{
    return Wrench(lhs.force*rhs,lhs.torque*rhs);
}

inline Wrench operator*(double lhs,const Wrench& rhs)
{
    return Wrench(lhs*rhs.force,lhs*rhs.torque);
}

inline Wrench operator/(const Wrench& lhs,double rhs)
{
    return Wrench(lhs.force/rhs,lhs.torque/rhs);
}

// addition of Wrench's
inline Wrench operator+(const Wrench& lhs,const Wrench& rhs)
{
    return Wrench(lhs.force+rhs.force,lhs.torque+rhs.torque);
}

inline Wrench operator-(const Wrench& lhs,const Wrench& rhs)
{
    return Wrench(lhs.force-rhs.force,lhs.torque-rhs.torque);
}

// unary -
inline Wrench operator-(const Wrench& arg) 
{
    return Wrench(-arg.force,-arg.torque);
}

inline Twist Frame::operator * (const Twist& arg) const
// Complexity : 24M+18A
{
    Twist tmp;
    tmp.rot = M*arg.rot;
    tmp.vel = M*arg.vel+p*tmp.rot;
    return tmp;
}
inline Twist Frame::Inverse(const Twist& arg) const
{
    Twist tmp;
    tmp.rot =  M.Inverse(arg.rot);
    tmp.vel = M.Inverse(arg.vel-p*arg.rot);
    return tmp;
}

inline Twist Twist::Zero()
{
    return Twist(Vector::Zero(),Vector::Zero());
}

inline void Twist::ReverseSign()
{   
    vel.ReverseSign();
    rot.ReverseSign();
}

inline Twist Twist::RefPoint(const Vector& v_base_AB) const
     // Changes the reference point of the twist.
     // The vector v_base_AB is expressed in the same base as the twist
     // The vector v_base_AB is a vector from the old point to
     // the new point.
     // Complexity : 6M+6A
{
    return Twist(this->vel+this->rot*v_base_AB,this->rot);
}

inline Twist& Twist::operator-=(const Twist& arg)
{
    vel-=arg.vel;
    rot -=arg.rot;
    return *this;
}

inline Twist& Twist::operator+=(const Twist& arg)
{
    vel+=arg.vel;
    rot +=arg.rot;
    return *this;
}

inline double& Twist::operator()(int i)
{
    // assert((0<=i)&&(i<6)); done by underlying routines
    if (i<3) 
        return vel(i);
    else
        return rot(i-3);
}

inline double Twist::operator()(int i) const
{
    // assert((0<=i)&&(i<6)); done by underlying routines
    if (i<3) 
        return vel(i);
    else
        return rot(i-3);
}

inline Twist operator*(const Twist& lhs,double rhs)
{
    return Twist(lhs.vel*rhs,lhs.rot*rhs);
}

inline Twist operator*(double lhs,const Twist& rhs)
{
    return Twist(lhs*rhs.vel,lhs*rhs.rot);
}

inline Twist operator/(const Twist& lhs,double rhs)
{
    return Twist(lhs.vel/rhs,lhs.rot/rhs);
}

// addition of Twist's
inline Twist operator+(const Twist& lhs,const Twist& rhs)
{
    return Twist(lhs.vel+rhs.vel,lhs.rot+rhs.rot);
}

inline Twist operator-(const Twist& lhs,const Twist& rhs)
{
    return Twist(lhs.vel-rhs.vel,lhs.rot-rhs.rot);
}

// unary -
inline Twist operator-(const Twist& arg) 
{
    return Twist(-arg.vel,-arg.rot);
}

//Spatial products for twists
inline Twist operator*(const Twist& lhs,const Twist& rhs)
{
    return Twist(lhs.rot*rhs.vel+lhs.vel*rhs.rot,lhs.rot*rhs.rot);
}
inline Wrench operator*(const Twist& lhs,const Wrench& rhs)
{
    return Wrench(lhs.rot*rhs.force,lhs.rot*rhs.torque+lhs.vel*rhs.force);
}

inline Frame::Frame(const Rotation & R)
{
    M=R;
    p=Vector::Zero();
}

inline Frame::Frame(const Vector & V)
{
    M = Rotation::Identity();
    p = V;
}

inline Frame::Frame(const Rotation & R, const Vector & V)
{
    M = R;
    p = V;
}

inline Frame operator *(const Frame& lhs,const Frame& rhs)
// Complexity : 36M+36A
{
    return Frame(lhs.M*rhs.M,lhs.M*rhs.p+lhs.p);
}

inline Vector Frame::operator *(const Vector & arg) const
{
    return M*arg+p;
}

inline Vector Frame::Inverse(const Vector& arg) const
{
    return M.Inverse(arg-p);
}

inline Frame Frame::Inverse() const
{
    return Frame(M.Inverse(),-M.Inverse(p));
}

inline void Vector::ReverseSign()
{
    data[0] = -data[0];
    data[1] = -data[1];
    data[2] = -data[2];
}

inline Vector operator-(const Vector & arg)
{
    Vector tmp;
    tmp.data[0]=-arg.data[0];
    tmp.data[1]=-arg.data[1];
    tmp.data[2]=-arg.data[2];
    return tmp;
}

inline void Vector::Set2DXY(const Vector2& v)
// a 3D vector where the 2D vector v is put in the XY plane
{
    data[0]=v(0);
    data[1]=v(1);
    data[2]=0;

}
inline void Vector::Set2DYZ(const Vector2& v)
// a 3D vector where the 2D vector v is put in the YZ plane
{
    data[1]=v(0);
    data[2]=v(1);
    data[0]=0;

}

inline void Vector::Set2DZX(const Vector2& v)
// a 3D vector where the 2D vector v is put in the ZX plane
{
    data[2]=v(0);
    data[0]=v(1);
    data[1]=0;

}

inline double& Rotation::operator()(int i,int j) {
    assert((0<=i)&&(i<=2)&&(0<=j)&&(j<=2));
    return data[i*3+j];
}

inline double Rotation::operator()(int i,int j) const {
    assert((0<=i)&&(i<=2)&&(0<=j)&&(j<=2));
    return data[i*3+j];
}

inline Rotation::Rotation( double Xx,double Yx,double Zx,
                            double Xy,double Yy,double Zy,
                            double Xz,double Yz,double Zz)
{
    data[0] = Xx;data[1]=Yx;data[2]=Zx;
    data[3] = Xy;data[4]=Yy;data[5]=Zy;
    data[6] = Xz;data[7]=Yz;data[8]=Zz;
}

inline Rotation::Rotation(const Vector& x,const Vector& y,const Vector& z) 
{
    data[0] = x.data[0];data[3] = x.data[1];data[6] = x.data[2];
    data[1] = y.data[0];data[4] = y.data[1];data[7] = y.data[2];
    data[2] = z.data[0];data[5] = z.data[1];data[8] = z.data[2];
}

inline Rotation operator *(const Rotation& lhs,const Rotation& rhs)
// Complexity : 27M+27A
{
    return Rotation(
                    lhs.data[0]*rhs.data[0]+lhs.data[1]*rhs.data[3]+lhs.data[2]*rhs.data[6],
                    lhs.data[0]*rhs.data[1]+lhs.data[1]*rhs.data[4]+lhs.data[2]*rhs.data[7],
                    lhs.data[0]*rhs.data[2]+lhs.data[1]*rhs.data[5]+lhs.data[2]*rhs.data[8],
                    lhs.data[3]*rhs.data[0]+lhs.data[4]*rhs.data[3]+lhs.data[5]*rhs.data[6],
                    lhs.data[3]*rhs.data[1]+lhs.data[4]*rhs.data[4]+lhs.data[5]*rhs.data[7],
                    lhs.data[3]*rhs.data[2]+lhs.data[4]*rhs.data[5]+lhs.data[5]*rhs.data[8],
                    lhs.data[6]*rhs.data[0]+lhs.data[7]*rhs.data[3]+lhs.data[8]*rhs.data[6],
                    lhs.data[6]*rhs.data[1]+lhs.data[7]*rhs.data[4]+lhs.data[8]*rhs.data[7],
                    lhs.data[6]*rhs.data[2]+lhs.data[7]*rhs.data[5]+lhs.data[8]*rhs.data[8]
                    );

}

inline Vector Rotation::operator*(const Vector& v) const {
// Complexity : 9M+6A
    return Vector(
     data[0]*v.data[0] + data[1]*v.data[1] + data[2]*v.data[2],
     data[3]*v.data[0] + data[4]*v.data[1] + data[5]*v.data[2],
     data[6]*v.data[0] + data[7]*v.data[1] + data[8]*v.data[2] 
    );
}

inline Twist Rotation::operator * (const Twist& arg) const
     // Transformation of the base to which the twist is expressed.
     // look at Frame*Twist for a transformation that also transforms
     // the velocity reference point.
     // Complexity : 18M+12A
{
    return Twist((*this)*arg.vel,(*this)*arg.rot);
}

inline Wrench Rotation::operator * (const Wrench& arg) const
     // Transformation of the base to which the wrench is expressed.
     // look at Frame*Twist for a transformation that also transforms
     // the force reference point.
{
    return Wrench((*this)*arg.force,(*this)*arg.torque);
}

inline Rotation Rotation::Identity() {
        return Rotation(1,0,0,0,1,0,0,0,1);
}

inline Rotation Rotation::Inverse() const
{
    Rotation tmp(*this);
    tmp.SetInverse();
    return tmp;
}

inline Vector Rotation::Inverse(const Vector& v) const {
    return Vector(
     data[0]*v.data[0] + data[3]*v.data[1] + data[6]*v.data[2],
     data[1]*v.data[0] + data[4]*v.data[1] + data[7]*v.data[2],
     data[2]*v.data[0] + data[5]*v.data[1] + data[8]*v.data[2] 
    );
}

inline void Rotation::SetInverse()
{
    double tmp;
    tmp = data[1];data[1]=data[3];data[3]=tmp;
    tmp = data[2];data[2]=data[6];data[6]=tmp;
    tmp = data[5];data[5]=data[7];data[7]=tmp;
}

inline double Frame::operator()(int i,int j) {
    assert((0<=i)&&(i<=3)&&(0<=j)&&(j<=3));
    if (i==3) {
        if (j==3)
            return 1.0;
        else
            return 0.0;
    } else {
        if (j==3) 
            return p(i);
        else
            return M(i,j);

    }
}

inline double Frame::operator()(int i,int j) const {
    assert((0<=i)&&(i<=3)&&(0<=j)&&(j<=3));
        if (i==3) {
        if (j==3)
            return 1;
        else
            return 0;
    } else {
        if (j==3) 
            return p(i);
        else
            return M(i,j);

    }
}

inline Frame Frame::Identity() {
    return Frame(Rotation::Identity(),Vector::Zero());
}

inline void Vector::Set2DPlane(const Frame& F_someframe_XY,const Vector2& v_XY)
// a 3D vector where the 2D vector v is put in the XY plane of the frame
// F_someframe_XY.
{
Vector tmp_XY;
tmp_XY.Set2DXY(v_XY);
*this = F_someframe_XY*tmp_XY;
}

//============ 2 dimensional version of the frames objects =============
inline Vector2::Vector2(double x,double y)
{
        data[0]=x;data[1]=y;
}

inline Vector2 operator +(const Vector2 & lhs,const Vector2& rhs)
{
    return Vector2(lhs.data[0]+rhs.data[0],lhs.data[1]+rhs.data[1]);
}

inline Vector2 operator -(const Vector2 & lhs,const Vector2& rhs)
{
    return Vector2(lhs.data[0]-rhs.data[0],lhs.data[1]-rhs.data[1]);
}

inline Vector2 operator *(const Vector2& lhs,double rhs) 
{
    return Vector2(lhs.data[0]*rhs,lhs.data[1]*rhs);
}

inline Vector2 operator *(double lhs,const Vector2& rhs) 
{
    return Vector2(lhs*rhs.data[0],lhs*rhs.data[1]);
}

inline Vector2 operator /(const Vector2& lhs,double rhs) 
{
    return Vector2(lhs.data[0]/rhs,lhs.data[1]/rhs);
}

inline Vector2& Vector2::operator +=(const Vector2 & arg)
{
    data[0]+=arg.data[0];
    data[1]+=arg.data[1];
    return *this;
}

inline Vector2& Vector2::operator -=(const Vector2 & arg)
{
    data[0]-=arg.data[0];
    data[1]-=arg.data[1];
    return *this;
}

inline Vector2 Vector2::Zero() {
    return Vector2(0,0);
}

inline double Vector2::operator()(int index) const {
    assert((0<=index)&&(index<=1));
    return data[index];
}

inline double& Vector2::operator () (int index)
{
    assert((0<=index)&&(index<=1));
    return data[index];
}

inline double Vector2::x() const { return data[0]; }
inline double Vector2::y() const { return data[1]; }

inline void Vector2::x( double _x ) { data[0] = _x; }
inline void Vector2::y( double _y ) { data[1] = _y; }

inline void Vector2::ReverseSign()
{
    data[0] = -data[0];
    data[1] = -data[1];
}

inline Vector2 operator-(const Vector2 & arg)
{
    return Vector2(-arg.data[0],-arg.data[1]);
}

inline void Vector2::Set3DXY(const Vector& v)
// projects v in its XY plane, and sets *this to these values
{
    data[0]=v(0);
    data[1]=v(1);
}
inline void Vector2::Set3DYZ(const Vector& v)
// projects v in its XY plane, and sets *this to these values
{
    data[0]=v(1);
    data[1]=v(2);
}
inline void Vector2::Set3DZX(const Vector& v)
// projects v in its XY plane, and sets *this to these values
{
    data[0]=v(2);
    data[1]=v(0);
}

inline void Vector2::Set3DPlane(const Frame& F_someframe_XY,const Vector& v_someframe) 
// projects v in the XY plane of F_someframe_XY, and sets *this to these values
// expressed wrt someframe.
{
    Vector tmp = F_someframe_XY.Inverse(v_someframe);
    data[0]=tmp(0);
    data[1]=tmp(1);
}

inline Vector2 Rotation2::operator*(const Vector2& v) const {
    return Vector2(v.data[0]*c-v.data[1]*s,v.data[0]*s+v.data[1]*c);
}

inline double Rotation2::operator()(int i,int j) const {
    assert((0<=i)&&(i<=1)&&(0<=j)&&(j<=1));
    if (i==j) return c;
    if (i==0) 
        return -s;
    else
        return s;
}

inline Rotation2 operator *(const Rotation2& lhs,const Rotation2& rhs) {
    return Rotation2(lhs.c*rhs.c-lhs.s*rhs.s,lhs.s*rhs.c+lhs.c*rhs.s);
}

inline void Rotation2::SetInverse() {
    s=-s;
}

inline Rotation2 Rotation2::Inverse() const {
    return Rotation2(c,-s);
}

inline Vector2 Rotation2::Inverse(const Vector2& v) const {
    return Vector2(v.data[0]*c+v.data[1]*s,-v.data[0]*s+v.data[1]*c);
}

inline Rotation2 Rotation2::Identity() {
    return Rotation2(1,0);
}

inline void Rotation2::SetIdentity()
{
	c = 1;
	s = 0;
}

inline Frame2::Frame2() {
}

inline Frame2::Frame2(const Rotation2 & R)
{
    M=R;
    p=Vector2::Zero();
}

inline Frame2::Frame2(const Vector2 & V)
{
    M = Rotation2::Identity();
    p = V;
}

inline Frame2::Frame2(const Rotation2 & R, const Vector2 & V)
{
    M = R;
    p = V;
}

inline Frame2 operator *(const Frame2& lhs,const Frame2& rhs)
{
    return Frame2(lhs.M*rhs.M,lhs.M*rhs.p+lhs.p);
}

inline Vector2 Frame2::operator *(const Vector2 & arg) const
{
    return M*arg+p;
}

inline Vector2 Frame2::Inverse(const Vector2& arg) const
{
    return M.Inverse(arg-p);
}

inline void Frame2::SetIdentity()
{
	M.SetIdentity();
	p = Vector2::Zero();
}

inline void Frame2::SetInverse()
{
    M.SetInverse();
    p = M*p;
    p.ReverseSign();
}

inline Frame2 Frame2::Inverse() const
{
    Frame2 tmp(*this);
    tmp.SetInverse();
    return tmp;
}

inline double Frame2::operator()(int i,int j) {
    assert((0<=i)&&(i<=2)&&(0<=j)&&(j<=2));
    if (i==2) {
        if (j==2)
            return 1;
        else
            return 0;
    } else {
        if (j==2) 
            return p(i);
        else
            return M(i,j);

    }
}

inline double Frame2::operator()(int i,int j) const {
    assert((0<=i)&&(i<=2)&&(0<=j)&&(j<=2));
    if (i==2) {
        if (j==2)
            return 1;
        else
            return 0;
    } else {
        if (j==2) 
            return p(i);
        else
            return M(i,j);

    }
}

// Scalar products.

inline double dot(const Vector& lhs,const Vector& rhs) {
    return rhs(0)*lhs(0)+rhs(1)*lhs(1)+rhs(2)*lhs(2);
}

inline double dot(const Twist& lhs,const Wrench& rhs) {
    return dot(lhs.vel,rhs.force)+dot(lhs.rot,rhs.torque);
}

inline double dot(const Wrench& rhs,const Twist& lhs) {
    return dot(lhs.vel,rhs.force)+dot(lhs.rot,rhs.torque);
}

inline void SetToZero(Vector& v) {
    v=Vector::Zero();
}
inline void SetToZero(Twist& v) {
    SetToZero(v.rot);
    SetToZero(v.vel);
}
inline void SetToZero(Wrench& v) {
    SetToZero(v.force);
    SetToZero(v.torque);
}

inline void SetToZero(Vector2& v) {
    v = Vector2::Zero();
}

////////////////////////////////////////////////////////////////
// The following defines the operations
//   diff
//   addDelta
//   random
//   posrandom
// on all the types defined in this library.
// (mostly for uniform integration, differentiation and testing).
// Defined as functions because double is not a class and a method
// would brake uniformity when defined for a double.
////////////////////////////////////////////////////////////////

/**
 * axis_a_b is a rotation vector, its norm is a rotation angle
 * axis_a_b rotates the a frame towards the b frame.
 * This routine returns the rotation matrix R_a_b
 */
Rotation Rot(const Vector& axis_a_b);

inline Vector diff(const Vector& a,const Vector& b,double dt) {
	return (b-a)/dt;
}
inline Twist diff(const Twist& a,const Twist& b,double dt) {
	return Twist(diff(a.vel,b.vel,dt),diff(a.rot,b.rot,dt));
}

inline Wrench diff(const Wrench& a,const Wrench& b,double dt) {
	return Wrench(
			diff(a.force,b.force,dt),
			diff(a.torque,b.torque,dt)
			);
}

inline Vector addDelta(const Vector& a,const Vector&da,double dt) {
	return a+da*dt;
}
inline Twist addDelta(const Twist& a,const Twist&da,double dt) {
	return Twist(addDelta(a.vel,da.vel,dt),addDelta(a.rot,da.rot,dt));
}
inline Wrench addDelta(const Wrench& a,const Wrench&da,double dt) {
	return Wrench(addDelta(a.force,da.force,dt),addDelta(a.torque,da.torque,dt));
}

/**
 * \brief addDelta operator for displacement rotational velocity.
 *
 * The Vector arguments here represent a displacement rotational velocity.  i.e. a rotation
 * around a fixed axis for a certain angle.  For this representation you cannot use diff() but
 * have to use diff_displ().
 *
 * \param a  : displacement rotational velocity
 * \param da : rotational velocity 
 * \return   displacement rotational velocity
 *
 * \warning do not confuse displacement rotational velocities and velocities
 * \warning do not confuse displacement twist and twist.
 *
inline Vector addDelta_displ(const Vector& a,const Vector&da,double dt) {
    return getRot(addDelta(Rot(a),da,dt)); 
}*/

/**
 * \brief addDelta operator for displacement twist.
 *
 * The Vector arguments here represent a displacement rotational velocity.  i.e. a rotation
 * around a fixed axis for a certain angle.  For this representation you cannot use diff() but
 * have to use diff_displ().
 *
 * \param a  : displacement twist 
 * \param da : twist 
 * \return   displacement twist 
 *
 * \warning do not confuse displacement rotational velocities and velocities
 * \warning do not confuse displacement twist and twist.
 *
inline Twist addDelta_displ(const Twist& a,const Twist&da,double dt) {
    return Twist(addDelta(a.vel,da.vel,dt),addDelta_displ(a.rot,da.rot,dt)); 
}*/

void random(Vector& a);
void random(Twist& a);
void random(Wrench& a);
void random(Rotation& R);
void random(Frame& F);
void posrandom(Vector& a);
void posrandom(Twist& a);
void posrandom(Wrench& a);
void posrandom(Rotation& R);
void posrandom(Frame& F);

inline bool operator==(const Frame& a,const Frame& b ) {
    return Equal(a,b);
}

inline bool operator!=(const Frame& a,const Frame& b) {
    return !operator==(a,b);
}

inline bool operator==(const Vector& a,const Vector& b) {
    return Equal(a,b);
     }

inline bool operator!=(const Vector& a,const Vector& b) {
    return !operator==(a,b);
}

inline bool operator==(const Twist& a,const Twist& b) {
    return Equal(a,b);
}

inline bool operator!=(const Twist& a,const Twist& b) {
    return !operator==(a,b);
}

inline bool operator==(const Wrench& a,const Wrench& b ) {
    return Equal(a,b);
}

inline bool operator!=(const Wrench& a,const Wrench& b) {
    return !operator==(a,b);
}

inline bool operator==(const Rotation& a,const Rotation& b) {
    return Equal(a,b);
}
inline bool operator!=(const Rotation& a,const Rotation& b) {
    return !operator==(a,b);
}

inline bool operator==(const Vector2& a,const Vector2& b) {
    return Equal(a,b);
     }

inline bool operator!=(const Vector2& a,const Vector2& b) {
    return !operator==(a,b);
}

}

template<> struct std::hash<KDL::Vector>
{
    std::size_t operator()(KDL::Vector const& v) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, v.x());
        KDL::hash_combine(seed, v.y());
        KDL::hash_combine(seed, v.z());
        return seed;
    }
};

template<> struct std::hash<KDL::Rotation>
{
    std::size_t operator()(KDL::Rotation const& r) const noexcept
    {
        size_t seed = 0;
        double x, y, z, w;
        r.GetQuaternion(x, y, z, w);
        KDL::hash_combine(seed, x);
        KDL::hash_combine(seed, y);
        KDL::hash_combine(seed, z);
        KDL::hash_combine(seed, w);
        return seed;
    }
};

template<> struct std::hash<KDL::Frame>
{
    std::size_t operator()(KDL::Frame const& f) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, f.p);
        KDL::hash_combine(seed, f.M);
        return seed;
    }
};

template<> struct std::hash<KDL::Wrench>
{
    std::size_t operator()(KDL::Wrench const& w) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, w.force);
        KDL::hash_combine(seed, w.torque);
        return seed;
    }
};

template<> struct std::hash<KDL::Twist>
{
    std::size_t operator()(KDL::Twist const& t) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, t.vel);
        KDL::hash_combine(seed, t.rot);
        return seed;
    }
};

template<> struct std::hash<KDL::Vector2>
{
    std::size_t operator()(KDL::Vector2 const& v) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, v.x());
        KDL::hash_combine(seed, v.y());
        return seed;
    }
};

template<> struct std::hash<KDL::Rotation2>
{
    std::size_t operator()(KDL::Rotation2 const& r) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, r.GetRot());
        return seed;
    }
};

template<> struct std::hash<KDL::Frame2>
{
    std::size_t operator()(KDL::Frame2 const& f) const noexcept
    {
        size_t seed = 0;
        KDL::hash_combine(seed, f.p);
        KDL::hash_combine(seed, f.M);
        return seed;
    }
};

#endif
