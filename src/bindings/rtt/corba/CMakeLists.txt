INCLUDE (${PROJ_SOURCE_DIR}/config/TaoIDL.cmake)
INCLUDE (${PROJ_SOURCE_DIR}/config/DependentOption.cmake)
INCLUDE(${PROJ_SOURCE_DIR}/config/FindCorbaDeps.cmake)

#this option was set in global_rules.cmake
IF(ENABLE_CORBA )
  MESSAGE( "CORBA Support enabled.")
  # Finally:
    
  # Add includes / lib paths if necessary
  IF( NOT ${ACE_DIR} STREQUAL /usr/include )
    INCLUDE_DIRECTORIES( ${ACE_DIR} )
    LINK_DIRECTORIES( ${ACE_DIR}/lib )
    SET(CMAKE_C_FLAGS_RTT "${CMAKE_C_FLAGS_RTT} -I${ACE_DIR}" CACHE INTERNAL "")
    SET(CMAKE_LINKFLAGS_RTT "${CMAKE_LINKFLAGS_RTT} -L${ACE_DIR}/lib" CACHE INTERNAL "")
  ENDIF( NOT ${ACE_DIR} STREQUAL /usr/include )
  IF( NOT ${TAO_DIR} STREQUAL /usr/include )
    INCLUDE_DIRECTORIES( ${TAO_DIR} )
    SET(CMAKE_C_FLAGS_RTT "${CMAKE_C_FLAGS_RTT} -I${TAO_DIR}" CACHE INTERNAL "")
  ENDIF( NOT ${TAO_DIR} STREQUAL /usr/include )
  IF( NOT ${ORBSVCS_DIR} STREQUAL /usr/include )
    INCLUDE_DIRECTORIES( ${ORBSVCS_DIR} )
    SET(CMAKE_C_FLAGS_RTT "${CMAKE_C_FLAGS_RTT} -I${ORBSVCS_DIR}" CACHE INTERNAL "")
  ENDIF( NOT ${ORBSVCS_DIR} STREQUAL /usr/include )
  # Is used for building  the library
  LINK_LIBRARIES( TAO TAO_IDL_BE TAO_PortableServer TAO_CosNaming ACE  )

  SET(CMAKE_LINKFLAGS_RTT "-lTAO -lTAO_IDL_BE -lTAO_PortableServer -lTAO_CosNaming -lACE" CACHE INTERNAL "")

  FILE( GLOB IDLS [^.]*.idl )
  FILE( GLOB CPPS [^.]*.cpp )
  FILE( GLOB HPPS [^.]*.hpp [^.]*.h [^.]*.inl)

  ORO_ADD_CORBA_SERVERS(CPPS HPPS ${IDLS} )
  SET( ENV{GLOBAL_GENERATED_SRCS} "${CPPS}" )

  #This has been added in order to generate files before make -j<N>
  # make -j<N> causes corruption of generated files because of overwriting
  ADD_CUSTOM_TARGET( idl DEPENDS ${CPPS} ${HPPS} COMMENT "Generating sources from .idl files")

  #MESSAGE("CPPS: $ENV{GLOBAL_GENERATED_SRCS}")
  MESSAGE("HPPS: ${HPPS}")
  INSTALL_FILES( /include/kdl/bindings/rtt/corba FILES ${HPPS})
  #GLOBAL_ADD_SRC( ${CPPS} )
  INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_BINARY_DIR} )

  ADD_LIBRARY(orocos-kdltk-corba SHARED ${CPPS})
  SET_TARGET_PROPERTIES( orocos-kdltk-corba PROPERTIES
  COMPILE_FLAGS "${CMAKE_CXX_FLAGS_ADD} ${CMAKE_C_FLAGS_RTT} -D_REENTRANT -DOROCOS_TARGET=${OROCOS_TARGET}"
  SOVERSION "${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}"
  VERSION "${KDL_VERSION}")


CONFIGURE_FILE( orocos-kdltk-corba.pc.in src/bindings/rtt/corba/orocos-kdltk-corba.pc @ONLY)

  INSTALL_TARGETS(/lib orocos-kdltk-corba)
  INSTALL_FILES( /lib/pkgconfig FILES orocos-kdltk-corba.pc)

ENDIF(ENABLE_CORBA)
