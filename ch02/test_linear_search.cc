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
    ASSERT_EQ(ar[0], *alg::linear_search(begin(ar), end(ar), ar[0]));
    ASSERT_EQ(ar[1], *alg::linear_search(begin(ar), end(ar), ar[1]));
    ASSERT_EQ(ar[2], *alg::linear_search(begin(ar), end(ar), ar[2]));
    ASSERT_EQ(ar[3], *alg::linear_search(begin(ar), end(ar), ar[3]));
    ASSERT_EQ(ar[4], *alg::linear_search(begin(ar), end(ar), ar[4]));
    ASSERT_EQ(end(ar), alg::linear_search(begin(ar), end(ar), 234));
    ASSERT_EQ(end(ar), alg::linear_search(begin(ar), end(ar), -234));
}

