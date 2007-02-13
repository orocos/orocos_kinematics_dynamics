IF( BUILD_TESTS )

  ENABLE_TESTING()
  INCLUDE_DIRECTORIES(${KDL_SOURCE_DIR})

  ADD_EXECUTABLE(framestest framestest.cpp)
  TARGET_LINK_LIBRARIES(framestest kdl)
  ADD_TEST(framestest framestest)

  ADD_EXECUTABLE(rframestest rframestest.cpp)
  TARGET_LINK_LIBRARIES(rframestest kdl)
  ADD_TEST(rframestest rframestest)

  ADD_EXECUTABLE(rallnumbertest rallnumbertest.cpp)
  TARGET_LINK_LIBRARIES(rallnumbertest kdl)
  ADD_TEST(rallnumbertest rallnumbertest)

  ADD_EXECUTABLE(serialchaintest serialchaintest.cpp)
  TARGET_LINK_LIBRARIES(serialchaintest kdl)
  ADD_TEST(serialchaintest serialchaintest)

  ADD_EXECUTABLE(iotest iotest.cpp)
  TARGET_LINK_LIBRARIES(iotest kdl)
  ADD_TEST(iotest iotest)

  ADD_EXECUTABLE(zxxzxztest zxxzxztest.cpp)
  TARGET_LINK_LIBRARIES(zxxzxztest kdl)
  ADD_TEST(zxxzxztest zxxzxztest)

  ADD_EXECUTABLE(jacobiantests jacobiantests.cpp jacobiandoubletests.cpp jacobianframetests.cpp)
  TARGET_LINK_LIBRARIES(jacobiantests kdl)
  ADD_TEST(jacobiantests jacobiantests)

#  ADD_EXECUTABLE(treetest treetest.cpp)
#  TARGET_LINK_LIBRARIES(treetest kdl)
#  ADD_TEST(treetest treetest)

  IF(OROCOS_PLUGIN)
    ADD_EXECUTABLE(toolkittest toolkittest.cpp)
    LINK_DIRECTORIES(${OROCOS_RTT_LINK_DIRS})
    TARGET_LINK_LIBRARIES(toolkittest kdltk kdl ${OROCOS_RTT_LIBS})
    ADD_TEST(toolkittest toolkittest)
  ENDIF(OROCOS_PLUGIN)

ENDIF( BUILD_TESTS )
