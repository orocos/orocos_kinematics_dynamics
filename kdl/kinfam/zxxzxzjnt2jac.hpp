#ifndef KDL_ZXXZXZJNT2JAC_HPP
#define KDL_ZXXZXZJNT2JAC_HPP
/***************************************************************************
                        zxxzxzJnt2Jac.hpp 
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
#include <kdl/kinfam/zxxzxz.hpp>
#include <kdl/kinfam/transmission.hpp>

namespace KDL {

  /**
   * \brief implements Jnt2Jac for a serial chain.
   */
  class ZXXZXZJnt2Jac : public Jnt2Jac {
	typedef ZXXZXZ      ChainType;
    const ChainType*                chain;
    std::vector<Twist>              Twists;
    Frame                           F_base_ee;
    int 							configuration;
    JointVector                     q;
    Jacobian<Frame>                 FJ_base_ee_local;
    Transmission*                   trans;
  public:
    ZXXZXZJnt2Jac(const ChainType* chain);
    virtual int evaluate(const JointVector& _q);
    /**
     * \brief get the Jacobian at a given endpoint.
     * 
     * There is only one endpoint, with number 0.
     * \see Jnt2Jac
     */
    virtual void getJacobian(Jacobian<Frame>& FJ_base_ee,int endpoint=0,int basepoint=0);
	
    virtual void setConfiguration(const std::vector<double>& q_config);
    virtual void getConfiguration(std::vector<double>& q_config);
	virtual void setConfiguration(int config);
    virtual void getConfiguration(int& config);

    virtual Jnt2Jac* clone() const;
    virtual ~ZXXZXZJnt2Jac();
  };
  
} // end of namespace KDL

#endif
