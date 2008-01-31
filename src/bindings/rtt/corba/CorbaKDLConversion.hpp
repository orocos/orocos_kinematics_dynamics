#include "KDLTypesC.h"
#include <rtt/corba/CorbaConversion.hpp>
namespace RTT
{

    template<>
    struct AnyConversion< KDL::Vector >
    {
        typedef Corba::DoubleSequence CorbaType;
        typedef KDL::Vector StdType;
        static CorbaType* toAny(const KDL::Vector& orig) {
            log(Debug)<< "Converting type 'KDL::Vector' to sequence<CORBA::Double>." <<endlog();
            CorbaType* ret = new CorbaType();
            ret->length( 3 );
                (*ret)[0] = orig.x();
                (*ret)[1] = orig.y();
                (*ret)[2] = orig.z();
            return ret;
        }

        static StdType get(const CorbaType* t) {
            log(Debug)<< "Converting type sequence<CORBA::Double> to 'KDL::Vector'" <<endlog();
            StdType ret;
            ret.x((*t)[0]);
            ret.y((*t)[1]);
            ret.z((*t)[2]);
            return ret;
        }

        static bool update(const CORBA::Any& any, StdType& _value) {
            log(Debug)<< "update KDL::Vector" <<endlog();
            CorbaType* result;
            if ( any >>= result ) {
                    _value.x((*result)[0]);
                    _value.y((*result)[1]);
                    _value.z((*result)[2]);
                return true;
            }
            return false;
        }

        static CORBA::Any_ptr createAny( const KDL::Vector& t ) {
            CORBA::Any_ptr ret = new CORBA::Any();
            *ret <<= toAny( t );
            return ret;
        }
    };

    template<>
    struct AnyConversion< KDL::Rotation >
    {
        typedef Corba::DoubleSequence CorbaType;
        typedef KDL::Rotation StdType;
        static CorbaType* toAny(const KDL::Rotation& orig) {
            log(Debug)<< "Converting type 'KDL::Rotation' to sequence<CORBA::Double>." <<endlog();
            CorbaType* ret = new CorbaType();
            ret->length( 9 );
                (*ret)[0] = orig(0,0);
                (*ret)[1] = orig(0,1);
                (*ret)[2] = orig(0,2);
                (*ret)[3] = orig(1,0);
                (*ret)[4] = orig(1,1);
                (*ret)[5] = orig(1,2);
                (*ret)[6] = orig(2,0);
                (*ret)[7] = orig(2,1);
                (*ret)[8] = orig(2,2);
            return ret;
        }

        static StdType get(const CorbaType* t) {
            log(Debug)<< "Converting type sequence<CORBA::Double> to 'KDL::Rotation'" <<endlog();
            StdType ret((*t)[0],(*t)[1],(*t)[2],(*t)[3],(*t)[4],(*t)[5],(*t)[6],(*t)[7],(*t)[8]);
            return ret;
        }

        static bool update(const CORBA::Any& any, StdType& _value) {
            log(Debug)<< "update KDL::Rotation" <<endlog();
            CorbaType* result;
            if ( any >>= result ) {
                    _value(0,0)=(*result)[0];
                    _value(0,1)=(*result)[1];
                    _value(0,2)=(*result)[2];
                    _value(1,0)=(*result)[3];
                    _value(1,1)=(*result)[4];
                    _value(1,2)=(*result)[5];
                    _value(2,0)=(*result)[6];
                    _value(2,1)=(*result)[7];
                    _value(2,2)=(*result)[8];
                return true;
            }
            return false;
        }

        static CORBA::Any_ptr createAny( const KDL::Rotation& t ) {
            CORBA::Any_ptr ret = new CORBA::Any();
            *ret <<= toAny( t );
            return ret;
        }

    };

    template<>
    struct AnyConversion< KDL::Frame >
    {
        typedef Corba::DoubleSequence CorbaType;
        typedef KDL::Frame StdType;
        static CorbaType* toAny(const KDL::Frame& orig) {
            log(Debug)<< "Converting type 'KDL::Frame' to sequence<CORBA::Double>." <<endlog();
            CorbaType* ret = new CorbaType();
            ret->length( 12 );
                (*ret)[0] = orig.p.x();
                (*ret)[1] = orig.p.y();
                (*ret)[2] = orig.p.z();
                (*ret)[3] = orig.M(0,0);
                (*ret)[4] = orig.M(0,1);
                (*ret)[5] = orig.M(0,2);
                (*ret)[6] = orig.M(1,0);
                (*ret)[7] = orig.M(1,1);
                (*ret)[8] = orig.M(1,2);
                (*ret)[9] = orig.M(2,0);
                (*ret)[10] = orig.M(2,1);
                (*ret)[11] = orig.M(2,2);
            return ret;
        }

        static StdType get(const CorbaType* t) {
            log(Debug)<< "Converting type sequence<CORBA::Double> to 'KDL::Frame'" <<endlog();
            StdType ret;
                    ret.p.x((*t)[0]);
                    ret.p.y((*t)[1]);
                    ret.p.z((*t)[2]);
                    ret.M(0,0)=(*t)[3];
                    ret.M(0,1)=(*t)[4];
                    ret.M(0,2)=(*t)[5];
                    ret.M(1,0)=(*t)[6];
                    ret.M(1,1)=(*t)[7];
                    ret.M(1,2)=(*t)[8];
                    ret.M(2,0)=(*t)[9];
                    ret.M(2,1)=(*t)[10];
                    ret.M(2,2)=(*t)[11];
            return ret;
        }

        static bool update(const CORBA::Any& any, StdType& _value) {
            log(Debug)<< "update KDL::Frame" <<endlog();
            CorbaType* result;
            if ( any >>= result ) {
                    _value.p.x((*result)[0]);
                    _value.p.y((*result)[1]);
                    _value.p.z((*result)[2]);
                    _value.M(0,0)=(*result)[3];
                    _value.M(0,1)=(*result)[4];
                    _value.M(0,2)=(*result)[5];
                    _value.M(1,0)=(*result)[6];
                    _value.M(1,1)=(*result)[7];
                    _value.M(1,2)=(*result)[8];
                    _value.M(2,0)=(*result)[9];
                    _value.M(2,1)=(*result)[10];
                    _value.M(2,2)=(*result)[11];
                return true;
            }
            return false;
        }

        static CORBA::Any_ptr createAny( const KDL::Frame& t ) {
            CORBA::Any_ptr ret = new CORBA::Any();
            *ret <<= toAny( t );
            return ret;
        }

    };

    template<>
    struct AnyConversion< KDL::Wrench >
    {
        typedef Corba::DoubleSequence CorbaType;
        typedef KDL::Wrench StdType;
        static CorbaType* toAny(const KDL::Wrench& orig) {
            log(Debug)<< "Converting type 'KDL::Wrench' to sequence<CORBA::Double>." <<endlog();
            CorbaType* ret = new CorbaType();
            ret->length( 6 );
                (*ret)[0] = orig.force.x();
                (*ret)[1] = orig.force.y();
                (*ret)[2] = orig.force.z();
                (*ret)[3] = orig.torque.x();
                (*ret)[4] = orig.torque.y();
                (*ret)[5] = orig.torque.z();
            return ret;
        }

        static StdType get(const CorbaType* t) {
            log(Debug)<< "Converting type sequence<CORBA::Double> to 'KDL::Wrench'" <<endlog();
            StdType ret;
                    ret.force.x((*t)[0]);
                    ret.force.y((*t)[1]);
                    ret.force.z((*t)[2]);
                    ret.torque.x((*t)[3]);
                    ret.torque.y((*t)[4]);
                    ret.torque.z((*t)[5]);
            return ret;
        }

        static bool update(const CORBA::Any& any, StdType& _value) {
            log(Debug)<< "update KDL::Wrench" <<endlog();
            CorbaType* result;
            if ( any >>= result ) {
                    _value.force.x((*result)[0]);
                    _value.force.y((*result)[1]);
                    _value.force.z((*result)[2]);
                    _value.torque.x((*result)[3]);
                    _value.torque.y((*result)[4]);
                    _value.torque.z((*result)[5]);
                return true;
            }
            return false;
        }

        static CORBA::Any_ptr createAny( const KDL::Wrench& t ) {
            CORBA::Any_ptr ret = new CORBA::Any();
            *ret <<= toAny( t );
            return ret;
        }

    };

    template<>
    struct AnyConversion< KDL::Twist >
    {
        typedef Corba::DoubleSequence CorbaType;
        typedef KDL::Twist StdType;
        static CorbaType* toAny(const KDL::Twist& orig) {
            log(Debug)<< "Converting type 'KDL::Twist' to sequence<CORBA::Double>." <<endlog();
            CorbaType* ret = new CorbaType();
            ret->length( 6 );
                (*ret)[0] = orig.vel.x();
                (*ret)[1] = orig.vel.y();
                (*ret)[2] = orig.vel.z();
                (*ret)[3] = orig.rot.x();
                (*ret)[4] = orig.rot.y();
                (*ret)[5] = orig.rot.z();
            return ret;
        }

        static StdType get(const CorbaType* t) {
            log(Debug)<< "Converting type sequence<CORBA::Double> to 'KDL::Twist'" <<endlog();
            StdType ret;
                    ret.vel.x((*t)[0]);
                    ret.vel.y((*t)[1]);
                    ret.vel.z((*t)[2]);
                    ret.rot.x((*t)[3]);
                    ret.rot.y((*t)[4]);
                    ret.rot.z((*t)[5]);
            return ret;
        }

        static bool update(const CORBA::Any& any, StdType& _value) {
            log(Debug)<< "update KDL::Twist" <<endlog();
            CorbaType* result;
            if ( any >>= result ) {
                    _value.vel.x((*result)[0]);
                    _value.vel.y((*result)[1]);
                    _value.vel.z((*result)[2]);
                    _value.rot.x((*result)[3]);
                    _value.rot.y((*result)[4]);
                    _value.rot.z((*result)[5]);
                return true;
            }
            return false;
        }

        static CORBA::Any_ptr createAny( const KDL::Twist& t ) {
            CORBA::Any_ptr ret = new CORBA::Any();
            *ret <<= toAny( t );
            return ret;
        }

    };
};
