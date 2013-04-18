/***************************************************************************
  tag: Erwin Aertbelien  Mon May 10 19:10:36 CEST 2004  path.cxx

                        path.cxx -  description
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
 *		$Id: path.cpp,v 1.1.1.1.2.4 2003/07/18 14:49:50 psoetens Exp $
 *		$Name:  $
 ****************************************************************************/


#include "utilities/error.h"
#include "utilities/error_stack.h"
#include "path.hpp"
#include "path_line.hpp"
#include "path_spline.hpp"
#include "path_point.hpp"
#include "path_circle.hpp"
#include "path_composite.hpp"
#include "path_roundedcomposite.hpp"
#include "path_cyclic_closed.hpp"
#include <memory>
#include <string.h>


namespace KDL {

using namespace std;

typedef boost::shared_ptr<Path_Point> PathPointPtr;
typedef boost::shared_ptr<Path_Circle> PathCirclePtr;
typedef boost::shared_ptr<RotationalInterpolation> RotationalInterpolationPtr;
typedef boost::shared_ptr<Path_Line> PathLinePtr;
typedef boost::shared_ptr<Path_RoundedComposite> PathRoundedCompositePtr;
typedef boost::shared_ptr<Path_Composite> PathCompositePtr;
typedef boost::shared_ptr<Path_Cyclic_Closed> PathCyclicClosedPtr;
typedef boost::shared_ptr<Path_Spline> PathSplinePtr;

int Path::Read(istream& is, PathPtr& returned_path) {
	IOTrace("Path::Read");
	char storage[64];
	EatWord(is,"[",storage,sizeof(storage));
	Eat(is,'[');
	int exit_code;
	if (strcmp(storage,"POINT")==0) {
		IOTrace("POINT");
		Frame startpos;
		is >> startpos;
		EatEnd(is,']');
		IOTracePop();
		IOTracePop();
		PathPointPtr point;
		exit_code = Path_Point::Create(startpos, point);
		if(exit_code != 0){
			returned_path = PathPtr();
			return exit_code;
		}
		returned_path = point;
		return 0;
	} else 	if (strcmp(storage,"LINE")==0) {
		IOTrace("LINE");
		Frame startpos;
		Frame endpos;
		is >> startpos;
		is >> endpos;
		RotationalInterpolationPtr orient;
		exit_code = RotationalInterpolation::Read(is, orient);
		if(exit_code != 0)
		{
			returned_path = PathPtr();
			return exit_code;
		}
		double eqradius;
		is >> eqradius;
		EatEnd(is,']');
		IOTracePop();
		IOTracePop();
		PathLinePtr line;
		exit_code = Path_Line::Create(startpos,endpos,orient,eqradius, line);
		if(exit_code != 0){
			returned_path = PathPtr();
			return exit_code;
		}
		returned_path = line;
		return 0;
	} else if (strcmp(storage,"SPLINE")==0) {
		IOTrace("SPLINE");
		vector<Vector> coeff_vector;
		is >> coeff_vector;
		int discretization;
		is >> discretization;
		RotationalInterpolationPtr orient;
		exit_code = RotationalInterpolation::Read(is, orient);
		if(exit_code != 0)
		{
			returned_path = PathPtr();
			return exit_code;
		}
		double eqradius;
		is >> eqradius;
		EatEnd(is,']');
		IOTracePop();
		IOTracePop();

		PathSplinePtr spline;
		exit_code = Path_Spline::Create(coeff_vector, discretization, orient, eqradius, spline);
		if(exit_code != 0)
		{
			returned_path = PathPtr();
			return exit_code;
		}
		returned_path = spline;
		return 0;
	}
	else if (strcmp(storage,"CIRCLE")==0) {
		IOTrace("CIRCLE");
		Frame F_base_start;
		Vector V_base_center;
		Vector V_base_p;
		Rotation R_base_end;
		double alpha;
		double eqradius;
		is >> F_base_start;
		is >> V_base_center;
		is >> V_base_p;
		is >> R_base_end;
		is >> alpha;
		alpha *= deg2rad;
		RotationalInterpolationPtr orient;
		exit_code = RotationalInterpolation::Read(is, orient);
		if(exit_code != 0)
		{
			returned_path = PathPtr();
			return exit_code;
		}
		is >> eqradius;
		EatEnd(is,']');
		IOTracePop();
		IOTracePop();

		PathCirclePtr circle;
		exit_code = Path_Circle::Create(	F_base_start,
												V_base_center,
												V_base_p,
												R_base_end,
												alpha,
												orient,
												eqradius, circle);
		if(exit_code != 0)
		{
			returned_path = PathPtr();
			return exit_code;
		}
		returned_path = circle;
		return 0;
	} else if (strcmp(storage,"ROUNDEDCOMPOSITE")==0) {
		IOTrace("ROUNDEDCOMPOSITE");
		double radius;
		is >> radius;
		double eqradius;
		is >> eqradius;
		RotationalInterpolationPtr orient;
		exit_code = RotationalInterpolation::Read(is,orient);
		if(exit_code != 0)
		{
			returned_path = PathPtr();
			return exit_code;
		}
		PathRoundedCompositePtr tr;
		exit_code = Path_RoundedComposite::Create(radius,eqradius,orient, tr);
		if(exit_code != 0)
		{
			returned_path = PathPtr();
			return exit_code;
		}
		int size;
		is >> size;
		int i;
		for (i=0;i<size;i++) {
			Frame f;
			is >> f;
			exit_code = tr->Add(f);
			if(exit_code != 0){
				returned_path = PathPtr();
				return exit_code;
			}
		}
		tr->Finish();
		EatEnd(is,']');
		IOTracePop();
		IOTracePop();
		returned_path = tr;
		return 0;
	} else if (strcmp(storage,"COMPOSITE")==0) {
		IOTrace("COMPOSITE");
		int size;
		PathCompositePtr tr;
		exit_code = Path_Composite::Create(tr);
		if(exit_code != 0){
			returned_path = PathPtr();
			return exit_code;
		}
		is >> size;
		int i;
		for (i=0;i<size;i++) {
			PathPtr path;
			exit_code = Path::Read(is, path);
			if(exit_code != 0)
			{
				returned_path = PathPtr();
				return exit_code;
			}
			tr->Add(path);
		}
		EatEnd(is,']');
		IOTracePop();
		IOTracePop();
		returned_path = tr;
		return 0;
	} else if (strcmp(storage,"CYCLIC_CLOSED")==0) {
		IOTrace("CYCLIC_CLOSED");
		int times;
		PathPtr tr;
		exit_code = Path::Read(is,tr);
		if(exit_code != 0)
		{
			returned_path = PathPtr();
			return exit_code;
		}
		is >> times;
		EatEnd(is,']');
		IOTracePop();
		IOTracePop();
		PathCyclicClosedPtr cyclic_closed;
		exit_code = Path_Cyclic_Closed::Create(tr,times, cyclic_closed);
		if(exit_code != 0){
			returned_path = PathPtr();
			return exit_code;
		}
		returned_path = cyclic_closed;
		return 0;
	} else {
		returned_path = PathPtr();
		return 147;
	}
	returned_path = PathPtr(); // just to avoid the warning;
	return 0;
}
}

