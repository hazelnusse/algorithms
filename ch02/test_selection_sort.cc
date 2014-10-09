#include <algorithm>
#include <array>

#include <gtest/gtest.h>

#include "random_vector_test.h"
#include "selection_sort.h"

class Test_selection_sort: public ::Test_random_vector {};

TEST_F(Test_selection_sort, SortArray) {
    alg::selection_sort(begin(v), end(v));
    ASSERT_TRUE(std::is_sorted(begin(v), end(v)));
}

TEST_F(Test_selection_sort, ReverseSortArray) {
    using comp = std::greater<decltype(v)::value_type>;
    alg::selection_sort(begin(v), end(v), comp());
    ASSERT_TRUE(std::is_sorted(begin(v), end(v), comp()));
}


TEST_F(Test_selection_sort, Exercise2_1_1) {
    std::array<int, 6> a{31, 41, 59, 26, 41, 58};
    alg::selection_sort(begin(a), end(a));
    ASSERT_TRUE(std::is_sorted(begin(a), end(a)));
}

