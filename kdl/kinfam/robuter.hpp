#ifndef KDL_ROBUTER_HPP
#define KDL_ROBUTER_HPP

#include <kdl/kinfam/serialchain.hpp>
#include <kdl/kinfam/unittransmission.hpp>

namespace KDL {

/**
 * \brief constructs a SerialChain kinematic object corresponding to our robuter platform with a mounted robot.
 */
class Robuter : public SerialChain {
	public:
	explicit Robuter(int jointoffset=0) :	
		SerialChain("Robuter", 6, jointoffset,new UnitTransmission(6))
	{
		double height = 0.75;
		addJoint(new JointTransX(Frame::Identity()));
		addJoint(new JointTransY(Frame::Identity()));
        setLastJointToEE(Frame(Rotation::Identity(),Vector(0,0,height)));
	};
};

}; // end of namespace KDL

#endif
