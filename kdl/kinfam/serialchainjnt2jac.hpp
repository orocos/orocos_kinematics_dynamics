#ifndef KDL_SERIALCHAINJNT2JAC_HPP
#define KDL_SERIALCHAINJNT2JAC_HPP
/***************************************************************************
                        SerialChainJnt2Jac.hpp 
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
#include <kdl/kinfam/serialchain.hpp>
#include <kdl/kinfam/transmission.hpp>

namespace KDL {

/**
 * \brief implements Jnt2Jac for a serial chain.
 */
class SerialChainJnt2Jac : public Jnt2Jac {
	const SerialChain*       chain;
    int                      offset;
	std::vector<Frame>       frames;
	Frame                    F_base_ee;
	std::vector<double>      q_geom;
	Jacobian<Frame>          FJ_base_ee_geom;
    Transmission*            trans;
public:
	SerialChainJnt2Jac(const SerialChain* chain);
	SerialChainJnt2Jac(const SerialChain* chain,int offset);
	virtual int evaluate(const JointVector& q);
	/**
	 * \brief get the Jacobian at a given endpoint.
	 * 
	 * There is only one endpoint, with number 0.
	 * \see Jnt2Jac
	 */
	virtual void getJacobian(Jacobian<Frame>& FJ_base_ee,int endpoint=0,int basepoint=0);

    /**
     * does not do anything, this transformation object does not need configuration
     * information.
     */	
    virtual void setConfiguration(const std::vector<double>& q_config) {} 

    virtual void getConfiguration(std::vector<double>& q_config);

	virtual Jnt2Jac* clone() const;
	virtual ~SerialChainJnt2Jac();
};

} // end of namespace KDL

#endif

