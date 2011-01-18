#include "kdlTypekit.hpp"

namespace KDL{
  using namespace std;
  using namespace RTT;

  void loadJacobianTypes(){
    RTT::types::Types()->addType( new KDLTypeInfo<Jacobian>("KDL.Jacobian") );
    RTT::types::Types()->addType( new SequenceTypeInfo<std::vector< Jacobian > >("KDL.Jacobian[]") );
  };

}  
