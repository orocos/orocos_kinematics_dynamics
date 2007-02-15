#ifndef KDL_CHAIN_HPP
#define KDL_CHAIN_HPP

#include "segment.hpp"

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
    private:
        std::vector<Segment*> segments;
        int nrOfJoints;
        string name;
    public:
        Chain(const string& name);
        Chain(const Chain& in);
        Chain& operator = ( const Chain& arg);
        
        void addSegment(Segment* segment);
    
        ChainJntPosArray* newJntPosArray(){return new ChainJntPosArray(nrOfJoints)};
        ChainJntVelArray* newJntVelArray(){return new ChainJntVelArray(nrOfJoints)};
        ChainJntAccArray* newJntAccArray(){return new ChainJntAccArray(nrOfJoints)};

        ChainCartPos* newCartPos(){return new ChainCartPos()};
        ChainCartVel* newCartVel(){return new ChainCartVel()};
        ChainCartAcc* newCartAcc(){return new ChainCartAcc()};
        
        virtual ~Chain();
    };
    
    
    /** 
     * \brief a jointvector for the position to be used with a chain object. 
     * @ingroup KinematicFamily
     */
    class ChainJntPosArray: public std::vector<double>{
    public:
        ChainJntPosArray(int size) : std::vector<double>(size){};
        ChainJntPosArray(int size,double init) : std::vector<double>(size,init){};
    };
    
    /** 
     * \brief a jointvector for the velocity to be used with a chain object. 
     * @ingroup KinematicFamily
     */
    class ChainJntVelArray: public std::vector<double>{
    public:
        ChainJntVelArray(int size) : std::vector<double>(size){};
        ChainJntVelArray(int size,double init) : std::vector<double>(size,init){};
    };
        
    /** 
     * \brief a jointvector for the acceleration to be used with a chain object. 
     * @ingroup KinematicFamily
     */
    class ChainJntAccArray: public std::vector<double>{
    public:
        ChainJntAccArray(int size) : std::vector<double>(size){};
        ChainJntAccArray(int size,double init) : std::vector<double>(size,init){};
    };
    
    /** 
     * \brief a framevector for the positions to be used with a chain
     * object.  
     * @ingroup KinematicFamily
     */
    class ChainCartPos: public Frame{
    public:
        ChainCartPos() : Frame(){};
    };

    /** e
     * \brief a framevector for the velocities to be used with a chain object. 
     * @ingroup KinematicFamily
     */
    class ChainCartVel: public Twist{
    public:
        ChainCartVel() : Twist(){};
    };
    
    
    /** 
     * \brief a framevector for the accelerations to be used with a chain object. 
     * @ingroup KinematicFamily
     */
    class ChainCartAcc: public Twist{
    public:
        ChainCartAcc() : Twist(){};
    };
        
}//end of namespace KDL

#endif
