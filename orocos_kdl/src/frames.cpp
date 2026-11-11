/***************************************************************************
                        frames.cpp -  description
                       -------------------------
    begin                : June 2006
    copyright            : (C) 2006 Erwin Aertbelien
    email                : firstname.lastname@mech.kuleuven.ac.be

 History (only major changes)( AUTHOR-Description ) :

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

#include "frames.hpp"
#include "utilities/utility.hpp"

#include <algorithm>

namespace KDL {

    void Frame::Make4x4(double * d)
    {
        int i;
        int j;
        for (i=0;i<3;i++) {
            for (j=0;j<3;j++)
                d[i*4+j]=M(i,j);
            d[i*4+3] = p(i);
        }
        for (j=0;j<3;j++)
            d[12+j] = 0.;
        d[15] = 1;
    }

    Frame Frame::DH_Craig1989(double a,double alpha,double d,double theta)
    // returns Modified Denavit-Hartenberg parameters (According to Craig)
    {
        double ct,st,ca,sa;
        ct = cos(theta);
        st = sin(theta);
        sa = sin(alpha);
        ca = cos(alpha);
        return Frame(Rotation(
                              ct,       -st,     0,
                              st*ca,  ct*ca,   -sa,
                              st*sa,  ct*sa,    ca   ),
                     Vector(
                            a,      -sa*d,  ca*d   )
                     );
    }

    Frame Frame::DH(double a,double alpha,double d,double theta)
    // returns Denavit-Hartenberg parameters (Non-Modified DH)
    {
        double ct,st,ca,sa;
        ct = cos(theta);
        st = sin(theta);
        sa = sin(alpha);
        ca = cos(alpha);
        return Frame(Rotation(
                              ct,    -st*ca,   st*sa,
                              st,     ct*ca,  -ct*sa,
                              0,        sa,      ca   ),
                     Vector(
                            a*ct,      a*st,  d   )
                     );
    }

    double Vector2::Norm() const
    {
        double tmp1 = fabs(data[0]);
        double tmp2 = fabs(data[1]);
        
        if (tmp1 == 0 && tmp2 == 0)
            return 0;

        if (tmp1 > tmp2) {
            return tmp1*sqrt(1+sqr(data[1]/data[0]));
        } else {
            return tmp2*sqrt(1+sqr(data[0]/data[1]));
        }
    }
    // makes v a unitvector and returns the norm of v.
    // if v is smaller than eps, Vector(1,0) is returned with norm 0.
    // if this is not good, check the return value of this method.
    double Vector2::Normalize(double eps) {
        double v = this->Norm();
        if (v < eps) {
            *this = Vector2(1,0);
            return 0;
        } else {
            *this = (*this)/v;
            return v;
        }
    }


    // do some effort not to lose precision
    double Vector::Norm() const
    {
        double tmp1;
        double tmp2;
        tmp1 = fabs(data[0]);
        tmp2 = fabs(data[1]);
        if (tmp1 >= tmp2) {
            tmp2=fabs(data[2]);
            if (tmp1 >= tmp2) {
                if (tmp1 == 0) {
                    // only the exactly zero vector, all others are handled correctly
                    return 0;
                }
                return tmp1*sqrt(1+sqr(data[1]/data[0])+sqr(data[2]/data[0]));
            } else {
                return tmp2*sqrt(1+sqr(data[0]/data[2])+sqr(data[1]/data[2]));
            }
        } else {
            tmp1=fabs(data[2]);
            if (tmp2 > tmp1) {
                return tmp2*sqrt(1+sqr(data[0]/data[1])+sqr(data[2]/data[1]));
            } else {
                return tmp1*sqrt(1+sqr(data[0]/data[2])+sqr(data[1]/data[2]));
            }
        }
    }

    // makes v a unitvector and returns the norm of v.
    // if v is smaller than eps, Vector(1,0,0) is returned with norm 0.
    // if this is not good, check the return value of this method.
    double Vector::Normalize(double eps) {
        double v = this->Norm();
        if (v < eps) {
            *this = Vector(1,0,0);
            return 0;
        } else {
            *this = (*this)/v;
            return v;
        }
    }


    // The nine entries are one quantity; for a rotation matrix they are <= 1 in
    // magnitude, so the tolerance stays absolute.
    bool Equal(const Rotation& a,const Rotation& b,double eps) {
        return detail::equalScaled(a.data, b.data, 9, eps);
    }


    Rotation Rotation::Quaternion(double x,double y,double z, double w)
    {
        double x2, y2, z2, w2;
        x2 = x*x;  y2 = y*y; z2 = z*z;  w2 = w*w;
        return Rotation(w2+x2-y2-z2, 2*x*y-2*w*z, 2*x*z+2*w*y,
                        2*x*y+2*w*z, w2-x2+y2-z2, 2*y*z-2*w*x,
                        2*x*z-2*w*y, 2*y*z+2*w*x, w2-x2-y2+z2);
    }

    /* From the following sources:
       http://web.archive.org/web/20041029003853/http:/www.j3d.org/matrix_faq/matrfaq_latest.html
       http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
       RobOOP::quaternion.cpp
    */
    void Rotation::GetQuaternion(double& x,double& y,double& z, double& w) const
    {
        double trace = (*this)(0,0) + (*this)(1,1) + (*this)(2,2);
        double epsilon=1E-12;
        if( trace > epsilon ){
            double s = 0.5 / sqrt(trace + 1.0);
            w = 0.25 / s;
            x = ( (*this)(2,1) - (*this)(1,2) ) * s;
            y = ( (*this)(0,2) - (*this)(2,0) ) * s;
            z = ( (*this)(1,0) - (*this)(0,1) ) * s;
        }else{
            if ( (*this)(0,0) > (*this)(1,1) && (*this)(0,0) > (*this)(2,2) ){
                double s = 2.0 * sqrt( 1.0 + (*this)(0,0) - (*this)(1,1) - (*this)(2,2));
                w = ((*this)(2,1) - (*this)(1,2) ) / s;
                x = 0.25 * s;
                y = ((*this)(0,1) + (*this)(1,0) ) / s;
                z = ((*this)(0,2) + (*this)(2,0) ) / s;
            } else if ((*this)(1,1) > (*this)(2,2)) {
                double s = 2.0 * sqrt( 1.0 + (*this)(1,1) - (*this)(0,0) - (*this)(2,2));
                w = ((*this)(0,2) - (*this)(2,0) ) / s;
                x = ((*this)(0,1) + (*this)(1,0) ) / s;
                y = 0.25 * s;
                z = ((*this)(1,2) + (*this)(2,1) ) / s;
            }else {
                double s = 2.0 * sqrt( 1.0 + (*this)(2,2) - (*this)(0,0) - (*this)(1,1) );
                w = ((*this)(1,0) - (*this)(0,1) ) / s;
                x = ((*this)(0,2) + (*this)(2,0) ) / s;
                y = ((*this)(1,2) + (*this)(2,1) ) / s;
                z = 0.25 * s;
            }
        }    
    }

Rotation Rotation::RPY(double roll,double pitch,double yaw)
    {
        double ca1,cb1,cc1,sa1,sb1,sc1;
        ca1 = cos(yaw); sa1 = sin(yaw);
        cb1 = cos(pitch);sb1 = sin(pitch);
        cc1 = cos(roll);sc1 = sin(roll);
        return Rotation(ca1*cb1,ca1*sb1*sc1 - sa1*cc1,ca1*sb1*cc1 + sa1*sc1,
                   sa1*cb1,sa1*sb1*sc1 + ca1*cc1,sa1*sb1*cc1 - ca1*sc1,
                   -sb1,cb1*sc1,cb1*cc1);
    }

// Gives back a rotation matrix specified with RPY convention
void Rotation::GetRPY(double& roll,double& pitch,double& yaw) const
    {
		double epsilon=1E-12;
		pitch = atan2(-data[6], sqrt( sqr(data[0]) +sqr(data[3]) )  );
        if ( fabs(pitch) > (PI_2-epsilon) ) {
            yaw = atan2(	-data[1], data[4]);
            roll  = 0.0 ;
        } else {
            roll  = atan2(data[7], data[8]);
            yaw   = atan2(data[3], data[0]);
        }
    }

Rotation Rotation::EulerZYZ(double Alfa,double Beta,double Gamma) {
        double sa,ca,sb,cb,sg,cg;
        sa  = sin(Alfa);ca = cos(Alfa);
        sb  = sin(Beta);cb = cos(Beta);
        sg  = sin(Gamma);cg = cos(Gamma);
        return Rotation( ca*cb*cg-sa*sg,     -ca*cb*sg-sa*cg,        ca*sb,
                 sa*cb*cg+ca*sg,     -sa*cb*sg+ca*cg,        sa*sb,
                 -sb*cg ,                sb*sg,              cb
                );

     }


void Rotation::GetEulerZYZ(double& alpha,double& beta,double& gamma) const {
		double epsilon = 1E-12;
        if (fabs(data[8]) > 1-epsilon  ) {
            gamma=0.0;
            if (data[8]>0) {
                beta = 0.0;
                alpha= atan2(data[3],data[0]);
            } else {
                beta = PI;
                alpha= atan2(-data[3],-data[0]);
            }
        } else {
            alpha=atan2(data[5], data[2]);
            beta=atan2(sqrt( sqr(data[6]) +sqr(data[7]) ),data[8]);
            gamma=atan2(data[7], -data[6]);
        }
 }

Rotation Rotation::Rot(const Vector& rotaxis,double angle) {
    // The formula is
    // V.(V.tr) + st*[V x] + ct*(I-V.(V.tr))
    // can be found by multiplying it with an arbitrary vector p
    // and noting that this vector is rotated.
    Vector rotvec = rotaxis;
	rotvec.Normalize();
	return Rotation::Rot2(rotvec,angle);
}

Rotation Rotation::Rot2(const Vector& rotvec,double angle) {
    // rotvec should be normalized !
    // The formula is
    // V.(V.tr) + st*[V x] + ct*(I-V.(V.tr))
    // can be found by multiplying it with an arbitrary vector p
    // and noting that this vector is rotated.
    double ct = cos(angle);
    double st = sin(angle);
    double vt = 1-ct;
    double m_vt_0=vt*rotvec(0);
    double m_vt_1=vt*rotvec(1);
    double m_vt_2=vt*rotvec(2);
    double m_st_0=rotvec(0)*st;
    double m_st_1=rotvec(1)*st;
    double m_st_2=rotvec(2)*st;
    double m_vt_0_1=m_vt_0*rotvec(1);
    double m_vt_0_2=m_vt_0*rotvec(2);
    double m_vt_1_2=m_vt_1*rotvec(2);
    return Rotation(
        ct      +  m_vt_0*rotvec(0),
        -m_st_2 +  m_vt_0_1,
        m_st_1  +  m_vt_0_2,
        m_st_2  +  m_vt_0_1,
        ct      +  m_vt_1*rotvec(1),
        -m_st_0 +  m_vt_1_2,
        -m_st_1 +  m_vt_0_2,
        m_st_0  +  m_vt_1_2,
        ct      +  m_vt_2*rotvec(2)
        );
}



Vector Rotation::GetRot() const
         // Returns a vector with the direction of the equiv. axis
         // and its norm is angle
     {
       Vector axis;
       double angle;
       angle = Rotation::GetRotAngle(axis,epsilon);
       return axis * angle;
     }



/** Returns the rotation angle around the equiv. axis
 * @param axis the rotation axis is returned in this variable
 * @param eps :  in the case of angle == 0 : rot axis is undefined and chosen
 *                                         to be the Z-axis
 *               in the case of angle == PI : 2 solutions, positive Z-component
 *                                            of the axis is chosen.
 * @result returns the rotation angle (between [0..PI] )
 * /todo :
 *   Check corresponding routines in rframes and rrframes
 */
double Rotation::GetRotAngle(Vector& axis,double eps) const {
    double angle,x,y,z; // variables for result
    double epsilon = eps; // margin to allow for rounding errors
    double epsilon2 = eps*10; // margin to distinguish between 0 and 180 degrees

    // optional check that input is pure rotation, 'isRotationMatrix' is defined at:
    // http://www.euclideanspace.com/maths/algebra/matrix/orthogonal/rotation/

    if ((std::abs(data[1] - data[3]) < epsilon)
        && (std::abs(data[2] - data[6])< epsilon)
        && (std::abs(data[5] - data[7]) < epsilon))
    {
        // singularity found
        // first check for identity matrix which must have +1 for all terms
        //  in leading diagonal and zero in other terms
        if ((std::abs(data[1] + data[3]) < epsilon2)
            && (std::abs(data[2] + data[6]) < epsilon2)
            && (std::abs(data[5] + data[7]) < epsilon2)
            && (std::abs(data[0] + data[4] + data[8]-3) < epsilon2))
        {
            // this singularity is identity matrix so angle = 0, axis is arbitrary
            // Choose 0, 0, 1 to pass orocos tests
            axis = KDL::Vector(0,0,1);
            angle = 0.0;
            return angle;
        }

        // otherwise this singularity is angle = 180
        angle = PI;
        double xx = (data[0] + 1) / 2;
        double yy = (data[4] + 1) / 2;
        double zz = (data[8] + 1) / 2;
        double xy = (data[1] + data[3]) / 4;
        double xz = (data[2] + data[6]) / 4;
        double yz = (data[5] + data[7]) / 4;

        if ((xx > yy) && (xx > zz))
        {
            // data[0] is the largest diagonal term
            x = sqrt(xx);
            y = xy/x;
            z = xz/x;
        }
        else if (yy > zz)
        {
            // data[4] is the largest diagonal term
            y = sqrt(yy);
            x = xy/y;
            z = yz/y;
        }
        else
        {
            // data[8] is the largest diagonal term so base result on this
            z = sqrt(zz);
            x = xz/z;
            y = yz/z;
        }
        axis = KDL::Vector(x, y, z);
        return angle; // return 180 deg rotation
    }

    double f = (data[0] + data[4] + data[8] - 1) / 2;

    x = (data[7] - data[5]);
    y = (data[2] - data[6]);
    z = (data[3] - data[1]);
    axis = KDL::Vector(x, y, z);
    angle = atan2(axis.Norm()/2,f);
    axis.Normalize();
    return angle;
}

// *this = *this * ROT(X,angle)
void Rotation::DoRotX(double angle)
{
    double cs = cos(angle);
    double sn = sin(angle);
    double x1,x2,x3;
    x1  = cs* (*this)(0,1) + sn* (*this)(0,2);
    x2  = cs* (*this)(1,1) + sn* (*this)(1,2);
    x3  = cs* (*this)(2,1) + sn* (*this)(2,2);
    (*this)(0,2) = -sn* (*this)(0,1) + cs* (*this)(0,2);
    (*this)(1,2) = -sn* (*this)(1,1) + cs* (*this)(1,2);
    (*this)(2,2) = -sn* (*this)(2,1) + cs* (*this)(2,2);
    (*this)(0,1) = x1;
    (*this)(1,1) = x2;
    (*this)(2,1) = x3;
}

void Rotation::DoRotY(double angle)
{
    double cs = cos(angle);
    double sn = sin(angle);
    double x1,x2,x3;
    x1  = cs* (*this)(0,0) - sn* (*this)(0,2);
    x2  = cs* (*this)(1,0) - sn* (*this)(1,2);
    x3  = cs* (*this)(2,0) - sn* (*this)(2,2);
    (*this)(0,2) = sn* (*this)(0,0) + cs* (*this)(0,2);
    (*this)(1,2) = sn* (*this)(1,0) + cs* (*this)(1,2);
    (*this)(2,2) = sn* (*this)(2,0) + cs* (*this)(2,2);
    (*this)(0,0) = x1;
    (*this)(1,0) = x2;
    (*this)(2,0) = x3;
}

void Rotation::DoRotZ(double angle)
{
    double cs = cos(angle);
    double sn = sin(angle);
    double x1,x2,x3;
    x1  = cs* (*this)(0,0) + sn* (*this)(0,1);
    x2  = cs* (*this)(1,0) + sn* (*this)(1,1);
    x3  = cs* (*this)(2,0) + sn* (*this)(2,1);
    (*this)(0,1) = -sn* (*this)(0,0) + cs* (*this)(0,1);
    (*this)(1,1) = -sn* (*this)(1,0) + cs* (*this)(1,1);
    (*this)(2,1) = -sn* (*this)(2,0) + cs* (*this)(2,1);
    (*this)(0,0) = x1;
    (*this)(1,0) = x2;
    (*this)(2,0) = x3;
}

void Frame::Integrate(const Twist& t_this,double samplefrequency)
{
    double n = t_this.rot.Norm()/samplefrequency;
    if (n<epsilon) {
        p += M*(t_this.vel/samplefrequency);
    } else {
        (*this) = (*this) * 
            Frame ( Rotation::Rot( t_this.rot, n ),
                    t_this.vel/samplefrequency
                );
    }
}

void Rotation2::SetRot(double angle) {
    c=cos(angle);s=sin(angle);
}

Rotation2 Rotation2::Rot(double angle) {
    return Rotation2(cos(angle),sin(angle));
}

double Rotation2::GetRot() const {
    return atan2(s,c);
}

// Tolerant comparison: one detail::equalScaled call per physical quantity, so the
// magnitude of one quantity (e.g. a translation) never loosens another (e.g. a rotation).

bool Equal(const Vector& a,const Vector& b,double eps) {
    return detail::equalScaled(a.data, b.data, 3, eps);
}

bool Equal(const Frame& a,const Frame& b,double eps) {
        return (Equal(a.p,b.p,eps)&&
                Equal(a.M,b.M,eps)   );
}

bool Equal(const Wrench& a,const Wrench& b,double eps) {
        return (Equal(a.force,b.force,eps)&&
                Equal(a.torque,b.torque,eps)  );
}

bool Equal(const Twist& a,const Twist& b,double eps) {
        return (Equal(a.rot,b.rot,eps)&&
                Equal(a.vel,b.vel,eps)  );
}

bool Equal(const Vector2& a,const Vector2& b,double eps) {
    return detail::equalScaled(a.data, b.data, 2, eps);
}

bool Equal(const Rotation2& a,const Rotation2& b,double eps) {
    const double ca[2] = {a.c, a.s};
    const double cb[2] = {b.c, b.s};
    return detail::equalScaled(ca, cb, 2, eps);
}

bool Equal(const Frame2& a,const Frame2& b,double eps) {
        return (Equal(a.p,b.p,eps)&&
                Equal(a.M,b.M,eps)   );
}

Rotation Rot(const Vector& axis_a_b) {
    // The formula is 
    // V.(V.tr) + st*[V x] + ct*(I-V.(V.tr))
    // can be found by multiplying it with an arbitrary vector p
    // and noting that this vector is rotated.
	Vector rotvec = axis_a_b;
	double angle = rotvec.Normalize(1E-10);
    double ct = ::cos(angle);
    double st = ::sin(angle);
    double vt = 1-ct;
    return Rotation(
        ct            +  vt*rotvec(0)*rotvec(0), 
        -rotvec(2)*st +  vt*rotvec(0)*rotvec(1), 
        rotvec(1)*st  +  vt*rotvec(0)*rotvec(2),
        rotvec(2)*st  +  vt*rotvec(1)*rotvec(0),
        ct            +  vt*rotvec(1)*rotvec(1),
        -rotvec(0)*st +  vt*rotvec(1)*rotvec(2),
        -rotvec(1)*st +  vt*rotvec(2)*rotvec(0),
        rotvec(0)*st  +  vt*rotvec(2)*rotvec(1),
        ct            +  vt*rotvec(2)*rotvec(2)
        );
    }

Vector diff(const Rotation& R_a_b1,const Rotation& R_a_b2,double dt) {
	Rotation R_b1_b2(R_a_b1.Inverse()*R_a_b2);
	return R_a_b1 * R_b1_b2.GetRot() / dt;
}

Twist diff(const Frame& F_a_b1,const Frame& F_a_b2,double dt) {
	return Twist(
			diff(F_a_b1.p,F_a_b2.p,dt),
			diff(F_a_b1.M,F_a_b2.M,dt)
			);
}

Rotation addDelta(const Rotation& a,const Vector&da,double dt) {
	return Rot(da*dt)*a;
}
Frame addDelta(const Frame& a,const Twist& da,double dt) {
	return Frame(
			addDelta(a.M,da.rot,dt),
			addDelta(a.p,da.vel,dt)
		   );
}

void random(Vector& a) {
	random(a[0]);
	random(a[1]);
	random(a[2]);
}
void random(Twist& a) {
	random(a.rot);
	random(a.vel);
}
void random(Wrench& a) {
   	random(a.torque);
	random(a.force);
}

void random(Rotation& R) {
	double alfa;
	double beta;
	double gamma;
	random(alfa);
	random(beta);
	random(gamma);
	R = Rotation::EulerZYX(alfa,beta,gamma);
}

void random(Frame& F) {
	random(F.M);
	random(F.p);
}

void posrandom(Vector& a) {
	posrandom(a[0]);
	posrandom(a[1]);
	posrandom(a[2]);
}
void posrandom(Twist& a) {
	posrandom(a.rot);
	posrandom(a.vel);
}
void posrandom(Wrench& a) {
   	posrandom(a.torque);
	posrandom(a.force);
}

void posrandom(Rotation& R) {
	double alfa;
	double beta;
	double gamma;
	posrandom(alfa);
	posrandom(beta);
	posrandom(gamma);
	R = Rotation::EulerZYX(alfa,beta,gamma);
}

void posrandom(Frame& F) {
	posrandom(F.M);
	posrandom(F.p);
}

}
