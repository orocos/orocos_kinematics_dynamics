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

#include <kdl/kinfam/zxxzxzcartvel2jnt.hpp>
#include <kdl/kinfam/transmission.hpp>
#include <kdl/frames_io.hpp>

namespace KDL
{
    ZXXZXZCartVel2Jnt::ZXXZXZCartVel2Jnt(const ZXXZXZ* _chain):
        chain(_chain),
        configuration(4),
        qdot(_chain->nrOfJoints()),
        q(_chain->nrOfJoints()),
        vel(Twist::Zero()),
        trans(_chain->transmission->clone())
    {
    }
    
    void ZXXZXZCartVel2Jnt::setTwist(const Twist& _vel,int endpoint,int basepoint)
    {
        vel = _vel;
    }
    
    int ZXXZXZCartVel2Jnt::evaluate(const JointVector& _q,JointVector& _qdot)
    {
        double Vwx, Vwy, Vwz; /* Translational velocity components of
                                 wrist */
        double Wx, Wy, temp1, temp2;
        double Wwy, Wwz /* Rotational velocity components of wrist */;
        
        double P6x, P6y, P6z; /* Coordinates (in the base frame) of the 6th link */
        //double Rxy_2;  /* square of XY distance betw. wrist & base of link2 */
        //double Rxyz_2;  /* square of XYZ distance betw. wrist & base of link2 */
        double s1, c1, s2, c2, s3, s4, c4, s5, c5, s6, c6; /* sin,cos of thetai */
        double s23, c23, s1c23, c1c23, c1s23,s1s23, c4s5, s5c6, s5s6,s4s5; /* temporary... */
        //double d13, d23;
        //double max_wrist_dist;
        double Vx, Vy;
        double Pwx, Pwy, Pwz;
        double dWv, dWh;
        double l1, l2, l3, l6;
        
        trans->fwdPos(_q,q,chain->offset());
        
        l1 = chain->getLinkLength(1);
        l2 = chain->getLinkLength(2);
        l3 = chain->getLinkLength(3);
        l6 = chain->getLinkLength(6);
        
        c1 = cos( q[ 0 ] );
        s1 = sin( q[ 0 ] );
        c2 = cos( q[ 1 ] );
        s2 = sin( q[ 1 ] );
        s3 = sin( q[ 2 ] );
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

        /* vertical distance of wrist from shoulder: */
        dWv = c2 * l2 + c23 * l3;
        /* horizontal distance of wrist from shoulder: */
        dWh = - s2 * l2 - s23 * l3;
        
        /* Position of last link: */
        P6x =(  s1c23 * c4s5 + c1 * s4s5 + s1s23 * c5   )* l6;
        P6y =(  - c1c23 * c4s5 + s1 * s4s5 - c1s23 * c5 )* l6;
        P6z =(  - s23 * c4s5 + c23 * c5                 )* l6;
        
        /* Position of wrist: */
        Pwx = - s1 * dWh;
        Pwy = + c1 * dWh;
        Pwz = l1 + dWv;
        
        //  Arm extended?
        //if ( Rxyz_2 > ( max_wrist_dist - EPS_ARM_EXTENDED * EPS_ARM_EXTENDED ) )
        //  {
        //    // s.singularitySet( Singularity::ArmExtended );
        //    /*Out of reach? */
        //    if ( Rxyz_2 > max_wrist_dist )
        //	//s.singularitySet( Singularity::OutOfReach );
        //	return 1;
        //  }
        //
        ///* Wrist is above shoulder? */
        //if ( fabs( dWh ) < EPS_WRIST_ABOVE_BASE )
        //  {
        //    //s.singularitySet( Singularity::WristAboveBase );
        //    return 1;
        //  }
        
        
        /* Inverse velocity calculations: */
        
        /* Calculation of wrist velocity: Low & Dubey, eq.(47) */
        Vwx = vel( 0 ) - vel( 4 ) * P6z + vel( 5 ) * P6y;
        
        Vwy = vel( 1 ) - vel( 5 ) * P6x + vel( 3 ) * P6z;

        Vwz = vel( 2 ) - vel( 3 ) * P6y + vel( 4 ) * P6x;

        /* First, second and third joint velocities: eqs.(44)-(45), Low & Dubey,
           eqs.(6.24),(6.25) Brochier & Haverhals */
        
        Vx = c1 * Vwx + s1 * Vwy;
        Vy = - c1 * Vwy + s1 * Vwx;
        
        qdot[ 0 ] = -( Vx ) / dWh;
        
        qdot[ 1 ] = ( s23 * Vy + c23 * Vwz ) / l2 / s3;

        qdot[ 2 ] = ( dWh * Vy - dWv * Vwz ) / l2 / l3 / s3;

        /* Velocity of end effector wrt the wrist: */
        Wx = - c1 * vel( 3 ) - s1 * vel( 4 );
        Wy = s1 * vel( 3 ) - c1 * vel( 4 );

        temp1 = vel( 5 ) - qdot[ 0 ];
        temp2 = Wx + qdot[ 1 ] + qdot[ 2 ];
        
        Wwy = c23 * Wy - s23 * temp1;
        Wwz = s23 * Wy + c23 * temp1;

        /* Fourth, fifth and sixth joint velocities: eqs.(48)-(50) Low & Dubey */
        qdot[ 4 ] = -s4 * Wwy - c4 * temp2;
        qdot[ 5 ] = ( c4 * Wwy - s4 * temp2 ) / s5;
        qdot[ 3 ] = Wwz - c5 * qdot[5];
        

        trans->invVel(q,qdot,_qdot,chain->offset());

        return 0;
    }
    
    void ZXXZXZCartVel2Jnt::setConfiguration(const std::vector<double>& q_config) {
        configuration=chain->getConfigurationFromJoints(q_config);	
    }
    
    void ZXXZXZCartVel2Jnt::getConfiguration(std::vector<double>& q_config) {
        chain->setConfigurationToJoints(configuration,q_config);	
    }
    
    void  ZXXZXZCartVel2Jnt::setConfiguration(int config) {
        assert(0<=config);
        assert(config<=7);
        configuration = config;	
    }
    
    void  ZXXZXZCartVel2Jnt::getConfiguration(int& config) {
        config=configuration;	
    }

    CartVel2Jnt*  ZXXZXZCartVel2Jnt::clone() const
    {
        return new ZXXZXZCartVel2Jnt(chain);
    }

    ZXXZXZCartVel2Jnt::~ZXXZXZCartVel2Jnt()
    {
        delete trans;
    }
    
}//namespace
