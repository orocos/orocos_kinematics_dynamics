/*
 * path_spline.cpp
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

#include "path_spline.hpp"

namespace KDL {

//Evaluates the given polynom in the given value.
//Vector: a + bx + cx² -> (a,b,c)
double Path_Spline::Evaluate_Polynomial(std::vector<double> coeff, double value){
	double result = 0;
	std::vector<double>::iterator it;

	for (it=coeff.begin() ; it < coeff.end(); it++){
		result += *it * pow(value, int(it - coeff.begin())); //Index == power
	}
	return result;
}

//Evaluates the derivative of the given polynom in the given value.
double Path_Spline::Evaluate_Polynomial_Derivative(std::vector<double> coeff, double value) const{
	double result = 0;
	std::vector<double>::iterator it;
	for (it = (coeff.begin() + 1) ; it < coeff.end(); it++){ //Constant is ignored
		result += *it * int(it - coeff.begin()) * pow(value, int(it - coeff.begin()) - 1);
	}
	return result;
}

//Evaluates the second derivative of the given polynom in the given value.
double Path_Spline::Evaluate_Polynomial_Second_Derivative(std::vector<double> coeff, double value) const{
	double result = 0;
	std::vector<double>::iterator it;
	for (it = (coeff.begin() + 2) ; it < coeff.end(); it++){ //Constant is ignored
		result += *it * int(it - coeff.begin()) * (int(it - coeff.begin())-1) * pow(value, int(it - coeff.begin()) - 2);
	}
	return result;
}

//Retrieves f_x, f_y, f_z from f.
void Path_Spline::Retrieve_Functions(	CoeffVector coeff_vector,
										std::vector<double>& f_x,
										std::vector<double>& f_y,
										std::vector<double>& f_z)
{
	std::vector<Vector>::iterator it;

	f_x.clear();
	for(it=coeff_vector.begin(); it< coeff_vector.end(); it++){
		f_x.push_back((*it).data[0]);
	}

	f_y.clear();
	for(it=coeff_vector.begin(); it< coeff_vector.end(); it++){
		f_y.push_back((*it).data[1]);
	}

	f_z.clear();
	for(it=coeff_vector.begin(); it< coeff_vector.end(); it++){
		f_z.push_back((*it).data[2]);
	}
}

//Evaluates the function g in the documentation.
double Path_Spline::Evaluate_G(CoeffVector coeff_vector, double value, int discretization)
{
	double result = 0;

	if(value == 0)
		return 0;

	std::vector<double> f_x;
	std::vector<double> f_y;
	std::vector<double> f_z;
	Path_Spline::Retrieve_Functions(coeff_vector, f_x, f_y, f_z);

	//The sum
	double step = 1 / discretization;
	for (double spline_parameter = step; spline_parameter <= value;	spline_parameter += step) {
		double temp;
		temp = pow((Evaluate_Polynomial(f_x, spline_parameter)- Evaluate_Polynomial(f_x, spline_parameter - step)), 2);
		temp += pow((Evaluate_Polynomial(f_y, spline_parameter)- Evaluate_Polynomial(f_y, spline_parameter - step)), 2);
		temp += pow((Evaluate_Polynomial(f_z, spline_parameter)- Evaluate_Polynomial(f_z, spline_parameter - step)), 2);
		temp = sqrt(temp);
		result += temp;
	}
	return result;
}

//Uses linear interpolation
double Path_Spline::Calculate_R(double s) const
{
	std::map<double, double>::const_iterator it = lookup_table.begin();

	if (s < (*it).first) {
		//s is less than the minimum element
		return (*it).second;
	}

	it = lookup_table.end();
	it--;
	if (s > (*it).first) {
		//s is larger than the maximum element
		return (*it).second;
	}

	it = lookup_table.lower_bound(s);
	if ((*it).first == s) {
		//Interpolation not needed
		return (*it).second;
	} else {
		//Interpolate
		std::map<double, double>::const_iterator current = it;
		it--;
		std::map<double, double>::const_iterator previous = it;

		double dx = ((*current).first) - ((*previous).first);
		double dy = (*current).second - (*previous).second;
		return (*previous).second + (s - (*previous).first) * dy / dx;
	}
}

double Path_Spline::Calculate_Rd(double s, double sd) const
{
	std::vector<double> f_x;
	std::vector<double> f_y;
	std::vector<double> f_z;
	Path_Spline::Retrieve_Functions(coeff_vector, f_x, f_y, f_z);
	double r = Calculate_R(s);

	double result;
	result = pow(Evaluate_Polynomial_Derivative(f_x,r),2);
	result += pow(Evaluate_Polynomial_Derivative(f_y,r),2);
	result += pow(Evaluate_Polynomial_Derivative(f_z,r),2);
	result = sqrt(result);
	result = sd / result;
	return result;
}

double Path_Spline::Calculate_Rdd(double s, double sd, double sdd) const
{
	std::vector<double> f_x;
	std::vector<double> f_y;
	std::vector<double> f_z;
	Path_Spline::Retrieve_Functions(coeff_vector, f_x, f_y, f_z);
	double r = Calculate_R(s);

	double temp1_numerator;
	temp1_numerator = Evaluate_Polynomial_Second_Derivative(f_x,r);
	temp1_numerator += Evaluate_Polynomial_Second_Derivative(f_y,r);
	temp1_numerator += Evaluate_Polynomial_Second_Derivative(f_z,r);

	double temp1_denominator;
	temp1_denominator = pow(Evaluate_Polynomial_Derivative(f_x,r),2);
	temp1_denominator += pow(Evaluate_Polynomial_Derivative(f_y,r),2);
	temp1_denominator += pow(Evaluate_Polynomial_Derivative(f_z,r),2);
	temp1_denominator = pow(temp1_denominator,(3/2));
	temp1_denominator *= -1;
	temp1_denominator *= pow(sd,2);

	double temp1 = temp1_numerator / temp1_denominator;

	double temp2;
	temp2 = pow(Evaluate_Polynomial_Derivative(f_x,r),2);
	temp2 += pow(Evaluate_Polynomial_Derivative(f_y,r),2);
	temp2 += pow(Evaluate_Polynomial_Derivative(f_z,r),2);
	temp2 = sqrt(temp2);
	temp2 = sdd / temp2;

	return temp1 + temp2;
}

/**
 * The coefficients should be entered like:
 * f_x = a + bx + cx²
 * f_y = d + ex + fx²
 * f_z = g + hx + ix²
 * -> [(a,d,g);(b,e,h);(c,f,i)]
 */
int Path_Spline::Create(	CoeffVector coeff_vector,
							int _discretization,
							RotationalInterpolationPtr _orient,
							double _eqradius,
							PathSplinePtr& spline,
							bool _aggregate)
{
	spline = PathSplinePtr(new Path_Spline());
	spline->coeff_vector = coeff_vector;
	spline->orient = _orient;
	spline->eqradius = _eqradius;
	spline->discretization = _discretization;

	/**
	 * TODO:
	 * Voor de distance wordt momenteel de waarde van g(r_k) gebruikt wanneer de splineparameter 1 is (helemaal op het einde).
	 * Het onderscheid tussen translatie en rotatie is overgenomen van line, circle, ...
	 */
	double dist = Evaluate_G(coeff_vector,1, _discretization);
	double alpha = spline->orient->Angle();

	// See what has the slowest eq. motion, and adapt
	// the other to this slower motion
	// use eqradius to transform between rot and transl.

	if(alpha != 0 && alpha*spline->eqradius > dist){
		// rotational_interpolation is the limitation
    	spline->pathlength = alpha*spline->eqradius;
    	spline->scalerot   = 1/spline->eqradius;
    	spline->scalelin   = dist/spline->pathlength;
	} else if (dist != 0){
		// translation is the limitation
    	spline->pathlength = dist;
    	spline->scalerot   = alpha/spline->pathlength;
    	spline->scalelin   = 1;
	} else {
    	// both were zero
    	spline->pathlength = 0;
    	spline->scalerot   = 1;
    	spline->scalelin   = 1;
	}

	// Initialization of the lookup table.
	double step = 1/_discretization;
	for(double spline_parameter = 0; spline_parameter <= 1; spline_parameter+= step){
		double length = Evaluate_G(coeff_vector, spline_parameter, _discretization);
		spline->lookup_table[length] = spline_parameter;
	}

	return 0;
}

int Path_Spline::LengthToS(double length, double& returned_length) {
	returned_length = length/scalelin;
	return 0;
}

double Path_Spline::PathLength(){
	return pathlength;
}

// s is the pathlength
int Path_Spline::Pos(double s, Frame& returned_position) const
{
	Rotation position;
	int exit_code = orient->Pos(s*scalerot, position);
	if(exit_code != 0){
		return exit_code;
	}

	std::vector<double> f_x;
	std::vector<double> f_y;
	std::vector<double> f_z;
	Path_Spline::Retrieve_Functions(coeff_vector, f_x, f_y, f_z);
	double r = Calculate_R(s);

	double x = Evaluate_Polynomial(f_x, r);
	double y = Evaluate_Polynomial(f_y,r);
	double z = Evaluate_Polynomial(f_z, r);

	returned_position = Frame(position,Vector(x,y,z));
	return 0;
}

int Path_Spline::Vel(double s,double sd, Twist& returned_velocity) const  {
	assert(coeff_vector.size() >= 2); //Spline order should be 2 or higher.

	Vector velocity;
	int exit_code = orient->Vel(s*scalerot,sd*scalerot, velocity);
	if(exit_code != 0){
		return exit_code;
	}

	std::vector<double> f_x;
	std::vector<double> f_y;
	std::vector<double> f_z;
	Path_Spline::Retrieve_Functions(coeff_vector, f_x, f_y, f_z);
	double r = Calculate_R(s);
	double rd = Calculate_Rd(s,sd);

	double x = Evaluate_Polynomial_Derivative(f_x,r) * rd;
	double y = Evaluate_Polynomial_Derivative(f_y,r) * rd;
	double z = Evaluate_Polynomial_Derivative(f_z,r) * rd;

	returned_velocity = Twist(Vector(x,y,z) ,velocity);
	return 0;
}

int Path_Spline::Acc(double s,double sd,double sdd, Twist& returned_acceleration) const  {
	assert(coeff_vector.size() >= 3);//Spline order should be 3 or higher.

	Vector acceleration;
	int exit_code = orient->Acc(s*scalerot,sd*scalerot,sdd*scalerot,acceleration);
	if(exit_code != 0){
		return exit_code;
	}

	std::vector<double> f_x;
	std::vector<double> f_y;
	std::vector<double> f_z;
	Path_Spline::Retrieve_Functions(coeff_vector, f_x, f_y, f_z);
	double r = Calculate_R(s);
	double rd = Calculate_Rd(s,sd);
	double rdd = Calculate_Rdd(s,sd,sdd);

	double x = Evaluate_Polynomial_Second_Derivative(f_x,r) * pow(rd,2) + Evaluate_Polynomial_Derivative(f_x,r) * rdd;
	double y = Evaluate_Polynomial_Second_Derivative(f_y,r) * pow(rd,2) + Evaluate_Polynomial_Derivative(f_y,r) * rdd;
	double z = Evaluate_Polynomial_Second_Derivative(f_z,r) * pow(rd,2) + Evaluate_Polynomial_Derivative(f_z,r) * rdd;

	returned_acceleration = Twist(Vector(x,y,z),acceleration);
	return 0;
}

boost::shared_ptr<Path> Path_Spline::Clone() {
	PathSplinePtr cloned_spline;

	std::vector<Vector> _coeff_vector;
	for(int i = 0; i < coeff_vector.size();i++){
		_coeff_vector.push_back(Vector(coeff_vector[i].data[0], coeff_vector[i].data[1], coeff_vector[i].data[2]));
	}

	Path_Spline::Create(coeff_vector, discretization, orient->Clone(), eqradius, cloned_spline, aggregate);
	return cloned_spline;
}

void Path_Spline::Write(std::ostream& os)  {
	os << "SPLINE[ ";
	os << " " << coeff_vector << std::endl;
	os << " " << discretization << std::endl;
	os << " ";orient->Write(os);
	os << " " << eqradius;
	os << "]" << std::endl;
}

Path_Spline::~Path_Spline() {
    if (aggregate)
        orient.reset();
}

} /* namespace KDL */
