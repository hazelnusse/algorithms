#include <array>

#include <gtest/gtest.h>

#include "linear_search.h"

class Test_linear_search: public ::testing::Test {
public:
    std::array<int, 5> ar;
    Test_linear_search() : ar{5, 2, 3, 1, 4} {
    }
};

TEST_F(Test_linear_search, SearchArray) {
    ASSERT_EQ(ar[0], *linear_search(ar.begin(), ar.end(), ar[0]));
    ASSERT_EQ(ar[1], *linear_search(ar.begin(), ar.end(), ar[1]));
    ASSERT_EQ(ar[2], *linear_search(ar.begin(), ar.end(), ar[2]));
    ASSERT_EQ(ar[3], *linear_search(ar.begin(), ar.end(), ar[3]));
    ASSERT_EQ(ar[4], *linear_search(ar.begin(), ar.end(), ar[4]));
    ASSERT_EQ(ar.end(), linear_search(ar.begin(), ar.end(), 234));
}

