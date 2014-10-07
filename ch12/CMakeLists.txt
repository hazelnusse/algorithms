include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_btree test_btree.cc)
target_link_libraries(test_btree ${GTEST_BOTH_LIBRARIES})
add_test(Test_btree test_btree)

