################################################################################
#
# CMake script for finding An Orocos RTT Plugin in case you require it during build time.
# If the optional OROCOS_ROOT_DIR environment variable exists, header files and
# libraries will be searched in the OROCOS_ROOT_DIR/include and OROCOS_ROOT_DIR/lib/orocos/plugins
# directories, respectively. Otherwise the default CMake search process will be
# used.
#
# Usage: find_package( RTTPlugin COMPONENTS rtt-scripting )
#
# This script creates the following variables:
#  RTT_PLUGIN_<COMPONENT>_FOUND: Boolean that indicates if the plugin was found
#  RTT_PLUGIN_<COMPONENT>_INCLUDE_DIRS: Path to the plugin header files (equal to OROCOS_RTT_INCLUDE_DIRS)
#  RTT_PLUGIN_<COMPONENT>_LIBRARIES: Plugin library
#
################################################################################

include(LibFindMacros)

# Get hint from environment variable (if any)
if(NOT $ENV{OROCOS_ROOT_DIR} STREQUAL "")
  set(OROCOS_ROOT_DIR $ENV{OROCOS_ROOT_DIR} CACHE PATH "Xenomai base directory location (optional, used for nonstandard installation paths)" FORCE)
  mark_as_advanced(OROCOS_ROOT_DIR)
endif()


FOREACH(COMPONENT ${RTTPlugin_FIND_COMPONENTS})
    set(PLUGIN_NAME   ${COMPONENT} ${COMPONENT}-${OROCOS_TARGET} )
    #STRING(TOUPPER ${COMPONENT} COMPONENT)

    set(RTT_PLUGIN_${COMPONENT}_INCLUDE_DIR ${OROCOS_RTT_INCLUDE_DIRS} )
    # Find plugins
    if(OROCOS_ROOT_DIR)
        # Use location specified by environment variable
        find_library(RTT_PLUGIN_${COMPONENT}_LIBRARY
            NAMES ${PLUGIN_NAME}
            PATHS ${OROCOS_ROOT_DIR}/lib
            PATH_SUFFIXES orocos/plugins orocos/plugins/${OROCOS_TARGET}
                orocos/types orocos/types/${OROCOS_TARGET}  NO_DEFAULT_PATH)
    else()
        # Use default CMake search process
        find_library(RTT_PLUGIN_${COMPONENT}_LIBRARY
            NAMES ${PLUGIN_NAME}
            PATHS ${OROCOS_INSTALL}/lib
            PATH_SUFFIXES orocos/types orocos/types/${OROCOS_TARGET}
                orocos/plugins orocos/plugins/${OROCOS_TARGET})
    endif()

    # Set the include dir variables and the libraries and let libfind_process do the rest.
    # NOTE: Singular variables for this library, plural for libraries this this lib depends on.
    set(RTT_PLUGIN_${COMPONENT}_PROCESS_INCLUDES RTT_PLUGIN_${COMPONENT}_INCLUDE_DIR )
    set(RTT_PLUGIN_${COMPONENT}_PROCESS_LIBS     RTT_PLUGIN_${COMPONENT}_LIBRARY )

    libfind_process( RTT_PLUGIN_${COMPONENT} )
    
ENDFOREACH(COMPONENT)

