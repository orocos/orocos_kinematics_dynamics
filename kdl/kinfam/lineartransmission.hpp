#ifndef KDL_LINEARTRANSMISSION_HPP
#define KDL_LINEARTRANSMISSION_HPP

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

#include <kdl/kinfam/transmission.hpp>
#include <kdl/jacobianframe.hpp>


namespace KDL {


/**
 * \brief implementation of Transmission in the case of a linear transformation.
 *
 * implements the relation geometric = scale*actuator + offset for all joints.
 * 
 */
class LinearTransmission:public Transmission {
public:
	int nrofjoints;
	std::vector<double> scale;
	std::vector<double> offset;

	/**
     * \brief Constructor for LinearTransmission
	 *
	 * 
     * implements the relation geometric = scale*actuator + offset for all joints.
	 *
 	 * this range are not copied.  The vectors scale and offset are of the size nrofjoints.
	 *
     * The following indices in the joint vectors are used : 
 	 *   - actuator[0..nrofjoints-1] are used.
     *   - geometric[0..nrofjoints-1] are used.
     *
	 * \param _nrofjoints  number of joints the transmission is applied to.
	 * \param _scale       scale to apply to the joint values.
	 * \param _offset      offset to apply to the joint values.
     */
	LinearTransmission(int _nrofjoints,
                       const std::vector<double>& scale,
                       const std::vector<double>& offset);
    LinearTransmission(const LinearTransmission& in);
    LinearTransmission& operator = (const LinearTransmission& in);
    
	/**
     * \brief Constructor for LinearTransmission.
	 *
     * identical to the other constructor.  But scale and offset will be changed later on.
     * The default scale is equal to 1.0 and the default offset is equal to 0.0.
	 *
	 * In some constructs, it is useful to have this constructor.
	 *
	 * \param _nrofjoints  number of joints the transmission is applied to.
	 */
	LinearTransmission(int _nrofjoints=0);

	/**
     * \brief sets values for the linear transmission for a joint.
	 * 
	 */
	void setTransmission(int jointnr,double scale,double offset);

	/**
	 * transforms the actuator joint vector into a geometric joint vector
     */
	virtual void fwdPos(const JointVector& actuator, JointVector& geometric, int indoffset);

	/**
	 * transforms the actuator joint vector into a geometric joint vector
     */
	virtual void invPos(const JointVector& geometric, JointVector& actuator, int indoffset);


	/**
     * transforms the geometric Jacobian into a Jacobian in actuator joint space.
	 */
	virtual void invJac(const Jacobian<Frame>& geometric, Jacobian<Frame>& actuator, int indoffset);

    /**
     * \brief transforms transmission joint values (actuator pos, actuator vel) -> (geometric vel)
     */
	virtual void fwdVel(const JointVector& actuator, const JointVector& actuatorvel,JointVector& geometricvel, int indoffset);


    /**
     * \brief transforms transmission joint values (geometric pos, geometric vel) -> (actuator vel)
     */
	virtual void invVel(const JointVector& geometricpos, const JointVector& geometricvel, JointVector& actuatorvel, int indoffset);

    virtual std::string getTypeName() const
    {
        return "LinearTransmission";
    };
    
    
	/**
	 * \brief make a deep virtual copy
	 */
	virtual Transmission* clone() const;
	virtual ~LinearTransmission();
};

} // namespace KDL

#endif

