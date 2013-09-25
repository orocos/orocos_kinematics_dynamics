cmake_minimum_required(VERSION 2.8.3)

FILE( GLOB KDL_SRCS [^.]*.cpp )
FILE( GLOB KDL_HPPS [^.]*.hpp [^.]*.inl)

FILE( GLOB UTIL_SRCS utilities/[^.]*.cpp utilities/[^.]*.cxx)
FILE( GLOB UTIL_HPPS utilities/[^.]*.h utilities/[^.]*.hpp)

ADD_LIBRARY(orocos-kdl SHARED ${KDL_SRCS} ${UTIL_SRCS})
SET_TARGET_PROPERTIES( orocos-kdl PROPERTIES
  SOVERSION "${KDL_VERSION_MAJOR}.${KDL_VERSION_MINOR}"
  VERSION "${KDL_VERSION}"
  COMPILE_FLAGS "${CMAKE_CXX_FLAGS_ADD} ${KDL_CFLAGS}"
  INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")

INSTALL(TARGETS orocos-kdl
  LIBRARY DESTINATION lib)

INSTALL(
  FILES ${KDL_HPPS}
  DESTINATION include/kdl)
INSTALL(
  FILES ${UTIL_HPPS}
  DESTINATION include/kdl/utilities)

# Orocos convention:
CONFIGURE_FILE( orocos-kdl.pc.in ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc @ONLY)

INSTALL(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/orocos-kdl.pc
  DESTINATION lib/pkgconfig)
