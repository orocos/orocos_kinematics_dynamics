# Generated from orogen/lib/orogen/templates/typekit/typelib/CMakeLists.txt

set(libname kdl-transport-typelib-${OROCOS_TARGET})
rosbuild_add_library(${libname} 
    ${CMAKE_SOURCE_DIR}/transports/typelib/KDL_Frame.cpp
    ${CMAKE_SOURCE_DIR}/transports/typelib/KDL_Rotation.cpp
    ${CMAKE_SOURCE_DIR}/transports/typelib/KDL_Twist.cpp
    ${CMAKE_SOURCE_DIR}/transports/typelib/KDL_Vector.cpp
    ${CMAKE_SOURCE_DIR}/transports/typelib/KDL_Wrench.cpp
    ${CMAKE_SOURCE_DIR}/transports/typelib/TypelibMarshallerBase.cpp
    ${CMAKE_SOURCE_DIR}/transports/typelib/TransportPlugin.cpp
    TypelibMarshallerBase.cpp)

target_link_libraries(${libname}
    ${TYPELIB_LIBRARIES})
target_link_libraries(${libname}
    LINK_INTERFACE_LIBRARIES)
