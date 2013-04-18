/***************************************************************************
  tag: Erwin Aertbelien  Mon May 10 19:10:36 CEST 2004  velocityprofile_rect.cxx

                        velocityprofile_rect.cxx -  description
                           -------------------
    begin                : Mon May 10 2004
    copyright            : (C) 2012 Wouter Bancken
    					   (C) 2004 Erwin Aertbelien
    email                : erwin.aertbelien@mech.kuleuven.ac.be

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
 *		$Id: velocityprofile_rect.cpp,v 1.1.1.1.2.5 2003/07/24 13:26:15 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/


#include "utilities/error.h"
#include "motionprofile_rect.hpp"

namespace KDL {

int MotionProfile_Rectangular::Create(MotionProfileRectangularPtr& profile, double _maxvel)
{
	profile = MotionProfileRectangularPtr(new MotionProfile_Rectangular());
	profile->maxvel = _maxvel;
	return 0;
}

int MotionProfile_Rectangular::Create(MotionProfileRectangularPtr& profile, double _maxvel, double pos1, double pos2)
{
	Create(profile,_maxvel);
	profile->SetProfile(pos1,pos2);
	return 0;
}

void MotionProfile_Rectangular::SetProfile(double pos1,double pos2)
{
	double diff;
	diff = pos2-pos1;          // increment per sec.
    if ( diff != 0 )
        {
            v    = (diff>0)?maxvel:-maxvel;
            p    = pos1;               // start pos
            d    = diff/v;
        }
    else
        {
            v = 0;
            p = pos1;
            d = 0;
        }
}

void MotionProfile_Rectangular::SetMax( double vMax )
{
    maxvel = vMax;
}


void MotionProfile_Rectangular::
	SetProfileDuration(double pos1,double pos2,double duration)
{
	double diff;
	diff = pos2-pos1;          // increment per sec.
    if ( diff != 0 )
        {
            v    = diff/duration;
            if (v > maxvel || duration==0 ) // safety.
                v=maxvel;
            p    = pos1;               // start pos
            d    = diff/v;
        }
    else
        {
            v    = 0;
            p    = pos1;
            d    = duration;
        }
}

double MotionProfile_Rectangular::Duration() const {
	return d;
}

int MotionProfile_Rectangular::Pos(double time, double& returned_position) const {
    if (time < 0) {
        returned_position = p;
        return 0;
    } else if (time>d) {
        returned_position = v*d+p;
        return 0;
    } else {
        returned_position = v*time+p;
        return 0;
    }
}

int MotionProfile_Rectangular::Vel(double time, double& returned_velocity) const {
    if (time < 0) {
        returned_velocity = 0;
        return 0;
    } else if (time>d) {
        returned_velocity = 0;
        return 0;
    } else {
        returned_velocity = v;
        return 0;
    }
}

int MotionProfile_Rectangular::Acc(double time, double& returned_acceleration) const {
	return 153;
}

void MotionProfile_Rectangular::Write(std::ostream& os) const {
	os << "CONSTVEL[" << maxvel << "]";
}
}

