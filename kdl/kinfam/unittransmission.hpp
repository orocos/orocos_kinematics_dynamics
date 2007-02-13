#ifndef KDL_UNITTRANSMISSION_HPP
#define KDL_UNITTRANSMISSION_HPP

/***************************************************************************
                        unittransmission.hpp -  description
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

#include <kdl/kinfam/transmission.hpp>
#include <kdl/jacobianframe.hpp>


namespace KDL {


/**
 * \brief implementation of Transmission in the case of no transformation.
 */
class UnitTransmission:public Transmission {
public:
	int nrofjoints;

	/**
     * \brief applies a unit transmission and subselection of joints.
     *
	 * For example, if some subclass specifies jointoffset and nrofjoints then :
 	 *   - actuator[jointoffset..jointoffset+nrofjoints-1] are used.
     *   - geometric[0..nrofjoints-1] are used.
     *
     * \param _nrofjoints   number of joints.
     */
	UnitTransmission(int _nrofjoints = 0):
		nrofjoints(_nrofjoints) {}
    UnitTransmission(const UnitTransmission& in):
        nrofjoints(in.nrofjoints){};
    UnitTransmission& operator = (const UnitTransmission& in)
    {
        this->nrofjoints = in.nrofjoints;
        return *this;
    }
    
	/**
	 * transforms the actuator joint vector into a geometric joint vector
     */
	virtual void fwdPos(const JointVector& actuator, JointVector& geometric,int offset) {
		for (int i=0;i<nrofjoints;++i) {
			geometric[i] = actuator[i+offset];
		}
	} 

	/**
	 * transforms the actuator joint vector into a geometric joint vector
     */
	virtual void invPos(const JointVector& geometric, JointVector& actuator,int offset) {
		for (int i=0;i<nrofjoints;++i) {
			actuator[i+offset] = geometric[i];
		}
	} 


	/**
     * transforms the geometric Jacobian into a Jacobian in actuator joint space.
	 */
	virtual void invJac(const Jacobian<Frame>& geometric, Jacobian<Frame>& actuator,int offset) {
        actuator.value() = geometric.value();
		for (int i=0;i<nrofjoints;++i) {
			actuator.deriv(i+offset) = geometric.deriv(i);	
		}
	}

    /**
     * \brief transforms transmission joint values (actuator pos, actuator vel) -> (geometric vel)
     */
	virtual void fwdVel(const JointVector& actuator, const JointVector& actuatorvel,JointVector& geometricvel,int offset) {
        for (int i=0;i<nrofjoints;++i) {
			geometricvel[i] = actuatorvel[i+offset];
        }
    } 

    /**
     * \brief transforms transmission joint values (geometric pos, geometric vel) -> (actuator vel)
     */
	virtual void invVel(const JointVector& geometricpos, const JointVector& geometricvel, JointVector& actuatorvel, int offset) {
	    for (int i=0;i<nrofjoints;++i) {
			actuatorvel[i+offset] = geometricvel[i];
		}
    }

    virtual std::string getTypeName() const
    {
        return "UnitTransmission";
    };
    
    

	/**
	 * \brief make a deep virtual copy
	 */
	virtual Transmission* clone() const {
		return new UnitTransmission(nrofjoints);
	}
	virtual ~UnitTransmission() {};
};

} // namespace KDL

#endif

