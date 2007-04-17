/***************************************************************************
                        jnt2cartvel.hpp -  description
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


#ifndef KDL_JNT2CARTVEL
#define KDL_JNT2CARTVEL

#include <kdl/kdl.hpp>
#include <kdl/kinfam/transformation.hpp>
#include <kdl/framevel.hpp>

namespace KDL {

  /**
   * \brief calculates cartesian position form the joint values.
   */
  class Jnt2CartVel : public Transformation {
  public:

    /**
     * \brief evaluates this transformation.
     *
     * After evaluation, the user can use the getFrame() method to receive the frame.
     * \return an errorcode, 0 if successful.
     */
    virtual int evaluate( const JointVector& q, const JointVector& qdot)=0;
    
    /**
     * \brief gets the pose and the twist  of an endpoint w.r.t. the base.
     * \param basepoint the point from where AND with respect to whom the transformation is taken.  Should
     *        be zero for the default basepoint.
     * \param endpoint the requested endpoint, should be zero for the default frame.
     * \param q the joint position.
     * \param q_dot the joint velocity
     * \param F_base_end a FrameVel object that is returned by this method.
     */
	virtual void getFrameVel( FrameVel& F_base_end,int endpoint=0,int basepoint=0)=0;

	/**
     * \brief make a deep virtual copy 
	 */
	virtual Jnt2CartVel* clone() const = 0;

	virtual ~Jnt2CartVel() {};
};

} // end of namespace KDL

#endif
