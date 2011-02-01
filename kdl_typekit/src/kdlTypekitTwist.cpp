#include "kdlTypekit.hpp"

namespace KDL{
  using namespace std;
  using namespace RTT;

  void loadTwistTypes(){
    RTT::types::Types()->addType( new KDLTypeInfo<Twist>("KDL.Twist") );
    RTT::types::Types()->addType( new SequenceTypeInfo<std::vector< Twist > >("KDL.Twist[]") );
  };
}  
