#ifndef KDL_FKSOLVER_HPP
#define KDL_FKSOLVER_HPP


namespace KDL {
    
    /**
     * \brief encapsulates a simple serial chain forward position solver
     *
     * This is an <bold>abstract</bold> class.
     *
     * And supports the following functions:
     *      - jnt2cart
     * @ingroup KinematicFamily
     */
    class FkSolver {
    protected:
    public:
        FkSolver(Chain* chain);
                
        cart2jnt(JntVector q_in, FrameVector f_out);
                
        virtual ~FkSolver();
    };
    
    
}//end of namespace KDL

#endif
