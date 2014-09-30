include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_stack test_stack.cc)
target_link_libraries(test_stack ${GTEST_BOTH_LIBRARIES})
add_test(Test_stack test_stack)

add_executable(test_queue test_queue.cc)
target_link_libraries(test_queue ${GTEST_BOTH_LIBRARIES})
add_test(Test_queue test_queue)

add_executable(test_queue_alternate test_queue_alternate.cc)
target_link_libraries(test_queue_alternate ${GTEST_BOTH_LIBRARIES})
add_test(Test_queue_alternate test_queue_alternate)

add_executable(test_deque test_deque.cc)
target_link_libraries(test_deque ${GTEST_BOTH_LIBRARIES})
add_test(Test_deque test_deque)

add_executable(test_list test_list.cc)
target_link_libraries(test_list ${GTEST_BOTH_LIBRARIES})
add_test(Test_list test_list)

