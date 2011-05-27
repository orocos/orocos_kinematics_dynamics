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
    oreg->add( newBinaryOperator( "/", divides3<Vector, Vector, double>() ) );
    oreg->add( newBinaryOperator( "/", divides3<Wrench, Wrench, double>() ) );
    oreg->add( newBinaryOperator( "/", divides3<Twist, Twist, double>() ) );

    RTT::Service::shared_ptr gs = RTT::internal::GlobalService::Instance();

    gs->provides("KDL")->addOperation("Vector_diff",(Vector (*) (const Vector&, const Vector&, double)) &diff).doc("");
    gs->provides("KDL")->addOperation("Rotation_diff",(Vector (*) (const Rotation&, const Rotation&, double)) &diff).doc("");
    gs->provides("KDL")->addOperation("Twist_diff",(Twist (*) (const Twist&, const Twist&, double)) &diff).doc("");
    gs->provides("KDL")->addOperation("Wrench_diff",(Wrench (*) (const Wrench&, const Wrench&, double)) &diff).doc("");
    gs->provides("KDL")->addOperation("Frame_diff",(Twist (*) (const Frame&, const Frame&, double)) &diff)
	    .doc("Returns the twist that is needed to move from frame f1 to frame f2 in a time d. The resulting twist is represented in the same reference frame as f1 and f2, and has reference point at the origin of f1");

    gs->provides("KDL")->addOperation("Vector_addDelta",(Vector (*) (const Vector&, const Vector&, double)) &addDelta).doc("");
    gs->provides("KDL")->addOperation("Rotation_addDelta",(Rotation (*) (const Rotation&, const Vector&, double)) &addDelta).doc("");
    gs->provides("KDL")->addOperation("Frame_addDelta", (Frame (*) (const Frame&, const Twist&, double)) &addDelta)
	    .doc("Constructs a frame that is obtained by: starting from frame f, apply twist t, during time d");

    return true;
  }
}
