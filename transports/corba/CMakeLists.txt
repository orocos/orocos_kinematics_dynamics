# Generated from orogen/lib/orogen/templates/typekit/corba/CMakeLists.txt

find_package(OrocosCORBA QUIET COMPONENTS Typekit)
IF(OROCOS-RTT_CORBA_FOUND)
  INCLUDE_DIRECTORIES(${OrocosCORBA_INCLUDE_DIRS})
  ADD_DEFINITIONS(${OrocosCORBA_DEFINES})
  
  include_directories(${OrocosCORBA_INCLUDE_DIRS})
  add_definitions(${OrocosCORBA_CFLAGS_OTHER})
  link_directories(${OrocosCORBA_LIBRARY_DIRS})
  
  # Set up generation of IDL files for CORBA support
  IF (NOT OrocosCORBA_Typekit_FOUND)
      MESSAGE(FATAL_ERROR "could not find development files for Orocos/CORBA")
  ENDIF(NOT OrocosCORBA_Typekit_FOUND)
  
  set(CORBA_FILES ${CMAKE_CURRENT_BINARY_DIR}/kdlTypesC.cpp)
  if(CORBA_IMPLEMENTATION STREQUAL "OMNIORB")
      list(APPEND CORBA_FILES ${CMAKE_CURRENT_BINARY_DIR}/kdlTypesDynSK.cpp)
  endif(CORBA_IMPLEMENTATION STREQUAL "OMNIORB")
  
  add_custom_command(OUTPUT ${CORBA_FILES}
      COMMAND ${OrocosCORBA_IDL} -Wbkeep_inc_path
          
          ${CMAKE_CURRENT_SOURCE_DIR}/kdlTypes.idl
      DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/kdlTypes.idl)
  
  add_definitions(${OrocosCORBA_Typekit_DEFINES})
  include_directories(${OrocosCORBA_Typekit_INCLUDE_DIRS})
  
  # Generate the CORBA transport
  set(libname_corba kdl-transport-corba)
  orocos_typekit(${libname_corba}
      ${CMAKE_SOURCE_DIR}/transports/corba/Convertions.cpp
      ${CMAKE_SOURCE_DIR}/transports/corba/TransportPlugin.cpp
      ${CMAKE_SOURCE_DIR}/transports/corba/__KDL__Frame.cpp
      ${CMAKE_SOURCE_DIR}/transports/corba/__KDL__Rotation.cpp
      ${CMAKE_SOURCE_DIR}/transports/corba/__KDL__Twist.cpp
      ${CMAKE_SOURCE_DIR}/transports/corba/__KDL__Vector.cpp
      ${CMAKE_SOURCE_DIR}/transports/corba/__KDL__Wrench.cpp
      ${CORBA_FILES})
  target_link_libraries(${libname_corba}
      kdl-typekit
      ${OrocosCORBA_LIBRARIES})


target_link_libraries(${libname_corba} LINK_INTERFACE_LIBRARIES ${OrocosCORBA_LIBRARIES})

install(FILES
   ${CMAKE_CURRENT_SOURCE_DIR}/transports/corba/Convertions.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/transports/corba/TransportPlugin.hpp
    Convertions.hpp
    kdlTypes.idl
    ${CMAKE_CURRENT_BINARY_DIR}/kdlTypesC.h
    DESTINATION include/orocos/kdl/transports/corba)

ENDIF(OROCOS-RTT_CORBA_FOUND)
