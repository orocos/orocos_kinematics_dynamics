IF(ENABLE_TESTS)
  ENABLE_TESTING()

  # kdl_add_test(<name> [extra sources...]): builds <name>.cpp with the shared
  # test runner, links it against orocos-kdl and registers it with CTest.
  FUNCTION(kdl_add_test name)
    ADD_EXECUTABLE(${name} ${name}.cpp test-runner.cpp ${ARGN})
    TARGET_LINK_LIBRARIES(${name} PRIVATE orocos-kdl ${CPPUNIT})
    TARGET_INCLUDE_DIRECTORIES(${name} PRIVATE ${CPPUNIT_HEADERS})
    TARGET_COMPILE_DEFINITIONS(${name} PRIVATE TESTNAME="${name}")
    ADD_TEST(NAME ${name} COMMAND ${name})
    SET_PROPERTY(GLOBAL APPEND PROPERTY KDL_TEST_TARGETS ${name})
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
  kdl_add_test(framesconsistencytest)

  # indexcheck aborts on purpose (assert), so it has its own main and no CppUnit runner.
  # CTest only evaluates PASS_REGULAR_EXPRESSION for processes that exit normally, not for
  # ones killed by SIGABRT, so the shell turns the abort into an ordinary exit status.
  ADD_EXECUTABLE(indexcheck indexcheck.cpp)
  TARGET_LINK_LIBRARIES(indexcheck PRIVATE orocos-kdl)
  ADD_TEST(NAME indexcheck COMMAND sh -c "$<TARGET_FILE:indexcheck> 2>&1; true")
  SET_TESTS_PROPERTIES(indexcheck PROPERTIES PASS_REGULAR_EXPRESSION "Assertion.*failed|Assertion failed")

  IF(ENABLE_COVERAGE)
    # Zero the counters, run the tests, capture, keep only the library sources,
    # render HTML and check the result against coverage.json.
    SET(KDL_COVERAGE_DIR ${CMAKE_BINARY_DIR}/coverage)
    ADD_CUSTOM_TARGET(coverage
      COMMAND ${CMAKE_COMMAND} -E make_directory ${KDL_COVERAGE_DIR}
      COMMAND lcov --zerocounters -d ${CMAKE_BINARY_DIR}
      COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_CURRENT_BINARY_DIR} ctest
      COMMAND lcov --capture -d ${CMAKE_BINARY_DIR} -o ${KDL_COVERAGE_DIR}/raw.info
              --ignore-errors mismatch,inconsistent,unused,negative,gcov
      COMMAND lcov --extract ${KDL_COVERAGE_DIR}/raw.info "*/orocos_kdl/src/*" "*/orocos_kdl/include/kdl/*"
              -o ${KDL_COVERAGE_DIR}/kdl.info --ignore-errors unused,inconsistent
      COMMAND genhtml ${KDL_COVERAGE_DIR}/kdl.info -o ${KDL_COVERAGE_DIR}/html
              --ignore-errors inconsistent
      COMMAND lcov --summary ${KDL_COVERAGE_DIR}/kdl.info
      COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/coverage_check.py
              ${KDL_COVERAGE_DIR}/kdl.info ${CMAKE_CURRENT_SOURCE_DIR}/coverage.json
      COMMENT "Measuring test coverage")
    GET_PROPERTY(KDL_TEST_TARGETS GLOBAL PROPERTY KDL_TEST_TARGETS)
    ADD_DEPENDENCIES(coverage ${KDL_TEST_TARGETS})
  ENDIF()

  ADD_CUSTOM_TARGET(check ctest -V WORKING_DIRECTORY ${PROJ_BINARY_DIR}/tests)
ENDIF(ENABLE_TESTS)
