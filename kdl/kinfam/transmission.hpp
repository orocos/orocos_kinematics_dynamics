#ifndef KDL_TRANSMISSION_H
#define KDL_TRANSMISSION_H

/***************************************************************************
                        Transmission -  description
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
#include <kdl/jacobianframe.hpp>
namespace KDL {

/**
 * \brief Transforms between actuator space and geometric space.
 *
 * This object is responsible for :
 *    - the transformation between the actuator joint values and the 
 *      geometric joints between the links of the robot.  Also coupled transmissions
 *      of the robot can be implemented by this object.
 *    - the selection of the used joints and columns of the Jacobian.
 * For example, if some subclass specifies jointoffset and nrofjoints then :
 *    - actuator[jointoffset..jointoffset+nrofjoints-1] are used.
 *    - geometric[0..nrofjoints-1] are used.
 * 
 * The Transmission class has become responsible for the selection of the used joints
 * because otherwise the transformation objects should now about the total size of the 
 * jointvector.   The total jointvector and its size should remain unknown by the kinematic 
 * family and transformation objects. 
 */
class Transmission {
public:
     Transmission(const Transmission& t){}
public:
    Transmission() {}
	/**
	 * \brief transforms the actuator joint vector into a geometric joint vector
     */
	virtual void fwdPos(const JointVector& actuator, JointVector& geometric,int offset) = 0;

	/**
	 * \brief transforms the geometric joint vector into the actuator joint vector
     */
	virtual void invPos(const JointVector& geometric, JointVector& actuator,int offset) = 0;

	/**
     * \brief transforms the geometric Jacobian into a Jacobian in actuator joint space.
     *
     * \warning This transforms the complete Jacobian<Frame> object.  This means it should copy the value() part
     * of the Jacobian<Frame> object !
     * \warning It is allowed for actuator to be the same variable as geometric
	 */
	virtual void invJac(const Jacobian<Frame>& geometric, Jacobian<Frame>& actuator,int offset) = 0;

    /**
     * \brief transforms transmission joint values (actuator pos, actuator vel) -> (geometric vel)
     */
	virtual void fwdVel(const JointVector& actuator, const JointVector& actuatorvel,JointVector& geometricvel,int offset) = 0;

    /**
     * \brief transforms transmission joint values (geometric pos, geometric vel) -> (actuator vel)
     */
	virtual void invVel(const JointVector& geometricpos, const JointVector& geometricvel, JointVector& actuatorvel,int offset) = 0;

    virtual std::string getTypeName() const = 0;
    
	/**
	 * make a deep virtual copy 
	 */
	virtual Transmission* clone() const = 0;

	virtual ~Transmission(){};
};

} // end of namespace KDL

#endif
