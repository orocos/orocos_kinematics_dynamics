/***************************************************************************
                        serialchaincartvel2jnt.hpp -  description
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


#ifndef KDL_SERIALCHAINCARTVEL2JNT_HPP
#define KDL_SERIALCHAINCARTVEL2JNT_HPP

#include <kdl/kdl.hpp>
#include <kdl/kinfam/cartpos2jnt.hpp>
#include <kdl/jacobian.hpp>
#include <kdl/kinfam/kinematicfamily.hpp>
#include <kdl/kinfam/serialchain.hpp>
#include <kdl/frames.hpp>
#include <kdl/constraints.hpp>

namespace KDL {

/**
 * \brief calculates joint values from a cartesian position.
 *
 * This is a simplistic implementation of this transformation.  Just to check
 * whether our class structure is sound.
 *
 * \todo or should this be for all kinematicfamily objects ?
 *
 */
class SerialChainCartVel2Jnt : public CartVel2Jnt {
	const SerialChain*  chain;
	Frame                   F_base_ee;
	Jnt2Jac*                jnt2jac;
	Jacobian<Frame>         FJ_base_actual;
	ConstraintMatrix        cm;
	std::vector<double>		q_dot_subset;
    Twist                   t_base_ee;
    


public: // QoS of this transformation object :
    /**
     * \brief constraint weights for the translations
     */
    double weight_trans;

    /**
     * \brief constraint weights for the rotations
     */
    double weight_rot;

    /**
     * \brief maximal amplification of the norm.
     *
     * The inverse will maximally amplify the norm by this amount.
     * If you set this very low (e.g. 5), then some directions are 
     * more easily regarded as singular.  If you set this very high (e.g. 1000) then
     * you can move closer ( in cartesian space) to a singularity, at the cost of 
     * higher joint velocities.  The norms are weighted norms.
     */
    double max_amp;

public:

	SerialChainCartVel2Jnt(const SerialChain* _chain);
	
	virtual int evaluate(const JointVector& _q,JointVector& _qdot);
    
    virtual void setTwist(const Twist& _t_base_ee,int endpoint=0,int basepoint=0);
    
    /**
     * Does not do anything.  It is not necessary to set the configuration for this transformation.
     */
    virtual void setConfiguration(const std::vector<double>& q_config) {}

    /**
     * Gets the configuration ( corresponds to the joints in actuator space without joint index offset).
     */
    virtual void getConfiguration(std::vector<double>& q_config);


	virtual CartVel2Jnt* clone() const;

	virtual ~SerialChainCartVel2Jnt();
};

} // end of namespace KDL

#endif
