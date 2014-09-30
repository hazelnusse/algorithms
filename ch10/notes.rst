Stacks & Queues & Deques
========================
element removed by delete operation is prespecified: stack deletes the most
recently inserted (LIFO), queue deletes the element in the set for the longest
time (FIFO)

Stacks
------
fixed size implementation will throw an overflow exception if push is call when
the stack is full.
will throw underflow exception if pop is called when stack is empty.
implemented using an std::array, complexity of push(), pop(), empty(), and full() is O(1).

Queues
------
Fixed size implementation works a bit differently than in the text.  Instead of
using an array of size N+1 to implement a queue of N elements, I use an array of
size N and add some boolean flags that indicate whether the queue is empty or
full.  It is marginally less time efficient but more space efficient (by 1
element) this way, so it might be good if the items in the queue are really
large. The implementation requires that the template type T implements a copy
assignment operator and that this operator frees any resources.  An additional
implementation using the approach outlined in the book is implemented in
queue_alternate.h

Deque
-----
This was implemented to complete exercise 10-1.5. It provides constant time
insertion and deletion from front or back and is implemented using a fixed size
array of size N+1, where N is the number of elements the deque can hold (i.e.,
one element is wasted as in the implementation of queue_alternate.h).

