IF(ENABLE_TESTS)
  ENABLE_TESTING()

  # kdl_add_test(<name> [extra sources...]): builds <name>.cpp with the shared
  # test runner, links it against orocos-kdl and registers it with CTest.
  FUNCTION(kdl_add_test name)
    ADD_EXECUTABLE(${name} ${name}.cpp test-runner.cpp ${ARGN})
    TARGET_LINK_LIBRARIES(${name} PRIVATE orocos-kdl ${CPPUNIT})
    TARGET_INCLUDE_DIRECTORIES(${name} PRIVATE ${CPPUNIT_HEADERS} ${PROJ_SOURCE_DIR}/src)
    TARGET_COMPILE_DEFINITIONS(${name} PRIVATE TESTNAME="${name}")
    ADD_TEST(NAME ${name} COMMAND ${name})
  ENDFUNCTION()

  kdl_add_test(framestest)
  kdl_add_test(kinfamtest)
  kdl_add_test(solvertest)
  kdl_add_test(inertiatest)
  kdl_add_test(jacobiantest)
  kdl_add_test(jacobiandottest)
  kdl_add_test(velocityprofiletest)
  kdl_add_test(pathtest)
  kdl_add_test(treeinvdyntest)

  ADD_CUSTOM_TARGET(check ctest -V WORKING_DIRECTORY ${PROJ_BINARY_DIR}/tests)
ENDIF(ENABLE_TESTS)
