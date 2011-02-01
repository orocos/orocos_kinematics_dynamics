#include "kdlTypekit.hpp"
namespace KDL{
  // CONSTRUCTORS
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
    bool KDLTypekitPlugin::loadConstructors()
    {
        TypeInfoRepository::shared_ptr ti = TypeInfoRepository::Instance();

        ti->type("KDL.Vector")->addConstructor( newConstructor(&vectorxyz) );
        ti->type("KDL.Rotation")->addConstructor( newConstructor( ptr_fun( Rotation::RPY )) );
        ti->type("KDL.Frame")->addConstructor( newConstructor(&framerv) );
        ti->type("KDL.Frame")->addConstructor( newConstructor(&framevr) );
        ti->type("KDL.Wrench")->addConstructor( newConstructor(&wrenchft) );
        ti->type("KDL.Twist")->addConstructor( newConstructor(&twistvw) );

        
        //ti->type("Frame[]")->addConstructor(newConstructor(stdvector_ctor<Frame>() ) );
        //ti->type("Frame[]")->addConstructor(newConstructor(stdvector_ctor2<Frame>() ) );
        //ti->type("Frame[]")->addConstructor(new StdVectorBuilder<Frame>() );

        //ti->type("Vector[]")->addConstructor(newConstructor(stdvector_ctor<Vector>() ) );
        //ti->type("Vector[]")->addConstructor(newConstructor(stdvector_ctor2<Vector>() ) );
        //ti->type("Vector[]")->addConstructor(new StdVectorBuilder<Vector>() );

        //ti->type("Rotation[]")->addConstructor(newConstructor(stdvector_ctor<Rotation>() ) );
        //ti->type("Rotation[]")->addConstructor(newConstructor(stdvector_ctor2<Rotation>() ) );
        //ti->type("Rotation[]")->addConstructor(new StdVectorBuilder<Rotation>() );

        //ti->type("Wrench[]")->addConstructor(newConstructor(stdvector_ctor<Wrench>() ) );
        //ti->type("Wrench[]")->addConstructor(newConstructor(stdvector_ctor2<Wrench>() ) );
        //ti->type("Wrench[]")->addConstructor(new StdVectorBuilder<Wrench>() );

        //ti->type("Twist[]")->addConstructor(newConstructor(stdvector_ctor<Twist>() ) );
        //ti->type("Twist[]")->addConstructor(newConstructor(stdvector_ctor2<Twist>() ) );
        //ti->type("Twist[]")->addConstructor(new StdVectorBuilder<Twist>() );

        return true;
    }

}
