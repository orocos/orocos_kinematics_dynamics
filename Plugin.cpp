/* Generated from orogen/lib/orogen/templates/typekit/Plugin.cpp */

// First load all RTT interfaces so that we get all "extern template"
// declarations in the TypekitImpl files
#include "Plugin.hpp"

#include <iostream>
#include <boost/cstdint.hpp>
#include <boost/lexical_cast.hpp>

#include <rtt/types/TypeInfoRepository.hpp>
#include <rtt/types/VectorTemplateComposition.hpp>
#include "type_info/Registration.hpp"

using namespace RTT;
using namespace std;

orogen_typekits::kdlTypekitPlugin::kdlTypekitPlugin()
{}

orogen_typekits::kdlTypekitPlugin::~kdlTypekitPlugin()
{}


#define TYPEKIT_PACKAGE_NAME_aux0(target) #target
#define TYPEKIT_PACKAGE_NAME_aux(target) "kdl-typekit-" TYPEKIT_PACKAGE_NAME_aux0(target)
#define TYPEKIT_PACKAGE_NAME TYPEKIT_PACKAGE_NAME_aux(OROCOS_TARGET)
bool orogen_typekits::kdlTypekitPlugin::loadTypes()
{
    RTT::types::TypeInfoRepository::shared_ptr ti_repository = RTT::types::TypeInfoRepository::Instance();

    RTT::types::TypeInfo* ti = 0;
    
    ti = KDL_Frame_TypeInfo();
    ti_repository->addType( ti );
    
    ti = KDL_Frames_TypeInfo();
    ti_repository->addType( ti );

    ti = KDL_Rotation_TypeInfo();
    ti_repository->addType( ti );
    
    ti = KDL_Rotations_TypeInfo();
    ti_repository->addType( ti );
    
    ti = KDL_Twist_TypeInfo();
    ti_repository->addType( ti );
    
    ti = KDL_Twists_TypeInfo();
    ti_repository->addType( ti );
    
    ti = KDL_Vector_TypeInfo();
    ti_repository->addType( ti );
    
    ti = KDL_Vectors_TypeInfo();
    ti_repository->addType( ti );
    
    ti = KDL_Wrench_TypeInfo();
    ti_repository->addType( ti );
    
    ti = KDL_Wrenches_TypeInfo();
    ti_repository->addType( ti );
    
    ti = KDL_JntArray_TypeInfo();
    ti_repository->addType( ti );
    
    ti = double_ArrayTypeInfo();
    ti_repository->addType( ti );
    
    return true;
}
namespace{
      Frame framevr( const Vector& v, const Rotation& r )
        {
                return Frame( r, v );
        };
        Frame framerv( const Rotation& r, const Vector& v )
        {
                return Frame( r, v );
        };


        Wrench wrenchft( const Vector& force, const Vector& torque )
        {
                return Wrench( force, torque );
        };

        Twist twistvw( const Vector& trans, const Vector& rot )
        {
                return Twist( trans, rot );
        };

        Vector vectorxyz( double a, double b, double c )
        {
                return Vector( a, b, c );
        };


        // INDEXING
        template<class WT>
        struct wrenchtwist_index
            : public std::binary_function<WT,int,double>
        {
            double operator()( WT& w, int index) const
            {
                if (index > 5 || index <0)
                    return 0.0;
                else
                    return w[index];
            }
        };
        /*
          double twist_index( Twist& t, int index)
          {
          if (index > 5 || index <0)
          return 0.0;
          else
          return t[index];
          }
        */

//        double double6D_index( Double6D d6,  int index )
//        {
//            if ( index > 5 || index < 0 )
//                return 0.0;
//            return d6[index];
//        }
//

        struct vector_index
            : public std::binary_function<Vector, int, double>
        {
            double operator()( Vector& v, int index ) const
                {
                    if (index > 2 || index <0)
                        return 0.0;
                    else
                        return v[index];
                }
        };

        // DOTTING
        template< int I>
        struct vector_dot
            : public std::unary_function<Vector, double>
        {
            double operator()(const Vector& v ) const
            {
                return v[I];
            }
        };

        struct twist_rot
            : public std::unary_function<Twist, Vector>
        {
            Vector operator()(const Twist& t ) const
            {
                return t.rot;
            }
        };

        struct twist_vel
            : public std::unary_function<Twist, Vector>
        {
            Vector operator()(const Twist& t ) const
            {
                return t.vel;
            }
        };

        struct wrench_torque
            : public std::unary_function<Wrench, Vector>
        {
            Vector operator()(const Wrench& t ) const
            {
                return t.torque;
            }
        };

        struct wrench_force
            : public std::unary_function<Wrench, Vector>
        {
            Vector operator()(const Wrench& t ) const
            {
                return t.force;
            }
        };

        struct frame_pos
            : public std::unary_function<Frame, Vector>
        {
            Vector operator()(const Frame& f ) const
            {
                return f.p;
            }
        };

        struct frame_rot
            : public std::unary_function<Frame, Rotation>
        {
            Rotation operator()(const Frame& f ) const
            {
                return f.M;
            }
        };

        struct frame_inv
            : public std::unary_function<Frame, Frame>
        {
            Frame operator()(const Frame& f ) const
            {
                return f.Inverse();
            }
        };

        struct rotation_roll
            : public std::unary_function<Rotation, double>
        {
            double operator()(const Rotation& rot ) const
            {
                double r,p,y;
                rot.GetRPY(r,p,y);
                return r;
            }
        };

        struct rotation_pitch
            : public std::unary_function<Rotation, double>
        {
            double operator()(const Rotation& rot ) const
            {
                double r,p,y;
                rot.GetRPY(r,p,y);
                return p;
            }
        };

        struct rotation_yaw
            : public std::unary_function<Rotation, double>
        {
            double operator()(const Rotation& rot ) const
            {
                double r,p,y;
                rot.GetRPY(r,p,y);
                return y;
            }
        };

        struct rotation_inv
            : public std::unary_function<Rotation, Rotation>
        {
            Rotation operator()(const Rotation& rot ) const
            {
                return rot.Inverse();
            }
        };
}
bool orogen_typekits::kdlTypekitPlugin::loadOperators()
{
        RTT::types::OperatorRepository::shared_ptr oreg = RTT::types::OperatorRepository::Instance();
        oreg->add( RTT::types::newBinaryOperator( "==", std::equal_to<Frame>() ) );
        oreg->add( RTT::types::newBinaryOperator( "!=", std::not_equal_to<Frame>() ) );
        oreg->add( RTT::types::newBinaryOperator( "==", std::equal_to<Vector>() ) );
        oreg->add( RTT::types::newBinaryOperator( "!=", std::not_equal_to<Vector>() ) );
        oreg->add( RTT::types::newBinaryOperator( "==", std::equal_to<Rotation>() ) );
        oreg->add( RTT::types::newBinaryOperator( "!=", std::not_equal_to<Rotation>() ) );
        oreg->add( RTT::types::newBinaryOperator( "==", std::equal_to<Wrench>() ) );
        oreg->add( RTT::types::newBinaryOperator( "!=", std::not_equal_to<Wrench>() ) );
        oreg->add( RTT::types::newBinaryOperator( "==", std::equal_to<Twist>() ) );
        oreg->add( RTT::types::newBinaryOperator( "!=", std::not_equal_to<Twist>() ) );
        oreg->add( RTT::types::newUnaryOperator( "-", std::negate<Vector>() ) );
        oreg->add( RTT::types::newBinaryOperator( "*", std::multiplies<Vector>() ) );
        oreg->add( RTT::types::newBinaryOperator( "*", std::multiplies<Frame>() ) );
        oreg->add( RTT::types::newBinaryOperator( "*", std::multiplies<Rotation>() ) );
        oreg->add( RTT::types::newBinaryOperator( "+", std::plus<Vector>() ) );
        oreg->add( RTT::types::newBinaryOperator( "-", std::minus<Vector>() ) );
        oreg->add( RTT::types::newBinaryOperator( "+", std::plus<Wrench>() ) );
        oreg->add( RTT::types::newBinaryOperator( "-", std::minus<Wrench>() ) );
        oreg->add( RTT::types::newBinaryOperator( "+", std::plus<Twist>() ) );
        oreg->add( RTT::types::newBinaryOperator( "-", std::minus<Twist>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "*", multiplies3<Vector,int, Vector>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "*", multiplies3<Vector,Vector, int>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "*", multiplies3<Vector,double, Vector>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "*", multiplies3<Vector,Vector, double>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "*", multiplies3<Wrench, Frame, Wrench>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "*", multiplies3<Twist, Frame, Twist>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "*", multiplies3<Vector, Frame, Vector>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "*", multiplies3<Vector, Rotation, Vector>() ) );

        oreg->add( RTT::types::newBinaryOperator( "[]", vector_index() ) );
        oreg->add( RTT::types::newBinaryOperator( "[]", wrenchtwist_index<Wrench>() ) );
        oreg->add( RTT::types::newBinaryOperator( "[]", wrenchtwist_index<Twist>() ) );

        // access to members of composite types, use the 'dot' operator
        //oreg->add( RTT::types::newDotOperator( "x", vector_dot<0>() ) );
        //oreg->add( RTT::types::newDotOperator( "y", vector_dot<1>() ) );
        //oreg->add( RTT::types::newDotOperator( "z", vector_dot<2>() ) );
        //oreg->add( RTT::types::newDotOperator( "rot", twist_rot() ) );
        //oreg->add( RTT::types::newDotOperator( "vel", twist_vel() ) );
        //oreg->add( RTT::types::newDotOperator( "force", wrench_torque() ) );
        //oreg->add( RTT::types::newDotOperator( "torque", wrench_force() ) );
        //oreg->add( RTT::types::newDotOperator( "roll", rotation_roll() ) );
        //oreg->add( RTT::types::newDotOperator( "pitch", rotation_pitch() ) );
        //oreg->add( RTT::types::newDotOperator( "yaw", rotation_yaw() ) );
        //oreg->add( RTT::types::newDotOperator( "inv", rotation_inv() ) );
        //oreg->add( RTT::types::newDotOperator( "p", frame_pos() ) );
        //oreg->add( RTT::types::newDotOperator( "M", frame_rot() ) );
        //oreg->add( RTT::types::newDotOperator( "R", frame_rot() ) );
        //oreg->add( RTT::types::newDotOperator( "inv", frame_inv() ) );

        oreg->add( RTT::types::newBinaryOperator( "[]", wrenchtwist_index<Wrench>() ) );
        oreg->add( RTT::types::newBinaryOperator( "[]", wrenchtwist_index<Twist>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "[]", stdvector_index<Frame>() ) );
        //oreg->add( RTT::types::newDotOperator( "size", get_size<const std::vector<Frame>&>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "[]", stdvector_index<Vector>() ) );
        //oreg->add( RTT::types::newDotOperator( "size", get_size<const std::vector<Vector>&>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "[]", stdvector_index<Rotation>() ) );
        //oreg->add( RTT::types::newDotOperator( "size", get_size<const std::vector<Rotation>&>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "[]", stdvector_index<Twist>() ) );
        //oreg->add( RTT::types::newDotOperator( "size", get_size<const std::vector<Twist>&>() ) );
        //oreg->add( RTT::types::newBinaryOperator( "[]", stdvector_index<Wrench>() ) );
        //oreg->add( RTT::types::newDotOperator( "size", get_size<const std::vector<Wrench>&>() ) );

  return true; 
}
bool orogen_typekits::kdlTypekitPlugin::loadConstructors()
{ 
  
        RTT::types::TypeInfoRepository::shared_ptr ti = RTT::types::TypeInfoRepository::Instance();
        ti->type("Vector")->addConstructor( RTT::types::newConstructor(&vectorxyz) );
        ti->type("Rotation")->addConstructor( RTT::types::newConstructor( RTT::internal::ptr_fun( Rotation::RPY )) );
        ti->type("Frame")->addConstructor( RTT::types::newConstructor(&framerv) );
        ti->type("Frame")->addConstructor( RTT::types::newConstructor(&framevr) );
        ti->type("Wrench")->addConstructor( RTT::types::newConstructor(&wrenchft) );
        ti->type("Twist")->addConstructor( RTT::types::newConstructor(&twistvw) );

        ti->type("Vectors")->addConstructor(RTT::types::newConstructor( RTT::types::stdvector_ctor<KDL::Vector>()));
        ti->type("Rotations")->addConstructor(RTT::types::newConstructor( RTT::types::stdvector_ctor<KDL::Rotation>()));
        ti->type("Frames")->addConstructor(RTT::types::newConstructor( RTT::types::stdvector_ctor<KDL::Frame>()));
        ti->type("Wrenches")->addConstructor(RTT::types::newConstructor( RTT::types::stdvector_ctor<KDL::Wrench>()));
        ti->type("Twists")->addConstructor(RTT::types::newConstructor( RTT::types::stdvector_ctor<KDL::Twist>()));
  
  return true;

}
std::string orogen_typekits::kdlTypekitPlugin::getName()
{ return "/orogen/kdl"; }

ORO_TYPEKIT_PLUGIN(orogen_typekits::kdlTypekitPlugin);

