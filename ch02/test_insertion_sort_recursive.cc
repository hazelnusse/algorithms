#include <algorithm>

#include <gtest/gtest.h>

#include "random_vector_test.h"
#include "insertion_sort_recursive.h"

class Test_insertion_sort_recursive: public ::Test_random_vector {};

TEST_F(Test_insertion_sort_recursive, SortArray) {
    insertion_sort_recursive(v.begin(), v.end());
    ASSERT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST_F(Test_insertion_sort_recursive, ReverseSortArray) {
    using comp = std::greater<decltype(v)::value_type>;
    insertion_sort_recursive(v.begin(), v.end(), comp());
    ASSERT_TRUE(std::is_sorted(v.begin(), v.end(), comp()));
}

