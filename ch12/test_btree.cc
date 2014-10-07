#include <gtest/gtest.h>
#include "btree.h"

class Test_btree: public ::testing::Test {
public:
    btree<int> s;
    Test_btree() {
    }

private:
};

TEST_F(Test_btree, Construct) {

}

