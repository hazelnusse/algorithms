#include <bitset>

#include <gtest/gtest.h>

#include "sum_n_bit_binary_integers.h"

class Test_sum: public ::testing::Test {
public:
    std::bitset<5> a;
    std::bitset<5> b;
    Test_sum() : a{}, b{} {}
};

TEST_F(Test_sum, Sum) {
    a = decltype(a){"10111"};
    b = decltype(b){"10111"};
    ASSERT_EQ(std::bitset<6>{"101110"}, sum(a, b));
    a = decltype(a){"10101"};
    b = decltype(b){"01010"};
    ASSERT_EQ(std::bitset<6>{"011111"}, sum(a, b));
    a = decltype(a){"00000"};
    b = decltype(b){"00000"};
    ASSERT_EQ(std::bitset<6>{"000000"}, sum(a, b));
}

