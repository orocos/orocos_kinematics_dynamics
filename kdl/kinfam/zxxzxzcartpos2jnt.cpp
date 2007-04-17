/***************************************************************************
                        ZXXZXZCartPos2Jnt 
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

#include <iostream>
#include <kdl/kdl.hpp>
#include <kdl/constraints.hpp>
#include <kdl/frames_io.hpp>
#include <kdl/jacobianframe.hpp>
#include <kdl/kinfam/transformation.hpp>
#include <kdl/kinfam/zxxzxzcartpos2jnt.hpp>


using namespace KDL;


ZXXZXZCartPos2Jnt::ZXXZXZCartPos2Jnt(const ChainType* _chain):
    chain(_chain),
    configuration(4),
    q(_chain->nrOfJoints()),
    trans(_chain->transmission->clone())
{
}

void ZXXZXZCartPos2Jnt::setFrame(const Frame& _F_base_ee,int endpoint,int basepoint) {
  F_base_ee = _F_base_ee;
}

/**
 */
int ZXXZXZCartPos2Jnt::evaluate(JointVector& _q) 
{
  double P6x, P6y, P6z; /* Coordinates (in the base frame) of the 6th link */
  double Rxy_2;  /* square of XY distance betw. wrist & base of link2 */
  double Rxyz_2;  /* square of XYZ distance betw. wrist & base of link2 */
  double s1, c1, s2, c2, s3, c3, s4, c4, s5, c5, s6, c6; /* sin,cos of thetai */
  double s23, c23, s1c23, c1c23; /* temporary... */
  double d13, d23;
  double temp1, temp2;   /* ...storage */
  double const1, const2;
  double max_wrist_dist;
  double Pwx, Pwy, Pwz;
  double dWv, dWh;
  double l1, l2, l3, l6;
  
  l1 = chain->getLinkLength(1);
  l2 = chain->getLinkLength(2);
  l3 = chain->getLinkLength(3);
  l6 = chain->getLinkLength(6);
  
  const1 = l2*l2+l3*l3;
  const2 = 2*l2*l3;
  max_wrist_dist = const1 + const2;
  
  //s.singularitySet( Singularity::None );
  
  /* Coordinates of last link wrt base: */
  P6x = F_base_ee.M( 0, 2 ) * l6;
  P6y = F_base_ee.M( 1, 2 ) * l6;
  P6z = F_base_ee.M( 2, 2 ) * l6;
  
  /* Wrist position: (Low & Dubey eq.(34)) */
  Pwx = F_base_ee.p[ 0 ] - P6x;
  Pwy = F_base_ee.p[ 1 ] - P6y;
  Pwz = F_base_ee.p[ 2 ] - P6z;
  
  /* Calculation of relevant lengths: */
  dWv = Pwz - l1;
  Rxy_2 = Pwx * Pwx + Pwy * Pwy;
  Rxyz_2 = Rxy_2 + dWv * dWv;
 
  if ( (configuration & ChainType::Backward)!=ChainType::Backward)
    dWh = -sqrt( Rxy_2 );
  else
    dWh = sqrt( Rxy_2 );
  

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
  
  /* Calculation of q[0] by geometry of triangle formed by dWh and Rxy_2: */
  s1 = Pwx * dWh / Rxy_2;
  c1 = -Pwy * dWh / Rxy_2;
  q[ 0 ] = atan2( s1, c1 );
  
  /* Calculation of q[2]: (formulas (B6) and (36), Low and Dubey) */
  c3 = ( Rxyz_2 - const1 ) / const2;
  if ( (configuration & ChainType::ElbowDown)==ChainType::ElbowDown) 
    s3 = -sqrt( 1.0 - c3 * c3 );
  else
    s3 = sqrt( 1.0 - c3 * c3 );
  q[ 2 ] = atan2( s3, c3 );
  
  /* Calculation of q[1]: (formulas (37), Low and Dubey) */
  temp1 = l3 * c3 + l2;
  temp2 = l3 * s3;
  c2 = ( dWv * temp1 + dWh * temp2 ) / Rxyz_2;
  s2 = ( dWh - c2 * temp2 ) / temp1;
  q[ 1 ] = atan2( s2, c2 );
  
  /* Orientation of wrist wrt arm: Dij (formulas (42), Low and Dubey) */
  s23 = s2 * c3 + c2 * s3;
  c23 = c2 * c3 - s2 * s3;
  s1c23 = s1 * c23;
  c1c23 = c1 * c23;
  d13 = F_base_ee.M( 0, 2 ) * c1 + F_base_ee.M( 1, 2 ) * s1;
  d23 = -F_base_ee.M( 0, 2 ) * s1c23 + F_base_ee.M( 1, 2 ) * c1c23 + F_base_ee.M( 2, 2 ) * s23;
  
  /* Calculation of q[3], q[4] and q[5], eqs.(39)-(41) Low & Dubey: */
  if ( ( fabs( d13 ) <  ChainType::KINEMATICS_EPS ) && ( fabs( d23 ) <  ChainType::KINEMATICS_EPS ) ) {
      /* Z-axes of links 4 and 6 are parallel! q[3] keeps its previous value! */
      s4 = sin( q[ 3 ] );
      c4 = cos( q[ 3 ] );
      s5 = 0.0;
      q[ 4 ] = 0.0;
   } else {
	  if ( (configuration & ChainType::Flip)!=ChainType::Flip) {
		q[3] = atan2(d13,-d23);
      } else {
		q[3] = atan2(-d13,d23);
      }
      c4 = cos( q[ 3 ] );
      if ( fabs( d23 ) > ZXXZXZ::KINEMATICS_EPS )
		s4 = - c4 * d13 / d23;
      else
		s4 = sin( q[ 3 ] );
      c5 = F_base_ee.M( 0, 2 ) * s1 * s23 - F_base_ee.M( 1, 2 ) * c1 * s23 + F_base_ee.M( 2, 2 ) * c23;
      s5 = -d23 * c4 + d13 * s4;
      q[ 4 ] = atan2( s5, c5 );
    }

  s6 = -( F_base_ee.M( 0, 1 ) * c1 + F_base_ee.M( 1, 1 ) * s1 ) * c4 + ( F_base_ee.M( 0, 1 ) * s1c23 - F_base_ee.M( 1, 1 ) * c1c23 - F_base_ee.M( 2, 1 ) * s23 ) * s4;
  c6 = ( F_base_ee.M( 0, 0 ) * c1 + F_base_ee.M( 1, 0 ) * s1 ) * c4 + ( -F_base_ee.M( 0, 0 ) * s1c23 + F_base_ee.M( 1, 0 ) * c1c23 + F_base_ee.M( 2, 0 ) * s23 ) * s4;
  q[ 5 ] = atan2( s6, c6 );  

  trans->invPos(q,_q,chain->offset());

  //if ( fabs( s5 ) < EPS_PARALLEL_WRIST ){
  //  //s.singularitySet( Singularity::ParallelWrist );
  //  return 1;
  //}
  
  
  /*
    if ( s.isSingular( Singularity::AnySingularity ) )
    return false;
    else
    return true;
  */
  return 0;
  
}


ZXXZXZCartPos2Jnt* ZXXZXZCartPos2Jnt::clone() const {
	return new ZXXZXZCartPos2Jnt(chain);
}

ZXXZXZCartPos2Jnt::~ZXXZXZCartPos2Jnt() {
    delete trans;
};

  void ZXXZXZCartPos2Jnt::setConfiguration(const std::vector<double>& q_config) {
	 configuration=chain->getConfigurationFromJoints(q_config);	
  }

  void ZXXZXZCartPos2Jnt::getConfiguration(std::vector<double>& q_config) {
	 chain->setConfigurationToJoints(configuration,q_config);	
  }

  void  ZXXZXZCartPos2Jnt::setConfiguration(int config) {
	assert(0<=config);
	assert(config<=7);
	configuration = config;	
  }

  void  ZXXZXZCartPos2Jnt::getConfiguration(int& config) {
	config=configuration;	
  }



