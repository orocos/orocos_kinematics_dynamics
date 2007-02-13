PROJECT(KDL)

SET( VERSION 0.2 CACHE STRING "Version of KinDynLibrary" )

SET( PROJ_SOURCE_DIR ${KDL_SOURCE_DIR} )
SET( PROJ_BINARY_DIR ${KDL_BINARY_DIR} )

IF ( NOT CMAKE_BUILD_TYPE )
  SET( CMAKE_BUILD_TYPE Release )
  MESSAGE( STATUS "Setting build type to '${CMAKE_BUILD_TYPE}'" )
ELSE ( NOT CMAKE_BUILD_TYPE )
  MESSAGE( STATUS "Build type set to '${CMAKE_BUILD_TYPE}' by user." )
ENDIF ( NOT CMAKE_BUILD_TYPE )

OPTION( OROCOS_PLUGIN "Build Orocos-plugin?" OFF)
IF( OROCOS_PLUGIN )
  IF(NOT OROCOS_INSTALL)
    SET( OROCOS_INSTALL /usr/local/orocos CACHE PATH "The RTT installation directory.")
  ENDIF(NOT OROCOS_INSTALL)
  INCLUDE (${KDL_SOURCE_DIR}/config/FindOrocosRTT.cmake)
ENDIF( OROCOS_PLUGIN )

OPTION( BUILD_TESTS "Turn me off to disable compilation of all tests" ON )

ADD_SUBDIRECTORY( doc )
ADD_SUBDIRECTORY( kdl )
ADD_SUBDIRECTORY( tests )

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

