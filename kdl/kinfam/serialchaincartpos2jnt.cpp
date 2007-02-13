/***************************************************************************
                        SerialChainCartPos2Jnt 
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

#include <kdl/kdl.hpp>
#include <kdl/kinfam/transformation.hpp>
#include <kdl/kinfam/serialchaincartpos2jnt.hpp>
#include <kdl/kinfam/serialchainjnt2jac.hpp>
#include <kdl/kinfam/jnt2jac.hpp>
#include <kdl/jacobianframe.hpp>
#include <kdl/constraints.hpp>
#include <iostream>
#include <kdl/frames_io.hpp>

using namespace KDL;

void SerialChainCartPos2Jnt::setConfiguration(const std::vector<double>& q_config) {
	assert(this->q_config.size()==q_config.size());
	for (unsigned int i=0;i<q_config.size();i++) {
		this->q_config[i] = q_config[i];
	}
} 


void SerialChainCartPos2Jnt::getConfiguration(std::vector<double>& q_config) {
	assert(this->q_config.size()==q_config.size());
	for (unsigned int i=0;i<q_config.size();i++) {
		q_config[i] = this->q_config[i];
	}
}

/**
 * \todo 
 *    BUG: ConstraintMatrix cannot be called with the exact number of joints. Why ?
 */
SerialChainCartPos2Jnt::SerialChainCartPos2Jnt(const SerialChain* _chain):
	chain(_chain),
	jnt2jac(new SerialChainJnt2Jac(_chain,0)),   // construct a serialchainjnt2jac with offset 0.
	FJ_base_actual(_chain->nrOfJoints()),
	cm(30,30),   
	djv(_chain->nrOfJoints()),
	jv(_chain->nrOfJoints()),
	q_config(_chain->nrOfJoints()),
	maxiter(200),
	stopcriterium(1E-6)
{
	assert(jnt2jac!=0);
	cm.eps = 1E-10;	
}

void SerialChainCartPos2Jnt::setFrame(const Frame& _F_base_ee,int endpoint,int basepoint) {
	F_base_ee = _F_base_ee;
}

/**
 * A first,preliminary implementation :
 * \todo
 *    analysis and improvement of the convergence and convergence
 *    criterium.  For now, it's something similar to Newton iterations.
 */
int SerialChainCartPos2Jnt::evaluate(std::vector<double>& jv_act) {
    //no transformation: the whole algorithm plays in actuator space.
    //But the joint offsets are taken into account :
	assert( (int)q_config.size() == chain->nrOfJoints() );
    for (unsigned int i=0;i<q_config.size();++i)
        jv[i]=q_config[i];
	double kpos = 0.4;
	double krot = 0.4;
	double wp   = 1;
	double wr	= 1;
	Twist d_base; 
	iter = 0;
	do {
		int result=jnt2jac->evaluate(jv);
		if (result!=0) return result;
		jnt2jac->getJacobian(FJ_base_actual);
		cm.resetConstraints(chain->nrOfJoints());
		cm.addConstraint(FJ_base_actual,kpos,krot,F_base_ee,Twist::Zero(),wp,wr);	
		cm.calculateOutput(djv);	
		for (unsigned int i=0;i<jv.size();++i) {
			jv[i] += djv[i];
		}
		d_base = diff(FJ_base_actual.value(), F_base_ee,1);
		difference = d_base.rot.Norm() + d_base.vel.Norm();
		iter++;
		//std::cout << "Iteration "<< iter << " difference= " << difference << std::endl;
		//std::cout << "F_base_ee " << F_base_ee << std::endl;
		//std::cout << "F_base_actual " << FJ_base_actual.value() << std::endl;
		
		if (iter > maxiter) {
			return 2;
		}
	} while (difference> stopcriterium);
	for (unsigned int i=0;i<jv_act.size();i++) {
        jv_act[i+chain->offset()]   = jv[i];
		q_config[i] = jv[i];
    }
	//std::cout << "number of iterations " << iter << std::endl;
	return 0;
}

SerialChainCartPos2Jnt* SerialChainCartPos2Jnt::clone() const {
	return new SerialChainCartPos2Jnt(chain);
}

SerialChainCartPos2Jnt::~SerialChainCartPos2Jnt() {
	delete jnt2jac;
};




