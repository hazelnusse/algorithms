#include <gtest/gtest.h>
#include "list.h"

class Test_list : public ::testing::Test {
public:
    list<int> l;
    Test_list() {
    }

private:
};

TEST_F(Test_list, Construct) {

}

TEST_F(Test_list, Insert) {
    l.insert(5);
}

TEST_F(Test_list, SearchEmptyList) {
    ASSERT_EQ(nullptr, l.search(5));
}

TEST_F(Test_list, SearchList) {
    l.insert(5);
    ASSERT_EQ(5, l.search(5)->key);
}

TEST_F(Test_list, DeleteElement) {
    l.insert(5);
    l.remove(l.search(5));
    ASSERT_TRUE(l.empty());
}

