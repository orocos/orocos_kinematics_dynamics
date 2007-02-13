#include <kdl/constraints.hpp>
#include <kdl/jacobianframe.hpp>
#include <fstream>
#include <iomanip>

using namespace KDL;

/**
 * \todo maxrows == maxcols 
 */

ConstraintMatrix::ConstraintMatrix(int _maxrows,int _maxcols) :
      maxrows(_maxrows),
      maxcols(_maxcols),
      cmat(new double[_maxrows*_maxcols]),
      cmatstride(_maxcols),
      desval(new double[_maxrows]),
      weight(new double[_maxrows]),   /* square root of the constraint weight matrix */
      jsweight(new double[_maxcols]), /* square root of the joint space weight matrix */
      pinvtmps( _maxrows>_maxcols?_maxrows:_maxcols), 
      /*pinvtmps(
        _maxrows>_maxcols?_maxrows:_maxcols, 
        _maxrows>_maxcols?_maxrows:_maxcols,
        100,
        5E-2), */
      cmati(new double[_maxrows*_maxcols]),
      cmatistride(_maxrows),
      nrOfConstraints(0),      
      eps(0.05),
      nrofits(100)
    {}

  void ConstraintMatrix::dump(std::ostream& os) {
      int p = os.precision(7);
	  int w = 16;
	  std::ios_base::fmtflags fl = os.setf(std::ios::scientific);
      int i,j;
      os << "Constraint Matrix and desired velocity(last column)" << std::endl;
      for (i=0;i<nrOfConstraints;++i) {
          for (j=0;j<nrofjoints;++j) {
              os << std::setw(w) << cmat[i*cmatstride+j] << "\t";
          }
          os << desval[i];
          os << std::endl;
      }
      os.flags(fl);
	  os.precision(p);
  }

  void ConstraintMatrix::dumpsvd(std::ostream& os) {
      int p = os.precision(7);
	  int w = 16;
	  std::ios_base::fmtflags fl = os.setf(std::ios::scientific);
      int i;
      for (i=0;i<nrofjoints;++i) {
          os << std::setw(w) << pinvtmps.S[pinvtmps.ndx[i]] << " ";
      }
      os << std::endl;
      os.flags(fl);
	  os.precision(p);
  }

	void ConstraintMatrix::resetConstraints(int _nrofjoints) {
        int i;
        nrofjoints = _nrofjoints;
        nrOfConstraints=0;        
        for (i=0;i<nrofjoints;++i) {
            jsweight[i]=1.0;
        }
    }
    void ConstraintMatrix::addConstraint(const Jacobian<double>& c,double K,double _desval,double _desvald,double _weight) {
        int i;        
        assert((0<=nrOfConstraints)&&(nrOfConstraints<maxrows));
        assert((!c.hasDerivs())||(c.nrOfDeriv()==nrofjoints));
        desval[nrOfConstraints] = K*(_desval - c.value()) + _desvald;
        weight[nrOfConstraints] = ::sqrt(_weight);
        if (c.hasDerivs()) {
            for (i=0;i<nrofjoints;++i) {
				if (c.hasDeriv(i)) {
					cmat[cmatstride*nrOfConstraints+i] = c.deriv(i);
				} else {
					cmat[cmatstride*nrOfConstraints+i] = 0.0;
				}
			}
        } else {
            for (i=0;i<nrofjoints;++i) {
                cmat[cmatstride*nrOfConstraints+i] = 0.0;
            }
        }
        nrOfConstraints++;
    }

    void ConstraintMatrix::addConstraintJoint(int jointnr,double value,double K,double _desval,double _desvald,double _weight) {
        int i;        
        assert((0<=nrOfConstraints)&&(nrOfConstraints<maxrows));
        desval[nrOfConstraints] = K*(_desval - value) + _desvald;
        weight[nrOfConstraints] = ::sqrt(_weight);
        for (i=0;i<nrofjoints;++i) {
            cmat[cmatstride*nrOfConstraints+i] = (i==jointnr)?1.0:0.0;
        }
        nrOfConstraints++;
    }


	void ConstraintMatrix::addConstraint(
		const Jacobian<Vector>& c,
		double K,
		const Vector& _desval,
		const Vector& _desvald,
		double _weight
	) {
        assert((0<=nrOfConstraints)&&(nrOfConstraints+2<maxrows));
        assert((!c.hasDerivs())||(c.nrOfDeriv()==nrofjoints));
		int r,i;
		Vector d = K*(_desval- c.value()) + _desvald;
        _weight = ::sqrt(_weight);
		for (r=0;r<3;r++) {	
			desval[nrOfConstraints] = d(r);
			weight[nrOfConstraints] = _weight;
			if (c.hasDerivs()) {
				for (i=0;i<nrofjoints;++i) {
					if (c.hasDeriv(i)) {
						cmat[cmatstride*nrOfConstraints+i] = c.deriv(i)(r);
					} else {
						cmat[cmatstride*nrOfConstraints+i] = 0.0;
					}
				}
			} else {
				for (i=0;i<nrofjoints;++i) {
					cmat[cmatstride*nrOfConstraints+i] = 0.0;
				}
			}
			nrOfConstraints++;
		}        
  	}
	/**
	 * \brief adds a 6 d.o.f. constraint on a Frame value and allows for control constant and weight for each component.
	 */
	void ConstraintMatrix::addConstraint(
		const Jacobian<Frame>& c,
		const std::vector<double>& K,
		const Frame& _desval,
		const Twist& _desvald,
		const std::vector<double>& _weight
	) {
        assert((0<=nrOfConstraints)&&(nrOfConstraints+5<maxrows));
        assert((!c.hasDerivs())||(c.nrOfDeriv()==nrofjoints));
		int r,i;
		Twist d = diff(c.value(),_desval,1.0);
		for (r=0;r<6;r++) {	
			desval[nrOfConstraints] = K[r]*d(r)+_desvald(r);
			weight[nrOfConstraints] = ::sqrt(_weight[r]);
			if (c.hasDerivs()) {
				for (i=0;i<nrofjoints;++i) {
					if (c.hasDeriv(i)) {
						cmat[cmatstride*nrOfConstraints+i] = c.deriv(i)(r);
					} else {
						cmat[cmatstride*nrOfConstraints+i] = 0.0;
					}
				}
			} else {
				for (i=0;i<nrofjoints;++i) {
					cmat[cmatstride*nrOfConstraints+i] = 0.0;
				}
			}
			nrOfConstraints++;
		}        
    }

	/**
	 * \brief adds a 6 d.o.f. constraint specifying the derivative of a Frame.
	 */
	void ConstraintMatrix::addConstraintWithoutControl(
		const Jacobian<Frame>& c,
		const Twist& desired,
		const std::vector<double>& _weight
	) {
        assert((0<=nrOfConstraints)&&(nrOfConstraints+5<maxrows));
        assert((!c.hasDerivs())||(c.nrOfDeriv()==nrofjoints));
		int r,i;
		for (r=0;r<6;r++) {	
			desval[nrOfConstraints] = desired(r);
			weight[nrOfConstraints] = ::sqrt(_weight[r]);
			if (c.hasDerivs()) {
				for (i=0;i<nrofjoints;++i) {
					if (c.hasDeriv(i)) {
						cmat[cmatstride*nrOfConstraints+i] = c.deriv(i)(r);
					} else {
						cmat[cmatstride*nrOfConstraints+i] = 0.0;
					}
				}
			} else {
				for (i=0;i<nrofjoints;++i) {
					cmat[cmatstride*nrOfConstraints+i] = 0.0;
				}
			}
			nrOfConstraints++;
		}   
    }



	void ConstraintMatrix::addConstraint(
		const Jacobian<Frame>& c,
		double Kpos,
		double Krot,
		const Frame& _desval,
		const Twist& _desvald,
		double _weightpos,
		double _weightrot
	) {
        assert((0<=nrOfConstraints)&&(nrOfConstraints+5<maxrows));
        assert((!c.hasDerivs())||(c.nrOfDeriv()==nrofjoints));
		int r,i;
		Twist d = diff(c.value(),_desval,1.0);
        _weightpos = ::sqrt(_weightpos);
        _weightrot = ::sqrt(_weightrot);
		for (r=0;r<6;r++) {	
			if (r<3) {
				desval[nrOfConstraints] = Kpos*d(r)+_desvald(r);
				weight[nrOfConstraints] = _weightpos;
			} else {
				desval[nrOfConstraints] = Krot*d(r)+_desvald(r);
				weight[nrOfConstraints] = _weightrot;
			}
			if (c.hasDerivs()) {
				for (i=0;i<nrofjoints;++i) {
					if (c.hasDeriv(i)) {
						cmat[cmatstride*nrOfConstraints+i] = c.deriv(i)(r);
					} else {
						cmat[cmatstride*nrOfConstraints+i] = 0.0;
					}
				}
			} else {
				for (i=0;i<nrofjoints;++i) {
					cmat[cmatstride*nrOfConstraints+i] = 0.0;
				}
			}
			nrOfConstraints++;
		}        
  	}



	void ConstraintMatrix::addConstraint(
		const Jacobian<Twist>& c,
		double Kpos,
		double Krot,
		const Twist& _desval,
		const Twist& _desvald,
		double _weightpos,
		double _weightrot
	) {
        assert((0<=nrOfConstraints)&&(nrOfConstraints+5<maxrows));
        assert((!c.hasDerivs())||(c.nrOfDeriv()==nrofjoints));
		int r,i;
		Twist d = _desval - c.value();
        _weightpos = ::sqrt(_weightpos);
        _weightrot = ::sqrt(_weightrot);
		for (r=0;r<6;r++) {	
			if (r<3) {
				desval[nrOfConstraints] = Kpos*d(r)+_desvald(r);
				weight[nrOfConstraints] = _weightpos;
			} else {
				desval[nrOfConstraints] = Krot*d(r)+_desvald(r);
				weight[nrOfConstraints] = _weightrot;
			}
			if (c.hasDerivs()) {
				for (i=0;i<nrofjoints;++i) {
					if (c.hasDeriv(i)) {
						cmat[cmatstride*nrOfConstraints+i] = c.deriv(i)(r);
					} else {
						cmat[cmatstride*nrOfConstraints+i] = 0.0;
					}
				}
			} else {
				for (i=0;i<nrofjoints;++i) {
					cmat[cmatstride*nrOfConstraints+i] = 0.0;
				}
			}
			nrOfConstraints++;
		}        
  	}




	void ConstraintMatrix::addConstraint(
		const Jacobian<Wrench>& c,
		double Kpos,
		double Krot,
		const Wrench& _desval,
		const Wrench& _desvald,
		double _weightpos,
		double _weightrot
	) {

        assert((0<=nrOfConstraints)&&(nrOfConstraints+5<maxrows));
        assert((!c.hasDerivs())||(c.nrOfDeriv()==nrofjoints));
		int r,i;
        _weightpos = ::sqrt(_weightpos);
        _weightrot = ::sqrt(_weightrot);
		Wrench d = diff(c.value(),_desval,1.0);
		for (r=0;r<6;r++) {	
			if (r<3) {
				desval[nrOfConstraints] = Kpos*d(r)+_desvald(r);
				weight[nrOfConstraints] = _weightpos;
			} else {
				desval[nrOfConstraints] = Krot*d(r)+_desvald(r);
				weight[nrOfConstraints] = _weightrot;
			}
			if (c.hasDerivs()) {
				for (i=0;i<nrofjoints;++i) {
					if (c.hasDeriv(i)) {
						cmat[cmatstride*nrOfConstraints+i] = c.deriv(i)(r);
					} else {
						cmat[cmatstride*nrOfConstraints+i] = 0.0;
					}
				}
			} else {
				for (i=0;i<nrofjoints;++i) {
					cmat[cmatstride*nrOfConstraints+i] = 0.0;
				}
			}
			nrOfConstraints++;
		}        
  	}
    /**
     * \todo  
	 *   ERROR HANDLING !!!
	 * \todo
	 *   conversion of std::vector<double> to double* in a safe and portable way.
     */
    void ConstraintMatrix::calculateOutput(std::vector<double>& output) {
        int i;
        if (nrOfConstraints==0) {
            for (i=0;i<nrofjoints;++i) output[i]=0.0;
            return;
        }
        /*
        int i,j;
        double sum;
        // temporary implementation..
        //MatrixOutput(std::cout,cmat,cmatstride,maxrows,maxcols);
        //std::cout << std::endl;
        pinvtmps.pinv(cmat,cmatstride,nrOfConstraints,maxcols,cmati,cmatistride);
        //MatrixOutput(std::cout,cmati,cmatistride,maxcols,maxrows);
        // std::cout << std::endl;
        for (i=0;i<maxcols;++i) {
            sum = 0.0;
            for (j=0;j<nrOfConstraints;++j) {
                sum+= cmati[ cmatistride* i + j]  * desval[j];
            }
            output[i] = sum;
        }*/
		/*
        if (lowerprior) {
            lowerprior->calculateOutput(output2);
            pinvtmps.inverseWithNullSpace(
                cmat,cmatstride,nrOfConstraints,maxcols,
                desval, output2,
                weight,jsweight,
                output);
        } else {
		*/
        /*pinvtmps.inverse(
            cmat,cmatstride,nrOfConstraints,nrofjoints,
            desval,
            weight,jsweight,
            output);*/
        pinvtmps.prepare(cmat,cmatstride,nrOfConstraints,nrofjoints,weight,jsweight,nrofits);
		// WARNING : this makes some assumptions on the implementation of vector<double> :
        pinvtmps.inverse(desval,&output[0],eps);
    }

    ConstraintMatrix::~ConstraintMatrix() {
        delete [] cmat;
        delete [] desval;
        delete [] weight;
		delete [] jsweight;
        delete [] cmati;
    }

	void ConstraintMatrix::setJointSpaceWeights(const std::vector<double>& jsw) {
		int i;
		for (i=0;i<nrofjoints;++i) {
            jsweight[i]=::sqrt(jsw[i]);
        }
	}
	/**
	 * \todo
 	 *   portable conversion of vector<> to double*
	 */
	void ConstraintMatrix::calculateOutput(std::vector<double>& output,const std::vector<double>& nullspace) {
        int i;
        if (nrOfConstraints==0) {
            for (i=0;i<nrofjoints;++i) output[i]=nullspace[i];
            return;
        }
        
        /*pinvtmps.inverseWithNullSpace(
            cmat,cmatstride,nrOfConstraints,nrofjoints,
            desval,nullspace,
            weight,jsweight,
            output);*/
        
        pinvtmps.prepare(cmat,cmatstride,nrOfConstraints,nrofjoints,weight,jsweight,nrofits);
        pinvtmps.inverseWithNullSpace(desval,&output[0],&nullspace[0],eps); 
        //dumpsvd(std::cout);
    }


    void ConstraintMatrix::reduce(const std::vector<bool>& list,const std::vector<double> value) {
        int newcol =0;   // index in the reduced vector (newcol <= col)
        for (int col=0;col<nrofjoints;++col) {
            // PRE COND : 0..col-1 is reduced
           int row;
           if (!list[col]) {
                // if not fixed
                // adapt col :
                for (row=0;row<nrOfConstraints;++row)
                    cmat[cmatstride*row+newcol] = cmat[cmatstride*row+col];
                // adapt joint space weights :
                jsweight[newcol]=jsweight[col];
                // adapt desired values and indices.
                newcol++;
           } else {
               for (row=0;row<nrOfConstraints;++row) {
                   desval[row] -= cmat[cmatstride*row+col]*value[row]; 
               }
           }
           // POST COND 0..col is reduced into a vector of 0..newcol-1
        }
        // reduce nrofjoints
        nrofjoints= newcol;
    }

    void ConstraintMatrix::reducejv(const std::vector<bool>& list,std::vector<double>& vec)
	{
        int newcol =0;
        for (int col=0;col<nrofjoints;++col) {
           if (!list[col]) {
                vec[newcol] = vec[col];
                newcol++;
           }
        }
    }

    void ConstraintMatrix::expandjv(int nrofalljoints,const std::vector<bool>& list,const std::vector<double>& values,std::vector<double>& vec)
    {
        int oldcol =nrofjoints-1;
        for (int col=nrofalljoints-1;col>=0;--col) {
           // PRE : vec is expanded for col+1<i<nrofalljoints
           if (!list[col]) {
                vec[col] = vec[oldcol];
                oldcol--;
           } else {
                vec[col] = values[col];
           }
           // POST : vec is expanded for col<i<nrofalljoints
        }
    }



    void ConstraintMatrix::calculateOutput(const std::vector<bool>& list, const std::vector<double>& value, std::vector<double>& output) {
        int nrofalljoints = nrofjoints;
        reduce(list,value);
        calculateOutput(output);  
        expandjv(nrofalljoints,list,value,output);
    }


    void ConstraintMatrix::calculateOutput(
		const std::vector<bool>& list, 
		const std::vector<double>& values, 
		std::vector<double>& output,
		std::vector<double>& nullspace) 
	{
        int nrofalljoints = nrofjoints;
        reduce(list,values);
        reducejv(list,nullspace);
        calculateOutput(output,nullspace);
        expandjv(nrofalljoints,list,values,output);
    }


