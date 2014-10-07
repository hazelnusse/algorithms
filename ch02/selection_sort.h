#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <functional>
#include <iterator>

// complexity: O(n), where n = end - begin
template <typename Iterator>
Iterator min(Iterator begin, Iterator end) {
    Iterator min;
    for (min = begin; begin != end; ++begin) {
        if (*begin < *min) {
            min = begin;
        }
    }
    return min;
}

// complexity: O(n^2), where n = end - begin
template <typename Iterator>
void selection_sort(Iterator begin, Iterator end)
{
    // Handle bad input:
    //     end - begin == 1, i.e., one element in container, already sorted
    //     end - begin <= 0, i.e., invalid container iterators
    //                                             // cost, times
    if (end - begin <= 1) {                        // c0, 1
        return;                                    // c1, 0 or 1
    }

    for (Iterator j = begin; j != end - 1; ++j) {  // c2,         n
        auto min_iter = min(j, end);               // O(end - j), n - 1
        std::swap(*min_iter, *j);                  // c3        , n - 1
    }
}
#endif
