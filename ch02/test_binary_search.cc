#include <algorithm>
#include <iostream>

#include <gtest/gtest.h>

#include "random_vector_test.h"
#include "binary_search.h"

class Test_binary_search: public ::Test_random_vector {};

TEST_F(Test_binary_search, FindsElementsInVector) {
    std::sort(v.begin(), v.end());
    for (std::size_t i = 0; i != v.size(); ++i) {
        auto result = binary_search(begin(v), end(v), v[i]);
        if (result == end(v)) {
            ASSERT_FALSE(std::binary_search(begin(v), end(v), v[i])); // STL binary search
        } else {
            ASSERT_TRUE(std::binary_search(begin(v), end(v), v[i]));  // STL binary search
            ASSERT_EQ(v[i], *result);   // values compare equal
        }
    }
}

TEST_F(Test_binary_search, FindsElementsInReverseVector) {
    using comp = std::greater<decltype(v)::value_type>;
    std::sort(v.begin(), v.end(), comp());
    for (std::size_t i = 0; i != v.size(); ++i) {
        auto result = binary_search(begin(v), end(v), v[i], comp());
        if (result == end(v)) {
            ASSERT_FALSE(std::binary_search(begin(v), end(v), v[i], comp())); // STL binary search
        } else {
            ASSERT_TRUE(std::binary_search(begin(v), end(v), v[i], comp()));  // STL binary search
            ASSERT_EQ(v[i], *result);   // values compare equal
        }
    }
}

