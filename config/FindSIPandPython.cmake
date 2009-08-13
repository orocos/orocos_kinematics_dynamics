# CMake module which checks for python and some its modules
# there is a two-stage support for python:
# - 

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJ_SOURCE_DIR}/config)
FIND_PACKAGE(PythonLibrary)

# enable/disable python support (mapserver export tool and bindings)
IF (PYTHON_LIBRARIES AND PYTHON_INCLUDE_PATH)
  SET (PYTHON_FOUND TRUE)
  MESSAGE(STATUS "Python libraries found")

  # TODO: should not be needed, report it to CMake devs
  IF (UNIX AND NOT APPLE)
    SET (PYTHON_LIBRARIES ${PYTHON_LIBRARIES} util)
  ENDIF (UNIX AND NOT APPLE)
  FIND_PACKAGE(SIP)
  #INCLUDE(${PROJ_SOURCE_DIR}/config/FindSIP.cmake)
  IF (SIP_FOUND)
    # check for SIP version
    # minimal version is 4.4
    SET (SIP_MIN_VERSION 040709)
    IF (SIP_VERSION EQUAL "${SIP_MIN_VERSION}" OR SIP_VERSION GREATER "${SIP_MIN_VERSION}")
      SET (SIP_IS_GOOD TRUE)
    ENDIF (SIP_VERSION EQUAL "${SIP_MIN_VERSION}" OR SIP_VERSION GREATER "${SIP_MIN_VERSION}")
    
    IF (NOT SIP_IS_GOOD)
      MESSAGE (STATUS "SIP is required in version 4.7.9 or later!")
    ENDIF (NOT SIP_IS_GOOD)
  ELSE (SIP_FOUND)
    MESSAGE (STATUS "SIP not found!")
  ENDIF (SIP_FOUND)
  
  # if SIP is found, enable bindings
  IF (SIP_IS_GOOD)
    SET (HAVE_PYTHON TRUE)
    MESSAGE(STATUS "Python bindings enabled")
  ELSE (SIP_IS_GOOD)
    SET (HAVE_PYTHON FALSE)
    MESSAGE(STATUS "Python bindings disabled due dependency problems!")
  ENDIF (SIP_IS_GOOD)
  
ENDIF (PYTHON_LIBRARIES AND PYTHON_INCLUDE_PATH)