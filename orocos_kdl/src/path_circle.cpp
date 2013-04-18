/***************************************************************************
  tag: Erwin Aertbelien  Mon May 10 19:10:36 CEST 2004  path_circle.cxx

                        path_circle.cxx -  description
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
 *		$Id: path_circle.cpp,v 1.1.1.1.2.5 2003/07/24 13:26:15 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/


#include "path_circle.hpp"
#include "utilities/error.h"

namespace KDL {

int Path_Circle::Create(const Frame& F_base_start,
		const Vector& _V_base_center,
		const Vector& V_base_p,
		const Rotation& R_base_end,
		double alpha,
		RotationalInterpolationPtr _orient,
		double _eqradius,
        PathCirclePtr& returned_circle,
        bool _aggregate
        )
		{
			returned_circle = PathCirclePtr(new Path_Circle());

			returned_circle->orient = _orient;
			returned_circle->eqradius = _eqradius;
			returned_circle->aggregate = _aggregate;

			returned_circle->F_base_center.p = _V_base_center;
			returned_circle->orient->SetStartEnd(F_base_start.M,R_base_end);
			double oalpha = returned_circle->orient->Angle();

			Vector x(F_base_start.p - returned_circle->F_base_center.p);
			returned_circle->radius = x.Normalize();

			if(returned_circle->radius < epsilon){
				returned_circle = PathCirclePtr();
				return 149;
			}

			Vector tmpv(V_base_p-returned_circle->F_base_center.p);
			tmpv.Normalize();
			Vector z( x * tmpv);
			double n = z.Normalize();

			if (n < epsilon){
				returned_circle = PathCirclePtr();
				return 150;
			}

			returned_circle->F_base_center.M = Rotation(x,z*x,z);
			double dist = alpha*returned_circle->radius;
			// See what has the slowest eq. motion, and adapt
			// the other to this slower motion
			// use eqradius to transform between rot and transl.
			// the same as for lineair motion
			if (oalpha*returned_circle->eqradius > dist) {
				// rotational_interpolation is the limitation
				returned_circle->pathlength = oalpha*returned_circle->eqradius;
				returned_circle->scalerot   = 1/returned_circle->eqradius;
				returned_circle->scalelin   = dist/returned_circle->pathlength;
			} else {
				// translation is the limitation
				returned_circle->pathlength = dist;
				returned_circle->scalerot   = oalpha/returned_circle->pathlength;
				returned_circle->scalelin   = 1;
			}
			return 0;
		}

int Path_Circle::LengthToS(double length, double& returned_length) {
	returned_length = length/scalelin;
	return 0;
}


double Path_Circle::PathLength() {
	return pathlength;
}

int Path_Circle::Pos(double s, Frame& returned_position) const {
	double p = s*scalelin / radius;
	Rotation position;
	int exit_code = orient->Pos(s*scalerot, position);
	if(exit_code != 0){
		return exit_code;
	}
	returned_position = Frame(position,F_base_center*Vector(radius*cos(p),radius*sin(p),0));
	return 0;
}

int Path_Circle::Vel(double s,double sd, Twist& returned_velocity) const {
	double p = s*scalelin / radius;
	double v = sd*scalelin / radius;
	Vector velocity;
	int exit_code = orient->Vel(s*scalerot,sd*scalerot, velocity);
	if(exit_code != 0){
		return exit_code;
	}
	returned_velocity = Twist( F_base_center.M*Vector(-radius*sin(p)*v,radius*cos(p)*v,0),velocity);
	return 0;
}

int Path_Circle::Acc(double s,double sd,double sdd, Twist& returned_acceleration) const {
	double p = s*scalelin / radius;
	double cp = cos(p);
	double sp = sin(p);
	double v = sd*scalelin / radius;
	double a = sdd*scalelin / radius;
	Vector acceleration;
	int exit_code = orient->Acc(s*scalerot,sd*scalerot,sdd*scalerot, acceleration);
	if(exit_code != 0){
		return exit_code;
	}
	returned_acceleration = Twist( F_base_center.M*Vector(-radius*cp*v*v  -  radius*sp*a,-radius*sp*v*v  +  radius*cp*a,0),acceleration);
	return 0;
}

boost::shared_ptr<Path> Path_Circle::Clone() {
	PathCirclePtr circle;
	Frame fp;
	Pos(0,fp);
	Rotation sp;
	orient->Pos(pathlength*scalerot, sp);

	Path_Circle::Create(	fp,
							F_base_center.p,
							F_base_center.M.UnitY(),
							sp,
							pathlength*scalelin/radius/deg2rad,
							orient->Clone(),
							eqradius,
							circle,
							aggregate
        					);
	return circle;
}

Path_Circle::~Path_Circle() {
    if (aggregate)
        orient.reset();
}

void Path_Circle::Write(std::ostream& os) {
	os << "CIRCLE[ ";
	Frame fp;
	Pos(0,fp);
	os << "  " << fp << std::endl;
	os << "  " << F_base_center.p << std::endl;
	os << "  " << F_base_center.M.UnitY() << std::endl;
	Rotation sp;
	orient->Pos(pathlength*scalerot,sp);
	os << "  " << sp << std::endl;
	os << "  " << pathlength*scalelin/radius/deg2rad << std::endl;
	os << "  ";orient->Write(os);
	os << "  " << eqradius;
	os << "]"<< std::endl;
}
}

