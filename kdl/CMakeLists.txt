#
# Test CMake version
#
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
#MARK_AS_ADVANCED( FORCE CMAKE_BACKWARDS_COMPATIBILITY )


###################################################
#                                                 #
#       Start project customization section       #
#                                                 #
###################################################

PROJECT(Orocos-KDL)

SET( KDL_VERSION 1.2.2 CACHE STRING "Version of Orocos KDL" )
STRING( REGEX MATCHALL "[0-9]+" KDL_VERSIONS ${KDL_VERSION} )
LIST( GET KDL_VERSIONS 0 KDL_VERSION_MAJOR)
LIST( GET KDL_VERSIONS 1 KDL_VERSION_MINOR)
LIST( GET KDL_VERSIONS 2 KDL_VERSION_PATCH)

SET(KDL_VERSION_PATCH "${KDL_VERSION_PATCH}")
MESSAGE( "Orocos KDL version ${VERSION} (${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}.${KDL_VERSION_PATCH})" )

SET( PROJ_SOURCE_DIR ${Orocos-KDL_SOURCE_DIR} )
SET( PROJ_BINARY_DIR ${Orocos-KDL_BINARY_DIR} )


IF(NOT CMAKE_INSTALL_PREFIX)
  SET( CMAKE_INSTALL_PREFIX /usr/local/ CACHE PATH "Installation directory" FORCE)
  MESSAGE( STATUS "Setting installation directory to ${CMAKE_INSTALL_PREFIX}" )
ENDIF(NOT CMAKE_INSTALL_PREFIX)

SET(CMAKE_VERSION "${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}")


IF ( NOT CMAKE_BUILD_TYPE )
  SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
  MESSAGE( "Setting build type to '${CMAKE_BUILD_TYPE}'" )
ELSE ( NOT CMAKE_BUILD_TYPE )
  MESSAGE( "Build type set to '${CMAKE_BUILD_TYPE}' by user." )
ENDIF ( NOT CMAKE_BUILD_TYPE )

SET( KDL_CFLAGS "")

find_package(Eigen 3.0 QUIET)
if(NOT Eigen_FOUND)
  include(${PROJ_SOURCE_DIR}/config/FindEigen3.cmake)
  set(Eigen_INCLUDE_DIR ${EIGEN3_INCLUDE_DIR})
endif()
include_directories(${Eigen_INCLUDE_DIR})
SET(KDL_CFLAGS "${KDL_CFLAGS} -I${Eigen_INCLUDE_DIR}")

INCLUDE (${PROJ_SOURCE_DIR}/config/DependentOption.cmake)

OPTION(ENABLE_TESTS OFF "Enable building of tests")
IF( ENABLE_TESTS )
  # If not in standard paths, set CMAKE_xxx_PATH's in environment, eg.
  # export CMAKE_INCLUDE_PATH=/opt/local/include
  # export CMAKE_LIBRARY_PATH=/opt/local/lib
  FIND_LIBRARY(CPPUNIT cppunit)
  SET(CPPUNIT ${CPPUNIT} "dl")
  FIND_PATH(CPPUNIT_HEADERS cppunit/TestRunner.h)
  IF ( CPPUNIT AND CPPUNIT_HEADERS)
    MESSAGE("-- Looking for Cppunit - found")
  ELSE ( CPPUNIT AND CPPUNIT_HEADERS )
    MESSAGE( FATAL_ERROR "-- Looking for Cppunit - not found")
  ENDIF ( CPPUNIT AND CPPUNIT_HEADERS )
ENDIF(ENABLE_TESTS )

OPTION(ENABLE_EXAMPLES OFF "Enable building of examples")

add_definitions(-DEIGEN2_SUPPORT)

ADD_SUBDIRECTORY( doc )
ADD_SUBDIRECTORY( src )
ADD_SUBDIRECTORY( tests )
ADD_SUBDIRECTORY( examples )
ADD_SUBDIRECTORY( models )

export(TARGETS orocos-kdl
  FILE "${PROJECT_BINARY_DIR}/orocos-kdl-targets.cmake")

export(PACKAGE kdl)

set(KDL_INCLUDE_DIRS ${Eigen_INCLUDE_DIR})

CONFIGURE_FILE(
  ${CMAKE_CURRENT_SOURCE_DIR}/orocos-kdl-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl-config.cmake @ONLY)

CONFIGURE_FILE(
  ${CMAKE_CURRENT_SOURCE_DIR}/orocos-kdl-config-version.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl-config-version.cmake @ONLY)

INSTALL(FILES ${PROJECT_BINARY_DIR}/orocos-kdl-config.cmake DESTINATION share/orocos-kdl)
INSTALL(FILES ${PROJECT_BINARY_DIR}/orocos-kdl-config-version.cmake DESTINATION share/orocos-kdl)
INSTALL(EXPORT orocos-kdl-targets DESTINATION share/orocos-kdl)

INSTALL(FILES package.xml DESTINATION share/kdl)
