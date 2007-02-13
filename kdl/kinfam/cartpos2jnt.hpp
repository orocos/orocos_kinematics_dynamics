/***************************************************************************
                        cartpos2jnt.hpp -  description
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


#ifndef KDL_CARTPOS2JNT
#define KDL_CARTPOS2JNT

#include <kdl/kdl.hpp>
#include <kdl/kinfam/transformation.hpp>
#include <kdl/frames.hpp>

namespace KDL {

/**
 * \brief calculates joint values from a cartesian position.
 */
class CartPos2Jnt : public Transformation {
public:
	/**
	 * \brief sets the desired Frame for an endpoint.
	 */
	virtual void setFrame(const Frame& q,int endpoint=0,int basepoint=0)=0;

	/**
	 * \brief evaluates and returns the joint values.
     *
	 * The iterative algorithm starts from the joint values given by
	 * setConfiguration(xxx)
	 */
	virtual int evaluate(std::vector<double>& jv)=0;

	/**
     * \brief make a deep virtual copy 
	 */
	virtual CartPos2Jnt* clone() const = 0;

	virtual ~CartPos2Jnt() {};
};

} // end of namespace KDL

#endif
