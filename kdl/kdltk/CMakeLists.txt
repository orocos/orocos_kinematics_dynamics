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

  CONFIGURE_FILE( kdltk.hpp.in kdl/kdltk/kdltk.hpp)
  INSTALL_FILES( /include/kdl/ FILES kdltk.hpp)
  INCLUDE_DIRECTORIES(${KDL_SOURCE_DIR}/kdl/kdltk)

  FILE( GLOB SRCS [^.]*.c* )
  FILE( GLOB HPPS [^.]*.h*[^.in] )
  
  INCLUDE_DIRECTORIES(${KDL_SOURCE_DIR} ${KDL_BINARY_DIR})
  ADD_LIBRARY(kdltk STATIC ${SRCS}) 
  INSTALL_TARGETS( /lib kdltk)
  INSTALL_FILES( /include/kdl/ FILES ${HPPS})

  CONFIGURE_FILE( kdltk.pc.in kdl/kdltk/kdltk.pc @ONLY)
  INSTALL_FILES( /lib/pkgconfig FILES kdltk.pc)
  
ENDIF( OROCOS_PLUGIN )
