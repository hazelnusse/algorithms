#include <algorithm>
#include <array>

#include <gtest/gtest.h>

#include "random_vector_test.h"
#include "selection_sort.h"

class Test_selection_sort: public ::Test_random_vector {};

TEST_F(Test_selection_sort, SortArray) {
    selection_sort(v.begin(), v.end());
    ASSERT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST_F(Test_selection_sort, ReverseSortArray) {
    using comp = std::greater<decltype(v)::value_type>;
    selection_sort(v.begin(), v.end(), comp());
    ASSERT_TRUE(std::is_sorted(v.begin(), v.end(), comp()));
}


TEST_F(Test_selection_sort, Exercise2_1_1) {
    std::array<int, 6> a{31, 41, 59, 26, 41, 58};
    selection_sort(a.begin(), a.end());
    ASSERT_TRUE(std::is_sorted(a.begin(), a.end()));
}

