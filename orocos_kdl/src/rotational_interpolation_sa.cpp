/***************************************************************************
  tag: Erwin Aertbelien  Mon May 10 19:10:36 CEST 2004  rotational_interpolation_sa.cxx

                        rotational_interpolation_sa.cxx -  description
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
 *		$Id: rotational_interpolation_singleaxis.cpp,v 1.1.1.1.2.2 2003/02/24 13:13:06 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/


#include "rotational_interpolation_sa.hpp"
#include "trajectory.hpp"

namespace KDL {

int RotationalInterpolation_SingleAxis::Create(RotationalInterpolationSingleAxisPtr& interpolation)
{
	interpolation = RotationalInterpolationSingleAxisPtr(new RotationalInterpolation_SingleAxis());
	return 0;
}

void RotationalInterpolation_SingleAxis::SetStartEnd(Rotation start,Rotation end) {
	R_base_start = start;
	R_base_end   = end;
	Rotation R_start_end = R_base_start.Inverse()*R_base_end;
	angle = R_start_end.GetRotAngle(rot_start_end);
}

int RotationalInterpolation_SingleAxis::Pos(double theta, Rotation& returned_position) const {
	returned_position = R_base_start* Rotation::Rot2(rot_start_end,theta);
	return 0;
}

int RotationalInterpolation_SingleAxis::Vel(double theta,double thetad, Vector& returned_velocity) const {
	returned_velocity = R_base_start * ( rot_start_end*thetad );
	return 0;
}

int RotationalInterpolation_SingleAxis::Acc(double theta,double thetad,double thetadd, Vector& returned_acceleration) const {
	returned_acceleration = R_base_start * ( rot_start_end* thetadd);
	return 0;
}

double RotationalInterpolation_SingleAxis::Angle() {
	return angle;
}

void RotationalInterpolation_SingleAxis::Write(std::ostream& os) const {
	os << "SingleAxis[] " << std::endl;
}

RotationalInterpolation_SingleAxis::~RotationalInterpolation_SingleAxis() {
}


boost::shared_ptr<RotationalInterpolation> RotationalInterpolation_SingleAxis::Clone() const {
	RotationalInterpolationSingleAxisPtr interpolation;
	RotationalInterpolation_SingleAxis::Create(interpolation);
	return interpolation;
}

}

