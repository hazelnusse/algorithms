Stacks & queues
===============
element removed by delete operation is prespecified: stack deletes the most
recently inserted (LIFO), queue deletes the element in the set for the longest
time (FIFO)

Stacks
======
fixed size implementation will throw an overflow exception if push is call when
the stack is full.
will throw underflow exception if pop is called when stack is empty.
implemented using an std::array, complexity of push(), pop(), empty(), and full() is O(1).

