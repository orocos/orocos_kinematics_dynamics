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

#include "rigidbodyinertia.hpp"

#include <Eigen/Core>

namespace KDL{
    
    const static bool mhi=true;

    RigidBodyInertia::RigidBodyInertia(double m_,const Vector& h_,const RotationalInertia& I_,bool /*mhi*/):
        m(m_),h(h_),I(I_)
    {
    }
    
    RigidBodyInertia::RigidBodyInertia(double m_, const Vector& c_, const RotationalInertia& Ic):
        m(m_),h(m*c_){
        //I=Ic-c x c x
        Eigen::Vector3d c_eig=Eigen::Map<const Eigen::Vector3d>(c_.data);
        Eigen::Map<Eigen::Matrix3d>(I.data)=Eigen::Map<const Eigen::Matrix3d>(Ic.data)-m_*(c_eig*c_eig.transpose()-c_eig.dot(c_eig)*Eigen::Matrix3d::Identity());
    }
    
    RigidBodyInertia operator*(double a,const RigidBodyInertia& I){
        return RigidBodyInertia(a*I.m,a*I.h,a*I.I,mhi);
    }
    
    RigidBodyInertia operator+(const RigidBodyInertia& Ia, const RigidBodyInertia& Ib){
        return RigidBodyInertia(Ia.m+Ib.m,Ia.h+Ib.h,Ia.I+Ib.I,mhi);
    }
    
    Wrench operator*(const RigidBodyInertia& I,const Twist& t){
        return Wrench(I.m*t.vel-I.h*t.rot,I.I*t.rot+I.h*t.vel);
    }

    RigidBodyInertia operator*(const Frame& T,const RigidBodyInertia& I){
        Frame X=T.Inverse();
        //mb=ma
        //hb=R*(h-m*r)
        //Ib = R(Ia+r x h x + (h-m*r) x r x)R'
        Vector hmr = (I.h-I.m*X.p);
        Eigen::Vector3d r_eig = Eigen::Map<Eigen::Vector3d>(X.p.data);
        Eigen::Vector3d h_eig = Eigen::Map<const Eigen::Vector3d>(I.h.data);
        Eigen::Vector3d hmr_eig = Eigen::Map<Eigen::Vector3d>(hmr.data);
        Eigen::Matrix3d rcrosshcross = h_eig *r_eig.transpose()-r_eig.dot(h_eig)*Eigen::Matrix3d::Identity();
        Eigen::Matrix3d hmrcrossrcross = r_eig*hmr_eig.transpose()-hmr_eig.dot(r_eig)*Eigen::Matrix3d::Identity();
        Eigen::Matrix3d R = Eigen::Map<Eigen::Matrix3d>(X.M.data);
        RotationalInertia Ib;
        Eigen::Map<Eigen::Matrix3d>(Ib.data) = R*((Eigen::Map<const Eigen::Matrix3d>(I.I.data)+rcrosshcross+hmrcrossrcross)*R.transpose());
        
        return RigidBodyInertia(I.m,T.M*hmr,Ib,mhi);
    }

    RigidBodyInertia operator*(const Rotation& M,const RigidBodyInertia& I){
        //mb=ma
        //hb=R*h
        //Ib = R(Ia)R' with r=0
        Eigen::Matrix3d R = Eigen::Map<const Eigen::Matrix3d>(M.data);
        RotationalInertia Ib;
        Eigen::Map<Eigen::Matrix3d>(Ib.data) = R.transpose()*(Eigen::Map<const Eigen::Matrix3d>(I.I.data)*R);
        
        return RigidBodyInertia(I.m,M*I.h,Ib,mhi);
    }

    RigidBodyInertia RigidBodyInertia::RefPoint(const Vector& p){
        //mb=ma
        //hb=(h-m*r)
        //Ib = (Ia+r x h x + (h-m*r) x r x)
        Vector hmr = (this->h-this->m*p);
        Eigen::Vector3d r_eig = Eigen::Map<const Eigen::Vector3d>(p.data);
        Eigen::Vector3d h_eig = Eigen::Map<Eigen::Vector3d>(this->h.data);
        Eigen::Vector3d hmr_eig = Eigen::Map<Eigen::Vector3d>(hmr.data);
        Eigen::Matrix3d rcrosshcross = h_eig * r_eig.transpose()-r_eig.dot(h_eig)*Eigen::Matrix3d::Identity();
        Eigen::Matrix3d hmrcrossrcross = r_eig*hmr_eig.transpose()-hmr_eig.dot(r_eig)*Eigen::Matrix3d::Identity();
        RotationalInertia Ib;
        Eigen::Map<Eigen::Matrix3d>(Ib.data) = Eigen::Map<Eigen::Matrix3d>(this->I.data)+rcrosshcross+hmrcrossrcross;
        
        return RigidBodyInertia(this->m,hmr,Ib,mhi);
    }
}//namespace
