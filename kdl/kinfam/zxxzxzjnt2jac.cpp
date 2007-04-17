/***************************************************************************
                        ZXXZXZJnt2Jac.hpp 
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

#include <kdl/kinfam/zxxzxzjnt2jac.hpp>

namespace KDL {


  //===========================================
  // implementation of ZXXZXZJnt2Jac
  //===========================================
  
  ZXXZXZJnt2Jac::ZXXZXZJnt2Jac(const ChainType* _chain):
    chain(_chain),
    Twists(_chain->nrOfJoints()),
    q(_chain->nrOfJoints()),
    FJ_base_ee_local(_chain->nrOfJoints()),
    trans(_chain->transmission->clone())
  {
    for(unsigned int i = 0;i<6;i++)
      SetToZero(Twists[i]);
  }
  
  int ZXXZXZJnt2Jac::evaluate( const JointVector& _q)
  {
    
    double c1, c2, c23, c4, c5, c6, s1, s2, s23, s4, s5, s6;
    double c1c23, c1s23, c4s5, s4s5, s1c23, s1s23, s5c6, s5s6;
    double P6x, P6y, P6z; /* Coordinates of the last link */
    //double R;  /* distance (squared) shoulder-wrist */
    double dWh, dWv;
    double Pwx, Pwy, Pwz;
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
    F_base_ee.M( 2, 2 ) = - s23 * c4s5 + c23 * c5;
    
    /* vertical distance of wrist from shoulder: */
    dWv = c2 * l2 + c23 * l3;
    /* horizontal distance of wrist from shoulder: */
    dWh = - s2 * l2 - s23 * l3;
    
    /* Position of last link: */
    P6x = F_base_ee.M( 0, 2 ) * l6;
    P6y = F_base_ee.M( 1, 2 ) * l6;
    P6z = F_base_ee.M( 2, 2 ) * l6;
    
    /* Position of wrist: */
    Pwx =  - s1 * dWh;
    Pwy =  c1 * dWh;
    Pwz = l1 + dWv;
    
    /* End effector position = position of last link + position of wrist: */
    F_base_ee.p[ 0 ] = P6x + Pwx;
    F_base_ee.p[ 1 ] = P6y + Pwy;
    F_base_ee.p[ 2 ] = P6z + Pwz;
    

    /* , eq.(37)-(43) */
    /* Angular velocity components: */
    Twists[ 0 ]( 3 ) = Twists[ 0 ]( 4 ) = Twists[ 1 ]( 5 ) = Twists[ 2 ]( 5 ) = 0.;
    
    Twists[ 1 ]( 3 ) = Twists[ 2 ]( 3 ) = c1;
    Twists[ 3 ]( 3 ) = s1s23;
    Twists[ 4 ]( 3 ) = c1 * c4 - s1c23 * s4;
    Twists[ 5 ]( 3 ) = s1 * ( c23 * c4s5 + s23 * c5 ) + c1 * s4s5;
    	       
    Twists[ 1 ]( 4 ) = Twists[ 2 ]( 4 ) = s1;
    Twists[ 3 ]( 4 ) = - c1s23;
    Twists[ 4 ]( 4 ) = s1 * c4 + c1c23 * s4;
    Twists[ 5 ]( 4 ) = s1 * s4s5 - c4s5 * c1c23 - c1s23 * c5;
    	       
    Twists[ 0 ]( 5 ) = 1.;
    Twists[ 3 ]( 5 ) = c23;
    Twists[ 4 ]( 5 ) = s23 * s4;
    Twists[ 5 ]( 5 ) = c23 * c5 - s23 * c4s5;
    
    /* Linear velocity components: */
    Twists[ 0 ]( 0 ) = -(P6y+Pwy);
    Twists[ 1 ]( 0 ) = Twists[ 2 ]( 0 ) = s1 * P6z;
    Twists[ 1 ]( 0 ) += s1 * dWv;
    Twists[ 2 ]( 0 ) += s1c23 * l3;
    Twists[ 3 ]( 0 ) = - Twists[ 3 ]( 5 ) * P6y + Twists[ 3 ]( 4 ) * P6z;
    Twists[ 4 ]( 0 ) = - Twists[ 4 ]( 5 ) * P6y + Twists[ 4 ]( 4 ) * P6z;
    Twists[ 5 ]( 0 ) = - Twists[ 5 ]( 5 ) * P6y + Twists[ 5 ]( 4 ) * P6z;
    
    Twists[ 0 ]( 1 ) = (P6x+Pwx);
    Twists[ 1 ]( 1 ) = Twists[ 2 ]( 1 ) = -c1 * P6z;
    Twists[ 1 ]( 1 ) -= c1 * dWv;
    Twists[ 2 ]( 1 ) -= c1c23 * l3;
    Twists[ 3 ]( 1 ) = - Twists[ 3 ]( 3 ) * P6z + Twists[ 3 ]( 5 ) * P6x;
    Twists[ 4 ]( 1 ) = - Twists[ 4 ]( 3 ) * P6z + Twists[ 4 ]( 5 ) * P6x;
    Twists[ 5 ]( 1 ) = - Twists[ 5 ]( 3 ) * P6z + Twists[ 5 ]( 5 ) * P6x;
    	     	 	     
    Twists[ 0 ]( 2 ) = 0.;
    Twists[ 1 ]( 2 ) = Twists[ 2 ]( 2 ) = c1 * P6y - s1 * P6x;
    Twists[ 1 ]( 2 ) += dWh;
    Twists[ 2 ]( 2 ) -= s23 * l3;
    Twists[ 3 ]( 2 ) = - Twists[ 3 ]( 4 ) * P6x + Twists[ 3 ]( 3 ) * P6y;
    Twists[ 4 ]( 2 ) = - Twists[ 4 ]( 4 ) * P6x + Twists[ 4 ]( 3 ) * P6y;
    Twists[ 5 ]( 2 ) = - Twists[ 5 ]( 4 ) * P6x + Twists[ 5 ]( 3 ) * P6y;


	configuration = 0;
	if (dWh < 0.0) configuration|=ChainType::Backward;	
	if (q[4]< 0.0) configuration|=ChainType::Flip;
	if (q[2]< 0.0) configuration|=ChainType::ElbowDown;
	
    
    /*
    // CALCULATION OF SINGULARITIES:
    s.singularitySet( Singularity::None );
    if ( fabs( dWh ) < EPS_WRIST_ABOVE_BASE )
    s.singularitySet( Singularity::WristAboveBase );
    
    R = dWv * dWv + dWh * dWh;
    
    if ( R > ( max_wrist_dist - EPS_ARM_EXTENDED * EPS_ARM_EXTENDED ) )
    {
    s.singularitySet( Singularity::ArmExtended );
    
    if ( R > max_wrist_dist )
    s.singularitySet( Singularity::OutOfReach );
    }
    
    if ( fabs( s5 ) < EPS_PARALLEL_WRIST )
    s.singularitySet( Singularity::ParallelWrist );
    
    if ( s.isSingular( Singularity::AnySingularity ) )
      return false;
    else
      return true;
    */
    return 0;
  }
  
  void ZXXZXZJnt2Jac::getJacobian(Jacobian<Frame>& FJ_base_ee,int endpoint, int basepoint) 
  {
    FJ_base_ee_local.value() = F_base_ee;
    // fill in Jacobian :
    for (unsigned int i=0;i<6;++i) {
      FJ_base_ee_local.deriv(i) = Twists[i];
    }
    trans->invJac(FJ_base_ee_local,FJ_base_ee,chain->offset());
  }
  
  Jnt2Jac* ZXXZXZJnt2Jac::clone() const {
    return new ZXXZXZJnt2Jac(chain);
  }

  ZXXZXZJnt2Jac::~ZXXZXZJnt2Jac() {
    delete trans;
  }

  void ZXXZXZJnt2Jac::setConfiguration(const std::vector<double>& q_config) {
	 configuration=chain->getConfigurationFromJoints(q_config);	
  }
  void ZXXZXZJnt2Jac::getConfiguration(std::vector<double>& q_config) {
	chain->setConfigurationToJoints(configuration,q_config);	
  }
  void  ZXXZXZJnt2Jac::setConfiguration(int config) {
	assert(0<=config);
	assert(config<=7);
	configuration = config;	
  }
  void  ZXXZXZJnt2Jac::getConfiguration(int& config) {
	config=configuration;	
  }

} // end of namespace KDL
