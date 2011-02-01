#include "kdlTypekit.hpp"

namespace KDL{
  using namespace std;
  using namespace RTT;

  void loadVectorTypes(){
    RTT::types::Types()->addType( new KDLTypeInfo<Vector>("KDL.Vector") );
    RTT::types::Types()->addType( new SequenceTypeInfo<std::vector< Vector > >("KDL.Vector[]") );
  };
}  
