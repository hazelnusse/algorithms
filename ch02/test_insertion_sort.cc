#include <algorithm>
#include <array>

#include <gtest/gtest.h>

#include "insertion_sort.h"
#include "print.h"
#include "random_vector_test.h"

class Test_insertion_sort: public ::Test_random_vector {};

TEST_F(Test_insertion_sort, SortArray) {
    insertion_sort(v.begin(), v.end());
    ASSERT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST_F(Test_insertion_sort, ReverseSortArray) {
    using comp = std::greater<decltype(v)::value_type>;
    insertion_sort(v.begin(), v.end(), comp());
    ASSERT_TRUE(std::is_sorted(v.begin(), v.end(), comp()));
}

TEST_F(Test_insertion_sort, Exercise2_1_1) {
    std::array<int, 6> a{31, 41, 59, 26, 41, 58};
    for (auto it = a.begin() + 1; it != a.end() + 1; ++it) {
        insertion_sort(a.begin(), it);
        print(a);
    }
}

