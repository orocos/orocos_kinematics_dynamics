
#Generate all files required for a corba server app.
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

