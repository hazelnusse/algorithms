#include <algorithm>

#include <gtest/gtest.h>

#include "random_vector_test.h"
#include "insertion_sort_recursive.h"

class Test_insertion_sort_recursive: public ::Test_random_vector {};

TEST_F(Test_insertion_sort_recursive, SortArray) {
    alg::insertion_sort_recursive(begin(v), end(v));
    ASSERT_TRUE(std::is_sorted(begin(v), end(v)));
}

TEST_F(Test_insertion_sort_recursive, ReverseSortArray) {
    using comp = std::greater<decltype(v)::value_type>;
    alg::insertion_sort_recursive(begin(v), end(v), comp());
    ASSERT_TRUE(std::is_sorted(begin(v), end(v), comp()));
}

