#include "kdlTypekit.hpp"

namespace KDL{
  using namespace std;
  using namespace RTT;

  void loadRotationTypes(){
    RTT::types::Types()->addType( new KDLTypeInfo<Rotation>("KDL.Rotation") );
    RTT::types::Types()->addType( new SequenceTypeInfo<std::vector< Rotation > >("KDL.Rotation[]") );
  };
}  
