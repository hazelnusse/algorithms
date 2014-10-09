#ifndef INSERTION_SORT_RECURSIVE_H
#define INSERTION_SORT_RECURSIVE_H

#include <functional>
#include <iterator>

namespace alg {

// assumptions:
// 1) [begin, end) is sorted
// 2) *end points to element to be inserted
template <typename Iterator,
          typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void insert_end_in_sorted_position(Iterator begin, Iterator end, Compare comp = Compare())
{
    // Find insertion point
    Iterator it;
    for (it = begin; it != end && comp(*it, *end); ++it) {}

    // Shift elements to the right by swapping with end position
    for (;it != end; ++it) {
        std::swap(*it, *end);
    }
}

template <typename Iterator,
          typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void insertion_sort_recursive(Iterator begin, Iterator end, Compare comp = Compare())
{
    if (std::distance(begin, end) > 1) {
        std::advance(end, -1);
        insertion_sort_recursive(begin, end, comp);
        insert_end_in_sorted_position(begin, end, comp);
    }
}

} // namespace alg

#endif

