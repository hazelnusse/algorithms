#include <gtest/gtest.h>
#include "queue_alternate.h"

constexpr size_t QUEUE_SIZE = 5;

class Test_queue_alternate: public ::testing::Test {
public:
    queue_alternate<int, QUEUE_SIZE> q;
    Test_queue_alternate() {
    }

private:
};

TEST_F(Test_queue_alternate, Construct) {

}

TEST_F(Test_queue_alternate, EmptyOnConstruct) {
    ASSERT_TRUE(q.empty());
    ASSERT_FALSE(q.full());
}
TEST_F(Test_queue_alternate, MaxSize) {
    ASSERT_EQ(QUEUE_SIZE, q.max_size());
}

TEST_F(Test_queue_alternate, EnqueueDequeue) {
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

TEST_F(Test_queue_alternate, WrapAround) {
    for (size_t i = 0; i < 2*q.max_size(); ++i) {
        q.enqueue(i);
        ASSERT_EQ(i, q.dequeue());
        ASSERT_TRUE(q.empty());
        ASSERT_FALSE(q.full());
    }
}

