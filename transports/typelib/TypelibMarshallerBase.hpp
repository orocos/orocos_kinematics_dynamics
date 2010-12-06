/* Generated from orogen/lib/orogen/templates/typekit/typelib/TypelibMarshallerBase.hpp */

#ifndef OROGEN_TYPELIB_MARSHALLER_BASE_HPP
#define OROGEN_TYPELIB_MARSHALLER_BASE_HPP

#include <rtt/types/TypeTransporter.hpp>
#include <rtt/base/PortInterface.hpp>
#include <rtt/FlowStatus.hpp>
#include <typelib/value_ops.hh>

namespace orogen_transports
{
    static const int TYPELIB_MARSHALLER_ID = 42;
    class TypelibMarshallerBase : public RTT::types::TypeTransporter
    {
        Typelib::Type const*  type_def;
        Typelib::MemoryLayout layout;
        std::string m_typename_typelib;
        std::string m_typename_orocos;

    public:
        struct Handle;

        TypelibMarshallerBase(std::string const& typelib_typename,
                std::string const& orocos_typename,
                Typelib::Registry const& registry);

        /** Returns the Typelib-friendly type name for this marshaller. I.e. the
         * type name for the pointer returned by getTypelibData.
         *
         * I.e. if the type is opaque, it is the name of the intermediate type.
         * Otherwise, it is the type name itself.
         */
        char const* getMarshallingType() const;

        /** Updates the sample handler by using a data sample that Typelib
         * understands. +typelib_data+ must be pointing to an object whose type
         * is the one returned by getMarshallingType.
         *
         * The handle will then point directly to the given data sample, i.e.
         * calls to \c read might modify that sample directly.
         *
         * The ownership of \c typelib_data is retained by the caller. I.e. it
         * has to delete it.
         */
        virtual void setTypelibSample(Handle* data, uint8_t* typelib_data) = 0;

        /** Updates the value of data->orocos_sample based on the data in
         * data->typelib_sample
         */
        virtual void refreshOrocosSample(Handle* data) const = 0;

        /** Returns a type-pruned pointer to an object that Typelib understands.
         * This object is of the type returned by getMarshallingType
         */
        uint8_t* getTypelibSample(Handle* sample);

        /** Creates a sample handler, which is an opaque type used to
         * read/write/marshal data. Unlike createHandle(), the handle returned
         * by this method already contains a preallocated data sample. It can
         * therefore be used as-is for readPort.
         */
        virtual Handle* createSample() = 0;

        /** Creates a sample handler, which is an opaque type used to
         * read/write/marshal data. Unlike createSample(), the handle returned
         * by this method does not contain any preallocated data sample. Using
         * it in readPort will cause memory allocation.
         */
        Handle* createHandle();

        /** Destroys the orocos-related data sample that is stored in \c data.
         *
         * For non-opaque types, this is the same than destroyOrocosSample and
         * destroyData. It is different only for opaque types.
         */
        virtual void deleteOrocosSample(Handle* data) = 0;

        /** Destroys the typelib-related data sample that is stored in \c data.
         *
         * For non-opaque types, this is the same than destroyTypelibSample and
         * destroyData. It is different only for opaque types.
         */
        virtual void deleteTypelibSample(Handle* data) = 0;

        /** Destroys the sample handle and the data it owns.
         *
         * What is actually deleted depends on how the handle has been used. For
         * instance, if setTypelibSample has been used, then the sample will not
         * be deleted.
         */
        void deleteHandle(Handle* data);

        /** Writes the data from from the handle into the data source
         */
        virtual void writeDataSource(RTT::base::DataSourceBase& source, Handle const* handle) = 0;

        /** Reads the data from a data source a handle
         */
        virtual bool readDataSource(RTT::base::DataSourceBase& source, Handle* handle) = 0;

        /** Reads the data from the given port into the opaque handle type.
         *
         * Use getTypelibData() to get a type-pruned pointer that can be
         * interpreted by Typelib
         *
         * Returns true if a sample has been read, false otherwise.
         */
        virtual RTT::FlowStatus readPort(RTT::base::InputPortInterface& port, Handle* sample) = 0;

        /** Writes the data to a port. \c sample is a type-pruned pointer of a
         * typelib-friendly data sample, whose type name is returned by
         * getMarshallingType.
         *
         * I.e. for opaque types, it is a pointer to a sample of the
         * intermediate type.
         */
        virtual void writePort(RTT::base::OutputPortInterface& port, Handle const* sample) = 0;

        /** Returns the marshalled size for the given data sample
         */
        size_t getMarshallingSize(Handle const* sample) const;
        /** Marshals the given sample directly on to a file
         */
        void marshal(int fd, Handle* sample) const;
        /** Marshals the given sample directly on to a C++ stream
         */
        void marshal(std::ostream& stream, Handle* sample) const;
        /** Marshals the given sample into a memory buffer
         */
        void marshal(std::vector<uint8_t>& buffer, Handle* sample) const;
        /** Update the sample in +sample+ from the marshalled data in +buffer+
         */
        virtual void unmarshal(std::vector<uint8_t>& buffer, Handle* sample) const;

        virtual RTT::base::ChannelElementBase* createStream(RTT::base::PortInterface* port, const RTT::ConnPolicy& policy, bool is_sender) const
        { return NULL; }
    };
}

#endif

