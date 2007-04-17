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

#include <kdl/kinfam/zxxzxzjnt2cartvel.hpp>
#include <kdl/kinfam/transmission.hpp>
#include <kdl/frames_io.hpp>

namespace KDL
{
    ZXXZXZJnt2CartVel::ZXXZXZJnt2CartVel(const ZXXZXZ* _chain):
        chain(_chain),
        F_base_ee(Frame::Identity()),
        vel_base(Twist::Zero()),
        q(_chain->nrOfJoints()),
        qdot(_chain->nrOfJoints()),
        configuration(4),
        trans(_chain->transmission->clone())
    {
    }
    
    int ZXXZXZJnt2CartVel::evaluate(const JointVector& _q, const JointVector& _qdot)
    {
        double c1, c2, c23, c4, c5, c6, s1, s2, s23, s4, s5, s6;
        double c1c23, c1s23, c4s5, s4s5, s1c23, s1s23, s5c6, s5s6;
        //double R;  /* distance (squared) shoulder-wrist */
        double dWh, dWv;
        double Pwx, Pwy, Pwz;
        double P6x, P6y, P6z;
        double l1, l2, l3, l6;
        double Wwy, Wwz; /* Angular velocity components of the wrist */
        double Wx, Wy, Vx, Vy; /* Angular and linear velocity
                                  components of end eff. */
        
        trans->fwdPos(_q,q,chain->offset());
        trans->fwdVel(_q,_qdot,qdot,chain->offset());
                
        l1 = chain->getLinkLength(1);
        l2 = chain->getLinkLength(2);
        l3 = chain->getLinkLength(3);
        l6 = chain->getLinkLength(6);
    
        c1 = cos( q[ 0 ] );
        s1 = sin( q[ 0 ] );
        c2 = cos( q[ 1 ] );
        s2 = sin( q[ 1 ] );
        c23 = cos( q[ 1 ] + q[ 2 ] );
        s23 = sin( q[ 1 ] + q[ 2 ] );
        c4 = cos( q[ 3 ] );
        s4 = sin( q[ 3 ] );
        c5 = cos( q[ 4 ] );
        s5 = sin( q[ 4 ] );
        c6 = cos( q[ 5 ] );
        s6 = sin( q[ 5 ] );
        s5c6 = s5 * c6;
        s5s6 = s5 * s6;
        c4s5 = c4 * s5;
        s4s5 = s4 * s5;
        c1c23 = c1 * c23;
        c1s23 = c1 * s23;
        s1c23 = s1 * c23;
        s1s23 = s1 * s23;
        
        F_base_ee.M( 1, 0 ) = s4 * c5 * s6 - c4 * c6;
        F_base_ee.M( 2, 0 ) = c4 * c5 * s6 + s4 * c6;
        F_base_ee.M( 0, 0 ) = -s1c23 * F_base_ee.M( 2, 0 ) - c1 * F_base_ee.M( 1, 0 ) + s1s23 * s5s6;
        F_base_ee.M( 1, 0 ) = c1c23 * F_base_ee.M( 2, 0 ) - s1 * F_base_ee.M( 1, 0 ) - c1s23 * s5s6;
        F_base_ee.M( 2, 0 ) = s23 * F_base_ee.M( 2, 0 ) + c23 * s5s6;
        
        F_base_ee.M( 1, 1 ) = s4 * c5 * c6 + c4 * s6;
        F_base_ee.M( 2, 1 ) = c4 * c5 * c6 - s4 * s6;
        F_base_ee.M( 0, 1 ) = -s1c23 * F_base_ee.M( 2, 1 ) - c1 * F_base_ee.M( 1, 1 ) + s1s23 * s5c6;
        F_base_ee.M( 1, 1 ) = c1c23 * F_base_ee.M( 2, 1 ) - s1 * F_base_ee.M( 1, 1 ) - c1s23 * s5c6;
        F_base_ee.M( 2, 1 ) = s23 * F_base_ee.M( 2, 1 ) + c23 * s5c6;
    
        F_base_ee.M( 0, 2 ) = s1c23 * c4s5 + c1 * s4s5 + s1s23 * c5;
        F_base_ee.M( 1, 2 ) = - c1c23 * c4s5 + s1 * s4s5 - c1s23 * c5;
        F_base_ee.M( 2, 2 ) = - s23 * c4s5 + c23 * c5;//OK           

        /* vertical distance of wrist from shoulder: */
        dWv = c2 * l2 + c23 * l3;
        /* horizontal distance of wrist from shoulder: */
        dWh = - s2 * l2 - s23 * l3;
    
       /* Position of wrist: */
        Pwx = - s1 * dWh;
        Pwy = + c1 * dWh;
        Pwz = l1 + dWv;

        /* Position of last link: */
        P6x = F_base_ee.M( 0, 2 ) * l6;
        P6y = F_base_ee.M( 1, 2 ) * l6;
        P6z = F_base_ee.M( 2, 2 ) * l6;
        
        F_base_ee.p[ 0 ] = P6x + Pwx;
        F_base_ee.p[ 1 ] = P6y + Pwy;
        F_base_ee.p[ 2 ] = P6z + Pwz;

        /* Forward velocity transformation according to Featherstone eqs.(37)-(43) */
        Wwy = -s4 * qdot[ 4 ] + c4s5 * qdot[ 5 ];
        Wwz = qdot[ 3 ] + c5 * qdot[ 5 ];
        
        Wx = -c4 * qdot[ 4 ] - s4s5 * qdot[ 5 ] - qdot[ 1 ] - qdot[ 2 ];
        Wy = c23 * Wwy + s23 * Wwz;
        
        vel_base( 3 ) = - c1 * Wx + s1 * Wy;
        vel_base( 4 ) = - c1 * Wy - s1 * Wx;
        vel_base( 5 ) = qdot[ 0 ] + c23 * Wwz - s23 * Wwy;
        
        Vx = -dWh * qdot[ 0 ];
        Vy = dWv * qdot[ 1 ] + l3 * c23 * qdot[ 2 ];
        
        //29/03/2005 changed velocity_base from ee-frame to base_frame
        
        vel_base( 0 ) = c1 * Vx + s1 * Vy + vel_base( 4 ) * P6z - vel_base( 5 ) * P6y;
        vel_base( 1 ) = -c1 * Vy + s1 * Vx + vel_base( 5 ) * P6x - vel_base( 3 ) * P6z;
        vel_base( 2 ) = dWh * qdot[ 1 ] - l3 * s23 * qdot[ 2 ] + vel_base( 3 ) * P6y - vel_base( 4 ) * P6x;
        
        /* CALCULATION OF CONFIGURATION: */
        configuration = 0;
        if (dWh < 0) configuration|=ZXXZXZ::Backward;	
        if (q[4]< 0) configuration|=ZXXZXZ::Flip;
        if (q[2]< 0) configuration|=ZXXZXZ::ElbowDown;
        
        return 0;
    }
    

    void ZXXZXZJnt2CartVel::getFrameVel( FrameVel& FV_base_ee, int endpoint, int basepoint)
    {
        FV_base_ee = FrameVel(F_base_ee,vel_base);
    }
    

    void ZXXZXZJnt2CartVel::setConfiguration(const std::vector<double>& q_config) 
    {
        configuration=chain->getConfigurationFromJoints(q_config);	
    }
    void ZXXZXZJnt2CartVel::getConfiguration(std::vector<double>& q_config) 
    {
        chain->setConfigurationToJoints(configuration,q_config);	
    }
    
    void  ZXXZXZJnt2CartVel::setConfiguration(int config) 
    {
        assert(0<=config);
        assert(config<=7);
        configuration = config;	
    }
    
    void  ZXXZXZJnt2CartVel::getConfiguration(int& config) 
    {
        config=configuration;	
    }

    Jnt2CartVel* ZXXZXZJnt2CartVel::clone() const {
        return new ZXXZXZJnt2CartVel(chain);
    }
    
    ZXXZXZJnt2CartVel::~ZXXZXZJnt2CartVel() {
        delete trans;
    }
}//namespace


