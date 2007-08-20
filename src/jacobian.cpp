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
  
#include "jacobian.hpp"

namespace KDL
{
    Jacobian::Jacobian(unsigned int _size):
        size(_size)
    {
        twists = new Twist[size];
    }
    
    Jacobian::Jacobian(const Jacobian& arg):
        size(arg.columns())
    {
        twists = new Twist[size];
        for(unsigned int i=0;i<size;i++)
            twists[i] = arg.twists[i];
    }

    Jacobian& Jacobian::operator = (const Jacobian& arg)
    {
        assert(size==arg.size);
        for(unsigned int i=0;i<size;i++)
            twists[i]=arg.twists[i];
        return *this;
    }
    

    Jacobian::~Jacobian()
    {
        delete [] twists;
    }

    double Jacobian::operator()(int i,int j)const
    {
        assert(i<6&&j<size);
        return twists[j](i);
    }
    
    double& Jacobian::operator()(int i,int j)
    {
        assert(i<6&&j<size);
        return twists[j](i);
    }

    unsigned int Jacobian::rows()const
    {
        return 6;
    }
    
    unsigned int Jacobian::columns()const
    {
        return size;
    }
    
    void SetToZero(Jacobian& jac)
    {
        for(unsigned int i=0;i<jac.columns();i++)
            SetToZero(jac.twists[i]);
    }
    
    void changeRefPoint(const Jacobian& src1, const Vector& base_AB, Jacobian& dest)
    {
        assert(src1.columns()==dest.columns());
        for(unsigned int i=0;i<src1.columns();i++)
            dest.twists[i]=src1.twists[i].RefPoint(base_AB);
    }
    
    void changeBase(const Jacobian& src1, const Rotation& rot, Jacobian& dest)
    {
        assert(src1.columns()==dest.columns());
        for(unsigned int i=0;i<src1.columns();i++)
            dest.twists[i]=rot*src1.twists[i];
    }
    
    void changeRefFrame(const Jacobian& src1,const Frame& frame, Jacobian& dest)
    {
        assert(src1.columns()==dest.columns());
        for(unsigned int i=0;i<src1.columns();i++)
            dest.twists[i]=frame*src1.twists[i];
    }
}
