/*
 * path_spline.hpp
 *
 *  Created on: Jul 31, 2012
 *      Author: Wouter Bancken
 *
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

#ifndef KDL_MOTION_PATH_SPLINE_H
#define KDL_MOTION_PATH_SPLINE_H

#include "path.hpp"
#include "rotational_interpolation.hpp"
#include <boost/shared_ptr.hpp>
#include <vector>
#include <map>

namespace KDL {

class Path_Spline : public Path
{
	typedef boost::shared_ptr<Path> PathPtr;
	typedef boost::shared_ptr<RotationalInterpolation> RotationalInterpolationPtr;
	typedef boost::shared_ptr<Path_Spline> PathSplinePtr;
	typedef std::vector<Vector> CoeffVector;

	//Orientation
	RotationalInterpolationPtr orient;

	//Vector of coefficients for f_x, f_y, f_z.
	CoeffVector coeff_vector;

	double eqradius; //Equivalent radius

	//Distribution over pos/rot
	double pathlength;
	double scalelin;
	double scalerot;
	bool aggregate;
	int discretization;

	//Lookup-table
	// length | spline_parameter
	std::map<double,double> lookup_table;

	//Used in create
	static double Evaluate_Polynomial(std::vector<double> coeff, double value);
	//Used in create
	static void Retrieve_Functions(CoeffVector coeff_vector, std::vector<double>& f_x, std::vector<double>& f_y, std::vector<double>& f_z);
	//Used in create
	static double Evaluate_G(CoeffVector coeff_vector, double value, int discretization);

	double Calculate_R(double s) const;
	double Calculate_Rd(double s, double sd) const;
	double Calculate_Rdd(double s, double sd, double sdd) const;
	double Evaluate_Polynomial_Derivative(std::vector<double> coeff, double value) const;
	double Evaluate_Polynomial_Second_Derivative(std::vector<double> coeff, double value) const;

public:
	/**
	 * The coefficients should be entered like:
	 * f_x = a + bx + cx²
	 * f_y = d + ex + fx²
	 * f_z = g + hx + ix²
	 * -> [(a,d,g);(b,e,h);(c,f,i)]
	 */
	static int Create(	CoeffVector coeff_vector,
						int discretization,
						RotationalInterpolationPtr _orient,
						double _eqradius,
						PathSplinePtr& spline,
						bool _aggregate = true);
	int LengthToS(double length, double& returned_length);
	virtual double PathLength();
	virtual int Pos(double s, Frame& returned_position) const;
	virtual int Vel(double s,double sd, Twist& returned_velocity) const ;
	virtual int Acc(double s,double sd,double sdd, Twist& returned_acceleration) const;
	virtual void Write(std::ostream& os);
	virtual PathPtr Clone();

	/**
	 * gets an identifier indicating the type of this Path object
	 */
	virtual IdentifierType getIdentifier() const {
		return ID_SPLINE;
	}

	virtual ~Path_Spline();

private:
	Path_Spline() {};
};

} /* namespace KDL */
#endif /* KDL_MOTION_PATH_SPLINE_H */
