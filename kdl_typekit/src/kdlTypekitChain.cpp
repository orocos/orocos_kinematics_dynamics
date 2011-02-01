#include "kdlTypekit.hpp"

namespace KDL{
  using namespace std;
  using namespace RTT;

  void loadChainTypes(){
    RTT::types::Types()->addType( new KDLTypeInfo<Chain>("KDL.Chain") );
    RTT::types::Types()->addType( new SequenceTypeInfo<std::vector< Chain > >("KDL.Chain[]") );
  };
}  
