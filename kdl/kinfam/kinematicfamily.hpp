#ifndef KDL_KINEMATICFAMILY
#define KDL_KINEMATICFAMILY

/***************************************************************************
                        XXXXXX -  description
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

#include <string>
#include <kdl/kinfam/jnt2cartpos.hpp>
#include <kdl/kinfam/jnt2jac.hpp>
#include <kdl/kinfam/cartpos2jnt.hpp>
#include <kdl/kinfam/jnt2cartvel.hpp>
#include <kdl/kinfam/cartvel2jnt.hpp>

namespace KDL {

    /**
     * \defgroup kinfam Kinematic Families.
     */

/**
 * \brief Interface to define a kinematic family
 *
 * Examples of a kinematic family are :
 *	 a general serial chain, or
 *   a chainZXXZXZ serial chain.
 *
 * \todo
 *    Documentation ! 
 * \ingroup kinfam
 */
class KinematicFamily {
protected:
    int _nrofjoints;
    int _offset;
public:
    KinematicFamily(const KinematicFamily& kf):
        _nrofjoints(kf.nrOfJoints()),
        _offset(kf.offset())
    {};
public:
    /**
     * \param nrofjoints : the number of joints that this serial chain will contain.
     * \param offset     : offset that is applied to the index of the joints. 
     *                     To get a subset of a jointvector.
     */
    KinematicFamily(int nrofjoints,int offset):_nrofjoints(nrofjoints),_offset(offset) {}

	/**
	 * \brief returns a function object that is used to calculate the cartesian position from the joint values.
	 * \return function object.  
	 * \warning Can return zero if the kinematic family does not implement this function.
	 * \warning User is responsible for deleting the created object
	 * \warning This object is not valid any more if the kinematic family instance is deleted.
	 */
	virtual Jnt2CartPos* createJnt2CartPos() const {
		return 0;
	}

	/**
	 * \brief returns a function object that is used to calculate joint values form the cartesian position.
	 * \return function object.  
	 * \warning Can return zero if the kinematic family does not implement this function.
	 * \warning User is responsible for deleting the created object
	 * \warning This object is not valid any more if the kinematic family instance is deleted.
	 */
	virtual CartPos2Jnt* createCartPos2Jnt() const {
		return 0;
	}


	/**
     * \brief returns a function object that is used to calculate the cartesian position and the jacobian from the joint
     *        values.  
	 * \return function object.  
     * \warning Can return zero if the kinematic family does not implement this function.
	 * \warning User is responsible for deleting the created object
	 * \warning This object is not valid any more if the kinematic family instance is deleted.
	 */
	virtual Jnt2Jac*     createJnt2Jac() const {
		return 0;
	}

	/**
     * \brief returns a function object that is used to calculate (joint pos, cart vel) -> ( joint vel). 
     *
	 * \return function object.  
     * \warning Can return zero if the kinematic family does not implement this function.
	 * \warning User is responsible for deleting the created object
	 * \warning This object pointer is not valid any more if the kinematic family instance is deleted.
	 */
	virtual CartVel2Jnt*  createCartVel2Jnt() const {
		return 0;
	}

	/**
     * \brief returns a function object that is used to calculate (joint pos, joint vel) -> ( cart vel). 
     *
	 * \return function object.  
     * \warning Can return zero if the kinematic family does not implement this function.
	 * \warning User is responsible for deleting the created object
	 * \warning This object pointer is not valid any more if the kinematic family instance is deleted.
	 */
	virtual Jnt2CartVel*  createJnt2CartVel() const {
		return 0;
	}
	/**
  	 * \brief make a deep virtual copy. 
	 */	
	virtual KinematicFamily* clone() const = 0;

	virtual ~KinematicFamily() {};
public:
	// meta-information :
	/**
     * \brief returns the type of the kinematic family object.
	 * 
	 * e.g.: 
	 *   - serialchain, 
	 *   - zxxzxz.
	 */
	virtual std::string getTypeName() const =0;
	/**
     * \brief returns the name of this instance of the kinematic family object. 
     *
     * e.g. 
	 *    - CRS, 
	 *    - Kuka361, 
	 *    - Kuka160
	 */
	virtual std::string getName() const =0;
	
	/**
     * \brief returns the number of joints that are used in this kinematic family instance.
     */
	virtual int nrOfJoints() const {
        return _nrofjoints;
    }

    /**
     * \brief returns the offset to the INDEX of the joints.  
     */
    virtual int offset() const {
        return _offset;
    } 

};

} // end of namespace KDL

#endif
