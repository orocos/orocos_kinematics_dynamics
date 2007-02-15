#ifndef KDL_CHAIN_IKSOLVER_HPP
#define KDL_CHAIN_IKSOLVER_HPP

#include "chain.hpp"

namespace KDL {
    
    /**
     * \brief encapsulates a simple serial chain inverse position solver
     *
     * This is an <bold>abstract</bold> class.
     *
     * And supports the following functions:
     *      - cart2jnt
     * @ingroup KinematicFamily
     */
    class ChainSolverPos {
    public:
        virtual cart2jnt(const ChainJntPosArray& q_init, const ChainCartPos& p_in, ChainJntPosArray& q_out)=0;
                
        virtual ~ChainSolverPos(){};
    };

    /**
     * \brief encapsulates a simple serial chain inverse velocity solver
     *
     * This is an <bold>abstract</bold> class.
     *
     * And supports the following functions:
     *      - cart2jnt
     * @ingroup KinematicFamily
     */
    class ChainSolverVel {
    public:
        virtual cart2jnt(const ChainJntPosArray& q_in, const ChainCartVel& v_in, ChainJntVelArray& qdot_out)=0;
        virtual cart2jnt(const ChainJntPosArray& q_init, const ChainCartPos& p_in, const ChainCartVel& v_in, 
                         ChainJntPosArray& q_out, ChainJntVelArray& qdot_out)=0;
                
        virtual ~ChainSolverVel(){};
        
    };

    /**
     * \brief encapsulates a simple serial chain inverse acceleration solver
     *
     * This is an <bold>abstract</bold> class.
     *      - eps
     *      - maximum iterations
     *
     * And supports the following functions:
     *      - cart2jnt
     * @ingroup KinematicFamily
     */
    class ChainSolverAcc {
    public:
                
        virtual cart2jnt(const ChainJntPosArray& q_in, const ChainJntVelArray& qdot_in, const ChainCartAcc& a_in,
                         ChainJntAccArray& qdotdot_out)=0;
        virtual cart2jnt(const ChainJntPosArray& q_in, const ChainCartVel& v_in, const ChainCartAcc& a_in,
                         ChainJntArrayVel& qdot_out, ChainJntArrayAcc& qdotdot_out)=0;
        virtual cart2jnt(const ChainJntPosArray& q_init, const ChainCartPos& p_in, const ChainJntVelArray& qdot_in, const ChainCartAcc& a_in,
                         ChainJntVelArray& qdot_out, ChainJntAccArray& qdotdot_out)=0; 
        virtual cart2jnt(const ChainJntPosArray& q_init, const ChainCartPos& p_in, const ChainCartVel& v_in, const ChainCartAcc& a_in,
                         ChainJntPosArray& q_out, ChainJntVelArray& qdot_out, ChainJntAccArray& qdotdot_out)=0; 
                
        virtual ~ChainSolverAcc(){};
    };
    
    
}//end of namespace KDL

#endif
