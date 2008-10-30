IF(ENABLE_TESTS)
  ENABLE_TESTING()

  INCLUDE_DIRECTORIES(${PROJ_SOURCE_DIR}/src)
  
  ADD_EXECUTABLE(framestest framestest.cpp test-runner.cpp)
  TARGET_LINK_LIBRARIES(framestest orocos-kdl ${CPPUNIT})
  ADD_TEST(framestest framestest)
  
  ADD_EXECUTABLE(kinfamtest kinfamtest.cpp test-runner.cpp)
  TARGET_LINK_LIBRARIES(kinfamtest orocos-kdl ${CPPUNIT})
  ADD_TEST(kinfamtest kinfamtest)

  ADD_EXECUTABLE(solvertest solvertest.cpp test-runner.cpp)
  TARGET_LINK_LIBRARIES(solvertest orocos-kdl ${CPPUNIT})
  ADD_TEST(solvertest solvertest)

  #ADD_EXECUTABLE(rframestest  rframestest.cpp)
  #TARGET_LINK_LIBRARIES(rframestest orocos-kdl)
  #ADD_TEST(rframestest rframestest)

  #ADD_EXECUTABLE(rallnumbertest  rallnumbertest.cpp)
  #TARGET_LINK_LIBRARIES(rallnumbertest orocos-kdl)
  #ADD_TEST(rallnumbertest rallnumbertest)

  
#  IF(OROCOS_PLUGIN)
#    ADD_EXECUTABLE(toolkittest toolkittest.cpp)
#    LINK_DIRECTORIES(${OROCOS_RTT_LINK_DIRS})
#    TARGET_LINK_LIBRARIES(toolkittest orocos-kdltk orocos-kdl ${OROCOS_RTT_LIBS})
#    ADD_TEST(toolkittest toolkittest)
#  ENDIF(OROCOS_PLUGIN)

  IF(PYTHON_BINDINGS)
    CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/framestest.py
      ${CMAKE_CURRENT_BINARY_DIR}/framestest.py COPY_ONLY)
    CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/kinfamtest.py
      ${CMAKE_CURRENT_BINARY_DIR}/kinfamtest.py COPY_ONLY)
    CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/frameveltest.py
      ${CMAKE_CURRENT_BINARY_DIR}/frameveltest.py COPY_ONLY)
    CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/PyKDLtest.py
      ${CMAKE_CURRENT_BINARY_DIR}/PyKDLtest.py COPY_ONLY)
    ADD_TEST(PyKDLtest PyKDLtest.py)
    
   
  ENDIF(PYTHON_BINDINGS)
  
  ADD_CUSTOM_TARGET(check ctest -V WORKING_DIRECTORY ${PROJ_BINARY_DIR}/tests)
ENDIF(ENABLE_TESTS)  

