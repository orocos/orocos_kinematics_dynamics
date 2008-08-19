// Copyright  (C)  2008  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

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


//implementation of svd according to (Maciejewski and Klein,1989)
//and (Braun, Ulrey, Maciejewski and Siegel,2002)
#ifndef SVD_BOOST_MACIE
#define SVD_BOOST_MACIE

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>

namespace ublas = boost::numeric::ublas;

namespace KDL
{
    int svd_boost_Macie(ublas::matrix<double>& A,ublas::matrix<double>& U,ublas::vector<double>& S, ublas::matrix<double>& V,
                        ublas::matrix<double>& B, ublas::vector<double>& tempi,
                        double treshold,bool toggle)
    {
        bool rotate = true;
        unsigned int sweeps=0;
        unsigned int rotations=0;
        if(toggle){
            //Calculate B from new A and previous V
            noalias(B)=prod(A,V);
            while(rotate){
                rotate=false;
                rotations=0;
                //Perform rotations between columns of B
                for(unsigned int i=0;i<B.size2();i++){
                    for(unsigned int j=i+1;j<B.size2();j++){
                        ublas::matrix_column<ublas::matrix<double> > Bi (B, i);
                        ublas::matrix_column<ublas::matrix<double> > Bj (B, j);
                        //calculate plane rotation
                        double p = ublas::inner_prod(Bi,Bj);
                        double qi = ublas::inner_prod(Bi,Bi);
                        double qj = ublas::inner_prod(Bj,Bj);
                        double q=qi-qj;
                        double alpha = pow(p,2.0)/(qi*qj);
                        //if columns are orthogonal with precision
                        //treshold, don't perform rotation and continue
                        if(alpha<treshold)
                            continue;
                        rotations++;
                        double c = sqrt(4*pow(p,2.0)+pow(q,2.0));
                        double cos,sin;
                        if(q>=0){
                            cos=sqrt((c+q)/(2*c));
                            sin=p/(c*cos);
                        }else{
                            if(p<0)
                                sin=-sqrt((c-q)/(2*c));
                            else
                                sin=sqrt((c-q)/(2*c));
                            cos=p/(c*sin);
                        }

                        //Apply plane rotation to columns of B
                        tempi.assign (cos*Bi + sin*Bj);
                        Bj.assign (- sin*Bi + cos*Bj);
                        Bi.assign (tempi);

                        ublas::vector_range<ublas::vector<double> > tempiv(tempi, ublas::range (0, V.size1()));
                        ublas::matrix_column<ublas::matrix<double> > Vi (V, i);
                        ublas::matrix_column<ublas::matrix<double> > Vj (V, j);

                        //Apply plane rotation to columns of V
                        tempiv.assign (cos*Vi + sin*Vj);
                        Vj.assign (- sin*Vi + cos*Vj);
                        Vi.assign (tempiv);

                        rotate=true;
                    }
                }
                //Only calculate new U and S if there were any rotations
                if(rotations!=0){
                    for(unsigned int i=0;i<U.size1();i++) {
                        ublas::matrix_column<ublas::matrix<double> > Ui (U, i);
                        if(i<B.size2()){
                            ublas::matrix_column<ublas::matrix<double> > Bi (B, i);
                            double si=sqrt(inner_prod(Bi,Bi));
                            if(si==0)
                                Ui.assign(Bi);
                            else
                                Ui.assign(Bi/si);
                            S(i)=si;
                        }
                        else
                            Ui.assign(0*tempi);
                    }
                    sweeps++;
                }
            }
            return sweeps;
        }else{
            //Calculate B from new A and previous U'
            noalias(B)=prod(trans(U),A);
            while(rotate){
                rotate=false;
                rotations=0;
                //Perform rotations between rows of B
                for(unsigned int i=0;i<B.size2();i++){
                    for(unsigned int j=i+1;j<B.size2();j++){
                        ublas::matrix_row<ublas::matrix<double> > Bi (B, i);
                        ublas::matrix_row<ublas::matrix<double> > Bj (B, j);
                        //calculate plane rotation
                        double p = ublas::inner_prod(Bi,Bj);
                        double qi = ublas::inner_prod(Bi,Bi);
                        double qj = ublas::inner_prod(Bj,Bj);
                        //std::cout<<"q"<<i<<": "<<qi<<std::endl;
                        //std::cout<<"q"<<j<<": "<<qj<<std::endl;
                        //std::cout<<"p"<<i<<j<<": "<<p<<std::endl;

                        double q=qi-qj;
                        double alpha = pow(p,2.0)/(qi*qj);
                        //if columns are orthogonal with precision
                        //treshold, don't perform rotation and
                        //continue
                        if(alpha<treshold)
                            continue;
                        rotations++;
                        double c = sqrt(4*pow(p,2.0)+pow(q,2.0));
                        double cos,sin;
                        if(q>=0){
                            cos=sqrt((c+q)/(2*c));
                            sin=p/(c*cos);
                        }else{
                            if(p<0)
                                sin=-sqrt((c-q)/(2*c));
                            else
                                sin=sqrt((c-q)/(2*c));
                            cos=p/(c*sin);
                        }

                        //Apply plane rotation to rows of B
                        ublas::vector_range<ublas::vector<double> > tempib(tempi, ublas::range (0, B.size2()));
                        tempib.assign (cos*Bi + sin*Bj);
                        Bj.assign (- sin*Bi + cos*Bj);
                        Bi.assign (tempib);

                        ublas::vector_range<ublas::vector<double> > tempiu(tempi, ublas::range (0, U.size1()));
                        ublas::matrix_column<ublas::matrix<double> > Ui (U, i);
                        ublas::matrix_column<ublas::matrix<double> > Uj (U, j);

                        //Apply plane rotation to rows of U
                        tempiu.assign (cos*Ui + sin*Uj);
                        Uj.assign (- sin*Ui + cos*Uj);
                        Ui.assign (tempiu);

                        rotate=true;
                    }
                }

                //Only calculate new U and S if there were any rotations
                if(rotations!=0){
                    for(unsigned int i=0;i<V.size1();i++) {
                        ublas::matrix_row<ublas::matrix<double> > Bi (B, i);
                        ublas::matrix_column<ublas::matrix<double> > Vi (V, i);
                        double si=sqrt(inner_prod(Bi,Bi));
                        if(si==0)
                            Vi.assign(Bi);
                        else
                            Vi.assign(Bi/si);
                        S(i)=si;
                    }
                    sweeps++;
                }
            }
            return sweeps;
        }
    }


}
#endif
