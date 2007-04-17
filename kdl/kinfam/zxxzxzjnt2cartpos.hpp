#ifndef KDL_ZXXZXZJNT2CARTPOS_HPP
#define KDL_ZXXZXZJNT2CARTPOS_HPP


// Copyright (C) 2006 Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//  
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//  

#include <kdl/kinfam/zxxzxz.hpp>
#include <kdl/kinfam/transmission.hpp>
#include <kdl/frames.hpp>

namespace KDL
{
  /**
   * @file   zxxzxzjnt2cartpos.hpp
   * @author Ruben Smits
   * @date   Tue Jul 18 08:27:52 2006
   * 
   * @brief  implements Jnt2CartPos for a serial chain
   * 
   * 
   */
  class ZXXZXZJnt2CartPos : public Jnt2CartPos
  {
	typedef ZXXZXZ      ChainType;
    const ZXXZXZ*       chain;
    Frame                           F_base_ee;
    int                             configuration;
    JointVector                     q;  
    Transmission*                   trans;

public:
    ZXXZXZJnt2CartPos(const ZXXZXZ* chain);
    virtual int evaluate(const JointVector& _q);
    /** 
     * gets the frame transformation from the base of the chain to the
     * end effector.
     * 
     * @param framenr: You can only get 1 frame, frame 0, the end effector frame. 
     * @param F_base_ee
     */
    virtual void getFrame(Frame& F_base_ee,int endpoint=0, int basepoint=0);
    virtual Jnt2CartPos* clone() const;

    virtual void setConfiguration(const std::vector<double>& q_config);

    virtual void getConfiguration(std::vector<double>& q_config);

	virtual void setConfiguration(int config);
   
	virtual void getConfiguration(int& config);

    virtual ~ZXXZXZJnt2CartPos();
  };
}//namespace
#endif

    
