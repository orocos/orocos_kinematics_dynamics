/***************************************************************************
  tag: Erwin Aertbelien  Mon May 10 19:10:36 CEST 2004  path_roundedcomposite.cxx

                        path_roundedcomposite.cxx -  description
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
 *		$Id: path_roundedcomposite.cpp,v 1.1.1.1.2.5 2003/07/24 13:26:15 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/


#include "path_roundedcomposite.hpp"
#include "path_line.hpp"
#include "path_circle.hpp"
#include "utilities/error.h"
#include <memory>


namespace KDL {

typedef boost::shared_ptr<Path_Line> PathLinePtr;
typedef boost::shared_ptr<Path_Circle> PathCirclePtr;

// private creator, to keep the type when cloning a Path_RoundedComposite, such that getIdentifier keeps on returning
// the correct value
int Path_RoundedComposite::Create(	PathCompositePtr _comp,
									double _radius,
									double _eqradius,
									RotationalInterpolationPtr _orient,
									bool _aggregate,
									int _nrofpoints,
									PathRoundedCompositePtr& composite
									)
{
	composite = PathRoundedCompositePtr(new Path_RoundedComposite());
	composite->comp = _comp;
	composite->radius = _radius;
	composite->eqradius = _eqradius;
	composite->orient = _orient;
	composite->aggregate = _aggregate;
	composite->nrofpoints = _nrofpoints;
	return 0;
}

int Path_RoundedComposite::Create(	double _radius,
									double _eqradius,
									RotationalInterpolationPtr _orient,
									PathRoundedCompositePtr& rounded_composite,
									bool _aggregate
									)
{
	rounded_composite = PathRoundedCompositePtr(new Path_RoundedComposite());
	rounded_composite->radius = _radius;
	rounded_composite->eqradius = _eqradius;
	rounded_composite->orient = _orient;
	rounded_composite->aggregate = _aggregate;

	PathCompositePtr composite;
	int exit_code = Path_Composite::Create(composite);
	if(exit_code != 0){
		rounded_composite = PathRoundedCompositePtr();
		return exit_code;
	}
	rounded_composite->comp = composite;

	rounded_composite->nrofpoints = 0;

	if (rounded_composite->eqradius<=0) {
		rounded_composite = PathRoundedCompositePtr();
		return 141;
	}
	return 0;
}

int Path_RoundedComposite::Add(const Frame& F_base_point) {
	double eps = 1E-7;
	if (nrofpoints == 0) {
		F_base_start = F_base_point;
	} else if (nrofpoints == 1) {
		F_base_via = F_base_point;
	} else {
		// calculate rounded segment : line + circle,
		// determine the angle between the line segments :
		Vector ab = F_base_via.p - F_base_start.p;
		Vector bc = F_base_point.p - F_base_via.p;
		double abdist = ab.Norm();
		double bcdist = bc.Norm();
		if (abdist < eps) {
			return 142;
		}
		if (bcdist < eps) {
			return 143;
		}
		double alpha = acos(dot(ab, bc) / abdist / bcdist);
		if ((PI - alpha) < eps) {
			return 144;
		}
		if (alpha < eps) {
			// no rounding is done in the case of parallel line segments

			boost::shared_ptr<Path_Line> line;
			int exit_code = Path_Line::Create(F_base_start, F_base_via, orient->Clone(), eqradius, line);
			if(exit_code != 0)
				return exit_code;
			comp->Add(line);

			F_base_start = F_base_via;
			F_base_via = F_base_point;
		} else {
			double d = radius / tan((PI - alpha) / 2); // tan. is guaranteed not to return zero.
			if (d >= abdist)
				return 145;

			if (d >= bcdist)
				return 146;

			PathLinePtr line1;
			int exit_code = Path_Line::Create(F_base_start, F_base_via, orient->Clone(), eqradius, line1);
			if(exit_code != 0)
				return exit_code;

			PathLinePtr line2;
			exit_code = Path_Line::Create(F_base_via, F_base_point, orient->Clone(), eqradius,line2);
			if(exit_code != 0)
				return exit_code;

			double length;
			line1->LengthToS(abdist - d, length);
			Frame F_base_circlestart;
			exit_code = line1->Pos(length, F_base_circlestart);
			if(exit_code != 0){
				return exit_code;
			}
			line2->LengthToS(d, length);


			Frame F_base_circleend;
			exit_code = line2->Pos(length, F_base_circleend);
			if(exit_code != 0){
				return exit_code;
			}

			// end of circle segment, beginning of next line
			Vector V_base_t = ab * (ab * bc);
			V_base_t.Normalize();

			PathLinePtr line;
			exit_code = Path_Line::Create(F_base_start, F_base_circlestart, orient->Clone(), eqradius,line);
			if(exit_code != 0)
				return exit_code;
			comp->Add(line);

			PathCirclePtr circle;
			exit_code = Path_Circle::Create(	F_base_circlestart,
													F_base_circlestart.p - V_base_t * radius,
													F_base_circleend.p,
													F_base_circleend.M,
													alpha,
													orient->Clone(),
													eqradius, circle);
			if(exit_code != 0){
				return exit_code;
			}
			comp->Add(circle);

			// shift for next line
			F_base_start = F_base_circleend; // end of the circle segment
			F_base_via = F_base_point;
		}
	}
	nrofpoints++;
	return 0;
}

void Path_RoundedComposite::Finish() {
	if (nrofpoints >= 1) {
		PathLinePtr line;
		Path_Line::Create(F_base_start, F_base_via, orient->Clone(), eqradius, line);
		comp->Add(line);
	}
}

int Path_RoundedComposite::LengthToS(double length, double& returned_length) {
	int exit_code =  comp->LengthToS(length, returned_length);
	return exit_code;
}


double Path_RoundedComposite::PathLength() {
	return comp->PathLength();
}

int Path_RoundedComposite::Pos(double s, Frame& returned_position) const {
	int exit_code = comp->Pos(s,returned_position);
	return exit_code;
}

int Path_RoundedComposite::Vel(double s, double sd, Twist& returned_velocity) const {
	int exit_code = comp->Vel(s, sd, returned_velocity);
	return exit_code;
}

int Path_RoundedComposite::Acc(double s, double sd, double sdd, Twist& returned_acceleration) const {
	int exit_code = comp->Acc(s, sd, sdd, returned_acceleration);
	return exit_code;
}

void Path_RoundedComposite::Write(std::ostream& os) {
	comp->Write(os);
}

int Path_RoundedComposite::GetNrOfSegments() {
	return comp->GetNrOfSegments();
}

boost::shared_ptr<Path> Path_RoundedComposite::GetSegment(int i) {
	return comp->GetSegment(i);
}

double Path_RoundedComposite::GetLengthToEndOfSegment(int i) {
	return comp->GetLengthToEndOfSegment(i);
}

void Path_RoundedComposite::GetCurrentSegmentLocation(double s,
		int& segment_number, double& inner_s) {
	comp->GetCurrentSegmentLocation(s,segment_number,inner_s);
}

Path_RoundedComposite::~Path_RoundedComposite() {
    if (aggregate)
        orient.reset();
	comp.reset();
}

boost::shared_ptr<Path> Path_RoundedComposite::Clone() {
	boost::shared_ptr<Path_RoundedComposite> composite;
	Path_RoundedComposite::Create(boost::static_pointer_cast<Path_Composite>(comp->Clone()),radius,eqradius,orient->Clone(), true, nrofpoints, composite);
	return composite;
}

}
