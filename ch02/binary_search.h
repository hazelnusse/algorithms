#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

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
Iterator binary_search(Iterator begin,
                       Iterator end,
                       U const& value,
                       Compare comp = Compare())
{
    const Iterator not_found = end;
    if (std::distance(begin, end) > 0) {
        Iterator mid = begin;
        std::advance(mid, std::distance(begin, end) / 2);
        if (value == *mid) {                // value is at midpoint
            return mid;                     // end recursion
        } else if (comp(value, *mid)) {     // value < *mid
            end = mid;                      // end is one past last element of range to search
        } else {                            // value > *mid
            begin = ++mid;                  // begin is one past mid since we know value != mid
        }
        mid = alg::binary_search(begin, end, value, comp);
        if (mid == end) {
            return not_found;
        }
        return mid;
    }
    return not_found;
}

} // namespace alg

#endif

