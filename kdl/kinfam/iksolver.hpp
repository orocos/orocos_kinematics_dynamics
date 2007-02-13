#ifndef KDL_IKSOLVER_HPP
#define KDL_IKSOLVER_HPP


namespace KDL {
    
    /**
     * \brief encapsulates a simple serial chain inverse position solver
     *
     * This is an <bold>abstract</bold> class.
     *      - eps
     *      - maximum iterations
     *
     * And supports the following functions:
     *      - cart2jnt
     * @ingroup KinematicFamily
     */
    class IkSolver {
    protected:
        double eps;
        int maxiter;
    public:
        IkSolver(Chain* chain);
                
        cart2jnt(JntVector q_in, FrameVector f_in, JntVector q_out);
                
        virtual ~IkSolver();
    };
    
    
}//end of namespace KDL

#endif
