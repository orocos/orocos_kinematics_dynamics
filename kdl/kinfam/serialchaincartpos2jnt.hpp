/***************************************************************************
                        serialchaincartpos2jnt.hpp -  description
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


#ifndef KDL_SERIALCHAINCARTPOS2JNT_HPP
#define KDL_SERIALCHAINCARTPOS2JNT_HPP

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
 */
class SerialChainCartPos2Jnt : public CartPos2Jnt {
	const SerialChain*  chain;
	Frame                   F_base_ee;
	Jnt2Jac*                jnt2jac;
	Jacobian<Frame>         FJ_base_actual;
	ConstraintMatrix        cm;
	std::vector<double>		djv;
	std::vector<double>		jv;
	std::vector<double>     q_config;
public:
	/**
	 * \brief maximum number of iterations to be used.
	 */	
	int maxiter;
	/**
	 * \brief evaluate stops iterating if the error < stopcriterium.
	 */
	double stopcriterium;
	
	/**
     * \brief the number of iterations of the last call to evaluate().
	 */
	int iter;

	/**
	 * \brief the error after the last call to evaluate().
	 */
	double difference;	
public:

	SerialChainCartPos2Jnt(const SerialChain* _chain);
	/**
	 * \brief sets the desired Frame for an endpoint.
	 */
	virtual void setFrame(const Frame& q,int endpoint=0,int basepoint=0);

	/**
	 * \brief evaluates and returns the joint values.
	 *
	 * \param jv as an input it gives the initial value for numerical iteration.
	 *        Afterwards jv will contain the resulting joint values.
	 * \return errorcode.  0 if succesfull. 1 if the maximal number of 
     *         iterations has exceeded.
	 */
	virtual int evaluate(std::vector<double>& jv);

	/**
     * \brief make a deep virtual copy 
	 */
	virtual SerialChainCartPos2Jnt* clone() const;

	/**
	 * \brief sets the desired configuration.
	 *
	 * \param q_config double vector that describes the configuration. The 
	 *        meaning and interpretation of q_config is up to the specific 
	 *        kinematic family. 
 	 *
	 * for a serial kinematic chain the configuration is sufficiently (and redundantly)
	 * described by the joint values of a kinematic chain in the same configuration. 
	 * Each configuration is a different solution to the inverse position kinematics. 
	 * It is possible that there exists a trajectory that goes from one configuration to another
	 * without going through a singularity.  (cuspidal manipulator).
     * 
     * For this class the configuration vector corresponds to  the actuator joint positions
     *  (without offset).
	 */ 
    virtual void setConfiguration(const std::vector<double>& q_config);

	/**
	 * \brief gets the desired configuration.
	 *
	 * \param q_config double vector that describes the configuration. The
	 *        meaning and interpretation of q_config is up to the specific 
	 *        kinematic family. 
	 */
    virtual void getConfiguration(std::vector<double>& q_config);

	virtual ~SerialChainCartPos2Jnt();
};

} // end of namespace KDL

#endif
