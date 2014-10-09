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
    Iterator mid = begin;
    auto N = std::distance(begin, end);
    std::advance(mid, N / 2);
    Iterator left = begin, right = end;
    while (N > 1) {
        if (value == *mid) {
            return mid;
        } else {
            if (comp(value, *mid)) {
                right = mid;
            } else {
                left = mid;
            }
            N = std::distance(left, right);
            mid = left;
            std::advance(mid, N / 2);
        }
    }
    if (value == *mid) {
        return mid;
    }
    return end;
}

} // namespace alg

#endif

