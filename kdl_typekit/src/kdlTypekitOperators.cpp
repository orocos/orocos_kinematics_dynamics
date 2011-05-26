#include "kdlTypekit.hpp"

namespace KDL{
  bool KDLTypekitPlugin::loadOperators()
  {
    OperatorRepository::shared_ptr oreg = OperatorRepository::Instance();

    oreg->add( newBinaryOperator( "==", std::equal_to<Frame>() ) );
    oreg->add( newBinaryOperator( "!=", std::not_equal_to<Frame>() ) );
    oreg->add( newBinaryOperator( "==", std::equal_to<Vector>() ) );
    oreg->add( newBinaryOperator( "!=", std::not_equal_to<Vector>() ) );
    oreg->add( newBinaryOperator( "==", std::equal_to<Rotation>() ) );
    oreg->add( newBinaryOperator( "!=", std::not_equal_to<Rotation>() ) );
    oreg->add( newBinaryOperator( "==", std::equal_to<Wrench>() ) );
    oreg->add( newBinaryOperator( "!=", std::not_equal_to<Wrench>() ) );
    oreg->add( newBinaryOperator( "==", std::equal_to<Twist>() ) );
    oreg->add( newBinaryOperator( "!=", std::not_equal_to<Twist>() ) );
    oreg->add( newUnaryOperator( "-", std::negate<Vector>() ) );
    oreg->add( newBinaryOperator( "*", std::multiplies<Vector>() ) );
    oreg->add( newBinaryOperator( "*", std::multiplies<Frame>() ) );
    oreg->add( newBinaryOperator( "*", std::multiplies<Rotation>() ) );
    oreg->add( newBinaryOperator( "+", std::plus<Vector>() ) );
    oreg->add( newBinaryOperator( "-", std::minus<Vector>() ) );
    oreg->add( newBinaryOperator( "+", std::plus<Wrench>() ) );
    oreg->add( newBinaryOperator( "-", std::minus<Wrench>() ) );
    oreg->add( newBinaryOperator( "+", std::plus<Twist>() ) );
    oreg->add( newBinaryOperator( "-", std::minus<Twist>() ) );
    oreg->add( newBinaryOperator( "*", multiplies3<Vector,int, Vector>() ) );
    oreg->add( newBinaryOperator( "*", multiplies3<Vector,Vector, int>() ) );
    oreg->add( newBinaryOperator( "*", multiplies3<Vector,double, Vector>() ) );
    oreg->add( newBinaryOperator( "*", multiplies3<Vector,Vector, double>() ) );
    oreg->add( newBinaryOperator( "*", multiplies3<Wrench, Frame, Wrench>() ) );
    oreg->add( newBinaryOperator( "*", multiplies3<Twist, Frame, Twist>() ) );
    oreg->add( newBinaryOperator( "*", multiplies3<Vector, Frame, Vector>() ) );
    oreg->add( newBinaryOperator( "*", multiplies3<Vector, Rotation, Vector>() ) );

    return true;
  }
}
