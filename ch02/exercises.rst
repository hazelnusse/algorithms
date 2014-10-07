Exercise 2.1-1
==============
Applying insertion sort to array A = [31, 41, 59, 26, 41, 58] results in the
following intermediate arrays::

31, 41, 59, 26, 41, 58
31, 41, 59, 26, 41, 58
31, 41, 59, 26, 41, 58
26, 31, 41, 59, 41, 58
26, 31, 41, 41, 59, 58
26, 31, 41, 41, 58, 59

The code for this is located in `test_insertion_sort.cc` and `insertion_sort.h`.

Exercise 2.1-2
==============
To change insetion sort from non-decreasing order to non-increasing order, the
comparison in the while loop header `key < A[i]` should be changed to `key >
A[i]`. This is implemented in the C++ template function `insertion_sort()` using
an optional template parameter which permits the comparison operation to be
customized by the user. By default the comparison is std::less, which yields the
normal non-decreasing sorted order, but by changing it to std::greater, we
obtain the non-increasing sorted order.

Exercise 2.1-3
==============
The C++ implementation of linear search is in `linear_search.h`.  We adopt the
iterator notation of C++ and use end to indicate a pointer which points to one
past the last element of the array.  If begin == end, the array is empty.
Dereferencing end is undefined. If linear_search returns end, it indicates v is
not in the array. The for loop is indexed by i. The loop invariant of linear
search is::

    At the start of each iteration of the for loop, the subarray
    A[first...(i-1)] does not contain the element v.

Proof:
Initialization
--------------
For non-empty arrays, when i == first, the subarray A[first...(i-1)] is the empty
array, which trivially does not contain the element v. For empty arrays
begin == end and we break from the loop and return end indicating the element v
was not found.

Maintenance
-----------
Each iteration checks whether `*i == v` (i.e., `A[i] == v`). If it does, we
break from the loop and loop and return i. If it does not, the loop index is
preserved and the loop invariant is preserved for the next iteration.

Termination
-----------
Two conditions cause the for loop to terminate

1. End of the the array is reached when `i == end`. By the loop invariant, this
   implies that the subarray A[first...(end-1)] does not contain the element v,
   hence we conclude that the entire array does not contain the element v and we
   return `end` to indicate that `v` was not found.
2. `*i == v`, which indicates that the loop invariant would be broken for the
   subarray A[first...(i + 1)], so we break the for loop and return i, which is
   the largest index for which the loop invariant is true.  By returning i, and
   with the knowledge that `i != last`, users of linear_search know the first
   element in the array which contains the value v.

Exercise 2.1-4
==============
Formal problem statement:
Input: Two sequences of N bits, stored in two n-element arrays A and B
Output: One sequence of N+1 bits, stored in one (n+1)-element array C which
contains the sum of A & B.

The C++ implementation is in `sum_n_bit_binary_integers.h`.

Exercise 2.2-1
==============
n^/1000 - 100n^2 - 100n + 3 is \Sigma(n^3)


Exercise 2.2-2
==============
Selection sort is implemented in `selection_sort.h`.  The loop is indexed by j,
starting at j = begin. The loop invariant is::

    At the start of each iteration of the for loop, the subarray A[begin...(j - 1)]
    consists of the (j-begin) smallest elements of A in sorted order.

Proof:
Initialization
--------------
Prior to the first iteration of the loop, we have j = begin, so that the
subarray A[begin...(j - 1)] is empty and hence the loop invariant is satisfied.

Maintenance
-----------
Each iteration finds the smallest element in the A[j...end-1] subarray and
swaps it into the j element, thus guaranteeing that the loop invariant holds
during the next iteration.

Termination
-----------
At termination, j = end - 1, hence the subarray A[begin...(j - 1)] =
A[begin...(end - 2)] consists of the (j - begin) == (end - 1 - begin) smallest
elements of A in sorted order. This implies that A[end - 2] <= A[end - 1], and
hence the whole array is also in sorted order.

It only needs to run for the first n - 1 elements because the algorithm will
swap the (n - 1)'th element with the n'th if the n'th element is the minimum of
the two.  The best case running time is Sigma(n^2) since the search for the
minimum traverse the entire subarray, even if it is in sorted order.  The worst
case running time is also Sigma(n^2).

Exercise 2.2-3
==============
The worst-case running time is when the element is not in the list, in which
case n comparisons are done and the running time is Sigma(n). The best case
occurs when the element is the first in the list and only 1 comparison is done,
in which case the running time is Sigma(n^0). For an array with n elements, if
the element is located at the i-th location, then i comparisons take place. The
average running time is the average of the running time of all possible
running times (assuming they are each equally likely)::

    average = (1 + 2 + 3 + ... + n) / n
            = sum_{k=1}^{n} k / n           # arithmetic series on numerator
            = n * (n + 1) / 2 / n
            = (n + 1) / 2

So the average running time for linear search is (n + 1)/2 which is still
Sigma(n).


Exercise 2.2-4
==============
Add a special case that checks if the input matches this special case.  For
example in any sort algorithm with input size n, you can check if the input is
sorted in running time O(n), and then the best case performance will be O(n)
when a sorted input is supplied to the algorithm.

