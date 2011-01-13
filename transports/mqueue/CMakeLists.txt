# Generated from orogen/lib/orogen/templates/typekit/mqueue/CMakeLists.txt
IF (NOT OROCOS-RTT_FOUND)
  FIND_PACKAGE(OROCOS-RTT REQUIRED)
ENDIF (NOT OROCOS-RTT_FOUND)

# Set up generation of IDL files for MQueue support
#pkg_check_modules(OrocosMQUEUE "orocos-rtt-mqueue-${OROCOS_TARGET}>=1.99.4")
IF (NOT OROCOS-RTT_MQUEUE_FOUND)
    MESSAGE(STATUS "RTT has not been build with MQueue support")
ENDIF(NOT OROCOS-RTT_MQUEUE_FOUND)

IF (OROCOS-RTT_MQUEUE_FOUND)
  
  set(MQueue_FILES "")
  
  # Generate the MQueue transport
  set(libname_mqueue kdl-transport-mqueue)
  orocos_typekit(${libname_mqueue}
      ${CMAKE_SOURCE_DIR}/transports/mqueue/TransportPlugin.cpp
      ${CMAKE_SOURCE_DIR}/transports/mqueue/__KDL__Frame.cpp
      ${CMAKE_SOURCE_DIR}/transports/mqueue/__KDL__Rotation.cpp
      ${CMAKE_SOURCE_DIR}/transports/mqueue/__KDL__Twist.cpp
      ${CMAKE_SOURCE_DIR}/transports/mqueue/__KDL__Vector.cpp
      ${CMAKE_SOURCE_DIR}/transports/mqueue/__KDL__Wrench.cpp
      ${MQueue_FILES})
  target_link_libraries(${libname_mqueue}
      kdl-typekit
      ${OROCOS-RTT_MQUEUE_LIBRARIES})
  
  
  target_link_libraries(${libname_mqueue} LINK_INTERFACE_LIBRARIES ${OROCOS-RTT_MQUEUE_LIBRARIES})
ENDIF(OROCOS-RTT_MQUEUE_FOUND)
