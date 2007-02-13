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

#ifndef KDL_ZXXZXZCARTVEL2JNT_HPP
#define KDL_ZXXZXZCARTVEL2JNT_HPP

#include <kdl/kdl.hpp>
#include <kdl/kinfam/zxxzxz.hpp>
#include <kdl/kinfam/cartvel2jnt.hpp>
#include <kdl/kinfam/transmission.hpp>
#include <kdl/frames.hpp>


namespace KDL
{
    
    class ZXXZXZCartVel2Jnt : public CartVel2Jnt 
    {
        const ZXXZXZ* chain;
        int	configuration;
        std::vector<double> qdot;
        std::vector<double> q;
        Twist vel;
        Transmission* trans;
    
    public:
        ZXXZXZCartVel2Jnt(const ZXXZXZ* _chain);
        
        virtual int evaluate(const JointVector& q,JointVector& _qdot);
        virtual void setTwist(const Twist& t_base_ee,int endpoint=0,int basepoint=0);
        
        virtual void setConfiguration(const std::vector<double>& q_config);
        virtual void getConfiguration(std::vector<double>& q_config);

        virtual void setConfiguration(int config); 
        virtual void getConfiguration(int& config);
        
        virtual CartVel2Jnt* clone() const;

        virtual ~ZXXZXZCartVel2Jnt();
    };//class
}//namespace

    

#endif
