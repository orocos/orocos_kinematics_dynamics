#include "kdlTypekit.hpp"

namespace KDL{
  using namespace std;
  using namespace RTT;

  void loadSegmentTypes(){
    RTT::types::Types()->addType( new KDLTypeInfo<Segment>("KDL.Segment") );
    RTT::types::Types()->addType( new SequenceTypeInfo<std::vector< Segment > >("KDL.Segment[]") );
  };
}  
