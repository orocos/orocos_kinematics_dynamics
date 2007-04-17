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

#ifndef KDL_ZXXZXZJNT2CARTVEL_HPP
#define KDL_ZXXZXZJNT2CARTVEL_HPP

#include <kdl/frames.hpp>
#include <kdl/framevel.hpp>
#include <kdl/kinfam/zxxzxz.hpp>
#include <kdl/kinfam/jnt2cartvel.hpp>
#include <kdl/kinfam/transmission.hpp>

namespace KDL
{
    
    class ZXXZXZJnt2CartVel : public Jnt2CartVel
    {
    private:
        const ZXXZXZ*      chain;
        Frame              F_base_ee;
        Twist              vel_base;
        JointVector        q;
        JointVector        qdot;
        int                configuration;
        Transmission*      trans;
        
    public:
        ZXXZXZJnt2CartVel(const ZXXZXZ* _chian);
        
        virtual int evaluate(const JointVector& _q, const JointVector& _qdot);
        
        virtual void getFrameVel( FrameVel& FV_base_ee, int endpoint=0,int basepoint=0);

        virtual void setConfiguration(const std::vector<double>& q_config);
        
        virtual void getConfiguration(std::vector<double>& q_config);
        
        virtual void setConfiguration(int config);
        
        virtual void getConfiguration(int& config);
        
        virtual Jnt2CartVel* clone() const;
        virtual ~ZXXZXZJnt2CartVel();
        
    };//class
}//namespace

#endif    
