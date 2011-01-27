/******************************************************************************
*                   This file is part of the KDL project                      *
*                                                                             *
*                     (C) 2004 Peter Soetens                                  *
*                         2010 Ruben Smits                                    *
*                         2010 Steven Bellens                                 *
*                       peter.soetens@mech.kuleuven.be                        *
*                       ruben.smits@mech.kuleuven.be                          *
*                       steven.bellens@mech.kuleuven.be                       *
*                    Department of Mechanical Engineering,                    *
*                   Katholieke Universiteit Leuven, Belgium.                  *
*                                                                             *
*       You may redistribute this software and/or modify it under either the  *
*       terms of the GNU Lesser General Public License version 2.1 (LGPLv2.1  *
*       <http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>) or (at your *
*       discretion) of the Modified BSD License:                              *
*       Redistribution and use in source and binary forms, with or without    *
*       modification, are permitted provided that the following conditions    *
*       are met:                                                              *
*       1. Redistributions of source code must retain the above copyright     *
*       notice, this list of conditions and the following disclaimer.         *
*       2. Redistributions in binary form must reproduce the above copyright  *
*       notice, this list of conditions and the following disclaimer in the   *
*       documentation and/or other materials provided with the distribution.  *
*       3. The name of the author may not be used to endorse or promote       *
*       products derived from this software without specific prior written    *
*       permission.                                                           *
*       THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  *
*       IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED        *
*       WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    *
*       ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,*
*       INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    *
*       (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS       *
*       OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) *
*       HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,   *
*       STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING *
*       IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE    *
*       POSSIBILITY OF SUCH DAMAGE.                                           *
*                                                                             *
*******************************************************************************/

#include <rtt/Property.hpp>
#include <rtt/PropertyBag.hpp>
#include <rtt/base/PropertyIntrospection.hpp>
#include <rtt/Logger.hpp>
#include <sstream>

#include "motionproperties.hpp"
//#include "kdltk.hpp"

namespace RTT
{
    using namespace std;


    template class Property<KDL::Frame>;
    template class Property<KDL::Wrench>;
    template class Property<KDL::Twist>;
    template class Property<KDL::Rotation>;
    template class Property<KDL::Vector>;

    /**
     *
     *    Vector
     *
     */

    /**
     * A Decomposer for Decomposing a Vector or Property<Vector>
     * into a typed Property<PropertyBag>.
     */
    class VectorDecomposer
    {
        PropertyBag resultBag;
        Property<double> X;
        Property<double> Y;
        Property<double> Z;

    public:

        VectorDecomposer( const Vector& v);

        PropertyBag& result() { return resultBag; }
    };

    /**
     * An Composer for constructing a Vector or Property<Vector>
     * from a typed PropertyBag.
     */
    class VectorComposer
    {
        const PropertyBag& bag;
    public:
        VectorComposer(const PropertyBag& _bag )
            : bag(_bag)
        {}

        bool getResult( Vector& res);
    };

    VectorDecomposer::VectorDecomposer( const Vector& v )
        : resultBag("KDL.Vector"), // bag_type
          X("X","X Value", v[0]),
          Y("Y","Y Value", v[1]),
          Z("Z","Z Value", v[2])
    {
        resultBag.add(X.clone());
        resultBag.add(Y.clone());
        resultBag.add(Z.clone());
    }

    bool VectorComposer::getResult(Vector& res)
    {
        if ( bag.getType() == "MotCon::Vector" || bag.getType() == "KDL.Vector" )
            {
                Property<double>* px = dynamic_cast<Property<double>*>( bag.find("X") );
                Property<double>* py = dynamic_cast<Property<double>*>( bag.find("Y") );
                Property<double>* pz = dynamic_cast<Property<double>*>( bag.find("Z") );
                // found it.
                if ( px != 0 && py != 0  && pz != 0)
                    {
                        res = Vector( px->get(),py->get(),pz->get() );
                        return true;
                    } else {
                        std::string element = !px ? "X" : !py ? "Y" : "Z";
                        Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Vector > "
                                      << ": Missing element '" <<element<<"'." <<Logger::endl;
                        return false;
                    }
            } else {
                Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Vector > "
                              << ": Expected type 'KDL.Vector', got type '"<< bag.getType() <<"'."
                              <<Logger::endl;
            }
        return false;
    }


    /**
     *
     *    Rotation
     *
     */

    /**
     * A Decomposer for Converting a Rotation or Property<Rotation>
     * into a typed Property<PropertyBag>.
     */
    class RotationDecomposer
    {
        PropertyBag resultBag;
        Property<double> X_x;
        Property<double> X_y;
        Property<double> X_z;
        Property<double> Y_x;
        Property<double> Y_y;
        Property<double> Y_z;
        Property<double> Z_x;
        Property<double> Z_y;
        Property<double> Z_z;
    public:

        RotationDecomposer( const Rotation& r );

        PropertyBag& result() { return resultBag; }
    };

    /**
     * An Composer for constructing a Rotation or Property<Rotation>
     * from a typed PropertyBag.
     */
    class RotationComposer
    {
        const PropertyBag& bag;
    public:
        RotationComposer(const PropertyBag& _bag )
            :  bag(_bag)
        {}

        bool getResult( Rotation& res );
    };

    RotationDecomposer::RotationDecomposer( const Rotation& r)
        : resultBag("KDL.Rotation"),
          X_x("X_x","", r(0,0) ),
          X_y("X_y","", r(1,0) ),
          X_z("X_z","", r(2,0) ),
          Y_x("Y_x","", r(0,1) ),
          Y_y("Y_y","", r(1,1) ),
          Y_z("Y_z","", r(2,1) ),
          Z_x("Z_x","", r(0,2) ),
          Z_y("Z_y","", r(1,2) ),
          Z_z("Z_z","", r(2,2) )
    {
        resultBag.add(X_x.clone());
        resultBag.add(X_y.clone());
        resultBag.add(X_z.clone());
        resultBag.add(Y_x.clone());
        resultBag.add(Y_y.clone());
        resultBag.add(Y_z.clone());
        resultBag.add(Z_x.clone());
        resultBag.add(Z_y.clone());
        resultBag.add(Z_z.clone());
    }

    bool RotationComposer::getResult(Rotation& res)
    {
        if ( bag.getType() == "MotCon::Rotation" || bag.getType() == "KDL.Rotation" )
            {

                Property<double>* X_x = dynamic_cast<Property<double>*>( bag.find("X_x") );
                Property<double>* X_y = dynamic_cast<Property<double>*>( bag.find("X_y") );
                Property<double>* X_z = dynamic_cast<Property<double>*>( bag.find("X_z") );
                Property<double>* Y_x = dynamic_cast<Property<double>*>( bag.find("Y_x") );
                Property<double>* Y_y = dynamic_cast<Property<double>*>( bag.find("Y_y") );
                Property<double>* Y_z = dynamic_cast<Property<double>*>( bag.find("Y_z") );
                Property<double>* Z_x = dynamic_cast<Property<double>*>( bag.find("Z_x") );
                Property<double>* Z_y = dynamic_cast<Property<double>*>( bag.find("Z_y") );
                Property<double>* Z_z = dynamic_cast<Property<double>*>( bag.find("Z_z") );
                // found it.
                if (  X_x != 0 && X_y != 0  && X_z != 0 &&
                      Y_x != 0 && Y_y != 0  && Y_z != 0 &&
                      Z_x != 0 && Z_y != 0  && Z_z != 0 )
                    {
                        res = Rotation(
                                                     X_x->get(), Y_x->get(),Z_x->get(),
                                                     X_y->get(),Y_y->get(),Z_y->get(),
                                                     X_z->get(),Y_z->get(),Z_z->get()
                                                     );
                        return true;
                    }
            }
        return false;
    }

    /**
     * A Decomposer for Converting a Rotation or Property<Rotation>
     * into a typed Property<PropertyBag> with the EulerZYX convention.
     */
    class EulerZYXDecomposer
    {
        PropertyBag resultBag;
        Property<double> _a;
        Property<double> _b;
        Property<double> _g;

    public:

        EulerZYXDecomposer( const Rotation& r);

        PropertyBag& result() { return resultBag; }
    };

    /**
     * An Composer for constructing an EulerZYX Rotation or Property<Rotation>
     * from a typed PropertyBag.
     */
    class EulerZYXComposer
    {
        const PropertyBag& bag;
    public:
        EulerZYXComposer(const PropertyBag& _bag )
            :  bag(_bag)
        {}

        bool getResult( Rotation& res );
    };

    EulerZYXDecomposer::EulerZYXDecomposer( const Rotation& r)
        : resultBag("KDL.EulerZYX"),
          _a("alpha","First Rotate around the Z axis with alpha in radians" ),
          _b("beta","Then Rotate around the new Y axis with beta in radians" ),
          _g("gamma","Then Rotation around the new X axis with gamma in radians" )
    {
        r.GetEulerZYX(_a.set(), _b.set(), _g.set());
        resultBag.add(_a.clone());
        resultBag.add(_b.clone());
        resultBag.add(_g.clone());
    }

    bool EulerZYXComposer::getResult(Rotation& res )
    {
        if ( bag.getType() == "KDL.EulerZYX" || bag.getType() == "MotCon::EulerZYX" )
            {

                // ZYX is deprecated, use alpha, beta, gamma. also alpha maps to Z and gamma to X !
                Property<double>* _a = dynamic_cast<Property<double>*>( bag.find("alpha") );
                if ( !_a)
                    _a = dynamic_cast<Property<double>*>( bag.find("Z") );
                Property<double>* _b = dynamic_cast<Property<double>*>( bag.find("beta") );
                if ( !_b)
                    _b = dynamic_cast<Property<double>*>( bag.find("Y") );
                Property<double>* _g = dynamic_cast<Property<double>*>( bag.find("gamma") );
                if ( !_g)
                    _g = dynamic_cast<Property<double>*>( bag.find("X") );

                // found it.
                if (  _a != 0 && _b != 0  && _g != 0 )
                    {
                        res = Rotation::EulerZYX(_a->get(), _b->get(), _g->get() );
                        return true;
                    } else {
                        std::string element = !_a ? "alpha" : !_b ? "beta" : "gamma";
                        Logger::log() << Logger::Error << "Aborting composition of (KDL.EulerZYX) Property< KDL.Rotation > "
                                      << ": Missing element '" <<element<<"'." <<Logger::endl;
                        return false;
                    }
            }
        return false;
    }

    /**
     * A Decomposer for Converting a Rotation or Property<Rotation>
     * into a typed Property<PropertyBag> with the RPY convention.
     */
    class RPYDecomposer
    {
        PropertyBag resultBag;
        Property<double> _r;
        Property<double> _p;
        Property<double> _y;

    public:

        RPYDecomposer( const Rotation& r);

        PropertyBag& result() { return resultBag; }
    };

    /**
     * An Composer for constructing an RPY Rotation or Property<Rotation>
     * from a typed PropertyBag.
     */
    class RPYComposer
    {
        const PropertyBag& bag;
    public:
        RPYComposer(const PropertyBag& _bag )
            :  bag(_bag)
        {}

        bool getResult( Rotation& res);
    };
    RPYDecomposer::RPYDecomposer( const Rotation& r)
        : resultBag("KDL.RPY" ),
          _r("R","First rotate around X with R(oll) in radians" ),
          _p("P","Next rotate around old Y with P(itch) in radians" ),
          _y("Y","Next rotate around old Z with Y(aw) in radians" )
    {
        r.GetRPY(_r.set(), _p.set(), _y.set());
        resultBag.add(_r.clone());
        resultBag.add(_p.clone());
        resultBag.add(_y.clone());
    }

    bool RPYComposer::getResult(Rotation& res)
    {
        if ( bag.getType() == "KDL.RPY" || bag.getType() == "MotCon::RPY" )
            {
                Property<double>* _r = dynamic_cast<Property<double>*>( bag.find("R") );
                Property<double>* _p = dynamic_cast<Property<double>*>( bag.find("P") );
                Property<double>* _y = dynamic_cast<Property<double>*>( bag.find("Y") );

                // found it.
                if (  _r != 0 && _p != 0  && _y != 0 )
                    {
                        res = Rotation::RPY(_r->get(), _p->get(), _y->get() );
                        return true;
                    } else {
                        std::string element = !_r ? "R" : !_p ? "P" : "Y";
                        Logger::log() << Logger::Error << "Aborting composition of (KDL.RPY) Property< KDL.Rotation > "
                                      << ": Missing element '" <<element<<"'." <<Logger::endl;
                        return false;
                    }
            }
        return false;
    }

    
    void decomposeProperty(const Vector &v, PropertyBag& targetbag)
    {
        // construct a property with same name and description, but containing a typed PropertyBag.
        VectorDecomposer vco(v);
        targetbag = vco.result();
    }

    bool composeProperty(const PropertyBag& bag, Vector &v)
    {
        VectorComposer vas( bag );
        return vas.getResult(v);
    }

    void decomposeProperty(const Rotation &b, PropertyBag& targetbag)
    {
        // construct a property with same name and description, but containing a typed PropertyBag.
#ifdef ROTATION_PROPERTIES_EULER
        EulerZYXDecomposer rot(b);
#else
# ifdef ROTATION_PROPERTIES_RPY
        RPYDecomposer rot(b);
# else
        RotationDecomposer rot(b);
# endif
#endif
        targetbag = rot.result();
    }

    bool composeProperty(const PropertyBag& bag, Rotation &r)
    {
        // try all three, see which one works, that one will fill in r.
        RPYComposer      rpyc(bag);
        EulerZYXComposer eulc(bag);
        RotationComposer rotc(bag);

        if ( rpyc.getResult( r ) || eulc.getResult( r ) || rotc.getResult( r ) )
            return true;
        else {
            Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Rotation > "
                          << ": Expected type 'KDL.Rotation','KDL.EulerZYX' or 'KDL.RPY', got type '"<< bag.getType() <<"'."
                          <<Logger::endl;
        }
        return false;
    }

    void decomposeProperty(const Twist &t, PropertyBag& targetbag)
    {
        targetbag.setType("KDL.Twist"); // bag_type

        VectorDecomposer vel( t.vel );
        VectorDecomposer rot( t.rot );

        targetbag.add( new Property<PropertyBag>("vel","Translational Velocity", vel.result() ) );
        targetbag.add( new Property<PropertyBag>("rot","Rotational Velocity",rot.result() ));
    }

    bool composeProperty(const PropertyBag& bag, Twist &t)
    {
        if ( bag.getType() == "KDL.Twist" || bag.getType() == "MotCon::Twist" )
            {

                // pass the subbag to the vector Composers
                Property<PropertyBag>* subbag = bag.getPropertyType<PropertyBag>("vel");
                if (! subbag ) {
                    Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Twist > "
                                  << ": Trans_Vel not found."
                                  <<Logger::endl;
                    return false;
                }
                VectorComposer vas_vel( subbag->value() );

                subbag = bag.getPropertyType<PropertyBag>("rot");
                if (! subbag ) {
                    Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Twist > "
                                  << ": Rot_Vel not found."
                                  <<Logger::endl;
                    return false;
                }
                VectorComposer vas_rot( subbag->value() );

                return vas_vel.getResult( t.vel ) && vas_rot.getResult( t.rot );
            } else {
                Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Twist > "
                              << ": Expected type 'KDL.Twist', got type '"<< bag.getType() <<"'."
                              <<Logger::endl;
            }
        return false;
    }

    void decomposeProperty(const Wrench &b, PropertyBag& targetbag)
    {
        // construct a property with same name and description, but containing a typed PropertyBag.
        targetbag.setType("KDL.Wrench"); // bag_type

        VectorDecomposer force( b.force );
        VectorDecomposer torque( b.torque );

        targetbag.add( new Property<PropertyBag>("force", "Axial Force", force.result() ) );
        targetbag.add( new Property<PropertyBag>("torque", "Axial Torque", torque.result() ) );
    }

    bool composeProperty(const PropertyBag& bag,Wrench &w)
    {
        if ( bag.getType() == "KDL.Wrench" ||  bag.getType() == "Motcon::Wrench")
            {

                // pass this bag to the vector Composers
                Property<PropertyBag>* subbag = bag.getPropertyType<PropertyBag>("force");
                if (! subbag ) {
                    Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Wrench > "
                                  << ": Force not found."
                                  <<Logger::endl;
                    return false;
                }
                VectorComposer vas_force( subbag->value() );

                subbag = bag.getPropertyType<PropertyBag>("torque");
                if (! subbag ) {
                    Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Wrench > "
                                  << ": Torque not found."
                                  <<Logger::endl;
                    return false;
                }
                VectorComposer vas_torque( subbag->value() );

                return vas_force.getResult( w.force ) && vas_torque.getResult( w.torque );
            } else {
                Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Wrench > "
                              << ": Expected type 'KDL.Wrench', got type '"<< bag.getType() <<"'."
                              <<Logger::endl;
                return false;
            }
        return false;
    }

    void decomposeProperty(const Frame &f, PropertyBag& targetbag )
    {
        // construct a typed PropertyBag.
        targetbag.setType("KDL.Frame");

        VectorDecomposer vel( f.p );
#ifdef ROTATION_PROPERTIES_EULER
        EulerZYXDecomposer rot( f.M );
#else
# ifdef ROTATION_PROPERTIES_RPY
        RPYDecomposer rot( f.M );
# else
        RotationDecomposer rot( f.M );
# endif
#endif

        targetbag.add( new Property<PropertyBag>("p","", vel.result() ) );
        targetbag.add( new Property<PropertyBag>("M","", rot.result() ) );
    }

    bool composeProperty(const PropertyBag& f_bag, Frame &f)
    {
        if ( f_bag.getType() == "KDL.Frame" ||  f_bag.getType() == "MotCon::Frame" )
            {
                // pass this bag to the vector Composers
                Property<PropertyBag>* subbag = f_bag.getPropertyType<PropertyBag>("p");
                if (! subbag ) {
                    Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Frame > "
                                  << ": Position not found."
                                  <<Logger::endl;
                    return false;
                }
                VectorComposer vas_pos( subbag->value() );

                subbag = f_bag.getPropertyType<PropertyBag>("M");
                if (! subbag ) {
                    Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Frame > "
                                  << ": Rotation not found."
                                  <<Logger::endl;
                    return false;
                }
                RPYComposer vas_rpy( subbag->value() );
                EulerZYXComposer vas_eul( subbag->value() );
                RotationComposer vas_rot( subbag->value() );
                bool result = vas_pos.getResult( f.p );
                if (!result )
                    {
                        Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Frame > "
                                      << ": element 'Position' has wrong format." <<Logger::endl;
                        return false;
                    }
                result = vas_rpy.getResult( f.M) ||
                    vas_eul.getResult( f.M ) ||
                    vas_rot.getResult( f.M );
                if (!result )
                    {
                        Logger::log()
                            << Logger::Error << "Aborting composition of Property< KDL.Frame > "
                            << ": Could not compose 'Rotation' type 'KDL.Rotation','KDL.EulerZYX' or 'KDL.RPY', got type '"
                            << subbag->get().getType() <<"'."<<Logger::endl;
                        return false;
                    }
                // OK: exit.
                return true;
            } else {
                Logger::log() << Logger::Error << "Aborting composition of Property< KDL.Frame > "
                              << ": Expected type 'KDL.Frame', got type '"<< f_bag.getType() <<"'."
                              <<Logger::endl;
                return false;
            }
        return false;
    }

} // MotionControl
