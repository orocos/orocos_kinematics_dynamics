/***************************************************************************
                         Jacobian.h -  description
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
#ifndef KDL_Jacobian_H
#define KDL_Jacobian_H

#include <kdl/traits.h>
#include <assert.h>
#include <bitset>
#include <vector>

#define MAXNROFDERIV 31

typedef std::bitset<MAXNROFDERIV> JacobianBitset;

/**
 * \file 
 * This file defines the framework for template expressions.
 */

/**
 *  @brief template class to mark template expressions.
 *
 *  - The following classes are a small framework to help building 
 *  classes for automatic differentiation towards multiple variables.
 *  Expressions that operate on these classes are implemented with 
 *  template expressions
 *
 *  - The basic type on which all operations have place is the template Jacobian<..>
 *  Instances of Jacobian<T> store a value of type T and n values for the derivative 
 *  of elements of type T.
 *
 *  - This template class marks template expressions.  Other template definitions
 *  can use this mark to detect a template expression and act accordingly.
 *  
 *  \subsection Necessary conditions for the type T.
 *  The Type T should have type definitions valueType and derivType.
 *  The underlying type will be an expression or the base type Jacobian<..>
 *  
 **/
template <typename T>
class Expr {
public:
    typedef typename T::exprType exprType; 
	/**
	 * returns the type of the derivative of T
	 */
	typedef typename T::derivType derivType;

	/**
	 * returns the type of the value of T
	 */
	typedef typename T::valueType valueType;

	/**
	 * contains the underlying element
	 */
    T elem;
public:
    /**
	 * Constructs an Expr out of an underlying type.
	 */
    Expr(const T& _elem):elem(_elem) {}
};



/**
 * \brief Jacobian<T> constructs a tangent vector class out of the given basetype.
 *
 * This class contains a value for type T and <b>n</b> values for derivatives of type T.
 * - Jacobian<T> can be used as a template parameter for Expr<T>
 * - take care not to copy construct objects of this type unnecessarely. The template expressions
 *   avoid unnecessarely copying of Jacobian<T>.  <b>Read (copy) construction documentation !</b>
 * - the member variable isconstant indicates that this entity has zero derivative 
 *   towards all variables.
 * - T should have an empty constructor.
 */


template <typename T>
class Jacobian {
public:

    typedef T exprType;
	typedef typename Traits<T>::valueType valueType;

	/**
	 * GeomTriats classes are used to derive the type of the derivatives of instances of type T.
	 */
	typedef typename Traits<T>::derivType derivType;
private:
    valueType val;
    std::vector<derivType> der;
    int size;
	JacobianBitset hasderiv;
public:
	/**
	 * \brief Construct an Jacobian<T> object, 
	 *
	 * When size==0, it will be declared constant, otherwise it is variable.
	 * \warning <b> allocates on the heap when _size not equal to 0 !</b>
	 */
	explicit Jacobian(int _size=0):
		val(),
		der(_size),
		size(_size),
		hasderiv() {
		assert(_size < MAXNROFDERIV);
	}
	
	void resize(int _size) {
		size=_size;
		hasderiv = JacobianBitset();
		der.resize(_size);
		assert(_size < MAXNROFDERIV);
	}



	/**
	 * \brief Copy constructor,
	 *
	 * \warning <b> allocates on the heap when arg is not constant !</b>
	 */
    Jacobian(const Jacobian<T>& arg): 
		val(arg.val),
		der(arg.size),
		size(arg.size),
		hasderiv(arg.hasderiv)
	{
        for (int i=0;i<size;++i) der[i]=arg.der[i];
    }

	/**
	 * \brief Construct an RVFrame object with size==0 and declared constant.
	 *
	 * arg gives the value given in its argument.  All derivatives are zero 
	 * and isconstant is set to true. Does NOT allocate on the heap.
	 */
	Jacobian(const valueType& arg):val(arg),der(0),size(0),hasderiv() {
	}

	/**
	 * \brief When memory was allocated (i.e. der!=0), deallocate.
	 */
    ~Jacobian() {
    }

	/**
	 * \brief returns the derivative towards the ith variable.
	 *
	 * - This method will be used with  a const Jacobian<T>& declaration.  It is impossible to use deriv(i) as
	 * an lvalue.
	 * - isConstant(i) should be false.
	 */
    derivType deriv(int i) const{
		assert((0<=i)&&(i<size));
		assert(hasderiv[i]);
        return der[i];
    }

	/**
	 * \brief returns the derivative towards the ith variable.
	 * 
	 * - This method will be used with non-const declarations of Jacobian<T>.  It that case deriv(i) can
	 * be an lvalue.
	 *
	 * - Will clear the isconstant flag for this variable, also when only the value is used !
	 *
	 * For example, for Jacobian<double>: 
	 * \verbatim
	   deriv(1) = 5.0;
	   \endverbatim
	 */
    derivType& deriv(int i) {
		assert((0<=i)&&(i<size));
		hasderiv[i]=true;
        return der[i];
    }

	/**
	 * \brief returns the value of this entity
	 *
	 * This method will be used with non-const declarations of Jacobian<T>.  It that case value() can
	 * be an lvalue.
	 */
    valueType& value(){
        return val;
    }

	/**
	 * \brief returns the value of this entity
	 *
	 * This method will be used with  a const Jacobian<T>& declaration.  It is impossible to use value() as
	 * an lvalue.
	 */
    valueType value() const {
        return val;
    }


	/**
	 * \brief returns the number of variables to which the derivative is taken.
	 */
    int nrOfDeriv() const {
        return size;
    }

	/**
	 * \brief indicates whether ith derivative is zero or not.
	 */

	bool hasDeriv(int i) const {
		return hasderiv[i];
	}

	/**
	 * \brief indicates whether all derivatives are zero.
	 */
	bool hasDerivs() const {
		return hasderiv.any();
	}

	
	/**
	 * \brief stores a bitset containing to target
	 * 
	 * target[i] is true if ith variable has a derivative.
	 */
	JacobianBitset getDerivs() const {
		return hasderiv;
	}

	/**
	 * \brief specify whether all derivatives are zero or not.
	 *
	 * \warning <b>This method does not change the amount of variables to which the derivative is taken.</b>
	 * \warning It is not valid to call this on a class with nrOfDeriv()==0.
	 */
	void setDeriv(int i,bool s=true) {
		assert(!( (!s) && (size==0) ));
		hasderiv[i] = s;
	}

	/**
	 * \brief evaluates an template expression and stores the result.
	 *
	 * This method calls the value() method the template expression and for each variable,
	 * it calls deriv(i) of the template expression.
	 * \warning 
     *    You can do only A=A*B if the underlying datatype supports this.
     *    For now all implemented instantiations of Jacobian support this.
     *    (double, Frame and variants, FrameVel and variants).
	 */
    template <class A>
    Jacobian<T>& operator=(const Expr<A>& e) {		
		const A& expr = e.elem;        
		hasderiv = expr.getDerivs();
		if (hasderiv.any()) {
			assert(expr.nrOfDeriv()==nrOfDeriv());
	        for (int i=0;i<size;++i)
				if (hasderiv[i]) {
					der[i] = expr.deriv(i);
				}
		}
		// it is important that the following is located after the 
		// der[i] assignments.  In this way, A = A*B is a correct use of
		// this routine. i.e. expr.deriv(i) could refer to expr.value()
		val = expr.value();
        return *this;
    }


	/**
	 * \brief assigns the argument to the current object
	 *
	 * Does NOT do any allocation.
	 * \warning <b>the current object and the argument should have the same number of derivatives</b>
	 */
    Jacobian<T>& operator=(const Jacobian<T>& expr) {		
		hasderiv = expr.hasderiv;
		if (hasderiv.any()) {
			assert(expr.nrOfDeriv()==nrOfDeriv());
			for (int i=0;i<size;++i) 
				if (hasderiv[i]) {
					der[i] = expr.deriv(i);
				}
		}
		val = expr.value();
        return *this;
    }

	/**
	 * \brief assigns the argument to the current object
	 *
	 * Assigns the argument to the stored value and makes all derivatives zero.
	 * isConstant() is true after this assignment.
	 */
	Jacobian<T>& operator=(const T& expr) {
        val = expr;
		hasderiv.reset();
        return *this;
    } 
};



/**
 * \brief Cnst<T> encapsulates something that only can be constant and never has a derivative.
 */


template <typename T>
class Cnst {
public:
    typedef T exprType;
	typedef typename Traits<T>::valueType valueType;

	/**
	 * GeomTriats classes are used to derive the type of the derivatives of instances of type T.
	 */
	typedef typename Traits<T>::derivType derivType;
private:
    valueType val;
public:
	//
	// -Default constructor 
	// -Default copy constructor
	// -Default destructor
	// are sufficient.


	/**
	 * \brief returns the derivative towards the ith variable.
	 * Should never be called.
	 */
    derivType deriv(int i) const{
		assert(false); // should never be called, this is a CONSTANT object.
        return derivType();
    }

	/**
	 * \brief returns the derivative towards the ith variable.
	 * Should never be called.
	 */
    derivType& deriv(int i) {
		assert(false); // should never be called, this is a CONSTANT object.
        return derivType();
    }

	/**
	 * \brief returns the value of this entity
	 *
	 * This method will be used with non-const declarations of Jacobian<T>.  It that case value() can
	 * be an lvalue.
	 */
    valueType& value(){
        return val;
    }

	/**
	 * \brief returns the value of this entity
	 *
	 * This method will be used with  a const Jacobian<T>& declaration.  It is impossible to use value() as
	 * an lvalue.
	 */
    valueType value() const {
        return val;
    }


	/**
	 * \brief returns the number of variables to which the derivative is taken.
	 */
    int nrOfDeriv() const {
        return 0;
    }

	/**
	 * \brief indicates whether ith derivative is zero or not.
	 */

	bool hasDeriv(int i) const {
		return false;
	}

	/**
	 * \brief indicates whether all derivatives are zero.
	 */
	bool hasDerivs() const {
		return false;
	}

	
	/**
	 * \brief stores a bitset containing to target
	 * 
	 * target[i] is true if ith variable has a derivative.
	 */
	JacobianBitset getDerivs() const {
		return JacobianBitset(0);
	}

	/**
	 * \brief specify whether all derivatives are zero or not.
	 *	 
	 * \warning Should never be called.
	 */
	void setDeriv(int i,bool s=true) {
		assert(false);
	}


	/**
	 * \brief assigns the argument to the current object
	 *
	 * Assigns the argument to the stored value and makes all derivatives zero.
	 * isConstant() is true after this assignment.
	 */
	 Cnst<T>& operator=(const T& expr) {
        val = expr;
        return *this;
    } 
};









#endif //KDL_Jacobian

