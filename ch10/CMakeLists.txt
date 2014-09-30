include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_stack test_stack.cc)
target_link_libraries(test_stack ${GTEST_BOTH_LIBRARIES})
add_test(Test_stack test_stack)

