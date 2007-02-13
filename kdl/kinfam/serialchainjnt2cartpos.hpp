#ifndef KDL_SERIALCHAINJNT2CARTPOS_HPP
#define KDL_SERIALCHAINJNT2CARTPOS_HPP

/***************************************************************************
                        SerialChainJnt2CartPos.hpp 
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

#include <kdl/kinfam/serialchain.hpp>
#include <kdl/kinfam/transmission.hpp>
#include <kdl/frames.hpp>
#include <vector>

namespace KDL {

/**
 * \brief implements Jnt2CartPos for a serial chain.
 */ 
class SerialChainJnt2CartPos : public Jnt2CartPos {
	const SerialChain*       chain;
	Frame                    F_base_ee;
	std::vector<double>      q_geom;
    Transmission*            trans;
    
public:
	SerialChainJnt2CartPos(const SerialChain* chain);
	virtual int evaluate(const JointVector& q);
	/**
	 * \brief gets the frame transformation.
	 * 
	 * You can only get 1 frame, frame 0, the end effector frame. 
	 */
	virtual void getFrame(Frame& F_base_ee,int endpoint,int basepoint);
	virtual Jnt2CartPos* clone() const;

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


	virtual ~SerialChainJnt2CartPos();
};

} // end of namespace KDL


#endif
