#
# Find the omniORB libraries and include dir
#

# OMNIORB4_INCLUDE_DIR  - Directories to include to use omniORB
# OMNIORB4_LIBRARIES    - Files to link against to use omniORB
# OMNIORB4_IDL_COMPILER
# OMNIORB4_FOUND        - When false, don't try to use omniORB
# OMNIORB4_DIR          - (optional) Suggested installation directory to search
# OMNIORB_IDL_FLAGS     - (optional) Set flags for to use corba
# OMNIORB_CPP_FLAGS     - (optional) Set flags for to use corba
#
# OMNIORB4_DIR can be used to make it simpler to find the various include
# directories and compiled libraries when omniORB was not installed in the
# usual/well-known directories (e.g. because you made an in tree-source
# compilation or because you installed it in an "unusual" directory).
# Just set OMNIORB4_DIR it to your specific installation directory
#

FIND_PATH( OMNIORB4_INCLUDE_DIR omniORB4/CORBA.h
  PATHS
  ${OMNIORB4_DIR}/include
  /usr/include
  /usr/local/include
)

SET( OMNIORB4_DEFAULT_LIB_PATH /usr/lib /usr/local/lib )
#### For the list of required libraries for omniORB see
# http://www.omniorb-support.com/pipermail/omniorb-list/2005-May/026666.html
# Basically, look at
#  - omniORB-4.0.5/README.*
#  - omniORB-4.0.5/readmes/*
# Platfrom dependencies might (only?) happen for Win32/VC++ (sigh):
# "Because of a bug in VC++, unless you require the dynamic interfaces, it
#  is suggested that you use a smaller stub library called msvcstub.lib."

IF(WIN32)
  SET (OMNIORB4_LIB_DIR_WIN32 ${OMNIORB4_DIR}/lib/x86_win32)
  SET (OMNIORB4_BIN_DIR_WIN32 ${OMNIORB4_DIR}/bin/x86_win32)
  IF(BUILD_SHARED_LIBS)
     SET (OMNIORB4_LIB_EXT 10_rt)
     SET (OMNITHREAD_LIB_EXT 33_rt)
  ENDIF(BUILD_SHARED_LIBS)
#  MESSAGE(${OMNITHREAD_LIB_EXT})
ENDIF(WIN32)

FIND_LIBRARY(  OMNIORB4_LIBRARY_omniORB4 omniORB4${OMNIORB4_LIB_EXT}
  PATHS ${OMNIORB4_DIR}/lib
        ${OMNIORB4_LIB_DIR_WIN32}
        ${OMNIORB4_DEFAULT_LIB_PATH}
)

FIND_LIBRARY( OMNIORB4_LIBRARY_omnithread omnithread${OMNITHREAD_LIB_EXT}
  PATHS ${OMNIORB4_DIR}/lib
        ${OMNIORB4_LIB_DIR_WIN32}
        ${OMNIORB4_DEFAULT_LIB_PATH}
)

FIND_LIBRARY( OMNIORB4_LIBRARY_COS4 COS4${OMNIORB4_LIB_EXT}
  PATHS ${OMNIORB4_DIR}/lib
        ${OMNIORB4_LIB_DIR_WIN32}
        ${OMNIORB4_DEFAULT_LIB_PATH}
)

FIND_LIBRARY( OMNIORB4_LIBRARY_COSDynamic4 COSDynamic4${OMNIORB4_LIB_EXT}
  PATHS ${OMNIORB4_DIR}/lib
        ${OMNIORB4_LIB_DIR_WIN32}
        ${OMNIORB4_DEFAULT_LIB_PATH}
)

FIND_LIBRARY( OMNIORB4_LIBRARY_Dynamic4 omniDynamic4${OMNIORB4_LIB_EXT}
  PATHS ${OMNIORB4_DIR}/lib
        ${OMNIORB4_LIB_DIR_WIN32}
        ${OMNIORB4_DEFAULT_LIB_PATH}
)

FIND_PROGRAM(OMNIORB4_IDL_COMPILER
  NAMES omniidl
  PATHS ${OMNIORB4_DIR}/bin
        ${OMNIORB4_LIB_DIR_WIN32}
        /usr/bin
        /usr/local/bin
  DOC "What is the path where omniidl (the idl compiler) can be found"
)

IF( OMNIORB4_INCLUDE_DIR )
IF( OMNIORB4_LIBRARY_omniORB4 )
IF( OMNIORB4_LIBRARY_omnithread )
IF( OMNIORB4_IDL_COMPILER )

  SET( OMNIORB4_FOUND "YES" )
  SET(CORBA_IS_OMNIORB 1)

  IF(NOT WIN32)
    SET(OMNIORB4_IDL_FLAGS "-bcxx -Wba -Wbh=.hh -Wbs=SK.cc -Wbd=DynSK.cc" CACHE STRING "Option for the omniorb4 idl compiler")
    SET(OMNIORB4_CPP_FLAGS "" CACHE STRING "Additional option for the linking with omniorb4")
  ELSE(NOT WIN32)
    SET(OMNIORB4_IDL_FLAGS "-T -bcxx -Wba -Wbh=.hh -Wbs=SK.cc -Wbd=DynSK.cc" CACHE STRING "Option for the omniorb4 idl compiler")
    SET(OMNIORB4_CPP_FLAGS "-mthreads -D__OMNIORB4__ -D__WIN32__ -D_WIN32_WINNT=0x0400 -D__x86__ -D__NT__  -D__OSVERSION__=4" CACHE STRING "Additional option for the linking with omniorb4")
  ENDIF(NOT WIN32)

  SEPARATE_ARGUMENTS(OMNIORB_IDL_FLAGS)
  SEPARATE_ARGUMENTS(OMNIORB_CPP_FLAGS)

  MARK_AS_ADVANCED( OMNIORB4_DIR )
  MARK_AS_ADVANCED( OMNIORB4_INCLUDE_DIR )
  MARK_AS_ADVANCED( OMNIORB4_LIBRARY_omniORB4 )
  MARK_AS_ADVANCED( OMNIORB4_LIBRARY_omnithread )
  MARK_AS_ADVANCED( OMNIORB4_LIBRARY_COS4 )
  MARK_AS_ADVANCED( OMNIORB4_LIBRARY_COSDynamic4 )
  MARK_AS_ADVANCED( OMNIORB4_LIBRARY_Dynamic4 )
  MARK_AS_ADVANCED( OMNIORB4_IDL_COMPILER )
  MARK_AS_ADVANCED( OMNIORB4_IDL_FLAGS )
  MARK_AS_ADVANCED( OMNIORB4_CPP_FLAGS )
  LIST(APPEND OMNIORB4_LIBRARIES
    ${OMNIORB4_LIBRARY_omniORB4}
    ${OMNIORB4_LIBRARY_Dynamic4}
    ${OMNIORB4_LIBRARY_omnithread})
  IF(OMNIORB4_LIBRARY_COS4)
    LIST(APPEND OMNIORB4_LIBRARIES
        ${OMNIORB4_LIBRARY_COS4}            # mandatory on FC2 and graal
        ${OMNIORB4_LIBRARY_COSDynamic4}     # mandatory on FC2 and graal
        )
  ENDIF(OMNIORB4_LIBRARY_COS4)

ENDIF( OMNIORB4_IDL_COMPILER )
ENDIF( OMNIORB4_LIBRARY_omnithread )
ENDIF( OMNIORB4_LIBRARY_omniORB4 )
ENDIF( OMNIORB4_INCLUDE_DIR )

IF( OMNIORB4_FOUND )
  SET(CORBA_LIBRARIES ${OMNIORB4_LIBRARIES})
  SET(CORBA_CFLAGS ${OMNIORB4_CPP_FLAGS})
  SET(CORBA_INCLUDE_DIRS ${OMNIORB4_INCLUDE_DIR})
  SET(CORBA_DEFINES "") #-DCORBA_IS_OMNIORB)

ELSE( OMNIORB4_FOUND )
  MESSAGE("omniORB installation was not found. Please provide OMNIORB4_DIR:")
  MESSAGE("  - through the GUI when working with ccmake, ")
  MESSAGE("  - as a command line argument when working with cmake e.g. ")
  MESSAGE("    cmake .. -DOMNIORB4_DIR:PATH=/usr/local/omniORB-4.0.5 ")
  MESSAGE("Note: the following message is triggered by cmake on the first ")
  MESSAGE("    undefined necessary PATH variable (e.g. OMNIORB4_INCLUDE_DIR).")
  MESSAGE("    Providing OMNIORB4_DIR (as above described) is probably the")
  MESSAGE("    simplest solution unless you have a really customized/odd")
  MESSAGE("    omniORB installation...")

  SET( OMNIORB4_DIR "" CACHE PATH "Root of omniORB instal tree." )
ENDIF( OMNIORB4_FOUND )

# Generate all files required for a corba server app.
# ORO_ADD_CORBA_SERVERS( foo_SRCS foo_HPPS file.idl ... ) 
MACRO(ORO_ADD_CORBA_SERVERS _sources _headers)
   FOREACH (_current_FILE ${ARGN})

      GET_FILENAME_COMPONENT(_tmp_FILE ${_current_FILE} ABSOLUTE)
      GET_FILENAME_COMPONENT(_basename ${_tmp_FILE} NAME_WE)
      GET_FILENAME_COMPONENT(_filedir ${_tmp_FILE} PATH)

      SET(_out  ${CMAKE_CURRENT_BINARY_DIR}/${_basename}C.cc ${CMAKE_CURRENT_BINARY_DIR}/${_basename}DynSK.cc)
      SET(_outh ${CMAKE_CURRENT_BINARY_DIR}/${_basename}C.h)

      IF (NOT HAVE_${_basename}_SERVER_RULE)
         SET(HAVE_${_basename}_SERVER_RULE ON)
         # CMake atrocity: if none of these OUTPUT files is used in a target in
         # the current CMakeLists.txt file, the ADD_CUSTOM_COMMAND is plainly
         # ignored and left out of the make files.
         ADD_CUSTOM_COMMAND(OUTPUT ${_out} ${_outh}
          COMMAND ${OMNIORB4_IDL_COMPILER} -bcxx -Wba -Wbh=C.h -Wbs=C.cc -I${CMAKE_CURRENT_SOURCE_DIR} ${_current_FILE}
          DEPENDS ${_tmp_FILE}
         )
     ENDIF (NOT HAVE_${_basename}_SERVER_RULE)

     SET(${_sources} ${${_sources}} ${_out})
     SET(${_headers} ${${_headers}} ${_outh})
    ENDFOREACH (_current_FILE)
ENDMACRO(ORO_ADD_CORBA_SERVERS)

#
# Find the omniORB libraries and include dir
#

# OMNIORB4_INCLUDE_DIR  - Directories to include to use omniORB
# OMNIORB4_LIBRARIES    - Files to link against to use omniORB
# OMNIORB4_IDL_COMPILER
# OMNIORB4_FOUND        - When false, don't try to use omniORB
# OMNIORB4_DIR          - (optional) Suggested installation directory to search
# OMNIORB_IDL_FLAGS     - (optional) Set flags for to use corba
# OMNIORB_CPP_FLAGS     - (optional) Set flags for to use corba
#
# OMNIORB4_DIR can be used to make it simpler to find the various include
# directories and compiled libraries when omniORB was not installed in the
# usual/well-known directories (e.g. because you made an in tree-source
# compilation or because you installed it in an "unusual" directory).
# Just set OMNIORB4_DIR it to your specific installation directory
#

FIND_PATH( OMNIORB4_INCLUDE_DIR omniORB4/CORBA.h
  PATHS
  ${OMNIORB4_DIR}/include
  /usr/include
  /usr/local/include
)

SET( OMNIORB4_DEFAULT_LIB_PATH /usr/lib /usr/local/lib )
#### For the list of required libraries for omniORB see
# http://www.omniorb-support.com/pipermail/omniorb-list/2005-May/026666.html
# Basically, look at
#  - omniORB-4.0.5/README.*
#  - omniORB-4.0.5/readmes/*
# Platfrom dependencies might (only?) happen for Win32/VC++ (sigh):
# "Because of a bug in VC++, unless you require the dynamic interfaces, it
#  is suggested that you use a smaller stub library called msvcstub.lib."

IF(WIN32)
  SET (OMNIORB4_LIB_DIR_WIN32 ${OMNIORB4_DIR}/lib/x86_win32)
  SET (OMNIORB4_BIN_DIR_WIN32 ${OMNIORB4_DIR}/bin/x86_win32)
  IF(BUILD_SHARED_LIBS)
     SET (OMNIORB4_LIB_EXT 10_rt)
     SET (OMNITHREAD_LIB_EXT 33_rt)
  ENDIF(BUILD_SHARED_LIBS)
#  MESSAGE(${OMNITHREAD_LIB_EXT})
ENDIF(WIN32)

FIND_LIBRARY(  OMNIORB4_LIBRARY_omniORB4 omniORB4${OMNIORB4_LIB_EXT}
  PATHS ${OMNIORB4_DIR}/lib
        ${OMNIORB4_LIB_DIR_WIN32}
        ${OMNIORB4_DEFAULT_LIB_PATH}
)

FIND_LIBRARY( OMNIORB4_LIBRARY_omnithread omnithread${OMNITHREAD_LIB_EXT}
  PATHS ${OMNIORB4_DIR}/lib
        ${OMNIORB4_LIB_DIR_WIN32}
        ${OMNIORB4_DEFAULT_LIB_PATH}
)

FIND_LIBRARY( OMNIORB4_LIBRARY_COS4 COS4${OMNIORB4_LIB_EXT}
  PATHS ${OMNIORB4_DIR}/lib
        ${OMNIORB4_LIB_DIR_WIN32}
        ${OMNIORB4_DEFAULT_LIB_PATH}
)

FIND_LIBRARY( OMNIORB4_LIBRARY_COSDynamic4 COSDynamic4${OMNIORB4_LIB_EXT}
  PATHS ${OMNIORB4_DIR}/lib
        ${OMNIORB4_LIB_DIR_WIN32}
        ${OMNIORB4_DEFAULT_LIB_PATH}
)

FIND_LIBRARY( OMNIORB4_LIBRARY_Dynamic4 omniDynamic4${OMNIORB4_LIB_EXT}
  PATHS ${OMNIORB4_DIR}/lib
        ${OMNIORB4_LIB_DIR_WIN32}
        ${OMNIORB4_DEFAULT_LIB_PATH}
)

FIND_PROGRAM(OMNIORB4_IDL_COMPILER
  NAMES omniidl
  PATHS ${OMNIORB4_DIR}/bin
        ${OMNIORB4_LIB_DIR_WIN32}
        /usr/bin
        /usr/local/bin
  DOC "What is the path where omniidl (the idl compiler) can be found"
)

IF( OMNIORB4_INCLUDE_DIR )
IF( OMNIORB4_LIBRARY_omniORB4 )
IF( OMNIORB4_LIBRARY_omnithread )
IF( OMNIORB4_IDL_COMPILER )

  SET( OMNIORB4_FOUND "YES" )
  SET(CORBA_IS_OMNIORB 1)

  IF(NOT WIN32)
    SET(OMNIORB4_IDL_FLAGS "-bcxx -Wba -Wbh=.hh -Wbs=SK.cc -Wbd=DynSK.cc" CACHE STRING "Option for the omniorb4 idl compiler")
    SET(OMNIORB4_CPP_FLAGS "" CACHE STRING "Additional option for the linking with omniorb4")
  ELSE(NOT WIN32)
    SET(OMNIORB4_IDL_FLAGS "-T -bcxx -Wba -Wbh=.hh -Wbs=SK.cc -Wbd=DynSK.cc" CACHE STRING "Option for the omniorb4 idl compiler")
    SET(OMNIORB4_CPP_FLAGS "-mthreads -D__OMNIORB4__ -D__WIN32__ -D_WIN32_WINNT=0x0400 -D__x86__ -D__NT__  -D__OSVERSION__=4" CACHE STRING "Additional option for the linking with omniorb4")
  ENDIF(NOT WIN32)

  SEPARATE_ARGUMENTS(OMNIORB_IDL_FLAGS)
  SEPARATE_ARGUMENTS(OMNIORB_CPP_FLAGS)

  MARK_AS_ADVANCED( OMNIORB4_DIR )
  MARK_AS_ADVANCED( OMNIORB4_INCLUDE_DIR )
  MARK_AS_ADVANCED( OMNIORB4_LIBRARY_omniORB4 )
  MARK_AS_ADVANCED( OMNIORB4_LIBRARY_omnithread )
  MARK_AS_ADVANCED( OMNIORB4_LIBRARY_COS4 )
  MARK_AS_ADVANCED( OMNIORB4_LIBRARY_COSDynamic4 )
  MARK_AS_ADVANCED( OMNIORB4_LIBRARY_Dynamic4 )
  MARK_AS_ADVANCED( OMNIORB4_IDL_COMPILER )
  MARK_AS_ADVANCED( OMNIORB4_IDL_FLAGS )
  MARK_AS_ADVANCED( OMNIORB4_CPP_FLAGS )
  LIST(APPEND OMNIORB4_LIBRARIES
    ${OMNIORB4_LIBRARY_omniORB4}
    ${OMNIORB4_LIBRARY_Dynamic4}
    ${OMNIORB4_LIBRARY_omnithread})
  IF(OMNIORB4_LIBRARY_COS4)
    LIST(APPEND OMNIORB4_LIBRARIES
        ${OMNIORB4_LIBRARY_COS4}            # mandatory on FC2 and graal
        ${OMNIORB4_LIBRARY_COSDynamic4}     # mandatory on FC2 and graal
        )
  ENDIF(OMNIORB4_LIBRARY_COS4)

ENDIF( OMNIORB4_IDL_COMPILER )
ENDIF( OMNIORB4_LIBRARY_omnithread )
ENDIF( OMNIORB4_LIBRARY_omniORB4 )
ENDIF( OMNIORB4_INCLUDE_DIR )

IF( OMNIORB4_FOUND )
  SET(CORBA_LIBRARIES ${OMNIORB4_LIBRARIES})
  SET(CORBA_CFLAGS ${OMNIORB4_CPP_FLAGS})
  SET(CORBA_INCLUDE_DIRS ${OMNIORB4_INCLUDE_DIR})
  SET(CORBA_DEFINES "") #-DCORBA_IS_OMNIORB)

ELSE( OMNIORB4_FOUND )
  MESSAGE("omniORB installation was not found. Please provide OMNIORB4_DIR:")
  MESSAGE("  - through the GUI when working with ccmake, ")
  MESSAGE("  - as a command line argument when working with cmake e.g. ")
  MESSAGE("    cmake .. -DOMNIORB4_DIR:PATH=/usr/local/omniORB-4.0.5 ")
  MESSAGE("Note: the following message is triggered by cmake on the first ")
  MESSAGE("    undefined necessary PATH variable (e.g. OMNIORB4_INCLUDE_DIR).")
  MESSAGE("    Providing OMNIORB4_DIR (as above described) is probably the")
  MESSAGE("    simplest solution unless you have a really customized/odd")
  MESSAGE("    omniORB installation...")

  SET( OMNIORB4_DIR "" CACHE PATH "Root of omniORB instal tree." )
ENDIF( OMNIORB4_FOUND )

# Generate all files required for a corba server app.
# ORO_ADD_CORBA_SERVERS( foo_SRCS foo_HPPS file.idl ... ) 
MACRO(ORO_ADD_CORBA_SERVERS _sources _headers)
   FOREACH (_current_FILE ${ARGN})

      GET_FILENAME_COMPONENT(_tmp_FILE ${_current_FILE} ABSOLUTE)
      GET_FILENAME_COMPONENT(_basename ${_tmp_FILE} NAME_WE)
      GET_FILENAME_COMPONENT(_filedir ${_tmp_FILE} PATH)

      SET(_out  ${CMAKE_CURRENT_BINARY_DIR}/${_basename}C.cc ${CMAKE_CURRENT_BINARY_DIR}/${_basename}DynSK.cc)
      SET(_outh ${CMAKE_CURRENT_BINARY_DIR}/${_basename}C.h)

      IF (NOT HAVE_${_basename}_SERVER_RULE)
         SET(HAVE_${_basename}_SERVER_RULE ON)
         # CMake atrocity: if none of these OUTPUT files is used in a target in
         # the current CMakeLists.txt file, the ADD_CUSTOM_COMMAND is plainly
         # ignored and left out of the make files.
         ADD_CUSTOM_COMMAND(OUTPUT ${_out} ${_outh}
          COMMAND ${OMNIORB4_IDL_COMPILER} -bcxx -Wba -Wbh=C.h -Wbs=C.cc -I${CMAKE_CURRENT_SOURCE_DIR} ${_current_FILE}
          DEPENDS ${_tmp_FILE}
         )
     ENDIF (NOT HAVE_${_basename}_SERVER_RULE)

     SET(${_sources} ${${_sources}} ${_out})
     SET(${_headers} ${${_headers}} ${_outh})
    ENDFOREACH (_current_FILE)
ENDMACRO(ORO_ADD_CORBA_SERVERS)

