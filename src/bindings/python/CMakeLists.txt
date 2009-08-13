include(SIPMacros)
IF (WIN32)
  SET(KDL_LIB     ${PROJ_BINARY_DIR}/src/kdl.dll)
ELSE (WIN32)
  IF (APPLE)
    SET(KDL_LIB   ${PROJ_BINARY_DIR}/src/liborocos-kdl.dylib)
  ELSE (APPLE)
    SET(KDL_LIB   ${PROJ_BINARY_DIR}/src/liborocos-kdl.so)
  ENDIF (APPLE)
ENDIF (WIN32)

include_directories(
  ${SIP_INCLUDE_DIR}
  ${PYTHON_INCLUDE_PATH}
  ${CMAKE_SOURCE_DIR}/src
  ${EIGEN2_INCLUDE_DIR})

file(GLOB SIP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.sip")
set(SIP_INCLUDES ${SIP_FILES})
add_sip_python_module(PyKDL ./PyKDL.sip orocos-kdl)
#set(SIP_EXTRA_FILES_DEPEND ${SIP_FILES})
