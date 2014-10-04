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
    insertion_sort(ar.begin(), ar.end());
    auto std_sorted = ar;
    std::sort(ar.begin(), ar.end());
    ASSERT_EQ(std_sorted, ar);
}

TEST_F(Test_insertion_sort, Exercise2_1_1) {
    std::array<int, 6> a{31, 41, 59, 26, 41, 58};
    for (auto it = a.begin() + 1; it != a.end() + 1; ++it) {
        insertion_sort(a.begin(), it);
        print(a);
    }
}
