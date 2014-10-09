#include <algorithm>
#include <array>

#include <gtest/gtest.h>

#include "random_vector_test.h"
#include "merge_sort.h"

class Test_merge_sort: public ::Test_random_vector {};

TEST_F(Test_merge_sort, Merge) {
    std::array<int, 5> ar{3, 4, 5, 1, 3};
    alg::merge(begin(ar), begin(ar) + 3, end(ar));
    std::array<int, 5> expected{1, 3, 3, 4, 5};
    ASSERT_EQ(expected, ar);
}

TEST_F(Test_merge_sort, MergeLengthOne) {
    std::array<int, 1> ar{1};
    alg::merge(begin(ar), begin(ar), end(ar));
    std::array<int, 1> expected{1};
    ASSERT_EQ(expected, ar);
}

TEST_F(Test_merge_sort, MergeSort) {
    ASSERT_FALSE(std::is_sorted(begin(v), end(v)));
    alg::merge_sort(begin(v), end(v));
    ASSERT_TRUE(std::is_sorted(begin(v), end(v)));
}

TEST_F(Test_merge_sort, MergeSortReverse) {
    using comp = std::greater<decltype(v)::value_type>;
    ASSERT_FALSE(std::is_sorted(begin(v), end(v), comp()));
    alg::merge_sort(begin(v), end(v), comp());
    ASSERT_TRUE(std::is_sorted(begin(v), end(v), comp()));
}

