INCLUDE (${PROJ_SOURCE_DIR}/config/TaoIDL.cmake)
INCLUDE (${PROJ_SOURCE_DIR}/config/DependentOption.cmake)
INCLUDE(${PROJ_SOURCE_DIR}/config/FindCorbaDeps.cmake)

#this option was set in global_rules.cmake
IF(ENABLE_CORBA )
  MESSAGE( "CORBA Support enabled.")
  # Finally:

  INCLUDE (${PROJ_SOURCE_DIR}/config/UseCorba.cmake)
    
  # Add includes / lib paths if necessary
  IF( NOT ${ACE_DIR} STREQUAL /usr/include )
    INCLUDE_DIRECTORIES( ${ACE_DIR} )
    LINK_DIRECTORIES( ${ACE_DIR}/../lib )
    SET(CMAKE_C_FLAGS_RTT "${CMAKE_C_FLAGS_RTT} -I${ACE_DIR}" CACHE INTERNAL "")
    SET(CMAKE_LINKFLAGS_RTT "${CMAKE_LINKFLAGS_RTT} -L${ACE_DIR}/../lib" CACHE INTERNAL "")
  ENDIF( NOT ${ACE_DIR} STREQUAL /usr/include )
  IF( NOT ${TAO_DIR} STREQUAL /usr/include )
    INCLUDE_DIRECTORIES( ${TAO_DIR} )
    SET(CMAKE_C_FLAGS_RTT "${CMAKE_C_FLAGS_RTT} -I${TAO_DIR}" CACHE INTERNAL "")
  ENDIF( NOT ${TAO_DIR} STREQUAL /usr/include )
  IF( NOT ${ORBSVCS_DIR} STREQUAL /usr/include )
    INCLUDE_DIRECTORIES( ${ORBSVCS_DIR} )
    SET(CMAKE_C_FLAGS_RTT "${CMAKE_C_FLAGS_RTT} -I${ORBSVCS_DIR}" CACHE INTERNAL "")
  ENDIF( NOT ${ORBSVCS_DIR} STREQUAL /usr/include )

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

  ADD_LIBRARY(orocos-kdltk-corba-${OROCOS_TARGET} SHARED ${CPPS})
  SET_TARGET_PROPERTIES( orocos-kdltk-corba-${OROCOS_TARGET} PROPERTIES
  COMPILE_FLAGS "${CMAKE_CXX_FLAGS_ADD} ${CMAKE_C_FLAGS_RTT} -D_REENTRANT -DOROCOS_TARGET=${OROCOS_TARGET}"
  SOVERSION "${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}"
  VERSION "${KDL_VERSION}"
  INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/rtt/${OROCOS_TARGET}/plugins")
  # Is used for building  the library
  TARGET_LINK_LIBRARIES(orocos-kdltk-corba-${OROCOS_TARGET} orocos-rtt-corba-${OROCOS_TARGET} orocos-kdltk-${OROCOS_TARGET} ${ORO_ACETAO_LIBRARIES})
  CONFIGURE_FILE( orocos-kdltk-corba.pc.in src/bindings/rtt/corba/orocos-kdltk-corba-${OROCOS_TARGET}.pc @ONLY)

  INSTALL_TARGETS(/lib/rtt/${OROCOS_TARGET}/plugins orocos-kdltk-corba-${OROCOS_TARGET})
  INSTALL_FILES( /lib/pkgconfig FILES orocos-kdltk-corba-${OROCOS_TARGET}.pc)

ENDIF(ENABLE_CORBA)
