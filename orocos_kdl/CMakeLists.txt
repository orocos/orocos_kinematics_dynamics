#
# Test CMake version
#
CMAKE_MINIMUM_REQUIRED(VERSION 3.12.0)


###################################################
#                                                 #
#       Start project customization section       #
#                                                 #
###################################################

PROJECT(orocos_kdl)

SET(KDL_VERSION 1.5.2)
STRING( REGEX MATCHALL "[0-9]+" KDL_VERSIONS ${KDL_VERSION} )
LIST( GET KDL_VERSIONS 0 KDL_VERSION_MAJOR)
LIST( GET KDL_VERSIONS 1 KDL_VERSION_MINOR)
LIST( GET KDL_VERSIONS 2 KDL_VERSION_PATCH)

MESSAGE( STATUS "Orocos KDL version ${VERSION} (${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}.${KDL_VERSION_PATCH})" )

SET( PROJ_SOURCE_DIR ${orocos_kdl_SOURCE_DIR} )
SET( PROJ_BINARY_DIR ${orocos_kdl_BINARY_DIR} )

# catkin-specific configuration (optional)
find_package(catkin QUIET)
if(catkin_FOUND)
  catkin_package(
    SKIP_CMAKE_CONFIG_GENERATION
    SKIP_PKG_CONFIG_GENERATION
  )
endif()

IF(NOT CMAKE_INSTALL_PREFIX)
  SET( CMAKE_INSTALL_PREFIX /usr/local/ CACHE PATH "Installation directory" FORCE)
  MESSAGE( STATUS "Setting installation directory to ${CMAKE_INSTALL_PREFIX}" )
ENDIF(NOT CMAKE_INSTALL_PREFIX)

SET(CMAKE_VERSION "${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}")


IF ( NOT CMAKE_BUILD_TYPE )
  SET(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
  MESSAGE( STATUS "Setting build type to '${CMAKE_BUILD_TYPE}'" )
ELSE ( NOT CMAKE_BUILD_TYPE )
  MESSAGE( STATUS "Build type set to '${CMAKE_BUILD_TYPE}' by user." )
ENDIF ( NOT CMAKE_BUILD_TYPE )

SET( KDL_CFLAGS "")

find_package(Eigen3 QUIET)
if(NOT EIGEN3_FOUND)
  include(${PROJ_SOURCE_DIR}/cmake/FindEigen3.cmake)
endif()
include_directories(${EIGEN3_INCLUDE_DIR})
SET(KDL_CFLAGS "${KDL_CFLAGS} -I\"${EIGEN3_INCLUDE_DIR}\"")

# Check the platform STL containers capabilities
include(cmake/CheckSTLContainers.cmake)
CHECK_STL_CONTAINERS()

# Set the default option appropriately
if(HAVE_STL_CONTAINER_INCOMPLETE_TYPES)
    set(KDL_USE_NEW_TREE_INTERFACE_DEFAULT OFF)
else(HAVE_STL_CONTAINER_INCOMPLETE_TYPES)
    set(KDL_USE_NEW_TREE_INTERFACE_DEFAULT ON)
endif(HAVE_STL_CONTAINER_INCOMPLETE_TYPES)

# Allow the user to select the Tree API version to use
set(KDL_USE_NEW_TREE_INTERFACE ${KDL_USE_NEW_TREE_INTERFACE_DEFAULT} CACHE BOOL "Use the new KDL Tree interface")

#Sanity check, inform the user
if(NOT HAVE_STL_CONTAINER_INCOMPLETE_TYPES AND NOT KDL_USE_NEW_TREE_INTERFACE)
    message(WARNING "You have chosen to use the current Tree Interface, but your platform doesn't support containers of "
        "incomplete types, this configuration is likely invalid")
endif()

# The new interface requires the use of shared pointers
if(KDL_USE_NEW_TREE_INTERFACE)
    # We need shared_ptr from boost since not all compilers are c++11 capable
    find_package(Boost REQUIRED)
    include_directories(${Boost_INCLUDE_DIRS})
endif(KDL_USE_NEW_TREE_INTERFACE)

OPTION(ENABLE_TESTS OFF "Enable building of tests")
IF( ENABLE_TESTS )
  # If not in standard paths, set CMAKE_xxx_PATH's in environment, eg.
  # export CMAKE_INCLUDE_PATH=/opt/local/include
  # export CMAKE_LIBRARY_PATH=/opt/local/lib
  FIND_LIBRARY(CPPUNIT cppunit)
  SET(CPPUNIT ${CPPUNIT} "dl")
  FIND_PATH(CPPUNIT_HEADERS cppunit/TestRunner.h)
  IF ( CPPUNIT AND CPPUNIT_HEADERS)
    MESSAGE( STATUS "-- Looking for Cppunit - found")
  ELSE ( CPPUNIT AND CPPUNIT_HEADERS )
    MESSAGE( FATAL_ERROR "-- Looking for Cppunit - not found")
  ENDIF ( CPPUNIT AND CPPUNIT_HEADERS )
ENDIF(ENABLE_TESTS )

OPTION(ENABLE_EXAMPLES OFF "Enable building of examples")

ADD_SUBDIRECTORY( doc )
ADD_SUBDIRECTORY( src )
ADD_SUBDIRECTORY( tests )
ADD_SUBDIRECTORY( models )
ADD_SUBDIRECTORY( examples )


export(TARGETS orocos-kdl
  FILE "${PROJECT_BINARY_DIR}/OrocosKDLTargets.cmake")

export(PACKAGE orocos_kdl)

# Generate CMake package configuration
CONFIGURE_FILE(orocos_kdl-config.cmake.in
  ${PROJECT_BINARY_DIR}/orocos_kdl-config.cmake @ONLY)
CONFIGURE_FILE(orocos_kdl-config-version.cmake.in
  ${PROJECT_BINARY_DIR}/orocos_kdl-config-version.cmake @ONLY)

# Create necessary directories for installation
INSTALL(DIRECTORY DESTINATION share/orocos_kdl/cmake)
INSTALL(DIRECTORY DESTINATION lib${LIB_SUFFIX}/pkgconfig)

INSTALL(FILES cmake/FindEigen3.cmake DESTINATION share/orocos_kdl/cmake COMPONENT Development)
INSTALL(FILES ${PROJECT_BINARY_DIR}/orocos_kdl-config.cmake DESTINATION share/orocos_kdl/cmake COMPONENT Development)
INSTALL(FILES ${PROJECT_BINARY_DIR}/orocos_kdl-config-version.cmake DESTINATION share/orocos_kdl/cmake COMPONENT Development)
INSTALL(EXPORT OrocosKDLTargets DESTINATION share/orocos_kdl/cmake COMPONENT Development)

# Generate pkg-config package configuration
CONFIGURE_FILE(orocos_kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc @ONLY)
CONFIGURE_FILE(orocos_kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos_kdl.pc @ONLY)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc DESTINATION lib${LIB_SUFFIX}/pkgconfig COMPONENT Development)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/orocos_kdl.pc DESTINATION lib${LIB_SUFFIX}/pkgconfig COMPONENT Development)

# Detect target architecture for multi-platform builds
if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
    set(TARGET_ARCHITECTURE "arm64")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64")
    set(TARGET_ARCHITECTURE "amd64")
else()
    # Default fallback
    set(TARGET_ARCHITECTURE "amd64")
endif()

# Allow override from environment variable (useful for cross-compilation)
if(DEFINED ENV{TARGET_ARCH})
    set(TARGET_ARCHITECTURE $ENV{TARGET_ARCH})
endif()

message(STATUS "Target architecture: ${TARGET_ARCHITECTURE}")

# CPack configuration for Debian packages
set(CPACK_PACKAGE_NAME "liborocos-kdl")
set(CPACK_PACKAGE_VERSION_MAJOR ${KDL_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${KDL_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${KDL_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION "${KDL_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Kinematics and Dynamics Library")
set(CPACK_PACKAGE_DESCRIPTION "The Kinematics and Dynamics Library (KDL) develops an application independent framework for modelling and computation of kinematic chains, such as robots, biomechanical human models, computer-animated figures, machine tools, etc.")
set(CPACK_PACKAGE_VENDOR "Orocos")
set(CPACK_PACKAGE_CONTACT "orocos-dev@lists.mech.kuleuven.be")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://orocos.org/kdl")

# Debian-specific settings
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Orocos Developers <orocos-dev@lists.mech.kuleuven.be>")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "${TARGET_ARCHITECTURE}")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "${CPACK_PACKAGE_HOMEPAGE_URL}")

# Enable component-based packaging
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_COMPONENTS_ALL Runtime Development)

# Runtime component (shared libraries)
set(CPACK_COMPONENT_RUNTIME_DISPLAY_NAME "Orocos KDL Runtime Libraries")
set(CPACK_COMPONENT_RUNTIME_DESCRIPTION "Runtime libraries for Orocos KDL")
set(CPACK_DEBIAN_RUNTIME_PACKAGE_NAME "liborocos-kdl")
set(CPACK_DEBIAN_RUNTIME_PACKAGE_DEPENDS "libc6")
set(CPACK_DEBIAN_RUNTIME_PACKAGE_SECTION "libs")
set(CPACK_DEBIAN_RUNTIME_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_RUNTIME_FILE_NAME "liborocos-kdl_${CPACK_PACKAGE_VERSION}_${TARGET_ARCHITECTURE}.deb")

# Development component (headers, cmake files)
set(CPACK_COMPONENT_DEVELOPMENT_DISPLAY_NAME "Orocos KDL Development Files")
set(CPACK_COMPONENT_DEVELOPMENT_DESCRIPTION "Development files for Orocos KDL")
set(CPACK_DEBIAN_DEVELOPMENT_PACKAGE_NAME "liborocos-kdl-dev")
set(CPACK_DEBIAN_DEVELOPMENT_PACKAGE_DEPENDS "liborocos-kdl (= ${CPACK_PACKAGE_VERSION}), libeigen3-dev")
set(CPACK_DEBIAN_DEVELOPMENT_PACKAGE_SECTION "libdevel")
set(CPACK_DEBIAN_DEVELOPMENT_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_DEVELOPMENT_FILE_NAME "liborocos-kdl-dev_${CPACK_PACKAGE_VERSION}_${TARGET_ARCHITECTURE}.deb")

# Source package
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
set(CPACK_SOURCE_IGNORE_FILES "/build/;/.git/;/.gitignore;/CMakeCache.txt;/CMakeFiles/;/Makefile;/cmake_install.cmake;/_CPack_Packages/;/.DS_Store")

include(CPack)
