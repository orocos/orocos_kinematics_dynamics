#ifndef KDL_CHAIN_FKSOLVER_HPP
#define KDL_CHAIN_FKSOLVER_HPP


namespace KDL {
    
    /**
     * \brief encapsulates a simple serial chain forward position kinematics solver
     *
     * This is an <bold>abstract</bold> class.
     *
     * And supports the following functions:
     *      - jnt2cart
     * @ingroup KinematicFamily
     */
    class ChainFkSolverPos {
    protected:
    public:
        virtual jnt2cart(const ChainJntPosArray& q_in, ChainCartPos& p_out)=0;
                
        virtual ~ChainFkSolverPos(){};
    };

    /**
     * \brief encapsulates a simple serial chain forward velocity kinematics solver
     *
     * This is an <bold>abstract</bold> class.
     *
     * And supports the following functions:
     *      - jnt2cart
     * @ingroup KinematicFamily
     */
    class ChainFkSolverVel {
    protected:
    public:
        virtual jnt2cart(const ChainJntPosArray& q_in, const ChainJntVelArray& qdot_in, ChainCartPos& p_out, ChainCartVel& v_out)=0;
                
        virtual ~ChainFkSolverVel(){};
    };

    /**
     * \brief encapsulates a simple serial chain forward acceleration kinematics solver
     *
     * This is an <bold>abstract</bold> class.
     *
     * And supports the following functions:
     *      - jnt2cart
     * @ingroup KinematicFamily
     */
    class ChainFkSolverAcc {
    public:
        virtual jnt2cart(const ChainJntPosArray& q_in, const ChainJntVelArray& qdot_in, const ChainJntAccArray& q_in, 
                         ChainCartPos& p_out, ChainCartVel& v_out, ChainCartAcc& a_out)=0;
                
        virtual ~ChainFkSolverAcc(){};
    };
    
    
}//end of namespace KDL

#endif
