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
    auto N = std::distance(begin, end);
    if (N > 1) {
        Iterator mid = begin;
        std::advance(mid, std::distance(begin, end) / 2);
        if (value == *mid) {                // value is at midpoint
            return mid;
        } else if (comp(value, *mid)) {     // value < *mid
            Iterator result = alg::binary_search(begin, mid, value, comp);
            if (result == mid) { // didn't find value in [begin, mid)
                return end;
            }
            return result;
        } else {                            // value > *mid
            return alg::binary_search(mid, end, value, comp);
        }
    } else if (N == 1 && value == *begin) {
        return begin;
    } else {
        return end;
    }
}

} // namespace alg

#endif

