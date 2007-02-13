#ifndef KDL_JNT2JAC
#define KDL_JNT2JAC

/***************************************************************************
                        jnt2jac.hpp -  description
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
#include <kdl/kdl.hpp>
#include <kdl/jacobian.hpp>
#include <kdl/kinfam/transformation.hpp>

namespace KDL {
/**
 * \brief calculates Jacobian and cartesian position from the joint values.
 */
class Jnt2Jac: public Transformation  {
public:
	/**
	 * \brief transforms given joints to a frame and jacobian.
	 * \param q : an array containing the joint values.
	 * \retval succesful evaluation will return 0 
	 */
	virtual int evaluate(const JointVector& q)=0;

	/**
	 * \brief gets the Jacobian corresponding to a certain endpoint.
	 *
	 * After evaluate() this method can request the Jacobian of an endpoint.
	 * The default end point number is 0. (i.e. the end point number if there is 
	 * only one endpoint).
	 *
	 * \param endpoint : the requested end point
	 * \param FJ_base_ee : the frame and the jacobian of the endpoint w.r.t. the base.
	 */
	virtual void getJacobian(Jacobian<Frame>& FJ_base_ee,int endpoint=0,int basepoint=0)=0;

	/**
     * \brief make a deep virtual copy 
	 */
	virtual Jnt2Jac* clone() const = 0;
	virtual ~Jnt2Jac() {};
};

} // end of namespace KDL
#endif
