/***************************************************************************
                        cartvel2jnt.hpp -  description
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


#ifndef KDL_CARTVEL2JNT
#define KDL_CARTVEL2JNT

#include <kdl/kdl.hpp>
#include <kdl/kinfam/transformation.hpp>

namespace KDL {

  /**
   * \brief calculates cartesian position form the joint values.
   */
  class CartVel2Jnt : public Transformation {
  public:

    /**
     * \brief evaluates this transformation for a given joint position.
     *
     * After this method, the user can use the getJointVel() method to receive the joint velocities. 
     * \return an errorcode, 0 if successful.
     */
    virtual int evaluate(const JointVector& _q, JointVector& _qdot)=0;
    
    /**
     * \brief sets the desired Twist and the joint positions. 
     *
     * \param endpoint the requested endpoint, should be zero for the default frame.
     * \param F_base_ee variable used to return the frame.
     */
    virtual void setTwist(const Twist& t_base_ee,int endpoint=0,int basepoint=0) = 0;
    
	/**
     * \brief make a deep virtual copy 
	 */
	virtual CartVel2Jnt* clone() const = 0;

	virtual ~CartVel2Jnt() {};
};

} // end of namespace KDL

#endif
