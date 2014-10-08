#include <algorithm>
#include <array>

#include <gtest/gtest.h>

#include "random_vector_test.h"
#include "merge_sort.h"

class Test_merge_sort: public ::Test_random_vector {};

TEST_F(Test_merge_sort, Merge) {
    std::array<int, 5> ar{3, 4, 5, 1, 3};
    merge(ar.begin(), ar.begin() + 3, ar.end());
    std::array<int, 5> expected{1, 3, 3, 4, 5};
    ASSERT_EQ(expected, ar);
}

TEST_F(Test_merge_sort, MergeLengthOne) {
    std::array<int, 1> ar{1};
    merge(ar.begin(), ar.begin(), ar.end());
    std::array<int, 1> expected{1};
    ASSERT_EQ(expected, ar);
}

TEST_F(Test_merge_sort, MergeSort) {
    ASSERT_FALSE(std::is_sorted(v.begin(), v.end()));
    merge_sort(v.begin(), v.end());
    ASSERT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST_F(Test_merge_sort, MergeSortReverse) {
    using comp = std::greater<decltype(v)::value_type>;
    ASSERT_FALSE(std::is_sorted(v.begin(), v.end(), comp()));
    merge_sort(v.begin(), v.end(), comp());
    ASSERT_TRUE(std::is_sorted(v.begin(), v.end(), comp()));
}

