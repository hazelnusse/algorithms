#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iterator>

template <class Iterator,
          typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
Iterator binary_search(Iterator begin,
                       Iterator end,
                       const typename std::iterator_traits<Iterator>::reference value,
                       Compare comp = Compare())
{
    Iterator mid = begin;
    std::advance(mid, std::distance(begin, end) / 2);
    if (value == *mid) {                // value is at midpoint
        return mid;
    } else if (comp(value, *mid)) {     // value < *mid
        auto result = binary_search(begin, mid, value, comp);
        if (result == mid) { // didn't find value in [begin, mid)
            return end;
        }
        return result;
    } else {                            // value > *mid
        return binary_search(mid, end, value, comp);
    }
}

#endif

