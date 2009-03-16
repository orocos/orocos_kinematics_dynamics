# Locate TAO install directory

INCLUDE (${PROJ_SOURCE_DIR}/config/FindPkgConfig.cmake)

MESSAGE ( STATUS "Looking for TAO with orbsvcs...")

# DOES NOT WORK: TAO_ID.pc not found on debian system... detect .so files instead !
#PKGCONFIG( "TAO_PortableServer" TAO_FOUND TAO_INCLUDE_DIRS TAO_DEFINES TAO_LINK_DIRS TAO_LIBS )
#PKGCONFIG( "TAO_CosNaming" TAONAMING_FOUND TAONAMING_INCLUDE_DIRS TAONAMING_DEFINES TAONAMING_LINK_DIRS TAONAMING_LIBS )

SET(ACE_DIR $ENV{ACE_ROOT})
SET(TAO_DIR $ENV{TAO_ROOT})
MESSAGE( "ACE_DIR is ${ACE_DIR}" )

IF (NOT ACE_DIR AND NOT CMAKE_CROSS_COMPILE)
    SET(ACE_DIR /usr)
ENDIF (NOT ACE_DIR AND NOT CMAKE_CROSS_COMPILE )
IF (NOT TAO_DIR AND NOT CMAKE_CROSS_COMPILE )
    SET(TAO_DIR /usr)
ENDIF (NOT TAO_DIR AND NOT CMAKE_CROSS_COMPILE )

# See if headers are present.
FIND_FILE(ACE_CONFIG config-all.h ${ACE_DIR}/include/ace )
FIND_FILE(TAO_ORB ORB.h ${TAO_DIR}/include/tao )
FIND_FILE(TAO_15 Any.h ${TAO_DIR}/include/tao/AnyTypeCode )

# try to find orbsvcs (FIX: include CosNaming.idl ourselves ??)
IF (NOT ORBSVCS_DIR )
    FIND_FILE(TAO_ORBSVCS CosNaming.idl ${TAO_DIR}/include/orbsvcs/orbsvcs)
    IF (TAO_ORBSVCS)
        SET( ORBSVCS_DIR ${TAO_DIR}/include/orbsvcs )
    ELSE (TAO_ORBSVCS)
        FIND_FILE(TAO_ORBSVCS CosNaming.idl ${TAO_DIR}/include/orbsvcs )
        SET( ORBSVCS_DIR ${TAO_DIR}/include )
    ENDIF (TAO_ORBSVCS)
ENDIF (NOT ORBSVCS_DIR )

IF (NOT ACE_CONFIG )
    MESSAGE( "ACE config-all.h not found in ${ACE_DIR}/include/ace.")
ELSE(NOT ACE_CONFIG ) 
    MESSAGE( "ACE config-all.h found in ${ACE_DIR}/include/ace.")
ENDIF (NOT ACE_CONFIG )

IF (NOT TAO_ORB )
    MESSAGE( "TAO ORB.h not found in ${TAO_DIR}/include/tao.")
ELSE (NOT TAO_ORB )
    MESSAGE( "TAO ORB.h found in ${TAO_DIR}/include/tao.")
ENDIF (NOT TAO_ORB )

IF (NOT TAO_15 )
    MESSAGE( "Assuming TAO < 1.5 (based on location of Any.h)")
ELSE (NOT TAO_15 )
    MESSAGE( "Assuming TAO >= 1.5 (based on location of Any.h)")
ENDIF (NOT TAO_15 )

IF (NOT TAO_ORBSVCS )
    MESSAGE( "TAO orbsvcs/CosNaming.idl not found in ${ORBSVCS_DIR}.")
ELSE (NOT TAO_ORBSVCS )
    MESSAGE( "TAO orbsvcs/CosNaming.idl found in ${ORBSVCS_DIR}.")
ENDIF (NOT TAO_ORBSVCS )

IF (ACE_CONFIG AND TAO_ORB AND TAO_ORBSVCS )
    MESSAGE ( "TAO with orbsvcs found.")

    FIND_PROGRAM( ORO_TAOIDL_EXECUTABLE tao_idl PATHS "${ACE_DIR}/bin" NO_DEFAULT_PATH )
    FIND_PROGRAM( ORO_TAOIDL_EXECUTABLE tao_idl )

    IF( NOT ORO_TAOIDL_EXECUTABLE )
        MESSAGE( FATAL "TAO Headers found but no tao_idl !")
    ELSE( NOT ORO_TAOIDL_EXECUTABLE )
        MESSAGE( "tao_idl: ${ORO_TAOIDL_EXECUTABLE}")
        SET(FOUND_TAO TRUE)
	SET(CORBA_IS_TAO 1)

        SET(CORBA_CFLAGS "")
        SET(CORBA_INCLUDE_DIRS "")
        SET(CORBA_LDFLAGS "")
        SET(CORBA_LIBRARIES "")
        SET(CORBA_LINK_DIRECTORIES "")
        SET(CORBA_DEFINES "") #-DCORBA_IS_TAO)

        # Set include/link variables
        IF( ${ACE_DIR} STREQUAL /usr )
            LIST(APPEND CORBA_INCLUDE_DIRS "${ACE_DIR}/include")
            LIST(APPEND CORBA_CFLAGS "-I${ACE_DIR}/include")
            LIST(APPEND CORBA_LINK_DIRECTORIES "${ACE_DIR}/lib")
            LIST(APPEND CORBA_LDFLAGS "-L${ACE_DIR}/lib")
        ENDIF( ${ACE_DIR} STREQUAL /usr )
        IF( NOT ${ACE_DIR} STREQUAL /usr )
            LIST(APPEND CORBA_INCLUDE_DIRS "${ACE_DIR}/include")
            LIST(APPEND CORBA_CFLAGS "-I${ACE_DIR}/include")
            LIST(APPEND CORBA_LINK_DIRECTORIES "${ACE_DIR}/lib")
            LIST(APPEND CORBA_LDFLAGS "-L${ACE_DIR}/lib")
        ENDIF( NOT ${ACE_DIR} STREQUAL /usr )
        IF( NOT ${TAO_DIR} STREQUAL /usr AND NOT ${TAO_DIR} STREQUAL ${ACE_DIR})
            LIST(APPEND CORBA_INCLUDE_DIRS "${TAO_DIR}/include")
            LIST(APPEND CORBA_CFLAGS "-I${TAO_DIR}/include")
            LIST(APPEND CORBA_LINK_DIRECTORIES "${TAO_DIR}/lib")
            LIST(APPEND CORBA_LDFLAGS "-L${TAO_DIR}/lib")
        ENDIF( NOT ${TAO_DIR} STREQUAL /usr AND NOT ${TAO_DIR} STREQUAL ${ACE_DIR})
        IF( NOT ${ORBSVCS_DIR} STREQUAL /usr AND NOT ${ORBSVCS_DIR} STREQUAL ${TAO_DIR})
            LIST(APPEND CORBA_INCLUDE_DIRS "${ORBSVCS_DIR}")
            LIST(APPEND CORBA_CFLAGS "-I${ORBSVCS_DIR}")
            LIST(APPEND CORBA_LINK_DIRECTORIES "${ORBSVCS_DIR}/lib")
            LIST(APPEND CORBA_LDFLAGS "-L${ORBSVCS_DIR}/lib")
        ENDIF( NOT ${ORBSVCS_DIR} STREQUAL /usr AND NOT ${ORBSVCS_DIR} STREQUAL ${TAO_DIR})

        # Is used for building  the library
        LIST(APPEND CORBA_LIBRARIES TAO TAO_PortableServer TAO_CosNaming ACE )
        LIST(APPEND CORBA_LDFLAGS -lTAO -lTAO_PortableServer -lTAO_CosNaming -lACE)

        IF(APPLE)
            # Mac OS X needs this define (or _POSIX_C_SOURCE) to pick up some type
            # definitions that ACE/TAO needs. Personally, I think this is a bug in
            # ACE/TAO, but ....
            LIST(APPEND CORBA_CFLAGS -D_DARWIN_C_SOURCE)
            # and needs additional libraries 
            LIST(APPEND CORBA_LIBRARIES TAO_AnyTypeCode)
        ENDIF(APPLE)

        IF( NOT TAO_15 )
            LIST(APPEND CORBA_LIBRARIES TAO_IDL_BE)
            LIST(APPEND CORBA_LDFLAGS -lTAO_IDL_BE)
        ENDIF( NOT TAO_15 )
    ENDIF( NOT ORO_TAOIDL_EXECUTABLE )
ENDIF (ACE_CONFIG AND TAO_ORB AND TAO_ORBSVCS )

# Generate all files required for a corba server app.
# ORO_ADD_CORBA_SERVERS( foo_SRCS foo_HPPS file.idl ... ) 
MACRO(ORO_ADD_CORBA_SERVERS _sources _headers)
   FOREACH (_current_FILE ${ARGN})

      GET_FILENAME_COMPONENT(_tmp_FILE ${_current_FILE} ABSOLUTE)
      GET_FILENAME_COMPONENT(_basename ${_tmp_FILE} NAME_WE)
      GET_FILENAME_COMPONENT(_filedir ${_tmp_FILE} PATH)

      SET(_server  ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S.cpp)
      SET(_serverh ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S.h ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S.inl)

      # From TAO 1.5 onwards, the _T files are no longer generated
      IF( NOT TAO_15 )
          SET(_tserver )
          SET(_tserverh ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S_T.h ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S_T.inl ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S_T.cpp)
      ENDIF( NOT TAO_15 )

      SET(_client  ${CMAKE_CURRENT_BINARY_DIR}/${_basename}C.cpp)
      SET(_clienth ${CMAKE_CURRENT_BINARY_DIR}/${_basename}C.h ${CMAKE_CURRENT_BINARY_DIR}/${_basename}C.inl)

      IF (NOT HAVE_${_basename}_SERVER_RULE)
         SET(HAVE_${_basename}_SERVER_RULE ON)
	 # CMake atrocity: if none of these OUTPUT files is used in a target in the current CMakeLists.txt file,
	 # the ADD_CUSTOM_COMMAND is plainly ignored and left out of the make files.
         ADD_CUSTOM_COMMAND(OUTPUT ${_tserver} ${_server} ${_client} ${_tserverh} ${_serverh} ${_clienth}
          COMMAND ${ORO_TAOIDL_EXECUTABLE} ${_current_FILE} -o ${CMAKE_CURRENT_BINARY_DIR} -I${CMAKE_CURRENT_SOURCE_DIR} -I${ORBSVCS_DIR}
          DEPENDS ${_tmp_FILE}
         )
     ENDIF (NOT HAVE_${_basename}_SERVER_RULE)

     SET(${_sources} ${${_sources}} ${_server} ${_tserver} ${_client})
     SET(${_headers} ${${_headers}} ${_serverh} ${_tserverh} ${_clienth})

     SET_SOURCE_FILES_PROPERTIES(${_server} ${_serverh} ${_tserver} ${_client} ${_tserverh} ${_clienth} PROPERTIES GENERATED TRUE)
    ENDFOREACH (_current_FILE)
ENDMACRO(ORO_ADD_CORBA_SERVERS)

# Locate TAO install directory

INCLUDE (${PROJ_SOURCE_DIR}/config/FindPkgConfig.cmake)

MESSAGE ( STATUS "Looking for TAO with orbsvcs...")

# DOES NOT WORK: TAO_ID.pc not found on debian system... detect .so files instead !
#PKGCONFIG( "TAO_PortableServer" TAO_FOUND TAO_INCLUDE_DIRS TAO_DEFINES TAO_LINK_DIRS TAO_LIBS )
#PKGCONFIG( "TAO_CosNaming" TAONAMING_FOUND TAONAMING_INCLUDE_DIRS TAONAMING_DEFINES TAONAMING_LINK_DIRS TAONAMING_LIBS )

SET(ACE_DIR $ENV{ACE_ROOT})
SET(TAO_DIR $ENV{TAO_ROOT})
MESSAGE( "ACE_DIR is ${ACE_DIR}" )

IF (NOT ACE_DIR AND NOT CMAKE_CROSS_COMPILE)
    SET(ACE_DIR /usr)
ENDIF (NOT ACE_DIR AND NOT CMAKE_CROSS_COMPILE )
IF (NOT TAO_DIR AND NOT CMAKE_CROSS_COMPILE )
    SET(TAO_DIR /usr)
ENDIF (NOT TAO_DIR AND NOT CMAKE_CROSS_COMPILE )

# See if headers are present.
FIND_FILE(ACE_CONFIG config-all.h ${ACE_DIR}/include/ace )
FIND_FILE(TAO_ORB ORB.h ${TAO_DIR}/include/tao )
FIND_FILE(TAO_15 Any.h ${TAO_DIR}/include/tao/AnyTypeCode )

# try to find orbsvcs (FIX: include CosNaming.idl ourselves ??)
IF (NOT ORBSVCS_DIR )
    FIND_FILE(TAO_ORBSVCS CosNaming.idl ${TAO_DIR}/include/orbsvcs/orbsvcs)
    IF (TAO_ORBSVCS)
        SET( ORBSVCS_DIR ${TAO_DIR}/include/orbsvcs )
    ELSE (TAO_ORBSVCS)
        FIND_FILE(TAO_ORBSVCS CosNaming.idl ${TAO_DIR}/include/orbsvcs )
        SET( ORBSVCS_DIR ${TAO_DIR}/include )
    ENDIF (TAO_ORBSVCS)
ENDIF (NOT ORBSVCS_DIR )

IF (NOT ACE_CONFIG )
    MESSAGE( "ACE config-all.h not found in ${ACE_DIR}/include/ace.")
ELSE(NOT ACE_CONFIG ) 
    MESSAGE( "ACE config-all.h found in ${ACE_DIR}/include/ace.")
ENDIF (NOT ACE_CONFIG )

IF (NOT TAO_ORB )
    MESSAGE( "TAO ORB.h not found in ${TAO_DIR}/include/tao.")
ELSE (NOT TAO_ORB )
    MESSAGE( "TAO ORB.h found in ${TAO_DIR}/include/tao.")
ENDIF (NOT TAO_ORB )

IF (NOT TAO_15 )
    MESSAGE( "Assuming TAO < 1.5 (based on location of Any.h)")
ELSE (NOT TAO_15 )
    MESSAGE( "Assuming TAO >= 1.5 (based on location of Any.h)")
ENDIF (NOT TAO_15 )

IF (NOT TAO_ORBSVCS )
    MESSAGE( "TAO orbsvcs/CosNaming.idl not found in ${ORBSVCS_DIR}.")
ELSE (NOT TAO_ORBSVCS )
    MESSAGE( "TAO orbsvcs/CosNaming.idl found in ${ORBSVCS_DIR}.")
ENDIF (NOT TAO_ORBSVCS )

IF (ACE_CONFIG AND TAO_ORB AND TAO_ORBSVCS )
    MESSAGE ( "TAO with orbsvcs found.")

    FIND_PROGRAM( ORO_TAOIDL_EXECUTABLE tao_idl PATHS "${ACE_DIR}/bin" NO_DEFAULT_PATH )
    FIND_PROGRAM( ORO_TAOIDL_EXECUTABLE tao_idl )

    IF( NOT ORO_TAOIDL_EXECUTABLE )
        MESSAGE( FATAL "TAO Headers found but no tao_idl !")
    ELSE( NOT ORO_TAOIDL_EXECUTABLE )
        MESSAGE( "tao_idl: ${ORO_TAOIDL_EXECUTABLE}")
        SET(FOUND_TAO TRUE)
	SET(CORBA_IS_TAO 1)

        SET(CORBA_CFLAGS "")
        SET(CORBA_INCLUDE_DIRS "")
        SET(CORBA_LDFLAGS "")
        SET(CORBA_LIBRARIES "")
        SET(CORBA_LINK_DIRECTORIES "")
        SET(CORBA_DEFINES "") #-DCORBA_IS_TAO)

        # Set include/link variables
        IF( ${ACE_DIR} STREQUAL /usr )
            LIST(APPEND CORBA_INCLUDE_DIRS "${ACE_DIR}/include")
            LIST(APPEND CORBA_CFLAGS "-I${ACE_DIR}/include")
            LIST(APPEND CORBA_LINK_DIRECTORIES "${ACE_DIR}/lib")
            LIST(APPEND CORBA_LDFLAGS "-L${ACE_DIR}/lib")
        ENDIF( ${ACE_DIR} STREQUAL /usr )
        IF( NOT ${ACE_DIR} STREQUAL /usr )
            LIST(APPEND CORBA_INCLUDE_DIRS "${ACE_DIR}/include")
            LIST(APPEND CORBA_CFLAGS "-I${ACE_DIR}/include")
            LIST(APPEND CORBA_LINK_DIRECTORIES "${ACE_DIR}/lib")
            LIST(APPEND CORBA_LDFLAGS "-L${ACE_DIR}/lib")
        ENDIF( NOT ${ACE_DIR} STREQUAL /usr )
        IF( NOT ${TAO_DIR} STREQUAL /usr AND NOT ${TAO_DIR} STREQUAL ${ACE_DIR})
            LIST(APPEND CORBA_INCLUDE_DIRS "${TAO_DIR}/include")
            LIST(APPEND CORBA_CFLAGS "-I${TAO_DIR}/include")
            LIST(APPEND CORBA_LINK_DIRECTORIES "${TAO_DIR}/lib")
            LIST(APPEND CORBA_LDFLAGS "-L${TAO_DIR}/lib")
        ENDIF( NOT ${TAO_DIR} STREQUAL /usr AND NOT ${TAO_DIR} STREQUAL ${ACE_DIR})
        IF( NOT ${ORBSVCS_DIR} STREQUAL /usr AND NOT ${ORBSVCS_DIR} STREQUAL ${TAO_DIR})
            LIST(APPEND CORBA_INCLUDE_DIRS "${ORBSVCS_DIR}")
            LIST(APPEND CORBA_CFLAGS "-I${ORBSVCS_DIR}")
            LIST(APPEND CORBA_LINK_DIRECTORIES "${ORBSVCS_DIR}/lib")
            LIST(APPEND CORBA_LDFLAGS "-L${ORBSVCS_DIR}/lib")
        ENDIF( NOT ${ORBSVCS_DIR} STREQUAL /usr AND NOT ${ORBSVCS_DIR} STREQUAL ${TAO_DIR})

        # Is used for building  the library
        LIST(APPEND CORBA_LIBRARIES TAO TAO_PortableServer TAO_CosNaming ACE )
        LIST(APPEND CORBA_LDFLAGS -lTAO -lTAO_PortableServer -lTAO_CosNaming -lACE)

        IF(APPLE)
            # Mac OS X needs this define (or _POSIX_C_SOURCE) to pick up some type
            # definitions that ACE/TAO needs. Personally, I think this is a bug in
            # ACE/TAO, but ....
            LIST(APPEND CORBA_CFLAGS -D_DARWIN_C_SOURCE)
            # and needs additional libraries 
            LIST(APPEND CORBA_LIBRARIES TAO_AnyTypeCode)
        ENDIF(APPLE)

        IF( NOT TAO_15 )
            LIST(APPEND CORBA_LIBRARIES TAO_IDL_BE)
            LIST(APPEND CORBA_LDFLAGS -lTAO_IDL_BE)
        ENDIF( NOT TAO_15 )
    ENDIF( NOT ORO_TAOIDL_EXECUTABLE )
ENDIF (ACE_CONFIG AND TAO_ORB AND TAO_ORBSVCS )

# Generate all files required for a corba server app.
# ORO_ADD_CORBA_SERVERS( foo_SRCS foo_HPPS file.idl ... ) 
MACRO(ORO_ADD_CORBA_SERVERS _sources _headers)
   FOREACH (_current_FILE ${ARGN})

      GET_FILENAME_COMPONENT(_tmp_FILE ${_current_FILE} ABSOLUTE)
      GET_FILENAME_COMPONENT(_basename ${_tmp_FILE} NAME_WE)
      GET_FILENAME_COMPONENT(_filedir ${_tmp_FILE} PATH)

      SET(_server  ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S.cpp)
      SET(_serverh ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S.h ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S.inl)

      # From TAO 1.5 onwards, the _T files are no longer generated
      IF( NOT TAO_15 )
          SET(_tserver )
          SET(_tserverh ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S_T.h ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S_T.inl ${CMAKE_CURRENT_BINARY_DIR}/${_basename}S_T.cpp)
      ENDIF( NOT TAO_15 )

      SET(_client  ${CMAKE_CURRENT_BINARY_DIR}/${_basename}C.cpp)
      SET(_clienth ${CMAKE_CURRENT_BINARY_DIR}/${_basename}C.h ${CMAKE_CURRENT_BINARY_DIR}/${_basename}C.inl)

      IF (NOT HAVE_${_basename}_SERVER_RULE)
         SET(HAVE_${_basename}_SERVER_RULE ON)
	 # CMake atrocity: if none of these OUTPUT files is used in a target in the current CMakeLists.txt file,
	 # the ADD_CUSTOM_COMMAND is plainly ignored and left out of the make files.
         ADD_CUSTOM_COMMAND(OUTPUT ${_tserver} ${_server} ${_client} ${_tserverh} ${_serverh} ${_clienth}
          COMMAND ${ORO_TAOIDL_EXECUTABLE} ${_current_FILE} -o ${CMAKE_CURRENT_BINARY_DIR} -I${CMAKE_CURRENT_SOURCE_DIR} -I${ORBSVCS_DIR}
          DEPENDS ${_tmp_FILE}
         )
     ENDIF (NOT HAVE_${_basename}_SERVER_RULE)

     SET(${_sources} ${${_sources}} ${_server} ${_tserver} ${_client})
     SET(${_headers} ${${_headers}} ${_serverh} ${_tserverh} ${_clienth})

     SET_SOURCE_FILES_PROPERTIES(${_server} ${_serverh} ${_tserver} ${_client} ${_tserverh} ${_clienth} PROPERTIES GENERATED TRUE)
    ENDFOREACH (_current_FILE)
ENDMACRO(ORO_ADD_CORBA_SERVERS)

