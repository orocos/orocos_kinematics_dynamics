/* Generated from orogen/lib/orogen/templates/typekit/typelib/TypelibMarshaller.hpp */

#ifndef OROGEN_TYPELIB_MARSHALLER_HPP
#define OROGEN_TYPELIB_MARSHALLER_HPP

#include "TypelibMarshallerBase.hpp"
#include <rtt/Port.hpp>

struct orogen_transports::TypelibMarshallerBase::Handle
{
    /** The TypelibMarshallerBase that created us
     */
    TypelibMarshallerBase* marshaller;
    /** Type-pruned pointer of the sample that Typelib can understand. It may be
     * the same as orocos_sample
     */
    uint8_t* typelib_sample;
    /** If true, the handle owns the memory addressed by \c typelib_sample, and
     * will therefore destroy it when it gets deleted.
     */
    bool owns_typelib;
    /** Type-pruned pointer of the sample that Orocos can understand. It may be
     * the same as typelib_sample
     */
    uint8_t* orocos_sample;
    /** If true, the handle owns the memory addressed by \c orocos_sample, and
     * will therefore destroy it when it gets deleted.
     */
    bool owns_orocos;

    void reset()
    {
        typelib_sample = 0;
        orocos_sample  = 0;
    }

    Handle(TypelibMarshallerBase* marshaller)
        : marshaller(marshaller)
        , typelib_sample(0), owns_typelib(true)
        , orocos_sample(0), owns_orocos(true) {}

    template<typename Type>
    Handle(TypelibMarshallerBase* marshaller, Type* data)
        : marshaller(marshaller)
        , typelib_sample(reinterpret_cast<uint8_t*>(data))
        , owns_typelib(true)
        , orocos_sample(typelib_sample)
        , owns_orocos(true) {}

    template<typename TypelibType, typename OrocosType>
    Handle(TypelibMarshallerBase* marshaller, TypelibType* typelib_data, OrocosType* orocos_data)
        : marshaller(marshaller)
        , typelib_sample(reinterpret_cast<uint8_t*>(typelib_data))
        , owns_typelib(true)
        , orocos_sample(reinterpret_cast<uint8_t*>(orocos_data))
        , owns_orocos(true) {}

    ~Handle()
    {
        if (owns_typelib && typelib_sample)
            marshaller->deleteTypelibSample(this);
        if (owns_orocos && orocos_sample)
            marshaller->deleteOrocosSample(this);
    }
};


namespace orogen_transports
{
    template<typename T>
    struct TypelibMarshaller : public orogen_transports::TypelibMarshallerBase
    {
        typedef TypelibMarshallerBase::Handle Handle;

        TypelibMarshaller(std::string const& orocos_name, Typelib::Registry const& registry)
            : orogen_transports::TypelibMarshallerBase(orocos_name, orocos_name, registry) { }

        TypelibMarshallerBase::Handle* createSample() { return new Handle(this, new T); }
        void deleteOrocosSample(Handle* data)  { deleteSamples(data); }
        void deleteTypelibSample(Handle* data) { deleteSamples(data); }
        void deleteSamples(Handle* data)
        {
            delete reinterpret_cast<T*>(data->orocos_sample);
            data->reset();
        }

        void setTypelibSample(Handle* handle, uint8_t* data)
        {
            handle->orocos_sample = handle->typelib_sample = reinterpret_cast<uint8_t*>(data);
            handle->owns_orocos = handle->owns_typelib = false;
        }

        void refreshOrocosSample(Handle* handle) const
        {
            // Nothing to do
        }

        bool readDataSource(RTT::base::DataSourceBase& source_base, Handle* handle)
        {
            RTT::internal::DataSource<T>& source = dynamic_cast<RTT::internal::DataSource<T>&>(source_base);
            if (source.evaluate())
            {
                T& data = *reinterpret_cast<T*>(handle->orocos_sample);
                data = dynamic_cast<RTT::internal::DataSource<T>&>(source_base).get();
                return true;
            }
            return false;
        }
        void writeDataSource(RTT::base::DataSourceBase& source, Handle const* handle)
        {
            T const& data = *reinterpret_cast<T const*>(handle->orocos_sample);
            dynamic_cast<RTT::internal::AssignableDataSource<T>&>(source).set(data);
        }

        RTT::FlowStatus readPort(RTT::base::InputPortInterface& port, Handle* handle)
        {
            T& data = *reinterpret_cast<T*>(handle->orocos_sample);
            return dynamic_cast< RTT::InputPort<T>& >(port).read(data);
        }
        void writePort(RTT::base::OutputPortInterface& port, Handle const* handle)
        {
            T const& data = *reinterpret_cast<T const*>(handle->orocos_sample);
            return dynamic_cast< RTT::OutputPort<T>& >(port).write(data);
        }
    };
}

#endif

