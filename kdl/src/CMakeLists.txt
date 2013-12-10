FILE( GLOB_RECURSE KDL_SRCS [^.]*.cpp [^.]*.cxx)
FILE( GLOB KDL_HPPS [^.]*.hpp [^.]*.inl)

FILE( GLOB UTIL_HPPS utilities/[^.]*.h utilities/[^.]*.hpp)

#In Windows (Visual Studio) it is necessary to specify the postfix
#of the debug library name and no symbols are exported by kdl, 
#so it is necessary to compile it as a static library
IF(MSVC)
    SET(CMAKE_DEBUG_POSTFIX "d")
    SET(LIB_TYPE STATIC)
ELSE(MSVC)
    SET(LIB_TYPE SHARED)
ENDIF(MSVC)

ADD_LIBRARY(orocos-kdl ${LIB_TYPE} ${KDL_SRCS})
 
SET_TARGET_PROPERTIES( orocos-kdl PROPERTIES
  SOVERSION "${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}"
  VERSION "${KDL_VERSION}"
  COMPILE_FLAGS "${CMAKE_CXX_FLAGS_ADD} ${KDL_CFLAGS}"
  INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
  PUBLIC_HEADER "${KDL_HPPS}"
  )

INSTALL(TARGETS orocos-kdl
  EXPORT OrocosKDLTargets
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include/kdl
)

# CMake 2.2:
#INSTALL_FILES( /include/kdl FILES ${KDL_HPPS})
INSTALL(FILES ${UTIL_HPPS} DESTINATION include/kdl/utilities)

# Orocos convention:
CONFIGURE_FILE( kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc @ONLY)
CONFIGURE_FILE( kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos_kdl.pc @ONLY)

INSTALL_FILES( /lib/pkgconfig FILES ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc)
INSTALL_FILES( /lib/pkgconfig FILES ${CMAKE_CURRENT_BINARY_DIR}/orocos_kdl.pc)
