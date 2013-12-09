/***************************************************************************
                        JacobianFrame.h -  description
                       -------------------------
    begin                : June 2006
    copyright            : (C) 2006 Erwin Aertbelien
    email                : firstname.lastname@mech.kuleuven.ac.be

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

#ifndef KDL_JACOBIANFRAME_H
#define KDL_JACOBIANFRAME_H

#include <kdl/jacobianexpr.hpp>
#include <kdl/frames.hpp>
#include <kdl/stiffness.hpp>
 
namespace KDL {


/**
 * \file 
 * \verbatim
 * OPERATIONS :
 *      - Jacobian<Frame> * Jacobian<Frame>      returns Jacobian<Frame>
 *      - Inverse(Jacobian<Frame>)        returns Jacobian<Frame>
 *      - Jacobian<Frame> * Jacobian<Vector>    returns Jacobian<Vector>
 *
 *      - RotX(Jacobian<double>)          returns Jacobian<Rotation>
 *      - RotY(Jacobian<double>)          returns Jacobian<Rotation>
 *      - RotZ(Jacobian<double>)          returns Jacobian<Rotation>
 *      - Inverse(Jacobian<Rotation>)     returns Jacobian<Rotation>
 *      - Jacobian<Rotation>*Jacobian<Rotation> returns Jacobian<Rotation>
 *      
 *      - dot(Jacobian<Vector>, Jacobian<Vector>) returns Jacobian<Vector>(dot-product)
 *      - Jacobian<Vector> * Jacobian<Vector>   returns Jacobian<Vector>  (cross-product)
 *      - Jacobian<Vector> + Jacobian<Vector>   returns Jacobian<Vector> 
 *      - Jacobian<Vector> - Jacobian<Vector>   returns Jacobian<Vector> 
 *      -    - Jacobian<Vector>           returns Jacobian<Vector>
 *      - norm( Jacobian<Vector> )        returns Jacobian<double> represening the norm of the vector
 *
 *      - Jacobian<Vector> * Jacobian<double>   returns Jacobian<Vector>
 *      - Jacobian<double> * Jacobian<Vector>   returns Jacobian<Vector>
 *      
 *      - Origin( Jacobian<Frame> )       returns Jacobian<Vector>
 *      - RotMat( Jacobian<Frame> )       returns Jacobian<Rotation>
 *      - UnitX( Jacobian<Rotation>)      returns Jacobian<Vector>
 *      - UnitY( Jacobian<Rotation>)      returns Jacobian<Vector>
 *      - UnitZ( Jacobian<Rotation>)      returns Jacobian<Vector>
 *      - CoordX( Jacobian<Vector> )      returns Jacobian<double>
 *      - CoordY( Jacobian<Vector> )      returns Jacobian<double>
 *      - CoordZ( Jacobian<Vector> )      returns Jacobian<double>
 *      - Diff( Jacobian<Frame>, Jacobian<Frame>) returns Jacobian<Twist>
 *      - Diff( Jacobian<Rotation>, Jacobian<Rotation> ) returns Jacobian<Rotation>
 *      - Diff( Jacobian<Vector>, Jacobian<Vector>) returns Jacobian<Vector>
 *
 * Jacobian<Wrench> operations.
 *     -Wrench                returns Wrench
 *     Wrench+Wrench           returns Wrench
 *     Wrench-Wrench           returns Wrench
 *     Rotation*Wrench        returns Wrench
 *     Wrench*double          returns Wrench
 *     double*Wrench          returns Wrench
 *     RefPoint(Wrench,Vector) returns Wrench
 *
 * Jacobian<Twist> operations.
 *      -Twist                returns Twist
 *     Twist+Twist           returns Twist
 *     Twist-Twist           returns Twist
 *     Rotation*Twist        returns Twist
 *     Twist*double          returns Twist
 *     double*Twist          returns Twist
 *     RefPoint(Twist,Vector) returns Twist
 *
 * Functions operating on Jacobian<> :
 *   - GetEulerZYX, SetEulerZYX
 *   - GetRPY, SetRPY
 *
 * \endverbatim
 */

/**
 * Inverse :
 *  derivative of R' is (derivative of R)' is [wx]', is [(-w)x]
 *
 *     (1) X2 = R*X1 + p      derivative is   w*X1 + R*X1dot + pdot
 *     (2) X1 = R'*(X2-p)     derivative is   (-w)x X2 + R'* X2dot + w x p - R'*pdot
 * compare (1) to (2) derive :
 *      R2 = R'
 *      p2 = -R'*p
 *      w2 = -w
 *      p2dot = w x p - R'*pdot
 */
template <>
class UnaryOp<OpInverse,Frame> {
public:
    typedef Frame exprType;
	typedef Frame valueType;
	typedef Twist derivType;
	static INLINE2 Frame value(const Frame& F) {
		return F.Inverse();
	}
	static INLINE2 Twist deriv(const Frame& a,const Twist& da) {
		return Twist( a.M.Inverse( da.rot*a.p-da.vel ), -a.M.Inverse( da.rot ) );
	}
};

DEFUNARY_TYPE(Inverse,OpInverse,Ref<Jacobian<Frame> >);

/**
 * When designing this class, I realized some inconsistency between the routines
 * fo transforming a twist (Frame::operator*(const Twist&) and these classes :
 *      Frame1 * Twist2   = velocity component of ( RVFrame2 * RVFrame1)
 *  (mind the order of the arguments ....)
 * The redefinition as Twist2 * Frame1 would make things more consistent, but would
 * break a LOT OF code and naming conventions...
 */

template <>
class BinaryOp<OpMult,Frame,Frame> {
public:
    typedef Frame exprType;
	typedef Frame valueType;
	typedef Twist derivType;
	INLINE2 static Frame value(const Frame& a,const Frame& b)  {
		return a*b;
	}
	INLINE2 static derivType derivVV(const Frame& a,const Twist& da,const Frame& b,const Twist& db) {
		return Twist(
			da.rot*(a.M*b.p)+a.M*db.vel+da.vel,
			da.rot + a.M * db.rot
		);
	}
	INLINE2 static derivType derivCV(const Frame& a,const Frame& /*b*/,const Twist& db) {
		return Twist(
			a.M*db.vel,
			a.M * db.rot
		);
	}
	INLINE2 static derivType derivVC(const Frame& a,const Twist& da,const Frame& b) {
		return Twist(
			da.rot*(a.M*b.p)+da.vel,
			da.rot
		);
	}
};

DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<Frame> >) 
DEFBINARY_LTYPE(operator*,OpMult,Ref<Jacobian<Frame> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<Frame> >,Ref<Jacobian<Frame> >)



template <>
class BinaryOp<OpMult,Frame,Vector> {
public:
    typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	INLINE2 static Vector value(const Frame& a,const Vector& b)  {
		return a*b;
	}

	INLINE2 static derivType derivVV(const Frame& a,const Twist& da,const Vector& b,const Vector& db) {
		return da.rot*(a.M*b)+a.M*db+da.vel;
	}
	INLINE2 static derivType derivCV(const Frame& a,const Vector& ,const Vector& db) {
		return a.M*db;
	}
	INLINE2 static derivType derivVC(const Frame& a,const Twist& da,const Vector& b) {
		return da.rot*(a.M*b)+da.vel;
	}
};
DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<Vector> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<Frame> >,Ref<Jacobian<Vector> >)
// no DEFBINARY_LTYPE, already defined.




template <>
class UnaryOp<OpRotX,double> {
public:
    typedef Rotation exprType;
	typedef Rotation valueType;
	typedef Vector derivType;
	static INLINE2 Rotation value(double angle) {
        return Rotation::RotX(angle);
	}
	static INLINE2 Vector deriv(double ,double da) {
		return Vector(da,0,0);
	}
};
DEFUNARY_TYPE(RotX,OpRotX,Ref<Jacobian<double> >);

template <>
class UnaryOp<OpRotY,double> {
public:
    typedef Rotation exprType;
	typedef Rotation valueType;
	typedef Vector derivType;
	static INLINE2 Rotation value(double angle) {
        return Rotation::RotY(angle);
	}
	static INLINE2 Vector deriv(double ,double da) {
		return Vector(0,da,0);
	}
};
DEFUNARY_TYPE(RotY,OpRotY,Ref<Jacobian<double> >);

template <>
class UnaryOp<OpRotZ,double> {
public:
    typedef Rotation exprType;
	typedef Rotation valueType;
	typedef Vector derivType;
	static INLINE2 Rotation value(double angle) {
        return Rotation::RotZ(angle);
	}
	static INLINE2 Vector deriv(double ,double da) {
		return Vector(0,0,da);
	}
};
DEFUNARY_TYPE(RotZ,OpRotZ,Ref<Jacobian<double> >);


template <>
class UnaryOp<OpInverse,Rotation> {
public:
    typedef Rotation exprType;
	typedef Rotation valueType;
	typedef Vector derivType;
	static INLINE2 Rotation value(const Rotation& R) {
		return R.Inverse();
	}
	static INLINE2 Vector deriv(const Rotation& a,const Vector& da) {
		return a.Inverse(-da);
	}
};

DEFUNARY_TYPE(Inverse,OpInverse,Ref<Jacobian<Rotation> >);

template <>
class BinaryOp<OpMult,Rotation,Rotation> {
public:
    typedef Rotation exprType;
	typedef Rotation valueType;
	typedef Vector derivType;
	INLINE2 static Rotation value(const Rotation& a,const Rotation& b)  {
		return a*b;
	}
	INLINE2 static derivType derivVV(const Rotation& a,const Vector& da,const Rotation& /*b*/,const Vector& db) {
		return 	a*db+da;
	}
	INLINE2 static derivType derivCV(const Rotation& a,const Rotation& /*b*/,const Vector& db) {
		return a*db;
	}
	INLINE2 static derivType derivVC(const Rotation& /*a*/,const Vector& da,const Rotation& /*b*/) {
        return da;
	}
};

DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<Rotation> >) 
DEFBINARY_LTYPE(operator*,OpMult,Ref<Jacobian<Rotation> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<Rotation> >,Ref<Jacobian<Rotation> >)

template <>
class BinaryOp<OpMult,Rotation,Vector> {
public:
    typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	INLINE2 static Vector value(const Rotation& a,const Vector& b)  {
		return a*b;
	}
	INLINE2 static derivType derivVV(const Rotation& a,const Vector& da,const Vector& b,const Vector& db) {
		return 	da*(a*b)+a*db;
	}
	INLINE2 static derivType derivCV(const Rotation& a,const Vector& /*b*/,const Vector& db) {
		return a*db;
	}
	INLINE2 static derivType derivVC(const Rotation& a,const Vector& da,const Vector& b) {
        return da*(a*b);
	}
};

DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<Rotation> >,Ref<Jacobian<Vector> >)



/**
 * operations defined :
 *       VECTOR = Diff(Vector,Vector)
 */
template <>
class BinaryOp<OpDiff,Vector,Vector> {
public:
    typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector   derivType;
	INLINE2 static valueType value(const Vector& a,const Vector& b) {
		return diff(a,b);
	}
	INLINE2 static derivType derivVV(const Vector& /*a*/,const Vector& da,const Vector& /*b*/,const Vector& db) {
		return db-da;
	}
	INLINE2 static derivType derivCV(const Vector& /*a*/,const Vector& /*b*/,const Vector& db) {
		return db;
	}
	INLINE2 static derivType derivVC(const Vector& /*a*/,const Vector& da,const Vector& /*b*/) {
		return -da;
	}
};

DEFBINARY_RTYPE(Diff,OpDiff,Ref<Jacobian<Vector> >) 
DEFBINARY_LTYPE(Diff,OpDiff,Ref<Jacobian<Vector> >) 
DEFBINARY_RLTYPE(Diff,OpDiff,Ref<Jacobian<Vector> >,Ref<Jacobian<Vector> >)



/**
 V* operations defined :
 *       VECTOR = Diff(Rotation,Rotation)
 */
template <>
class BinaryOp<OpDiff,Rotation,Rotation> {
public:
    typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector   derivType;
	INLINE2 static valueType value(const Rotation& a,const Rotation& b) {
		return diff(a,b);
	}
	INLINE2 static derivType derivVV(const Rotation& /*a*/,const Vector& da,const Rotation& /*b*/,const Vector& db) {
		return db-da;
	}
	INLINE2 static derivType derivCV(const Rotation& /*a*/,const Rotation& /*b*/,const Vector& db) {
		return db;
	}
	INLINE2 static derivType derivVC(const Rotation& /*a*/,const Vector& da,const Rotation& /*b*/) {
		return -da;
	}
};

DEFBINARY_RTYPE(Diff,OpDiff,Ref<Jacobian<Rotation> >) 
DEFBINARY_LTYPE(Diff,OpDiff,Ref<Jacobian<Rotation> >) 
DEFBINARY_RLTYPE(Diff,OpDiff,Ref<Jacobian<Rotation> >,Ref<Jacobian<Rotation> >)

/**
 * operations defined :
 *       Twist = Diff(Frame,Frame)
 */
template <>
class BinaryOp<OpDiff,Frame,Frame> {
public:
	typedef Twist exprType;
	typedef Twist valueType;
	typedef Twist derivType;
	INLINE2 static valueType value(const Frame& a,const Frame& b) {
		return diff(a,b);
	}
	INLINE2 static derivType derivVV(const Frame& /*a*/,const Twist& da,const Frame& /*b*/,const Twist& db) {
		return db-da;
	}
	INLINE2 static derivType derivCV(const Frame& /*a*/,const Frame& /*b*/,const Twist& db) {
		return db;
	}
	INLINE2 static derivType derivVC(const Frame& /*a*/,const Twist& da,const Frame& /*b*/) {
		return -da;
	}
};

DEFBINARY_RTYPE(Diff,OpDiff,Ref<Jacobian<Frame> >) 
DEFBINARY_LTYPE(Diff,OpDiff,Ref<Jacobian<Frame> >) 
DEFBINARY_RLTYPE(Diff,OpDiff,Ref<Jacobian<Frame> >,Ref<Jacobian<Frame> >)




/*
 * Operations defined :
 *   VECTOR = VECTOR * VECTOR
 *   VECTOR = VECTOR + VECTOR
 *   VECTOR = VECTOR - VECTOR
 *   DOUBLE = DOT(VECTOR,VECTOR)
 *   VECTOR = - VECTOR
 *
 * For the meaning of the operations, look at the corresponding operations 
 * for the valueTypes.
 */
template <>
class BinaryOp<OpDot,Vector,Vector> {
public:
	typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	INLINE2 static valueType value(const Vector& a,const Vector& b) {
		return dot(a,b);
	}
	INLINE2 static derivType derivVV(const Vector& a,const Vector& da,const Vector& b,const Vector& db) {
		return dot(a,db)+dot(da,b);
	}
	INLINE2 static derivType derivCV(const Vector& a,const Vector& /*b*/,const Vector& db) {
		return dot(a,db);
	}
	INLINE2 static derivType derivVC(const Vector& /*a*/,const Vector& da,const Vector& b) {
		return dot(da,b);
	}
};

DEFBINARY_RTYPE(dot,OpDot,Ref<Jacobian<Vector> >) 
DEFBINARY_LTYPE(dot,OpDot,Ref<Jacobian<Vector> >) 
DEFBINARY_RLTYPE(dot,OpDot,Ref<Jacobian<Vector> >,Ref<Jacobian<Vector> >)

template <>
class BinaryOp<OpMult,Vector,Vector> {
public:
	typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	INLINE2 static valueType value(const Vector& a,const Vector& b) {
		return a*b;
	}
	INLINE2 static derivType derivVV(const Vector& a,const Vector& da,const Vector& b,const Vector& db) {
		return a*db+da*b;
	}
	INLINE2 static derivType derivCV(const Vector& a,const Vector& /*b*/,const Vector& db) {
		return a*db;
	}
	INLINE2 static derivType derivVC(const Vector& /*a*/,const Vector& da,const Vector& b) {
		return da*b;
	}
};
DEFBINARY_LTYPE(operator*,OpMult,Ref<Jacobian<Vector> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<Vector> >,Ref<Jacobian<Vector> >)

template <>
class BinaryOp<OpAdd,Vector,Vector> {
public:
	typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	INLINE2 static valueType value(const valueType& a,const valueType& b) {
		return a+b;
	}
	INLINE2 static derivType derivVV(const valueType& /*a*/,const derivType& da,const valueType& /*b*/,const derivType& db) {
		return da+db;
	}
	INLINE2 static derivType derivCV(const valueType& /*a*/,const valueType& /*b*/,const derivType& db) {
		return db;
	}
	INLINE2 static derivType derivVC(const valueType& /*a*/,const derivType& da,const valueType& /*b*/) {
		return da;
	}
};
DEFBINARY_RTYPE(operator+,OpAdd,Ref<Jacobian<Vector> >) 
DEFBINARY_LTYPE(operator+,OpAdd,Ref<Jacobian<Vector> >) 
DEFBINARY_RLTYPE(operator+,OpAdd,Ref<Jacobian<Vector> >,Ref<Jacobian<Vector> >)



template <>
class BinaryOp<OpSub,Vector,Vector> {
public:
	typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	INLINE2 static valueType value(const valueType& a,const valueType& b) {
		return a-b;
	}
	INLINE2 static derivType derivVV(const valueType& /*a*/,const derivType& da,const valueType& /*b*/,const derivType& db) {
		return da-db;
	}
	INLINE2 static derivType derivCV(const valueType& /*a*/,const valueType& /*b*/,const derivType& db) {
		return -db;
	}
	INLINE2 static derivType derivVC(const valueType& /*a*/,const derivType& da,const valueType& /*b*/) {
		return da;
	}
};
DEFBINARY_RTYPE(operator-,OpSub,Ref<Jacobian<Vector> >) 
DEFBINARY_LTYPE(operator-,OpSub,Ref<Jacobian<Vector> >) 
DEFBINARY_RLTYPE(operator-,OpSub,Ref<Jacobian<Vector> >,Ref<Jacobian<Vector> >)


template <>
class UnaryOp<OpNegate,Vector> {
public:
	typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	static INLINE2 valueType value(const Vector& F) {
		return -F;
	}
	static INLINE2 derivType deriv(const Vector& /*a*/,const Vector& da) {
		return -da;
	}
};
DEFUNARY_TYPE(operator-,OpNegate,Ref< Jacobian<Vector> >)


template <>
class UnaryOp<OpNorm,Vector> {
public:
	typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 valueType value(const Vector& a) {
		return a.Norm();
	}
	static INLINE2 derivType deriv(const Vector& a,const Vector& da) {
		// of course, when norm==0, there exist no derivative,..
		return dot(a,da)/a.Norm();

	}
};
DEFUNARY_TYPE(norm,OpNorm,Ref< Jacobian<Vector> >)




template <>
class BinaryOp<OpMult,Vector,double> {
public:
	typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	INLINE2 static valueType value(const Vector& a,double b) {
		return a*b;
	}
	INLINE2 static derivType derivVV(const Vector& a,const Vector& da,double b,double db) {
		return a*db+da*b;
	}
	INLINE2 static derivType derivCV(const Vector& a,double /*b*/,double db) {
		return a*db;
	}
	INLINE2 static derivType derivVC(const Vector& /*a*/,const Vector& da,double b) {
		return da*b;
	}
};

//DEFBINARY_RTYPE(dot,OpDot,Ref<Jacobian<double> >)  //already defined 
//DEFBINARY_LTYPE(dot,OpDot,Ref<Jacobian<Vector> >)  //already defined 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<Vector> >,Ref<Jacobian<double> >)

template <>
class BinaryOp<OpMult,double,Vector> {
public:
	typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	INLINE2 static valueType value(double a,const Vector& b) {
		return a*b;
	}
	INLINE2 static derivType derivVV(double a,double da,const Vector& b,const Vector& db) {
		return a*db+da*b;
	}
	INLINE2 static derivType derivCV(double a,const Vector& /*b*/,const Vector& db) {
		return a*db;
	}
	INLINE2 static derivType derivVC(double /*a*/,double da,const Vector& b) {
		return da*b;
	}
};

//DEFBINARY_RTYPE(dot,OpDot,Ref<Jacobian<double> >)  //already defined 
//DEFBINARY_LTYPE(dot,OpDot,Ref<Jacobian<Vector> >)  //already defined 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<double> >,Ref<Jacobian<Vector> >)



/***************************************************************/
/*    Some selection of components                             */
/***************************************************************/

template <>
class UnaryOp<OpRotation,Frame> {
public:
	typedef Rotation exprType;
	typedef Rotation valueType;
	typedef Vector derivType;
	static INLINE2 Rotation value(const Frame& F) {
		return F.M;
	}
	static INLINE2 Vector deriv(const Frame& /*a*/,const Twist& da) {
		return da.rot;
	}
};

DEFUNARY_TYPE(RotMat,OpRotation,Ref<Jacobian<Frame> >);



template <>
class UnaryOp<OpOrigin,Frame> {
public:
	typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	static INLINE2 Vector value(const Frame& F) {
		return F.p;
	}
	static INLINE2 Vector deriv(const Frame& /*a*/,const Twist& da) {
		return da.vel;
	}
};

DEFUNARY_TYPE(Origin,OpOrigin,Ref<Jacobian<Frame> >);


template <>
class UnaryOp<OpUnitX,Rotation> {
public:
	typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	static INLINE2 Vector value(const Rotation& R) {
		return R.UnitX();
	}
	static INLINE2 Vector deriv(const Rotation& a,const Vector& da) {
		return da * a.UnitX();
	}
};

DEFUNARY_TYPE(UnitX,OpUnitX,Ref<Jacobian<Rotation> >);

template <>
class UnaryOp<OpUnitY,Rotation> {
public:
	typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	static INLINE2 Vector value(const Rotation& R) {
		return R.UnitY();
	}
	static INLINE2 Vector deriv(const Rotation& a,const Vector& da) {
		return da * a.UnitY();
	}
};

DEFUNARY_TYPE(UnitY,OpUnitY,Ref<Jacobian<Rotation> >);


template <>
class UnaryOp<OpUnitZ,Rotation> {
public:
	typedef Vector exprType;
	typedef Vector valueType;
	typedef Vector derivType;
	static INLINE2 Vector value(const Rotation& R) {
		return R.UnitZ();
	}
	static INLINE2 Vector deriv(const Rotation& a,const Vector& da) {
		return da * a.UnitZ();
	}
};

DEFUNARY_TYPE(UnitZ,OpUnitZ,Ref<Jacobian<Rotation> >);

template <>
class UnaryOp<OpCoordX,Vector> {
public:
	typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 double value(const Vector& a) {
		return a[0];
	}
	static INLINE2 double deriv(const Vector& /*a*/,const Vector& da) {
		return da[0];
	}
};

DEFUNARY_TYPE(CoordX,OpCoordX,Ref<Jacobian<Vector> >);

template <>
class UnaryOp<OpCoordY,Vector> {
public:
	typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 double value(const Vector& a) {
		return a[1];
	}
	static INLINE2 double deriv(const Vector& /*a*/,const Vector& da) {
		return da[1];
	}
};

DEFUNARY_TYPE(CoordY,OpCoordY,Ref<Jacobian<Vector> >);

template <>
class UnaryOp<OpCoordZ,Vector> {
public:
	typedef double exprType;
	typedef double valueType;
	typedef double derivType;
	static INLINE2 double value(const Vector& a) {
		return a[2];
	}
	static INLINE2 double deriv(const Vector& /*a*/,const Vector& da) {
		return da[2];
	}
};

DEFUNARY_TYPE(CoordZ,OpCoordZ,Ref<Jacobian<Vector> >);

/***********************************************************
 * Jacobian<Twist> operations.
 *     -Twist                returns Twist
 *     Twist+Twist           returns Twist
 *     Twist-Twist           returns Twist
 *     Rotation*Twist        returns Twist
 *     Twist*double          returns Twist
 *     double*Twist          returns Twist
 *     RefPoint(Twist,Vector) returns Twist
 ***********************************************************/
template <>
class UnaryOp<OpNegate,Twist> {
public:
	typedef Twist exprType;
	typedef Twist valueType;
	typedef Twist derivType;
	static INLINE2 valueType value(const Twist& F) {
		return -F;
	}
	static INLINE2 derivType deriv(const Twist& /*a*/,const Twist& da) {
		return -da;
	}
};

DEFUNARY_TYPE(operator-,OpNegate,Ref< Jacobian<Twist> >)



template <>
class BinaryOp<OpAdd,Twist,Twist> {
public:
	typedef Twist exprType;
	typedef Twist valueType;
	typedef Twist derivType;
	INLINE2 static valueType value(const Twist& a,const Twist& b)  {
		return a+b;
	}

	INLINE2 static derivType derivVV(const Twist&,const Twist& da,const Twist&,const Twist& db) {
        return da+db;
	}
	INLINE2 static derivType derivCV(const Twist& /*a*/,const Twist& /*b*/,const Twist& db) {
        return db;
	}
	INLINE2 static derivType derivVC(const Twist& /*a*/,const Twist& da,const Twist& /*b*/) {
        return da;
	}
};
DEFBINARY_RTYPE(operator+,OpAdd,Ref<Jacobian<Twist> >) 
DEFBINARY_RLTYPE(operator+,OpAdd,Ref<Jacobian<Twist> >,Ref<Jacobian<Twist> >)


template <>
class BinaryOp<OpSub,Twist,Twist> {
public:
	typedef Twist exprType;
	typedef Twist valueType;
	typedef Twist derivType;
	INLINE2 static valueType value(const Twist& a,const Twist& b)  {
		return a-b;
	}

	INLINE2 static derivType derivVV(const Twist&,const Twist& da,const Twist&,const Twist& db) {
        return da-db;
	}
	INLINE2 static derivType derivCV(const Twist& /*a*/,const Twist& /*b*/,const Twist& db) {
        return -db;
	}
	INLINE2 static derivType derivVC(const Twist& /*a*/,const Twist& da,const Twist& /*b*/) {
        return da;
	}
};
DEFBINARY_RTYPE(operator-,OpSub,Ref<Jacobian<Twist> >) 
DEFBINARY_RLTYPE(operator-,OpSub,Ref<Jacobian<Twist> >,Ref<Jacobian<Twist> >)

template <>
class BinaryOp<OpMult,Rotation,Twist> {
public:
	typedef Twist exprType;
	typedef Twist valueType;
	typedef Twist derivType;
	INLINE2 static valueType value(const Rotation& a,const Twist& b)  {
		return a*b;
	}

	INLINE2 static derivType derivVV(const Rotation& a,const Vector& da,const Twist& b,const Twist& db) {
        return Twist(
            a*db.vel+da*(a*b.vel),
            a*db.rot+da*(a*b.rot)
        );
	}
	INLINE2 static derivType derivCV(const Rotation& a,const Twist& ,const Twist& db) {
        return Twist(
            a*db.vel,
            a*db.rot
        );
	}
	INLINE2 static derivType derivVC(const Rotation& a,const Vector& da,const Twist& b) {
        return Twist(
            da*(a*b.vel),
            da*(a*b.rot)
        );

	}
};
DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<Twist> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<Rotation> >,Ref<Jacobian<Twist> >)
// no DEFBINARY_LTYPE, already defined.

template <>
class BinaryOp<OpMult,Twist,double> {
public:
	typedef Twist exprType;
	typedef Twist valueType;
	typedef Twist derivType;
	INLINE2 static valueType value(const Twist& a,double b)  {
		return a*b;
	}

	INLINE2 static derivType derivVV(const Twist& a,const Twist& da,double b,double db) {
        return a*db+da*b;
	}
	INLINE2 static derivType derivCV(const Twist& a,double /*b*/ ,double db) {
        return a*db;
	}
	INLINE2 static derivType derivVC(const Twist& /*a*/,const Twist& da,double b) {
        return da*b;
	}
};
//DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<double> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<Twist> >,Ref<Jacobian<double> >)


template <>
class BinaryOp<OpMult,double,Twist> {
public:
	typedef Twist exprType;
	typedef Twist valueType;
	typedef Twist derivType;
	INLINE2 static valueType value(double a,const Twist& b)  {
		return a*b;
	}

	INLINE2 static derivType derivVV(double a,double da,const Twist& b,const Twist& db) {
        return a*db+da*b;
	}
	INLINE2 static derivType derivCV(double a,const Twist& /*b*/ ,const Twist& db) {
        return a*db;
	}
	INLINE2 static derivType derivVC(double /*a*/,double da,const Twist& b) {
        return da*b;
	}
};
//DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<double> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<double> >,Ref<Jacobian<Twist> >)

template <>
class BinaryOp<OpRefPoint,Twist,Vector> {
public:
	typedef Twist exprType;
	typedef Twist valueType;
	typedef Twist derivType;
	INLINE2 static valueType value(const Twist& a,const Vector& b)  {
        //return Twist(a.vel+a.rot*b,a.rot);
		return a.RefPoint(b);
	}

	INLINE2 static derivType derivVV(
        const Twist& a,const Twist& da,
        const Vector& b,const Vector& db) 
    {        
        return Twist(
            da.vel + da.rot*b + a.rot*db,
            da.rot
        );
	}
	INLINE2 static derivType derivCV(const Twist& a,const Vector& /*b*/ ,const Vector& db) {
        return Twist(
            a.rot*db,
            Vector::Zero()
        );
	}
	INLINE2 static derivType derivVC(const Twist& /*a*/,const Twist& da,const Vector& b) {
        return Twist(
            da.vel + da.rot*b,
            da.rot
        );
	}
};

DEFBINARY_LTYPE(RefPoint,OpRefPoint,Ref<Jacobian<Twist> >) 
DEFBINARY_RTYPE(RefPoint,OpRefPoint,Ref<Jacobian<Vector> >) 
DEFBINARY_RLTYPE(RefPoint,OpRefPoint,Ref<Jacobian<Twist> >,Ref<Jacobian<Vector> >)

/***********************************************************
 * Jacobian<Wrench> operations.
 *     -Wrench                returns Wrench
 *     Wrench+Wrench           returns Wrench
 *     Wrench-Wrench           returns Wrench
 *     Rotation*Wrench        returns Wrench
 *     Wrench*double          returns Wrench
 *     double*Wrench          returns Wrench
 *     RefPoint(Wrench,Vector) returns Wrench
 ***********************************************************/
template <>
class UnaryOp<OpNegate,Wrench> {
public:
	typedef Wrench exprType;
	typedef Wrench valueType;
	typedef Wrench derivType;
	static INLINE2 valueType value(const Wrench& F) {
		return -F;
	}
	static INLINE2 derivType deriv(const Wrench& /*a*/,const Wrench& da) {
		return -da;
	}
};

DEFUNARY_TYPE(operator-,OpNegate,Ref< Jacobian<Wrench> >)



template <>
class BinaryOp<OpAdd,Wrench,Wrench> {
public:
	typedef Wrench exprType;
	typedef Wrench valueType;
	typedef Wrench derivType;
	INLINE2 static valueType value(const Wrench& a,const Wrench& b)  {
		return a+b;
	}

	INLINE2 static derivType derivVV(const Wrench&,const Wrench& da,const Wrench&,const Wrench& db) {
        return da+db;
	}
	INLINE2 static derivType derivCV(const Wrench& /*a*/,const Wrench& /*b*/,const Wrench& db) {
        return db;
	}
	INLINE2 static derivType derivVC(const Wrench& /*a*/,const Wrench& da,const Wrench& /*b*/) {
        return da;
	}
};
DEFBINARY_RTYPE(operator+,OpAdd,Ref<Jacobian<Wrench> >) 
DEFBINARY_RLTYPE(operator+,OpAdd,Ref<Jacobian<Wrench> >,Ref<Jacobian<Wrench> >)


template <>
class BinaryOp<OpSub,Wrench,Wrench> {
public:
	typedef Wrench exprType;
	typedef Wrench valueType;
	typedef Wrench derivType;
	INLINE2 static valueType value(const Wrench& a,const Wrench& b)  {
		return a-b;
	}

	INLINE2 static derivType derivVV(const Wrench&,const Wrench& da,const Wrench&,const Wrench& db) {
        return da-db;
	}
	INLINE2 static derivType derivCV(const Wrench& /*a*/,const Wrench& /*b*/,const Wrench& db) {
        return -db;
	}
	INLINE2 static derivType derivVC(const Wrench& /*a*/,const Wrench& da,const Wrench& /*b*/) {
        return da;
	}
};
DEFBINARY_RTYPE(operator-,OpSub,Ref<Jacobian<Wrench> >) 
DEFBINARY_RLTYPE(operator-,OpSub,Ref<Jacobian<Wrench> >,Ref<Jacobian<Wrench> >)

template <>
class BinaryOp<OpMult,Rotation,Wrench> {
public:
	typedef Wrench exprType;
	typedef Wrench valueType;
	typedef Wrench derivType;
	INLINE2 static valueType value(const Rotation& a,const Wrench& b)  {
		return a*b;
	}

	INLINE2 static derivType derivVV(const Rotation& a,const Vector& da,const Wrench& b,const Wrench& db) {
        return Wrench(
            a*db.force+da*(a*b.force),
            a*db.torque+da*(a*b.torque)
        );
	}
	INLINE2 static derivType derivCV(const Rotation& a,const Wrench& ,const Wrench& db) {
        return Wrench(
            a*db.force,
            a*db.torque
        );
	}
	INLINE2 static derivType derivVC(const Rotation& a,const Vector& da,const Wrench& b) {
        return Wrench(
            da*(a*b.force),
            da*(a*b.torque)
        );

	}
};
DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<Wrench> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<Rotation> >,Ref<Jacobian<Wrench> >)
// no DEFBINARY_LTYPE, already defined.

template <>
class BinaryOp<OpMult,Wrench,double> {
public:
	typedef Wrench exprType;
	typedef Wrench valueType;
	typedef Wrench derivType;
	INLINE2 static valueType value(const Wrench& a,double b)  {
		return a*b;
	}

	INLINE2 static derivType derivVV(const Wrench& a,const Wrench& da,double b,double db) {
        return a*db+da*b;
	}
	INLINE2 static derivType derivCV(const Wrench& a,double /*b*/ ,double db) {
        return a*db;
	}
	INLINE2 static derivType derivVC(const Wrench& /*a*/,const Wrench& da,double b) {
        return da*b;
	}
};
//DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<double> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<Wrench> >,Ref<Jacobian<double> >)


template <>
class BinaryOp<OpMult,double,Wrench> {
public:
	typedef Wrench exprType;
	typedef Wrench valueType;
	typedef Wrench derivType;
	INLINE2 static valueType value(double a,const Wrench& b)  {
		return a*b;
	}

	INLINE2 static derivType derivVV(double a,double da,const Wrench& b,const Wrench& db) {
        return a*db+da*b;
	}
	INLINE2 static derivType derivCV(double a,const Wrench& /*b*/ ,const Wrench& db) {
        return a*db;
	}
	INLINE2 static derivType derivVC(double /*a*/,double da,const Wrench& b) {
        return da*b;
	}
};
//DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<double> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Jacobian<double> >,Ref<Jacobian<Wrench> >)

template <>
class BinaryOp<OpRefPoint,Wrench,Vector> {
public:
	typedef Wrench exprType;
	typedef Wrench valueType;
	typedef Wrench derivType;
	INLINE2 static valueType value(const Wrench& a,const Vector& b)  {
        // return Wrench(a.force, a.torque+ a.force* b)
		return a.RefPoint(b);
	}

	INLINE2 static derivType derivVV(
        const Wrench& a,const Wrench& da,
        const Vector& b,const Vector& db) 
    {        
        return Wrench(
            da.force,
            da.torque + da.force*b + a.force*db
        );
	}
	INLINE2 static derivType derivCV(const Wrench& a,const Vector& /*b*/ ,const Vector& db) {
        return Wrench(
            Vector::Zero(),
            a.force*db
        );
    }
	INLINE2 static derivType derivVC(const Wrench& /*a*/,const Wrench& da,const Vector& b) {
        return Wrench(
            da.force,
            da.torque + da.force*b 
        );
    }
};

DEFBINARY_LTYPE(RefPoint,OpRefPoint,Ref<Jacobian<Wrench> >) 
//DEFBINARY_RTYPE(RefPoint,OpRefPoint,Ref<Jacobian<Vector> >) 
DEFBINARY_RLTYPE(RefPoint,OpRefPoint,Ref<Jacobian<Wrench> >,Ref<Jacobian<Vector> >)


/**
 * STIFNESS RELATED OPERATIONS :
 */

template <>
class BinaryOp<OpMult,Stiffness,Twist> {
public:
	typedef Wrench exprType;
	typedef Wrench valueType;
	typedef Wrench derivType;
	INLINE2 static valueType value(const Stiffness& a,const Twist& b)  {
        // return Wrench(a.force, a.torque+ a.force* b)
		return a*b;
	}

	INLINE2 static derivType derivVV(
        const Stiffness& a,const Stiffness& da,
        const Twist& b,const Twist& db) 
    {        
        //assert(false);
		return a*db+da*b;
	}
	INLINE2 static derivType derivCV(const Stiffness& a,const Twist& /*b*/ ,const Twist& db) {
        return a*db;
    }
	INLINE2 static derivType derivVC(const Stiffness& /*a*/,const Stiffness& da,const Twist& b) {
        //assert(false);
		return da*b;
    }
};

DEFBINARY_LTYPE(operator*,OpMult,Ref<Cnst<Stiffness> >) 
//DEFBINARY_RTYPE(operator*,OpMult,Ref<Jacobian<Twist> >) 
DEFBINARY_RLTYPE(operator*,OpMult,Ref<Cnst<Stiffness> >,Ref<Jacobian<Twist> >)



template <>
class BinaryOp<OpInverse,Stiffness,Wrench> {
public:
	typedef Twist exprType;
	typedef Twist valueType;
	typedef Twist derivType;
	INLINE2 static valueType value(const Stiffness& a,const Wrench& b)  {
        // return Wrench(a.force, a.torque+ a.force* b)
		return a.Inverse(b);
	}

	INLINE2 static derivType derivVV(
        const Stiffness& /*a*/,const Stiffness& da,
        const Wrench& b,const Wrench& /*db*/) 
    {        
        //assert(false);
		return da.Inverse(b);
	}
	INLINE2 static derivType derivCV(const Stiffness& a,const Wrench& /*b*/ ,const Wrench& db) {
        return a.Inverse(db);
    }
	INLINE2 static derivType derivVC(const Stiffness& /*a*/,const Stiffness& da,const Wrench& b) {
        //assert(false);
		return da.Inverse(b);
    }
};

//DEFBINARY_LTYPE(Inverse,OpInverse,Ref<Cnst<Stiffness> >) 
//DEFBINARY_RTYPE(Inverse,OpInverse,Ref<Jacobian<Wrench> >) 
DEFBINARY_RLTYPE(Inverse,OpInverse,Ref<Cnst<Stiffness> >,Ref<Jacobian<Wrench> >)




/**
 * \brief function to get the euler zyx angles. 
 * \param JR input parameter that indicates the Rotation and Jacobian with the rotational velocities.
 * \param gamma output parameter will contain the amount of rotation around X.  
 * \param beta output parameter will contain the amount of rotation around Y.
 * \param alpha output parameter will contain the amount of rotation around Z.
 * \retval 0 if successfull, otherwise its a singular situation.
 */
 int GetEulerZYX(const Jacobian<Rotation>& JR, 
				  Jacobian<double>& gamma, 
				  Jacobian<double>& beta, 
				  Jacobian<double>& alpha,
				  double eps=epsilon);


/**
 * \brief funcion to set the euler zyx angles. 
 * \param gamma input parameter that contains the amount of rotation around X.  
 * \param beta input parameter that contains the amount of rotation around Y.
 * \param alpha output parameter that contains the amount of rotation around Z.
 * \param JR output parameter that will contain the Rotation and Jacobian with the rotational velocities.
 */
 void SetEulerZYX(const Jacobian<double>& gamma, 
				  const Jacobian<double>& beta, 
				  const Jacobian<double>& alpha,
 				  Jacobian<Rotation>& JR);
/**
 * \brief function to get the rpy angles. 
 * \param JR input parameter that indicates the Rotation and Jacobian with the rotational velocities.
 * \param roll output parameter will contain the amount of rotation around X.  
 * \param pitch output parameter will contain the amount of rotation around Y.
 * \param yaw output parameter will contain the amount of rotation around Z.
 * \retval 0 if successfull, otherwise its a singular situation.
 */
 inline int GetRPY(const Jacobian<Rotation>& JR, 
				  Jacobian<double>& roll, 
				  Jacobian<double>& pitch, 
				  Jacobian<double>& yaw,
				  double eps=epsilon) {
	return GetEulerZYX(JR,roll,pitch,yaw);
}


/**
 * \brief funcion to set the rpy angles. 
 * \param gamma input parameter that contains the amount of rotation around X.  
 * \param beta input parameter that contains the amount of rotation around Y.
 * \param alpha output parameter that contains the amount of rotation around Z.
 * \param JR output parameter that will contain the Rotation and Jacobian with the rotational velocities.
 */
 inline void SetRPY(const Jacobian<double>& roll, 
				  const Jacobian<double>& pitch, 
				  const Jacobian<double>& yaw,
 				  Jacobian<Rotation>& JR) {
	SetEulerZYX(roll,pitch,yaw,JR);	
}


} // namespace

#endif



