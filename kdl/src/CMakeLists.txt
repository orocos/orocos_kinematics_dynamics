FILE( GLOB_RECURSE KDL_SRCS [^.]*.cpp [^.]*.cxx)
FILE( GLOB KDL_HPPS [^.]*.hpp [^.]*.inl)

FILE( GLOB UTIL_HPPS utilities/[^.]*.h utilities/[^.]*.hpp)
ADD_LIBRARY(orocos-kdl SHARED ${KDL_SRCS})
SET_TARGET_PROPERTIES( orocos-kdl PROPERTIES
  SOVERSION "${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}"
  VERSION "${KDL_VERSION}"
  COMPILE_FLAGS "${CMAKE_CXX_FLAGS_ADD} ${KDL_CFLAGS}"
  INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
  PUBLIC_HEADER "${KDL_HPPS}"
  )

INSTALL(TARGETS orocos-kdl
  EXPORT orocos-kdl-targets
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include/kdl
)

# CMake 2.2:
#INSTALL_FILES( /include/kdl FILES ${KDL_HPPS})
INSTALL(FILES ${UTIL_HPPS} DESTINATION include/kdl/utilities)

# Orocos convention:
CONFIGURE_FILE( orocos-kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc @ONLY)
CONFIGURE_FILE( orocos-kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos_kdl.pc @ONLY)

INSTALL_FILES( /lib/pkgconfig FILES ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc)
INSTALL_FILES( /lib/pkgconfig FILES ${CMAKE_CURRENT_BINARY_DIR}/orocos_kdl.pc)
