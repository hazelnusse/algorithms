#ifndef BINARY_SEARCH_NON_RECURSIVE_H
#define BINARY_SEARCH_NON_RECURSIVE_H

#include <functional>       // for std::less
#include <iterator>         // for std::distance, std::advance

namespace alg {

/**
 * \brief Find iterator to value in range [begin, end), returning
 * end if not found.
 *
 * It is assumed that [begin, end) is sorted with respect to comp.
 */
template <class Iterator,
          typename U,
          typename Compare = std::less<U>>
Iterator binary_search_non_recursive(Iterator begin,
                                     Iterator end,
                                     U const& value,
                                     Compare comp = Compare())
{
    const Iterator not_found = end--;
    while (std::distance(begin, end) >= 0) {
        Iterator mid = begin;
        std::advance(mid, std::distance(begin, end) / 2);
        if (*mid == value) {
            return mid;
        } else if (comp(value, *mid)) {
            end = --mid;
        } else {
            begin = ++mid;
        }
    }
    return not_found;
}

} // namespace alg

#endif

