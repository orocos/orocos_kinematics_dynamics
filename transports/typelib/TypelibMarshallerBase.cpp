/* Generated from orogen/lib/orogen/templates/typekit/typelib/TypelibMarshallerBase.cpp */

#include "TypelibMarshaller.hpp"

using namespace orogen_transports;

typedef TypelibMarshallerBase::Handle Handle;

TypelibMarshallerBase::TypelibMarshallerBase(std::string const& typelib_typename,
        std::string const& orocos_typename,
        Typelib::Registry const& registry)
    : m_typename_typelib(typelib_typename)
    , m_typename_orocos(orocos_typename)
    , type_def(registry.get(typelib_typename))
{
    if (!type_def)
        throw std::runtime_error(typelib_typename + " is not present in the typekit registry");

    layout    = Typelib::layout_of(*type_def, false, false);
}

Handle* TypelibMarshallerBase::createHandle() { return new Handle(this); }
void TypelibMarshallerBase::deleteHandle(Handle* handle) { delete handle; }
uint8_t* TypelibMarshallerBase::getTypelibSample(Handle* handle)
{
    return handle->typelib_sample;
}

char const* TypelibMarshallerBase::getMarshallingType() const
{ return m_typename_typelib.c_str(); }
size_t TypelibMarshallerBase::getMarshallingSize(Handle const* handle) const
{ return Typelib::getDumpSize(handle->typelib_sample, layout); }
void TypelibMarshallerBase::marshal(int fd, Handle* handle) const
{ Typelib::dump(handle->typelib_sample, fd, layout); }
void TypelibMarshallerBase::marshal(std::ostream& stream, Handle* handle) const
{ Typelib::dump(handle->typelib_sample, stream, layout); }
void TypelibMarshallerBase::marshal(std::vector<uint8_t>& buffer, Handle* handle) const
{ Typelib::dump(handle->typelib_sample, buffer, layout); }
void TypelibMarshallerBase::unmarshal(std::vector<uint8_t>& buffer, Handle* handle) const
{
    Typelib::load(handle->typelib_sample, *type_def, buffer, layout);
    refreshOrocosSample(handle);
}

