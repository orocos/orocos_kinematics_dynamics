IF( OROCOS_PLUGIN )

  OPTION(ROTATION_PROPERTIES_RPY "" ON)
  OPTION(ROTATION_PROPERTIES_EULER "" OFF)

#  SET(ROTATION_PROPERTIES "RPY" CACHE STRING "choose how the plugin should write angles to the propertyfile: RPY, EULER, MATRIX" )
#  IF( ${ROTATION_PROPERTIES} STREQUAL "RPY" )
#    MESSAGE("Choosing RPY for Rotation property type")
#    SET(ROTATION_PROPERTIES_RPY 1)
#  ENDIF(${ROTATION_PROPERTIES} STREQUAL "RPY")
#  IF(${ROTATION_PROPERTIES} STREQUAL "EULER")
#    MESSAGE("Choosing EULER for Rotation property type")
#    SET(ROTATION_PROPERTIES_EULER 1)
#  ENDIF(${ROTATION_PROPERTIES} STREQUAL "EULER")

  CONFIGURE_FILE( kdltk.hpp.in src/bindings/rtt/kdltk.hpp)
  INSTALL_FILES( /include/kdl/bindings/rtt FILES kdltk.hpp)
  INCLUDE_DIRECTORIES(${PROJ_SOURCE_DIR}/src)

  FILE( GLOB SRCS [^.]*.cpp [^.]*.cxx)
  FILE( GLOB HPPS [^.]*.hpp [^.]*.h)
  
  INCLUDE_DIRECTORIES(${PROJ_SOURCE_DIR} ${PROJ_BINARY_DIR}/src/bindings/rtt
      ${OROCOS_RTT_INCLUDE_DIRS} ${OROCOS_INSTALL}/include/rtt /usr/include/orbsvcs)
  ADD_DEFINITIONS(-D_REENTRANT)
  INCLUDE_DIRECTORIES(/usr/include/orbsvcs /usr/include/rtt)
  ADD_LIBRARY(orocos-kdltk-${OROCOS_TARGET} SHARED ${SRCS})
  SET_TARGET_PROPERTIES(orocos-kdltk-${OROCOS_TARGET} PROPERTIES
  SOVERSION "${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}" 
  VERSION "${KDL_VERSION}") 
  INSTALL_TARGETS( /lib/rtt/${OROCOS_TARGET}/plugins orocos-kdltk-${OROCOS_TARGET})
  INSTALL_FILES( /include/kdl/bindings/rtt FILES ${HPPS})
  TARGET_LINK_LIBRARIES(orocos-kdltk-${OROCOS_TARGET} orocos-kdl orocos-rtt-${OROCOS_TARGET})

  CONFIGURE_FILE( kdltk.pc.in src/bindings/rtt/orocos-kdltk-${OROCOS_TARGET}.pc @ONLY)
  INSTALL_FILES( /lib/pkgconfig FILES orocos-kdltk-${OROCOS_TARGET}.pc)

  add_subdirectory(corba)

ENDIF( OROCOS_PLUGIN )
