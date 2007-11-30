ENABLE_TESTING()

#EXCLUDE_FROM_ALL is cmake 2.4.4
SET(DO_EXCLUDE)
IF (${CMAKE_VERSION} STRGREATER "2.4.3" )
  SET(DO_EXCLUDE EXCLUDE_FROM_ALL)
ENDIF (${CMAKE_VERSION} STRGREATER "2.4.3" )

INCLUDE_DIRECTORIES(${PROJ_SOURCE_DIR}/src)

ADD_EXECUTABLE(framestest ${DO_EXCLUDE} framestest.cpp test-runner.cpp)
TARGET_LINK_LIBRARIES(framestest orocos-kdl cppunit)
ADD_TEST(framestest framestest)

ADD_EXECUTABLE(kinfamtest ${DO_EXCLUDE} kinfamtest.cpp test-runner.cpp)
TARGET_LINK_LIBRARIES(kinfamtest orocos-kdl cppunit)
ADD_TEST(kinfamtest kinfamtest)

ADD_EXECUTABLE(solvertest ${DO_EXCLUDE} solvertest.cpp test-runner.cpp)
TARGET_LINK_LIBRARIES(solvertest orocos-kdl cppunit)
ADD_TEST(solvertest solvertest)

#ADD_EXECUTABLE(rframestest ${DO_EXCLUDE} rframestest.cpp)
#TARGET_LINK_LIBRARIES(rframestest orocos-kdl)
#ADD_TEST(rframestest rframestest)

#ADD_EXECUTABLE(rallnumbertest ${DO_EXCLUDE} rallnumbertest.cpp)
#TARGET_LINK_LIBRARIES(rallnumbertest orocos-kdl)
#ADD_TEST(rallnumbertest rallnumbertest)

# ADD_EXECUTABLE(serialchaintest serialchaintest.cpp)
#   TARGET_LINK_LIBRARIES(serialchaintest orocos-kdl)
#   ADD_TEST(serialchaintest serialchaintest)

#   ADD_EXECUTABLE(iotest iotest.cpp)
#   TARGET_LINK_LIBRARIES(iotest orocos-kdl)
#   ADD_TEST(iotest iotest)

#   ADD_EXECUTABLE(zxxzxztest zxxzxztest.cpp)
#   TARGET_LINK_LIBRARIES(zxxzxztest orocos-kdl)
#   ADD_TEST(zxxzxztest zxxzxztest)

#  ADD_EXECUTABLE(jacobiantests jacobiantests.cpp jacobiandoubletests.cpp jacobianframetests.cpp)
#  TARGET_LINK_LIBRARIES(jacobiantests orocos-kdl)
#  ADD_TEST(jacobiantests jacobiantests)

#  ADD_EXECUTABLE(treetest treetest.cpp)
#  TARGET_LINK_LIBRARIES(treetest orocos-kdl)
#  ADD_TEST(treetest treetest)

IF(OROCOS_PLUGIN)
  ADD_EXECUTABLE(toolkittest ${DO_EXCLUDE} toolkittest.cpp)
  LINK_DIRECTORIES(${OROCOS_RTT_LINK_DIRS})
  TARGET_LINK_LIBRARIES(toolkittest orocos-kdltk orocos-kdl ${OROCOS_RTT_LIBS})
  ADD_TEST(toolkittest toolkittest)
ENDIF(OROCOS_PLUGIN)

IF(PYTHON_BINDINGS)
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/framestest.py
    ${CMAKE_CURRENT_BINARY_DIR}/framestest.py COPY_ONLY)
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/kinfamtest.py
    ${CMAKE_CURRENT_BINARY_DIR}/kinfamtest.py COPY_ONLY)
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/frameveltest.py
    ${CMAKE_CURRENT_BINARY_DIR}/frameveltest.py COPY_ONLY)
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/PyKDLtest.py
    ${CMAKE_CURRENT_BINARY_DIR}/PyKDLtest.py COPY_ONLY)
  ADD_CUSTOM_COMMAND(OUTPUT PyKDLtest-make-exec
    COMMAND chmod ARGS +x ${CMAKE_CURRENT_BINARY_DIR}/PyKDLtest.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  ADD_TEST(PyKDLtest PyKDLtest.py)
ENDIF(PYTHON_BINDINGS)
    

ADD_CUSTOM_TARGET(check ctest -V 
  DEPENDS framestest kinfamtest solvertest PyKDLtest-make-exec# rframestest rallnumbertest 
  WORKING_DIRECTORY ${PROJ_BINARY_DIR}/tests)

