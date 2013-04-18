/***************************************************************************
  tag: Erwin Aertbelien  Mon May 10 19:10:36 CEST 2004  velocityprofile.cxx

                        velocityprofile.cxx -  description
                           -------------------
    begin                : Mon May 10 2004
    copyright            : (C) 2004 Erwin Aertbelien
    email                : erwin.aertbelien@mech.kuleuven.ac.be
    History				 : Wouter Bancken (08/2012) - Refactored

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
/*****************************************************************************
 *  \author
 *  	Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version
 *		ORO_Geometry V0.2
 *
 *	\par History
 *		- $log$
 *
 *	\par Release
 *		$Id: velocityprofile.cpp,v 1.1.1.1.2.3 2003/02/24 13:13:06 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/


#include "utilities/error.h"
#include "utilities/error_stack.h"
#include "motionprofile_rect.hpp"
#include "motionprofile_dirac.hpp"
#include "motionprofile_trap.hpp"
#include "motionprofile_traphalf.hpp"
#include <string.h>

namespace KDL {

using namespace std;

typedef boost::shared_ptr<MotionProfile_Dirac> MotionProfileDiracPtr;
typedef boost::shared_ptr<MotionProfile_Rectangular> MotionProfileRectangularPtr;
typedef boost::shared_ptr<MotionProfile_Trap> MotionProfileTrapPtr;
typedef boost::shared_ptr<MotionProfile_TrapHalf> MotionProfileTrapHalfPtr;

int MotionProfile::Read(istream& is, MotionProfilePtr& returned_profile) {
	IOTrace("MotionProfile::Read");
	char storage[25];
	EatWord(is,"[",storage,sizeof(storage));
	Eat(is,'[');
	int exit_code;
	if (strcmp(storage,"DIRACVEL")==0) {
		Eat(is,']');
		IOTracePop();
		MotionProfileDiracPtr profile;
		exit_code = MotionProfile_Dirac::Create(profile);
		if(exit_code != 0){
			returned_profile = MotionProfilePtr();
			return exit_code;
		}
		returned_profile = profile;
		return 0;
	} else if (strcmp(storage,"CONSTVEL")==0) {
		double vel;
		is >> vel;
		Eat(is,']');
		IOTracePop();
		MotionProfileRectangularPtr profile;
		exit_code = MotionProfile_Rectangular::Create(profile,vel);
		if(exit_code != 0){
			returned_profile = MotionProfilePtr();
			return exit_code;
		}
		returned_profile = profile;
		return 0;
	} else if (strcmp(storage,"TRAPEZOIDAL")==0) {
		double maxvel;
		double maxacc;
 		is >> maxvel;
		Eat(is,',');
		is >> maxacc;
		Eat(is,']');
		IOTracePop();
		MotionProfileTrapPtr profile;
		exit_code = MotionProfile_Trap::Create(profile,maxvel,maxacc);
		if(exit_code != 0){
			returned_profile = MotionProfilePtr();
			return exit_code;
		}
		returned_profile = profile;
		return 0;
	} else if (strcmp(storage,"TRAPEZOIDALHALF")==0) {
		double maxvel;
		double maxacc;
 		is >> maxvel;
		Eat(is,',');
		is >> maxacc;
		Eat(is,',');
		bool starting;
		is >> starting;
		Eat(is,']');
		IOTracePop();
		MotionProfileTrapHalfPtr profile;
		exit_code = MotionProfile_TrapHalf::Create(profile,maxvel,maxacc,starting);
		if(exit_code != 0){
			returned_profile = MotionProfilePtr();
			return exit_code;
		}
		returned_profile = profile;
		return 0;
	}
	else {
		returned_profile = MotionProfilePtr();
		return 151;
	}
	returned_profile = MotionProfilePtr();
	return 0;
}

}
