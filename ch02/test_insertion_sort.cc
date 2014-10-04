#include <algorithm>
#include <array>
#include <iostream>

#include <gtest/gtest.h>

#include "insertion_sort.h"

template <class Container>
void print(const Container& c) {
    std::copy(c.begin(), c.end(),
            std::ostream_iterator<typename Container::value_type>(std::cout, ", "));
    std::cout << "\n";
}

class Test_insertion_sort: public ::testing::Test {
public:
    std::array<int, 5> ar;
    Test_insertion_sort() : ar{5, 2, 3, 1, 4} {
    }
};

TEST_F(Test_insertion_sort, SortArray) {
    auto ar_copy = ar;
    insertion_sort(ar.begin(), ar.end());
    std::sort(ar_copy.begin(), ar_copy.end());
    ASSERT_EQ(ar_copy, ar);
}

TEST_F(Test_insertion_sort, Exercise2_1_1) {
    std::array<int, 6> a{31, 41, 59, 26, 41, 58};
    for (auto it = a.begin() + 1; it != a.end() + 1; ++it) {
        insertion_sort(a.begin(), it);
        print(a);
    }
}

TEST_F(Test_insertion_sort, ReverseSortArray) {
    using comp = std::greater<decltype(ar)::value_type>;
    auto ar_copy = ar;
    insertion_sort(ar.begin(), ar.end(), comp());
    print(ar);
    std::sort(ar_copy.begin(), ar_copy.end(), comp());
    print(ar_copy);
    ASSERT_EQ(ar_copy, ar);
}
