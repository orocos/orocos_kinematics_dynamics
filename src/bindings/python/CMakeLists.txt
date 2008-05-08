IF (WIN32)
  SET(BINDINGS_LIBS ${CMAKE_CURRENT_BINARY_DIR}/PyKDL.pyd)
  SET(KDL_LIB     ${PROJ_BINARY_DIR}/src/kdl.dll)
ELSE (WIN32)
  SET(BINDINGS_LIBS ${CMAKE_CURRENT_BINARY_DIR}/PyKDL.so)
  IF (APPLE)
    SET(KDL_LIB   ${PROJ_BINARY_DIR}/src/liborocos-kdl.dylib)
  ELSE (APPLE)
    SET(KDL_LIB   ${PROJ_BINARY_DIR}/src/liborocos-kdl.so)
  ENDIF (APPLE)
ENDIF (WIN32)

SET (BINDINGS_MAKEFILE ${CMAKE_CURRENT_BINARY_DIR}/Makefile)

# 'python' target will force to build bindings libs for core and gui
ADD_CUSTOM_TARGET (python DEPENDS ${BINDINGS_LIBS})

# don't run python before the libs are built
ADD_DEPENDENCIES (python orocos-kdl)

TARGET_LINK_LIBRARIES(python orocos-kdl)

FILE(GLOB SIP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.sip")

# Step 1: during configuration
# create file configure.py from configure.py.in
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/configure.py.in
               ${CMAKE_CURRENT_BINARY_DIR}/configure.py)

# Step 2: during make
# run python configure.py
# it will run SIP utility to generate sources and will prepare makefiles
# should be run everytime core or gui library has been changed
ADD_CUSTOM_COMMAND(OUTPUT ${BINDINGS_MAKEFILE} PRE_BUILD
                   COMMAND ${PYTHON_EXECUTABLE}
                   ARGS ${CMAKE_CURRENT_BINARY_DIR}/configure.py
                   DEPENDS ${KDL_LIB} ${CMAKE_CURRENT_BINARY_DIR}/configure.py ${SIP_FILES})

ADD_CUSTOM_COMMAND(OUTPUT ${BINDINGS_LIBS} PRE_LINK
                   COMMAND ${CMAKE_MAKE_PROGRAM}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                   DEPENDS ${BINDINGS_MAKEFILE})

ADD_CUSTOM_COMMAND(TARGET python POST_BUILD
                   COMMAND ln ARGS -sf ${CMAKE_CURRENT_BINARY_DIR}/PyKDL.so ${CMAKE_BINARY_DIR}/tests/
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})


#IF (BINDINGS_GLOBAL_INSTALL)

# python's site-packages dir: bindings will be installed here
IF (UNIX)
  SET (CMD "
import sys
v = sys.version_info
print sys.exec_prefix + '/lib/python' + str(v[0]) + '.' + str(v[1]) + '/site-packages'
")
ELSE (UNIX)
  SET (CMD "
import sys
print sys.exec_prefix + '/lib/site-packages'
")
ENDIF (UNIX)

EXEC_PROGRAM(${PYTHON_EXECUTABLE} ARGS -c "\"${CMD}\"" OUTPUT_VARIABLE SITE_PKG_PATH)

#ELSE (BINDINGS_GLOBAL_INSTALL)
#
#  SET (SITE_PKG_PATH bindings/python)
#  
#ENDIF (BINDINGS_GLOBAL_INSTALL)


# Step 4: install built libs to python's site packages
INSTALL(FILES ${BINDINGS_LIBS} DESTINATION ${SITE_PKG_PATH}/kdl)


