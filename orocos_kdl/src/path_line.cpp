/***************************************************************************
  tag: Erwin Aertbelien  Mon May 10 19:10:36 CEST 2004  path_line.cxx

                        path_line.cxx -  description
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
 *		$Id: path_line.cpp,v 1.1.1.1.2.3 2003/07/24 13:26:15 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/


#include "path_line.hpp"

namespace KDL {

int Path_Line::Create(	const Frame& F_base_start,
						const Frame& F_base_end,
						RotationalInterpolationPtr _orient,
						double _eqradius,
						PathLinePtr& line,
						bool _aggregate)
	{
		line = PathLinePtr(new Path_Line());

		line->orient = _orient;
		line->V_base_start = F_base_start.p;
		line->V_base_end = F_base_end.p;
	    line->eqradius = _eqradius;
	    line->aggregate = _aggregate;

	    line->V_start_end = line->V_base_end - line->V_base_start;
	    double dist = line->V_start_end.Normalize();
	    line->orient->SetStartEnd(F_base_start.M,F_base_end.M);
	    double alpha = line->orient->Angle();

	    // See what has the slowest eq. motion, and adapt
	    // the other to this slower motion
	    // use eqradius to transform between rot and transl.

	    // Only modify if non zero (prevent division by zero)
	    if ( alpha != 0 && alpha*line->eqradius > dist) {
	    	// rotational_interpolation is the limitation
	    	line->pathlength = alpha*line->eqradius;
	    	line->scalerot   = 1/line->eqradius;
	    	line->scalelin   = dist/line->pathlength;
	    } else if ( dist != 0 ) {
	    	// translation is the limitation
	    	line->pathlength = dist;
	    	line->scalerot   = alpha/line->pathlength;
	    	line->scalelin   = 1;
	    } else {
	    	// both were zero
	    	line->pathlength = 0;
	    	line->scalerot   = 1;
	    	line->scalelin   = 1;
	    }
	    return 0;
	}

int Path_Line::Create(	const Frame& F_base_start,
						const Twist& twist_in_base,
						RotationalInterpolationPtr _orient,
						double _eqradius,
						PathLinePtr& line,
						bool _aggregate)
	{
		line = PathLinePtr(new Path_Line());

		line->orient = _orient;
		line->V_base_start = F_base_start.p;
		line->V_base_end = F_base_start.p + twist_in_base.vel;
		line->eqradius =_eqradius;
		line->aggregate = _aggregate;

		// startframe and starttwist are expressed in Wo.
		// after 1 time unit, startframe has translated over starttwist.vel
		// and rotated over starttwist.rot.Norm() (both vectors can be zero)
		// Thus the frame on the path after 1 time unit is defined by
		// startframe.Integrate(starttwist, 1);
		line->V_start_end = line->V_base_end - line->V_base_start;
		double dist = line->V_start_end.Normalize(); // distance traveled during 1 time unit
		line->orient->SetStartEnd(F_base_start.M, (F_base_start*Frame( Rotation::Rot(twist_in_base.rot, twist_in_base.rot.Norm() ), twist_in_base.vel )).M);
		double alpha = line->orient->Angle();        // rotation during 1 time unit

		// See what has the slowest eq. motion, and adapt
		// the other to this slower motion
		// use eqradius to transform between rot and transl.
		// Only modify if non zero (prevent division by zero)
		if ( alpha != 0 && alpha*line->eqradius > dist) {
			// rotational_interpolation is the limitation
			line->pathlength = alpha*line->eqradius;
			line->scalerot   = 1/line->eqradius;
			line->scalelin   = dist/line->pathlength;
		} else if ( dist != 0 ) {
			// translation is the limitation
			line->pathlength = dist;
			line->scalerot   = alpha/line->pathlength;
			line->scalelin   = 1;
		} else {
		 // both were zero
			line->pathlength = 0;
			line->scalerot   = 1;
			line->scalelin   = 1;
		}
		return 0;
	}

int Path_Line::LengthToS(double length, double& returned_length) {
	returned_length = length/scalelin;
	return 0;
}
double Path_Line::PathLength(){
	return pathlength;
}

int Path_Line::Pos(double s, Frame& returned_position) const  {
	Rotation position;
	int exit_code = orient->Pos(s*scalerot, position);
	if(exit_code != 0){
		return exit_code;
	}
	returned_position = Frame(position,V_base_start + V_start_end*s*scalelin );
	return 0;
}

int Path_Line::Vel(double s,double sd, Twist& returned_velocity) const  {
	Vector velocity;
	int exit_code = orient->Vel(s*scalerot,sd*scalerot, velocity);
	if(exit_code != 0){
		return exit_code;
	}
	returned_velocity = Twist( V_start_end*sd*scalelin, velocity );
	return 0;
}

int Path_Line::Acc(double s,double sd,double sdd, Twist& returned_acceleration) const  {
	Vector acceleration;
	int exit_code = orient->Acc(s*scalerot,sd*scalerot,sdd*scalerot,acceleration);
	if(exit_code != 0){
		return exit_code;
	}
	returned_acceleration = Twist( V_start_end*sdd*scalelin, acceleration);
	return 0;
}


Path_Line::~Path_Line() {
    if (aggregate)
        orient.reset();
}

boost::shared_ptr<Path> Path_Line::Clone() {
	PathLinePtr line;
	if (aggregate){
		Rotation fp;
		orient->Pos(0,fp);
		Rotation sp;
		orient->Pos(pathlength*scalerot,sp);

		Path_Line::Create(	Frame(fp,V_base_start),
                        	Frame(sp,V_base_end),
                        	orient->Clone(),
                        	eqradius,
                        	line,
                        	true
                        	);
		return line;
	}

    // else :
	Rotation fp;
	orient->Pos(0,fp);
	Rotation sp;
	orient->Pos(pathlength*scalerot, sp);

	Path_Line::Create(	Frame(fp,V_base_start),
            			Frame(sp,V_base_end),
            			orient,
            			eqradius,
            			line,
            			false
            			);
	return line;
}

void Path_Line::Write(std::ostream& os)  {
	os << "LINE[ ";
	Rotation fp;
	orient->Pos(0,fp);
	os << "  " << Frame(fp,V_base_start) << std::endl;
	Rotation sp;
	orient->Pos(pathlength*scalerot,sp);
	os << "  " << Frame(sp,V_base_end) << std::endl;
	os << "  ";orient->Write(os);
	os << "  " << eqradius;
	os << "]"  << std::endl;
}

}

