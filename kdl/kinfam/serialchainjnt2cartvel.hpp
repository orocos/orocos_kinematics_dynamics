#ifndef KDL_SERIALCHAINJNT2CARTVEL_HPP
#define KDL_SERIALCHAINJNT2CARTVEL_HPP
/***************************************************************************
                        SerialChainJnt2CartVel.hpp 
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

#include <vector>
#include <kdl/frames.hpp>
#include <kdl/framevel.hpp>
#include <kdl/kinfam/serialchain.hpp>
#include <kdl/kinfam/jnt2cartvel.hpp>
#include <kdl/kinfam/transmission.hpp>

namespace KDL {

/**
 * \brief implements Jnt2Jac for a serial chain.
 */
class SerialChainJnt2CartVel : public Jnt2CartVel {
	const SerialChain*       chain;
	std::vector<Frame>       frames;
	Frame                    F_base_ee;
	std::vector<double>      q_geom;
	std::vector<double>      q_geom_dot;
    Transmission*            trans;
public:
	SerialChainJnt2CartVel(const SerialChain* chain);
	virtual int evaluate(const JointVector& q, const JointVector& qdot);
    /**
     * basepoint and endpoint are ignored for a serialchain.
     * @see Jnt2CartVel::getFrameVel
     */
	virtual void getFrameVel( FrameVel& F_base_end,int endpoint=0,int basepoint=0);

    /**
     * Does not do anything, because you cannot set the configuration of this transformation
     * object.  You can only read it.
     */
    virtual void setConfiguration(const std::vector<double>& q_config) {}

    /**
     * gets the configuration vector, which in this case corresponds to
     * the actuator joint space vector of the last transformation.
     */
    virtual void getConfiguration(std::vector<double>& q_config);


	
	virtual Jnt2CartVel* clone() const;
	virtual ~SerialChainJnt2CartVel();
};

} // end of namespace KDL

#endif

