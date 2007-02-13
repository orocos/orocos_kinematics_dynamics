#ifndef KDL_CRS450_HPP
#define KDL_CRS450_HPP

#include <kdl/kinfam/serialchain.hpp>
#include <kdl/kinfam/zxxzxz.hpp>
#include <kdl/kinfam/unittransmission.hpp>

namespace KDL {
  
  /**
   * \brief constructs a ZXXZXZ object with the parameters of a CRS 450 robot.
   * \todo
   *    should we use ZXXZXZ or ZYYZYZ ? (in comrade we used ZYYZYZ..).
   */
  class CRS450 : public SerialChain {
  public:
    explicit CRS450(int jointoffset=0) :	
      SerialChain("CRS450", 6, jointoffset,new UnitTransmission(6))
    {
      double L1 = 0.33;
      double L2 = 0.305;
      double L3 = 0.33;
      double L4 = 0.176; 
      addJoint(new JointRotZ(Frame::Identity())); // j1
      addJoint(new JointRotX(Frame(Rotation::Identity(),Vector(0,0,L1))));// j2
      addJoint(new JointRotX(Frame(Rotation::Identity(),Vector(0,0,L2))));// j3
      addJoint(new JointRotZ(Frame(Rotation::Identity(),Vector(0,0,0)))); // j4
      addJoint(new JointRotX(Frame(Rotation::Identity(),Vector(0,0,L3))));// j5
      addJoint(new JointRotZ(Frame(Rotation::Identity(),Vector(0,0,0)))); // j6
      setLastJointToEE(Frame(Rotation::Identity(),Vector(0,0,L4)));
    };
  };
  
  class CRS450Feath : public ZXXZXZ
  {
  public:
    explicit CRS450Feath(int jointoffset=0) :
      ZXXZXZ("CRS450",jointoffset,new UnitTransmission(6))
    {
      setLinkLengths(0.33,0.305,0.33,0.176);
    };
  };
  
}; // end of namespace KDL

#endif
