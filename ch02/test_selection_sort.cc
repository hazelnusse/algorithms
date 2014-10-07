#include <algorithm>
#include <array>
#include <iostream>

#include <gtest/gtest.h>

#include "selection_sort.h"

template <class Container>
void print(const Container& c) {
    std::copy(c.begin(), c.end(),
            std::ostream_iterator<typename Container::value_type>(std::cout, ", "));
    std::cout << "\n";
}

class Test_selection_sort: public ::testing::Test {
public:
    std::array<int, 5> ar;
    Test_selection_sort() : ar{5, 1, 3, 1, 4} {
    }
};

TEST_F(Test_selection_sort, FindMin) {
    ASSERT_EQ(&ar[1], min(ar.begin(), ar.end()));
    std::sort(ar.begin(), ar.end());
    ASSERT_EQ(&ar[0], min(ar.begin(), ar.end()));

}

TEST_F(Test_selection_sort, SortArray) {
    auto ar_copy = ar;
    selection_sort(ar.begin(), ar.end());
    std::sort(ar_copy.begin(), ar_copy.end());
    ASSERT_EQ(ar_copy, ar);
}

TEST_F(Test_selection_sort, Exercise2_1_1) {
    std::array<int, 6> a{31, 41, 59, 26, 41, 58};
    std::array<int, 6> a_copy  = a;
    selection_sort(a.begin(), a.end());
    std::sort(a_copy.begin(), a_copy.end());
    ASSERT_EQ(a_copy, a);
}
