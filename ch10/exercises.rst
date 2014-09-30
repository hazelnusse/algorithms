Exercise 10.1-1
---------------
Initially empty stack of size 6:
|x|x|x|x|x|x|
PUSH(S, 4)
|4|x|x|x|x|x|
PUSH(S, 1)
|4|1|x|x|x|x|
PUSH(S, 3)
|4|1|3|x|x|x|
POP(S)
|4|1|x|x|x|x|
PUSH(S, 8)
|4|1|8|x|x|x|
POP(S)
|4|1|x|x|x|x|


Exercise 10.1-2
---------------
Use two pointers to track the top of the stack. The first pointer would
initially point to the element before the first element and would
increment/decrement just like a regular stack pointer.  The second pointer would
initilly point to the element after the last element and would
increment/decrement in the opposite direction as a regular stack pointer. A full
method/function would need to be implemented that would check whether the two
stack pointers are different by one, in which case the stack is full. The full
method would need to be called when pushing to either stack, and if the stack
were full, and overflow error/exception would need to be returned/thrown.

Exercise 10.1-3
---------------
Initially empty queue Q using an array:
|x|x|x|x|x|x|
 t
 h
ENQUEUE(Q, 4)
|4|x|x|x|x|x|
 h t
ENQUEUE(Q, 1)
|4|1|x|x|x|x|
 h   t
ENQUEUE(Q, 3)
|4|1|3|x|x|x|
 h     t
DEQUEUE(Q)
|4|1|3|x|x|x|
   h   t
ENQUEUE(Q, 8)
|4|1|3|8|x|x|
   h     t
DEQUEUE(Q)
|4|1|3|8|x|x|
     h   t

Exercise 10.1-4
---------------
See `queue.h` and `test_queue.h` for a C++ implementation which uses a size N
array for a size N queue. See `queue_alternate.h` and `test_queue_alternate.h`
for a C++ implementation which uses a size N+1 array for a size N queue.

Exercise 10.1-5
---------------
See `deque.h` and `test_deque.h` for a C++ implementation which uses a size N+1
array for a size N queue. The deque supports enqueue_front, enqueue_back,
dequeue_front and dequeue_back, all of which are O(1) complexity.

Exercise 10.1-6
---------------
TODO

Exercise 10.1-7
---------------
TODO

