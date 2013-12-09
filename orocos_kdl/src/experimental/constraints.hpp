#ifndef KDL_CONSTRAINTS_HPP
#define KDL_CONSTRAINTS_HPP

#include <vector>
#include <kdl/jacobianframe.hpp>
#include <kdl/pinv.hpp>
#include <kdl/frames.hpp>
#include <fstream>


namespace KDL {

/**
 * \brief stores constraints and solves them.
 */
class ConstraintMatrix {
	  int maxrows,maxcols;
    double* cmat;    
    int cmatstride;
    double* desval;   
    double* weight;   // square root of the constraint space weights ...
    double* jsweight; // square root of the joint space weights ...
    PseudoInverse pinvtmps;
    //PseudoInverse pinvtmps;
    double* cmati;
    int cmatistride;

    int nrOfConstraints;    
    double* output2;
    int nrofjoints;
public:
    double eps;
    int    nrofits;
protected:

    /**
     * \brief reduces the matrix when a number of joints have a fixed value.
     *
     * reduce the problem by filling in the predefined value for some joints
     * \param [in] fixed : a bool vector indicating which joints are fixed. 
     *                      true means the joint is fixed.
     * \param [in] values : a double vector, for the indices where fixed[] is true
     *                     it indicates the value.  
     */
    void reduce(const std::vector<bool>& list,const std::vector<double> value);

    /**
	 * \brief reduces a joint vector when a number of joints have a fixed value.
     *
     * adapt a joint vector to a reduced vector
     * \param [in] list indicates which joints are fixed
     * \param [in/out] vec : original joint vector
     */
    void reducejv(const std::vector<bool>& list, std::vector<double>& vec);

    
    /**
     * \brief expands a reduced joint vector.
     *
     * expand a reduced joint vector 
     * \param [in] nrofalljoints the size of the output vector.
     * \param [in] list indicates which joints are fixed
     * \param [in] values  : values of the fixed joints.
     * \param [in/out] vec : input vector
     */
    void expandjv(int nrofalljoints,const std::vector<bool>& list,const std::vector<double>& values,std::vector<double>& vec);


public:
    /**
	 * \brief constructs a Constraint Matrix.
	 *
     * Initializes all data-structures
     * maxrows = the number of d.o.f. that the constraints impose.
     * maxcols = the number of d.o.f. of the joint variables.
     */
    ConstraintMatrix(int _maxrows,int _maxcols);

    /**
	 * \brief resets to zero constraints.
	 *
     * should be called before you call addConstraints.
     * Also resets the joint space weights.
     * \param [in] nrofjoints give the number of joints.  subsequent calls to addConstraint
     *             should have PV<..> variables with the same number of derivatives.
     */
    void resetConstraints(int nrofjoints);

	/**
	 * \brief adds a constraint to one joint. 
	 *
	 * \param jointnr : the joint whos value you want to apply a constraint to.
	 * \param value   : actual value of the joint.
	 * \param K       : control constant for this constraint.
	 * \param _desval : desired value of the joint. 
	 * \param _desvald: desired velocity of the joint (feedforward).
	 * \param _weight : weight of this constraint.
	 */
    void addConstraintJoint(int jointnr,double value,double K,double _desval,double _desvald,double _weight);

    /**
	 * \brief adds a 1 d.o.f. constraint on a double value.
	 *
     * Adds a constraint that imposes c to be equal to desval with a given weight.
     * adds the line :
     *    Jc q = K ( c-desval) + desvald     
     *    and  changes the diagonal element of the weight to the given variable
     *    (note : this variable is a square, it is always > 0)
     *
     */
    void addConstraint(const Jacobian<double>& c,double K,double _desval,double _desvald,double _weight);

	/**
	 * \brief adds a 3 d.o.f. constraint on a Vector value.
	 */
	void addConstraint(const Jacobian<Vector>& c,double K,const Vector& _desval,const Vector& _desvald,double _weight);

	/**
	 * \brief adds a 6 d.o.f. constraint on a Frame value.
	 */
	void addConstraint(
		const Jacobian<Frame>& c,
		double Kpos,
		double Krot,
		const Frame& _desval,
		const Twist& _desvald,
		double _weightpos,
		double _weightrot
	);

	/**
	 * \brief adds a 6 d.o.f. constraint on a Frame value and allows for 
     * control constant and weight for each component.
	 */
	void addConstraint(
		const Jacobian<Frame>& c,
		const std::vector<double>& K,
		const Frame& _desval,
		const Twist& _desvald,
		const std::vector<double>& _weight
	);

	/**
	 * \brief adds a 6 d.o.f. constraint specifying the derivative of a Frame.
     * If there should be a control loop, the user should implement it externally
     * to this method.
	 */
	void addConstraintWithoutControl(
		const Jacobian<Frame>& c,
		const Twist& desired,
		const std::vector<double>& _weight
	);

	/**
	 * \brief adds a 6 d.o.f. constraint on a displacement twist value. 
	 */
	void addConstraint(
		const Jacobian<Twist>& c,
		double Kpos,
		double Krot,
		const Twist& _desval,
		const Twist& _desvald,
		double _weightpos,
		double _weightrot
	);


	/**
	 * \brief adds a 6 d.o.f. constraint on a Wrench.
	 */
	void addConstraint(
		const Jacobian<Wrench>& c,
		double Kpos,
		double Krot,
		const Wrench& _desval,
		const Wrench& _desvald,
		double _weightpos,
		double _weightrot
	);

	/**
	 * \brief set the joint space weights for each of the joints.
	 */
	void setJointSpaceWeights(const std::vector<double>& jsw);



    /**
	 * \brief solves the constraints.
	 *
     * \param [out] output : the calculated joint values.
     * \todo : ERROR HANDLING !!!
     */
    void calculateOutput(std::vector<double>& output);

    /**
	 * \brief solves the constraints while trying to be as close as possible to a given vector.
	 *
     * \param [in]  nullspace : desired joint values for motion in nullspace
     * \param [out] output : the calculated joint values.
     */
	void calculateOutput(std::vector<double>& output,const std::vector<double>& nullspace);


    /**
	 * \brief solves the constraints if a certain number of joints have a fixed value. 
	 *
     * \param[in]   list  : list[i] is true if joint i is fixed
     * \param[in]   values : if joint i is fixed, then its value is value[i]
     * \param [out] output : the calculated joint values.
     * \todo : ERROR HANDLING !!!
     */
    void calculateOutput(const std::vector<bool>& list, const std::vector<double>& values, std::vector<double>& output);

    /**
	 * \brief solves the constraints while trying to be as close as possible to a given vector
	 *        if a certain number of joints have a fixed value. 
	 *
     * \param[in]   list  : list[i] is true if joint i is fixed
     * \param[in]   values : if joint i is fixed, then its value is value[i]
     * \param [out] output : the calculated joint values.
     * \param [in/out]  nullspace : the desired nullspace motion.  This vector will be changed by this routine
	 *                  with temporary values.
     * \todo : ERROR HANDLING !!!
     */
    void calculateOutput(const std::vector<bool>& list, 
						const std::vector<double>& values, 
						std::vector<double>& output,
						std::vector<double>& nullspace);

	/**
	 * \brief dump internal structures to a stream for debugging.
	 */
    void dump(std::ostream& os);
	
	/**
	 * \brief dump statistics about the svd to a stream.
	 */
    void dumpsvd(std::ostream& os);

    ~ConstraintMatrix();
};

}

#endif

