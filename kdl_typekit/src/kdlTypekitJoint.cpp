#include "kdlTypekit.hpp"

namespace KDL{
  using namespace std;
  using namespace RTT;

  void loadJointTypes(){
    RTT::types::Types()->addType( new KDLTypeInfo<Joint>("KDL.Joint") );
    RTT::types::Types()->addType( new SequenceTypeInfo<std::vector< Joint > >("KDL.Joint[]") );
  };
}  
