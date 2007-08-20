/***************************************************************************
                        jacobianframe.cpp -  description
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

#include <kdl/jacobianframe.hpp>

namespace KDL {


#if 0
/**
 * \brief function to get the euler zyx angles. 
 * \param JR input parameter that indicates the Rotation and Jacobian with the rotational velocities.
 * \param gamma output parameter will contain the amount of rotation around X.  
 * \param beta output parameter will contain the amount of rotation around Y.
 * \param alpha output parameter will contain the amount of rotation around Z.
 * \retval 0 if successfull, otherwise its a singular situation.
 */
 int GetEulerZYX(const Jacobian<Rotation>& JR, 
				  Jacobian<double>& gamma, 
				  Jacobian<double>& beta, 
				  Jacobian<double>& alpha,
				  double eps) {
	// position-domain :
	JR.value().GetEulerZYX(alpha.value(),beta.value(),gamma.value());
	double ca = ::cos(alpha.value()); 
	double sa = ::sin(alpha.value()); 
	double cb = ::cos(beta.value()); 
	double sb = ::sin(beta.value()); 
	// velocity-domain :
	assert(gamma.nrOfDeriv()==JR.nrOfDeriv());
	assert(beta.nrOfDeriv()==JR.nrOfDeriv());
	assert(alpha.nrOfDeriv()==JR.nrOfDeriv());
    for (int i=0;i<JR.nrOfDeriv();++i) {
		if (JR.hasDeriv(i) ) {
			Vector w = JR.deriv(i);			
			double dgamma = (ca*w[0]+sa*w[1]);
			if (fabs(cb) < eps) { 
				if (fabs(dgamma)< eps) {
					dgamma = 0.0;  // arbitrary choice
				} else {
					return 1;
				}
			} else {
				dgamma /= cb;
			}
			double dalpha = w[2] + sb*dgamma;
			double dbeta  = -sa*w[0]+ca*w[1];
			gamma.deriv(i)=dgamma;
			alpha.deriv(i)=dalpha;
			beta.deriv(i) =dbeta;
		} else {
			gamma.setDeriv(i,false);
			beta.setDeriv(i,false);
			alpha.setDeriv(i,false);
		}
	}
	return 0;
 }
/**
 * \brief funcion to set the euler zyx angles. 
 * \param gamma input parameter that contains the amount of rotation around X.  
 * \param beta input parameter that contains the amount of rotation around Y.
 * \param alpha output parameter that contains the amount of rotation around Z.
 * \param JR output parameter that will contain the Rotation and Jacobian with the rotational velocities.
 */
 void SetEulerZYX(const Jacobian<double>& gamma, 
				  const Jacobian<double>& beta, 
				  const Jacobian<double>& alpha,
 				  Jacobian<Rotation>& JR) {
	// position-domain :
	JR.value() = Rotation::EulerZYX(alpha.value(),beta.value(),gamma.value());
	double ca = ::cos(alpha.value()); 
	double sa = ::sin(alpha.value()); 
	double cb = ::cos(beta.value()); 
	double sb = ::sin(beta.value()); 
	// velocity-domain :
	assert(gamma.nrOfDeriv()==JR.nrOfDeriv());
	assert(beta.nrOfDeriv()==JR.nrOfDeriv());
	assert(alpha.nrOfDeriv()==JR.nrOfDeriv());
    for (int i=0;i<gamma.nrOfDeriv();++i) {
		if (gamma.hasDeriv(i) || beta.hasDeriv(i) || alpha.hasDeriv(i) ) {
			Vector w;
			double dalpha  = alpha.deriv(i);
			double dbeta   = beta.deriv(i);
			double dgamma  = gamma.deriv(i);
			w[0] = -sa*dbeta + ca*cb*dgamma;
			w[1] =  ca*dbeta + sa*cb*dgamma;
			w[2] =  dalpha - sb*dgamma; 
			JR.deriv(i) = w;
		} else {
			JR.setDeriv(i,false);
		}
	}
}

#endif
} // end of namespace
