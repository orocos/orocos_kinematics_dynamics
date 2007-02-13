#ifndef KDL_CHAIN_HPP
#define KDL_CHAIN_HPP


namespace KDL {
    
    /**
     * \brief encapsulates a simple serial chain
     *
     * This is an <bold>abstract</bold> class.
     * A simple chain is described by the following properties : 
     *      - nr of joints
     *      - all the segments
     *
     * And supports the following functions:
     *      - addSegment()
     * @ingroup KinematicFamily
     */
    class Chain {
    protected:
        std::vector<Segment*> segments;
    public:
        Chain(Segment* root);
        Chain(const Chain& in);
        Chain& operator = ( const Chain& arg);
        
        virtual void addSegment(Segment* segment);
        
        virtual Chain* clone() const = 0;
        
        virtual ~Chain();
    };
    
    
    /** 
     * \brief a jointvector to be used with a chain object. 
     * @ingroup KinematicFamily
     */
    class JntVector
    {
    protected:
        std::vector<double> q;
    public:
        JntVector(Chain* chain);
        virtual ~JntVector();
    };

    /** 
     * \brief a framevector to be used with a chain object. 
     * @ingroup KinematicFamily
     */
    class FrameVector
    {
    protected:
        std::vector<Frame> frames;
    public:
        FrameVector(Chain* chain);
        virtual ~FrameVector();
    };
    
}//end of namespace KDL

#endif
