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
};
