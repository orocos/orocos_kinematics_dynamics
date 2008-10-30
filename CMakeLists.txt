#
# Test CMake version
#
CMAKE_MINIMUM_REQUIRED(VERSION 2.2)
#MARK_AS_ADVANCED( FORCE CMAKE_BACKWARDS_COMPATIBILITY )

# for CMake 2.6 corrected behaviour (see "cmake --help-policy CMP0003")
IF(COMMAND cmake_policy AND ${CMAKE_MAJOR_VERSION} EQUAL 2 AND ${CMAKE_MINOR_VERSION} GREATER 4)
  CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND cmake_policy AND ${CMAKE_MAJOR_VERSION} EQUAL 2 AND ${CMAKE_MINOR_VERSION} GREATER 4)

###################################################
#                                                 #
#       Start project customization section       #
#                                                 #
###################################################

PROJECT(Orocos-KDL)

SET( KDL_VERSION 1.0.0 CACHE STRING "Version of Orocos KDL" )
STRING( REGEX MATCHALL "[0-9]+" KDL_VERSIONS ${KDL_VERSION} )
LIST( GET KDL_VERSIONS 0 KDL_VERSION_MAJOR)
LIST( GET KDL_VERSIONS 1 KDL_VERSION_MINOR)
LIST( GET KDL_VERSIONS 2 KDL_VERSION_PATCH)

SET(KDL_VERSION_PATCH "${KDL_VERSION_PATCH}")
MESSAGE( "Orocos KDL version ${VERSION} (${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}.${KDL_VERSION_PATCH})" )

SET( PROJ_SOURCE_DIR ${Orocos-KDL_SOURCE_DIR} )
SET( PROJ_BINARY_DIR ${Orocos-KDL_BINARY_DIR} )


IF(NOT CMAKE_INSTALL_PREFIX)
  SET( CMAKE_INSTALL_PREFIX /usr/local/orocos CACHE PATH "Installation directory" FORCE)
  MESSAGE( STATUS "Setting installation directory to ${CMAKE_INSTALL_PREFIX}" )
ENDIF(NOT CMAKE_INSTALL_PREFIX)

SET(CMAKE_VERSION "${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}")


IF ( NOT CMAKE_BUILD_TYPE )
  SET( CMAKE_BUILD_TYPE "RTT" CACHE STRING "Build type: None (Use CMAKE_C_FLAGS and CMAKE_CXX_FLAGS), RTT (Recommended), Release, Debug, RelWithDebInfo, MinSizeRel." FORCE )
  MESSAGE( "Setting build type to '${CMAKE_BUILD_TYPE}'" )
  SET( CMAKE_C_FLAGS_RTT "-O2 -DNDEBUG" CACHE STRING "The CFLAGS for RTT" )
  SET( CMAKE_CXX_FLAGS_RTT "-O2 -DNDEBUG" CACHE STRING "The CXXFLAGS flags for RTT"  )
ELSE ( NOT CMAKE_BUILD_TYPE )
  MESSAGE( "Build type set to '${CMAKE_BUILD_TYPE}' by user." )
  IF ( NOT CMAKE_BUILD_TYPE STREQUAL "RTT" )
    MARK_AS_ADVANCED(FORCE CMAKE_C_FLAGS_RTT CMAKE_CXX_FLAGS_RTT)
  ELSE ( NOT CMAKE_BUILD_TYPE STREQUAL "RTT" )
    MARK_AS_ADVANCED(CLEAR CMAKE_C_FLAGS_RTT CMAKE_CXX_FLAGS_RTT)
  ENDIF ( NOT CMAKE_BUILD_TYPE STREQUAL "RTT" )
ENDIF ( NOT CMAKE_BUILD_TYPE )

OPTION( OROCOS_PLUGIN "Build Orocos-plugin?" OFF)
IF( OROCOS_PLUGIN )
  SET( RTT_VVERSION "v1.4.x" )
  IF(NOT OROCOS_INSTALL)
    SET( OROCOS_INSTALL /usr CACHE PATH "The RTT installation directory.")
  ENDIF(NOT OROCOS_INSTALL)
  INCLUDE (${PROJ_SOURCE_DIR}/config/FindOrocosRTT.cmake)
  IF (OROCOS_RTT_1.4)
    SET( CMAKE_C_FLAGS_RTT "-O2 -DNDEBUG ${OROCOS_RTT_DEFINES}")
    SET( CMAKE_CXX_FLAGS_RTT "-O2 -DNDEBUG ${OROCOS_RTT_DEFINES}")
    MESSAGE( "CMAKE_CXX_FLAGS_RTT are : ${CMAKE_CXX_FLAGS_RTT}" )
  ENDIF (OROCOS_RTT_1.4)
ENDIF( OROCOS_PLUGIN )

INCLUDE (${PROJ_SOURCE_DIR}/config/DependentOption.cmake)

OPTION( PYTHON_BINDINGS "Build python-bindings?" OFF)

INCLUDE (${PROJ_SOURCE_DIR}/config/FindSIPandPython.cmake)
DEPENDENT_OPTION( ENABLE_CORBA "Enable CORBA (using TAO)" ON "ACE_CONFIG AND TAO_ORB AND TAO_ORBSVCS AND CORBA_ENABLED" OFF)

OPTION(ENABLE_TESTS OFF "Enable building of tests")

ADD_SUBDIRECTORY( doc )
ADD_SUBDIRECTORY( src )
ADD_SUBDIRECTORY( tests )

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

############################################################
##                                                         #
## Setup PACKAGING                                         #
##                                                         #
############################################################

IF ( "${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" STREQUAL "2.4" )
OPTION( CPACK_PACKAGES "Set to ON to build the packages. Requires cmake >2.4" OFF )
IF (CPACK_PACKAGES)

INCLUDE(InstallRequiredSystemLibraries)

# ATTENTION: There is sometimes a _SOURCE_ version of an
# option as well, set both if necessary !

# Create .tar.gz and .tar.tbz2 files:
SET(CPACK_GENERATOR "TBZ2")
SET(CPACK_SOURCE_GENERATOR "TBZ2")

# The plain 'package' target works correctly.
SET(CPACK_IGNORE_FILES        "/CVS/;/.svn/;.swp$;.#;/#;/build/")
# Since the 'package_source' target does a bold copy, define a list of
# files which should be excluded. Note that 'subpattern' matching is used,
# thus to exclude a directory use /mydir/
SET(CPACK_SOURCE_IGNORE_FILES "/CVS/;/.svn/;.swp$;.#;/#;/build/;~")

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Orocos KDL")
SET(CPACK_PACKAGE_VENDOR "The Orocos Community")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
SET(CPACK_PACKAGE_VERSION_MAJOR "${KDL_VERSION_MAJOR}")
SET(CPACK_PACKAGE_VERSION_MINOR "${KDL_VERSION_MINOR}")
SET(CPACK_PACKAGE_VERSION_PATCH "${KDL_VERSION_PATCH}")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMAKE ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}")
SET(CPACK_STRIP_FILES "bin/cmake")
#SET(CPACK_PACKAGE_EXECUTABLES "OrocosExec" "Orocos Executable")
INCLUDE(CPack)
ENDIF (CPACK_PACKAGES)
ELSE ( "${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" STREQUAL "2.4" )

   MESSAGE ( "Disabling packaging for version ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}")

ENDIF ( "${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" STREQUAL "2.4" )
