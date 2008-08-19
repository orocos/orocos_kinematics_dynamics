// Copyright  (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

// Version: 1.0
// Author: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// Maintainer: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// URL: http://www.orocos.org/kdl

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef KDL_JNTARRAY_HPP
#define KDL_JNTARRAY_HPP

#include "frames.hpp"
#include "jacobian.hpp"

namespace KDL
{
    /**
     * @brief This class represents an fixed size array containing
     * joint values of a KDL::Chain.
     */

    class JntArray
    {
    private:
        unsigned int size;
        double* data;
    public:
        /**
         * Constructor of the joint array
         *
         * @param size size of the array, this cannot be changed
         * afterwards.
         */
        JntArray(unsigned int size);
        JntArray(const JntArray& arg);
        ~JntArray();
        JntArray& operator = ( const JntArray& arg);
        /**
         * get_item operator for the joint array, if a second value is
         * given it should be zero, since a JntArray resembles a column.
         *
         *
         * @return the joint value at position i, starting from 0
         */
        double operator()(unsigned int i,unsigned int j=0)const;
        /**
         * set_item operator, again if a second value is given it
         *should be zero.
         *
         * @return reference to the joint value at position i,starting
         *from zero.
         */
        double& operator()(unsigned int i,unsigned int j=0);
        /**
         * Returns the number of rows (size) of the array
         *
         */
        unsigned int rows()const;
        /**
         * Returns the number of columns of the array, always 1.
         */
        unsigned int columns()const;

        /**
         * Function to add two joint arrays, all the arguments must
         * have the same size: A + B = C. This function is
         * aliasing-safe, A or B can be the same array as C.
         *
         * @param src1 A
         * @param src2 B
         * @param dest C
         */
        friend void Add(const JntArray& src1,const JntArray& src2,JntArray& dest);
        /**
         * Function to substract two joint arrays, all the arguments must
         * have the same size: A - B = C. This function is
         * aliasing-safe, A or B can be the same array as C.
         *
         * @param src1 A
         * @param src2 B
         * @param dest C
         */
        friend void Substract(const JntArray& src1,const JntArray& src2,JntArray& dest);
        /**
         * Function to multiply all the array values with a scalar
         * factor: A*b=C. This function is aliasing-safe, A can be the
         * same array as C.
         *
         * @param src A
         * @param factor b
         * @param dest C
         */
        friend void Multiply(const JntArray& src,const double& factor,JntArray& dest);
        /**
         * Function to divide all the array values with a scalar
         * factor: A/b=C. This function is aliasing-safe, A can be the
         * same array as C.
         *
         * @param src A
         * @param factor b
         * @param dest C
         */
        friend void Divide(const JntArray& src,const double& factor,JntArray& dest);
        /**
         * Function to multiply a KDL::Jacobian with a KDL::JntArray
         * to get a KDL::Twist, it should not be used to calculate the
         * forward velocity kinematics, the solver classes are build
         * for this purpose.
         * J*q = t
         *
         * @param jac J
         * @param src q
         * @param dest t
         */
        friend void MultiplyJacobian(const Jacobian& jac, const JntArray& src, Twist& dest);
        /**
         * Function to set all the values of the array to 0
         *
         * @param array
         */
        friend void SetToZero(JntArray& array);
        /**
         * Function to check if two arrays are the same with a
         *precision of eps
         *
         * @param src1
         * @param src2
         * @param eps default: epsilon
         *
         */
        friend bool Equal(const JntArray& src1,const JntArray& src2,double eps=epsilon);

        friend bool operator==(const JntArray& src1,const JntArray& src2);
        //friend bool operator!=(const JntArray& src1,const JntArray& src2);
        };

    bool operator==(const JntArray& src1,const JntArray& src2);
    //bool operator!=(const JntArray& src1,const JntArray& src2);

}

#endif
