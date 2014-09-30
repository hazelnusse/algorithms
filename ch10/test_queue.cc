#include <gtest/gtest.h>
#include "queue.h"

constexpr size_t QUEUE_SIZE = 5;

class Test_queue: public ::testing::Test {
public:
    queue<int, QUEUE_SIZE> q;
    Test_queue() {
    }

private:
};

TEST_F(Test_queue, Construct) {

}

TEST_F(Test_queue, EmptyOnConstruct) {
    ASSERT_TRUE(q.empty());
    ASSERT_FALSE(q.full());
}
TEST_F(Test_queue, MaxSize) {
    ASSERT_EQ(QUEUE_SIZE, q.max_size());
}

TEST_F(Test_queue, EnqueueDequeue) {
    for (size_t i = 0; i < q.max_size(); ++i) {
        q.enqueue(i);
        ASSERT_FALSE(q.empty());
    }
    ASSERT_TRUE(q.full());
    ASSERT_THROW(q.enqueue(1), overflow);
    ASSERT_TRUE(q.full());

    for (size_t i = 0; i < q.max_size(); ++i) {
        ASSERT_EQ(i, q.dequeue());
        ASSERT_FALSE(q.full());
    }
    ASSERT_TRUE(q.empty());
    ASSERT_THROW(q.dequeue(), underflow);
}

TEST_F(Test_queue, WrapAround) {
    for (size_t i = 0; i < 2*q.max_size(); ++i) {
        q.enqueue(i);
        ASSERT_EQ(i, q.dequeue());
        ASSERT_TRUE(q.empty());
        ASSERT_FALSE(q.full());
    }
}

