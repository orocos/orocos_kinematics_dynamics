/***************************************************************************
                        jnt2cartpos.hpp -  description
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


#ifndef KDL_JNT2CARTPOS
#define KDL_JNT2CARTPOS

#include <kdl/kdl.hpp>
#include <kdl/frames.hpp>
#include <kdl/kinfam/transformation.hpp>

namespace KDL {

  /**
   * \brief calculates cartesian position form the joint values.
   */
  class Jnt2CartPos : public Transformation {
  public:
    /**
     * \brief evaluates this transformation.
     *
     * After evaluation, the user can use the getFrame() method to receive the frame.
     * \return an errorcode, 0 if successful.
     */
    virtual int evaluate(const JointVector& q)=0;
    
    /**
     * \brief gets the frame transformation of an endpoint w.r.t. the base.
     *
     * \param endpoint the requested endpoint, should be zero for the default frame.
     * \param F_base_ee variable used to return the frame.
     */
    virtual void getFrame(Frame& F_base_ee,int endpoint=0,int basepoint=0) = 0;
    
	/**
     * \brief make a deep virtual copy 
	 */
	virtual Jnt2CartPos* clone() const = 0;

	virtual ~Jnt2CartPos() {};
};

} // end of namespace KDL

#endif
