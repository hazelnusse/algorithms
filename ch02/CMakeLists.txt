include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_insertion_sort test_insertion_sort.cc)
target_link_libraries(test_insertion_sort ${GTEST_BOTH_LIBRARIES})
add_test(Test_insertion_sort test_insertion_sort)

add_executable(test_linear_search test_linear_search.cc)
target_link_libraries(test_linear_search ${GTEST_BOTH_LIBRARIES})
add_test(Test_linear_search test_linear_search)

