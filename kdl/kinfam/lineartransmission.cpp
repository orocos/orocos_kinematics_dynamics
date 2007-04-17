/***************************************************************************
                        lineartransmission.hpp -  description
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

#include <kdl/kinfam/lineartransmission.hpp>

namespace KDL {
	LinearTransmission::LinearTransmission(int _nrofjoints,
                       const std::vector<double>& _scale,
                       const std::vector<double>& _offset) :
		nrofjoints(_nrofjoints),
		scale(_scale),
		offset(_offset) {}

	LinearTransmission::LinearTransmission(int _nrofjoints) :
		nrofjoints(_nrofjoints),
		scale(_nrofjoints),
		offset(_nrofjoints) {
		for (int i=0;i<nrofjoints;++i) {
			scale[i]=1.0;
			offset[i]=0.0;
		}
	}

    LinearTransmission::LinearTransmission(const LinearTransmission& in):
        nrofjoints(in.nrofjoints),
        scale(in.scale),
        offset(in.offset)
    {
    }
    
    LinearTransmission& LinearTransmission::operator = (const LinearTransmission& in)
    {
        this->offset = in.offset;
        this->scale = in.scale;
        this->nrofjoints = in.nrofjoints;
        return *this;
    }
        
	void LinearTransmission::setTransmission(int jointnr,double _scale,double _offset) {
		scale[jointnr]  = _scale;
		offset[jointnr] = _offset;
	}

	void LinearTransmission::fwdPos(const JointVector& actuator, JointVector& geometric,int indoffset) {
		for (int i=0;i<nrofjoints;++i) {
			geometric[i] = scale[i]*actuator[i+indoffset]+offset[i];
		}
	} 

	/**
	 * transforms the actuator joint vector into a geometric joint vector
     */
	void LinearTransmission::invPos(const JointVector& geometric, JointVector& actuator,int indoffset) {
		for (int i=0;i<nrofjoints;++i) {
			actuator[i+indoffset] = (geometric[i]-offset[i])/scale[i];
		}
	} 

	/**
     * transforms the geometric Jacobian into a Jacobian in actuator joint space.
	 */
	void LinearTransmission::invJac(const Jacobian<Frame>& geometric, Jacobian<Frame>& actuator,int indoffset) {
        actuator.value() = geometric.value();
        for (int i=0;i<nrofjoints;++i) {
            actuator.deriv(i+indoffset) = scale[i]*geometric.deriv(i);	
		}
	}
    void LinearTransmission::fwdVel(const JointVector& actuator, const JointVector& actuatorvel,JointVector& geometricvel,int indoffset) {
        for (int i=0;i<nrofjoints;++i) {
			geometricvel[i] = scale[i]*actuatorvel[i+indoffset];
        }
    } 



	void LinearTransmission::invVel(const JointVector& geometricpos, const JointVector& geometricvel, JointVector& actuatorvel,int indoffset) {
	    for (int i=0;i<nrofjoints;++i) {
			actuatorvel[i+indoffset] = geometricvel[i]/scale[i];
		}
    }

	/**
	 * \brief make a deep virtual copy
	 */
	Transmission* LinearTransmission::clone() const {
		return new LinearTransmission(nrofjoints,scale,offset);
	}
	
	LinearTransmission::~LinearTransmission() {};

} // namespace KDL

