#include "kdlTypekit.hpp"

namespace KDL{
  using namespace std;
  using namespace RTT;

  void loadFrameTypes(){
    RTT::types::Types()->addType( new KDLTypeInfo<Frame>("KDL.Frame") );
    RTT::types::Types()->addType( new SequenceTypeInfo<std::vector< Frame > >("KDL.Frame[]") );
  };

}  
