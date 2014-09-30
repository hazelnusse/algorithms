
#include <gtest/gtest.h>
#include "deque.h"

constexpr size_t DEQUE_SIZE = 7;
class Test_deque: public ::testing::Test {
public:
    deque<int, DEQUE_SIZE> d;
    Test_deque() {
    }

private:
};

TEST_F(Test_deque, Construct) {

}

TEST_F(Test_deque, EmptyOnConstruct) {
    ASSERT_TRUE(d.empty());
    ASSERT_FALSE(d.full());
}

TEST_F(Test_deque, DequeSize) {
    ASSERT_EQ(DEQUE_SIZE, d.max_size());
}

TEST_F(Test_deque, EnqueueDequeue) {
    for (size_t i = 0; i < 3*DEQUE_SIZE; ++i) {
        d.enqueue_front(i);
        d.enqueue_back(i);
        ASSERT_FALSE(d.empty());
        ASSERT_FALSE(d.full());
        ASSERT_EQ(i, d.dequeue_front());
        ASSERT_EQ(i, d.dequeue_back());
        ASSERT_TRUE(d.empty());
        ASSERT_FALSE(d.full());
    }
}

TEST_F(Test_deque, EnqueueFrontDequeueBack) {
    d.enqueue_front(1);
    d.enqueue_front(2);
    ASSERT_EQ(1, d.dequeue_back());
    ASSERT_EQ(2, d.dequeue_back());
}

TEST_F(Test_deque, DequeueFrontEnqueueBack) {
    d.enqueue_back(1);
    d.enqueue_back(2);
    ASSERT_EQ(1, d.dequeue_front());
    ASSERT_EQ(2, d.dequeue_front());
}

TEST_F(Test_deque, OverFlowTest) {
    for (size_t i = 0; i < d.max_size(); ++i) {
        d.enqueue_back(i);
    }
    ASSERT_TRUE(d.full());
    ASSERT_THROW(d.enqueue_back(1), overflow);
    ASSERT_THROW(d.enqueue_front(1), overflow);
}

TEST_F(Test_deque, UnderFlowTest) {
    ASSERT_TRUE(d.empty());
    ASSERT_THROW(d.dequeue_front(), underflow);
    ASSERT_THROW(d.dequeue_back(), underflow);
}

