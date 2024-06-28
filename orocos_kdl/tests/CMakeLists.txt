IF(ENABLE_TESTS)
  ENABLE_TESTING()

  INCLUDE_DIRECTORIES(${PROJ_SOURCE_DIR}/src ${CPPUNIT_HEADERS} ${PROJECT_BINARY_DIR}/src)

  ADD_EXECUTABLE(framestest framestest.cpp test-runner.cpp)
  TARGET_LINK_LIBRARIES(framestest orocos-kdl ${CPPUNIT})
  target_compile_definitions(framestest PRIVATE TESTNAME="framestest")
  ADD_TEST(NAME framestest COMMAND framestest)

 ADD_EXECUTABLE(kinfamtest kinfamtest.cpp test-runner.cpp)
 TARGET_LINK_LIBRARIES(kinfamtest orocos-kdl ${CPPUNIT})
  target_compile_definitions(kinfamtest PRIVATE TESTNAME="kinfamtest")
 ADD_TEST(NAME kinfamtest COMMAND kinfamtest)

 ADD_EXECUTABLE(solvertest solvertest.cpp test-runner.cpp)
 TARGET_LINK_LIBRARIES(solvertest orocos-kdl ${CPPUNIT})
  target_compile_definitions(solvertest PRIVATE TESTNAME="solvertest")
 ADD_TEST(NAME solvertest COMMAND solvertest)

 ADD_EXECUTABLE(inertiatest inertiatest.cpp test-runner.cpp)
 TARGET_LINK_LIBRARIES(inertiatest orocos-kdl ${CPPUNIT})
  target_compile_definitions(inertiatest PRIVATE TESTNAME="inertiatest")
 ADD_TEST(NAME inertiatest COMMAND inertiatest)

 ADD_EXECUTABLE(jacobiantest jacobiantest.cpp test-runner.cpp)
 TARGET_LINK_LIBRARIES(jacobiantest orocos-kdl ${CPPUNIT})
  target_compile_definitions(jacobiantest PRIVATE TESTNAME="jacobiantest")
 ADD_TEST(NAME jacobiantest COMMAND jacobiantest)

 ADD_EXECUTABLE(jacobiandottest jacobiandottest.cpp test-runner.cpp)
 TARGET_LINK_LIBRARIES(jacobiandottest orocos-kdl ${CPPUNIT})
  target_compile_definitions(jacobiandottest PRIVATE TESTNAME="jacobiandottest")
 ADD_TEST(NAME jacobiandottest COMMAND jacobiandottest)

 ADD_EXECUTABLE(velocityprofiletest velocityprofiletest.cpp test-runner.cpp)
 TARGET_LINK_LIBRARIES(velocityprofiletest orocos-kdl ${CPPUNIT})
  target_compile_definitions(velocityprofiletest PRIVATE TESTNAME="velocityprofiletest")
 ADD_TEST(NAME velocityprofiletest COMMAND velocityprofiletest)

 ADD_EXECUTABLE(treeinvdyntest treeinvdyntest.cpp test-runner.cpp)
 TARGET_LINK_LIBRARIES(treeinvdyntest orocos-kdl ${CPPUNIT})
  target_compile_definitions(treeinvdyntest PRIVATE TESTNAME="treeinvdyntest")
 ADD_TEST(NAME treeinvdyntest COMMAND treeinvdyntest)

#  ADD_EXECUTABLE(rallnumbertest  rallnumbertest.cpp)
#  TARGET_LINK_LIBRARIES(rallnumbertest orocos-kdl)
#  ADD_TEST(NAME rallnumbertest COMMAND rallnumbertest)

  ADD_CUSTOM_TARGET(check ctest -V WORKING_DIRECTORY ${PROJ_BINARY_DIR}/tests)
ENDIF(ENABLE_TESTS)
