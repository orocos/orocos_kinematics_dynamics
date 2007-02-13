#ifndef KDL_KUKA361TRANSMISSION_H
#define KDL_KUKA361TRANSMISSION_H

/***************************************************************************
                        Kuka361Transmission.hpp - transmission to transform the 
                        kuka 361 kinematics to a zxxzxz kinematics 
                       ------------------------------------------------------------
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
#include <kdl/kinfam/transmission.hpp>
#include <kdl/kinfam/lineartransmission.hpp>
#include <kdl/kinfam/zxxzxz.hpp>
#include <vector>
#include <math.h>

namespace KDL {
    /**
     * \brief implementation of Transmission in the case of a Kuka 361 robot.
     */

    static const double SQRT3d2 = 0.8660254037844386;
    static const double M_PI_T2 = 2 * M_PI;
    static const double SQRT3t2 = 3.46410161513775; // 2 sqrt(3)

    /**
     * This transmission transforms the kinematics of a kuka 361 robot with a Dubbel Winkel Hand 
     * (DWH) wrist kinematics to ZXXZXZ kinematics. 
     * 
     */
    class Kuka361Transmission:public Transmission  
    {
    private:
        int          nrofjoints;
        Transmission* trans;
        JointVector  q;
        JointVector  qdot;
        Jacobian<Frame> JF;
    
    public:
        /**
         * - as an extra argument another transmission can be given as an argument to the 
         * constructor.  The ownership of the given argument is transfered to Kuka361Transmission. 
         * - Order of application of the fwd transmissions : Kuka361Transmission ( _trans ( entity) )
         * - If no argument, a  linear transmission that changes the sign of some axes is used. 
         */
        Kuka361Transmission(Transmission* _trans=NULL):
            nrofjoints(6),
            trans(_trans),
            q(6),
            qdot(6),
            JF(6)
        {
            if (trans == NULL){
                std::vector<double> offsets(6,0);
                std::vector<double> factors(6,1);
                factors[0] = -1; factors[3] = -1; factors[5] = -1;
                trans = new LinearTransmission(6, factors, offsets);
            }
        }

        Kuka361Transmission(const Kuka361Transmission& in):
            nrofjoints(in.nrofjoints),
            trans(in.trans->clone()),
            q(6),
            qdot(6),
            JF(6)
        {};
        
        Kuka361Transmission& operator = (const Kuka361Transmission& in)
        {
            this->trans = in.trans->clone();
	    return *this;
        };
                
        virtual void fwdPos(const JointVector& actuator, JointVector& geometric,int offset) 
        {
            trans->fwdPos(actuator,q,offset);
            for(unsigned int i = 0; i < 3 ; i++)
                geometric[i] = q[i];

            // convert last 3 axis from DWH into ZXZ
            double c5 = cos( q[ 4 ] );
            double s5 = sin( q[ 4 ] );
            double c5_eq = ( c5 + 3. ) / 4;   /* eq.(3-1) inverse */
            double alpha;
            if ( q[ 4 ] < -ZXXZXZ::KINEMATICS_EPS ){
                alpha = atan2( -s5, 0.8660254037844386 * ( c5 - 1. ) );  /* eq.(3-3)/(3-4) */
                geometric[ 4 ] = -2. * acos( c5_eq );
            }
            else{
                if ( q[ 4 ] < ZXXZXZ::KINEMATICS_EPS ){
                    alpha = M_PI_2;
                    geometric[ 4 ] = 0.0;
                }
                else{
                    alpha = atan2( s5, 0.8660254037844386 * ( 1. - c5 ) );
                    geometric[ 4 ] = 2. * acos( c5_eq );
                }
            }
            
            geometric[ 3 ] = q[ 3 ] + alpha;
            geometric[ 5 ] = q[ 5 ] - alpha;

        }
        
        virtual void invPos(const JointVector& geometric, JointVector& actuator,int offset) 
        {
            for(unsigned int i = 0; i < 3 ; i++)
                q[i] = geometric[i];
            
            double c5 = 4. * cos ( geometric[ 4 ] / 2. ) - 3.;
            double s5, alpha;

            if (c5 > 1.) c5 = 1; else if (c5 <-1.) c5=-1.; // correction for rounding errors
            
            if ( geometric[ 4 ] < -ZXXZXZ::KINEMATICS_EPS ){
                q[ 4 ] = -acos( c5 );
                s5 = sin( q[ 4 ] );
                alpha = atan2 ( -s5, SQRT3d2 * ( c5 - 1. ) );
            }else{
                if ( geometric[ 4 ] < ZXXZXZ::KINEMATICS_EPS ){
                    alpha = M_PI_2;
                    q[ 4 ] = 0.0;
                }else{
                    q[ 4 ] = acos( c5 );
                    s5 = sin( q[ 4 ] );
                    alpha = atan2 ( s5, SQRT3d2 * ( 1. - c5 ) );
                }
            }
            
            q[ 3 ] = geometric[ 3 ] - alpha;
            
            if ( q[ 3 ] >= M_PI )
                q[ 3 ] -= M_PI_T2;
            else if ( q[ 3 ] <= -M_PI )
                q[ 3 ] += M_PI_T2;

            q[ 5 ] = geometric[ 5 ] + alpha;
            
            if ( q[ 5 ] >= M_PI )
                q[ 5 ] -= M_PI_T2;
            else if ( q[ 5 ] <= -M_PI )
                q[ 5 ] += M_PI_T2;
            
            trans->invPos(q,actuator,offset);
        }
        
        virtual void invJac(const Jacobian<Frame>& geometric, Jacobian<Frame>& actuator,int offset) 
        {
            double s5 = sin( q [ 4 ] );
            double c5 = cos( q [ 4 ] );
            double A, B;
            double alpha;
            
            JF = geometric;
            
            if ( q[ 4 ] < -ZXXZXZ::KINEMATICS_EPS ){
                A = -2. * s5 / sqrt( ( 1. - c5 ) * ( c5 + 7. ) );
            }else{
                if ( q[ 4 ] < ZXXZXZ::KINEMATICS_EPS ){
                    A = 1.;
                }else{
                    alpha = atan2( s5, 0.8660254037844386 * ( 1. - c5 ) );
                    A = 2. * s5 / sqrt( ( 1. - c5 ) * ( c5 + 7. ) );
                }
            }
            
            B = SQRT3t2 / ( 7. + c5 );
            
            for ( unsigned int i = 0;i < 6;i++ )
                {
                    JF.deriv( 4 )( i ) = A * geometric.deriv( 4 )( i ) + B * ( -geometric.deriv( 3 )( i ) + geometric.deriv( 5 )( i ) );
                }
            
            trans->invJac(JF,actuator,offset);
        }
        
        virtual void fwdVel(const JointVector& actuator, const JointVector& actuatorvel,JointVector& geometricvel,int offset) 
        {
            trans->fwdVel(actuator,actuatorvel,qdot,offset);
            trans->fwdPos(actuator,q,offset);

            for(unsigned int i = 0; i < 3 ; i++)
                geometricvel[i] = qdot[i];

            double c5 = cos( q[ 4 ] );
            double s5 = sin( q[ 4 ] );
            
            if ( q[ 4 ] < -ZXXZXZ::KINEMATICS_EPS ){
                geometricvel[ 4 ] = -2. * s5 * qdot[ 4 ] / sqrt( ( 1. - c5 ) * ( c5 + 7. ) );
            }else{
                if ( q[ 4 ] < ZXXZXZ::KINEMATICS_EPS ){
                    geometricvel[ 4 ] = qdot[ 4 ];
                }else{
                    geometricvel[ 4 ] = 2. * s5 * qdot[ 4 ] / sqrt( ( 1. - c5 ) * ( c5 + 7. ) );
                }
            }
            
            double alphadot = -3.46410161513775 / ( 7. + c5 ) * qdot[ 4 ];
            geometricvel[ 3 ] = qdot[ 3 ] + alphadot;
            geometricvel[ 5 ] = qdot[ 5 ] - alphadot;

        }
        
        virtual void invVel(const JointVector& geometricpos, const JointVector& geometricvel, JointVector& actuatorvel, int offset) 
        {
            this->invPos(geometricpos,q,offset);
            
            for(unsigned int i = 0; i < 3 ; i++)
                qdot[i] = geometricvel[i];
            
            double c5 = cos( q[ 4 ] );
            double s5 = sin( q[ 4 ] );
            
            if ( geometricpos[ 4 ] < -ZXXZXZ::KINEMATICS_EPS ){
                qdot[ 4 ] = -sqrt( ( 1. - c5 ) * ( 7. + c5 ) ) * geometricvel[ 4 ] / 2. / s5;
            }else{
                if ( geometricpos[ 4 ] < ZXXZXZ::KINEMATICS_EPS ){
                    qdot[ 4 ] = geometricvel[ 4 ];
                }else{
                    qdot[ 4 ] = sqrt( ( 1. - c5 ) * ( 7. + c5 ) ) * geometricvel[ 4 ] / 2. / s5;
                }
            }
            
            double alphadot = -SQRT3t2 / ( 7. + c5 ) * qdot[ 4 ];
            
            qdot[ 3 ] = geometricvel[ 3 ] - alphadot;
            qdot[ 5 ] = geometricvel[ 5 ] + alphadot;
            
            //herberekening qdot = f(geometricvel)
            trans->invVel(q,qdot,actuatorvel,offset);
        }

        virtual std::string getTypeName() const
        {
            return "Kuka361Transmission";
        };
        

        virtual Transmission* getTransmission()const
        {
            return trans;
        }
        
        virtual Transmission* clone() const{
            return new Kuka361Transmission(trans->clone());
        }
        
        virtual ~Kuka361Transmission() {
            delete trans;
        }
    };

} // namespace
#endif
