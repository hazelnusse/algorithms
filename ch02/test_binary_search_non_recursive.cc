#include <algorithm>
#include <array>
#include <iostream>

#include <gtest/gtest.h>

#include "random_vector_test.h"
#include "binary_search_non_recursive.h"

class Test_binary_search_non_recursive: public ::Test_random_vector {};

TEST_F(Test_binary_search_non_recursive, FindsElementsInVector) {
    std::sort(v.begin(), v.end());
    for (std::size_t i = 0; i != v.size(); ++i) {
        auto result = alg::binary_search_non_recursive(begin(v), end(v), v[i]);
        if (result == end(v)) {
            ASSERT_FALSE(std::binary_search(begin(v), end(v), v[i])); // STL binary search
        } else {
            ASSERT_TRUE(std::binary_search(begin(v), end(v), v[i]));  // STL binary search
            ASSERT_EQ(v[i], *result);   // values compare equal
        }
    }
}

TEST_F(Test_binary_search_non_recursive, FindsElementsInReverseVector) {
    using comp = std::greater<decltype(v)::value_type>;
    std::sort(v.begin(), v.end(), comp());
    for (std::size_t i = 0; i != v.size(); ++i) {
        auto result = alg::binary_search_non_recursive(begin(v), end(v), v[i], comp());
        if (result == end(v)) {
            ASSERT_FALSE(std::binary_search(begin(v), end(v), v[i], comp())); // STL binary search
        } else {
            ASSERT_TRUE(std::binary_search(begin(v), end(v), v[i], comp()));  // STL binary search
            ASSERT_EQ(v[i], *result);   // values compare equal
        }
    }
    ASSERT_EQ(end(v), alg::binary_search_non_recursive(begin(v), end(v), v[0]+1, comp()));
}

TEST_F(Test_binary_search_non_recursive, FindsElementInLengthOneArray) {
    std::array<int, 1> ar{1};
    ASSERT_EQ(begin(ar), alg::binary_search_non_recursive(begin(ar), end(ar), ar[0]));
    ASSERT_EQ(end(ar), alg::binary_search_non_recursive(begin(ar), end(ar), 5));
}

