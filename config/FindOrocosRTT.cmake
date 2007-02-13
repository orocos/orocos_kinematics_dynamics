# Locate Orocos::RTT install directory

# This module defines
# OROCOS_RTT_HOME where to find include, lib, bin, etc.
# OROCOS_RTT_FOUND, is set to true

INCLUDE (${KDL_SOURCE_DIR}/config/FindPkgConfig.cmake)

IF ( CMAKE_PKGCONFIG_EXECUTABLE )

    MESSAGE( "Using pkgconfig" )
    
    SET(ENV{PKG_CONFIG_PATH} "${OROCOS_INSTALL}/lib/pkgconfig:${OROCOS_INSTALL}/packages/install/lib/pkgconfig/")
    MESSAGE( "Setting environment of PKG_CONFIG_PATH to: $ENV{PKG_CONFIG_PATH}")
    PKGCONFIG( "orocos-rtt >= 1.0.0" OROCOS_RTT OROCOS_RTT_INCLUDE_DIRS OROCOS_RTT_DEFINES OROCOS_RTT_LINK_DIRS OROCOS_RTT_LIBS )

    IF( OROCOS_RTT )
        MESSAGE("   Includes in: ${OROCOS_RTT_INCLUDE_DIRS}")
        MESSAGE("   Libraries in: ${OROCOS_RTT_LINK_DIRS}")
        MESSAGE("   Libraries: ${OROCOS_RTT_LIBS}")
        MESSAGE("   Defines: ${OROCOS_RTT_DEFINES}")

	INCLUDE_DIRECTORIES( ${OROCOS_RTT_INCLUDE_DIRS} )
        LINK_DIRECTORIES( ${OROCOS_RTT_LINK_DIRS} )

    ELSE  ( OROCOS_RTT )
        MESSAGE( FATAL_ERROR "Can't find Orocos Real-Time Toolkit")
    ENDIF ( OROCOS_RTT )

ELSE  ( CMAKE_PKGCONFIG_EXECUTABLE )

    # Can't find pkg-config -- have to search manually
    MESSAGE( FATAL_ERROR "Can't find pkg-config ")

ENDIF ( CMAKE_PKGCONFIG_EXECUTABLE )
