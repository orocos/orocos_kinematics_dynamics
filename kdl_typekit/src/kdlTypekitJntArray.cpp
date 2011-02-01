#include "kdlTypekit.hpp"

namespace KDL{
  using namespace std;
  using namespace RTT;

  void loadJntArrayTypes(){
    RTT::types::Types()->addType( new KDLTypeInfo<JntArray>("KDL.JntArray") );
    RTT::types::Types()->addType( new SequenceTypeInfo<std::vector< JntArray > >("KDL.JntArray[]") );
  };
}  
