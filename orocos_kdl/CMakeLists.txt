#
# Test CMake version
#
CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
#MARK_AS_ADVANCED( FORCE CMAKE_BACKWARDS_COMPATIBILITY )


###################################################
#                                                 #
#       Start project customization section       #
#                                                 #
###################################################

PROJECT(orocos_kdl)

SET( KDL_VERSION 1.5.1)
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
if(NOT EIGEN3_FOUND OR NOT TARGET Eigen3::Eigen)
  include(${PROJ_SOURCE_DIR}/cmake/FindEigen3.cmake)
endif()

if(NOT TARGET Eigen3::Eigen)
  message(FATAL_ERROR "Eigen3 NOT FOUND")
endif()

SET(KDL_CFLAGS "${KDL_CFLAGS} -I${EIGEN3_INCLUDE_DIR}")

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

# Configuration variables
set(orocos_kdl_TARGETS_EXPORT_NAME "OrocosKDLTargets")
set(orocos_kdl_VERSION_CONFIG_FILENAME "${PROJECT_NAME}-config-version.cmake")
set(orocos_kdl_CONFIG_FILENAME "${PROJECT_NAME}-config.cmake")

ADD_SUBDIRECTORY( doc )
ADD_SUBDIRECTORY( src )
ADD_SUBDIRECTORY( tests )
ADD_SUBDIRECTORY( models )
ADD_SUBDIRECTORY( examples )

# Generate CMake package configuration
include(CMakePackageConfigHelpers)

set(orocos_kdl_CMAKE_INSTALL_SUFFIX share/orocos_kdl/cmake)

configure_package_config_file(orocos_kdl-config.cmake.in ${orocos_kdl_CONFIG_FILENAME}
                              INSTALL_DESTINATION ${orocos_kdl_CMAKE_INSTALL_SUFFIX})
write_basic_package_version_file(${orocos_kdl_VERSION_CONFIG_FILENAME}
                                 VERSION ${KDL_VERSION}
                                 COMPATIBILITY AnyNewerVersion)
                                 
INSTALL(FILES cmake/FindEigen3.cmake 
              ${CMAKE_CURRENT_BINARY_DIR}/${orocos_kdl_CONFIG_FILENAME}
              ${CMAKE_CURRENT_BINARY_DIR}/${orocos_kdl_VERSION_CONFIG_FILENAME}
        DESTINATION ${orocos_kdl_CMAKE_INSTALL_SUFFIX})
INSTALL(EXPORT OrocosKDLTargets DESTINATION ${orocos_kdl_CMAKE_INSTALL_SUFFIX})

# Generate pkg-config package configuration
CONFIGURE_FILE(orocos_kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc @ONLY)
CONFIGURE_FILE(orocos_kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos_kdl.pc @ONLY)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc DESTINATION lib${LIB_SUFFIX}/pkgconfig)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/orocos_kdl.pc DESTINATION lib${LIB_SUFFIX}/pkgconfig)
