#ifndef RANDOM_VECTOR_TEST
#define RANDOM_VECTOR_TEST

#include <random>
#include <vector>
#include <gtest/gtest.h>

class Test_random_vector: public ::testing::Test {
public:
    std::random_device rd;
    std::default_random_engine engine;
    std::uniform_int_distribution<int> dist;
    std::vector<int> v;
    Test_random_vector() : rd{}, engine{rd()}, dist{100, 1000}, v(dist(rd))
    {
        for (auto& vi : v) {
            vi = dist(engine);
        }
    }
};

#endif

