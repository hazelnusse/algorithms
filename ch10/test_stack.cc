#include <gtest/gtest.h>
#include "stack.h"

constexpr size_t STACK_SIZE = 7;
class Test_stack: public ::testing::Test {
public:
    stack<int, STACK_SIZE> s;
    Test_stack() {
    }

private:
};

TEST_F(Test_stack, Construct) {

}

TEST_F(Test_stack, PushPop) {
    s.push(15);
    s.push(6);
    s.push(2);
    s.push(9);
    ASSERT_EQ(9, s.pop());
    ASSERT_EQ(2, s.pop());
    ASSERT_EQ(6, s.pop());
    ASSERT_EQ(15, s.pop());
}

TEST_F(Test_stack, EmptyOnConstruct) {
    ASSERT_TRUE(s.empty());
}

TEST_F(Test_stack, NotFullOnConstruct) {
    ASSERT_FALSE(s.full());
}


TEST_F(Test_stack, NotEmptyOrFullAfterPush) {
    s.push(15);
    ASSERT_FALSE(s.empty());
    ASSERT_FALSE(s.full());
}

TEST_F(Test_stack, PopThrowsUnderflowWhenEmpty) {
    ASSERT_THROW(s.pop(), underflow);
}

TEST_F(Test_stack, PushThrowsOverflowWhenFull) {
    for (size_t i = 0; i < s.max_size(); ++i) {
        s.push(i);
    }
    ASSERT_TRUE(s.full());
    ASSERT_THROW(s.push(1), overflow);
}

TEST_F(Test_stack, MaxSize) {
    ASSERT_EQ(STACK_SIZE, s.max_size());
}
