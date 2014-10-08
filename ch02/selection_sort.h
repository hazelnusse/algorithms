#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <functional>
#include <iterator>

// complexity: O(n^2), where n = end - begin
template <typename Iterator,
          typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void selection_sort(Iterator begin, Iterator end, Compare comp = Compare())
{
    if (std::distance(begin, end) > 1) {
        Iterator one_before_end = end;
        --one_before_end;
        for (Iterator j = begin; j != one_before_end; ++j) {  // c2,         n
            auto it = std::min_element(j, end, comp);         // max(N-1, 0) comparisons, where N = std::distanc(j, end);
            std::swap(*it, *j);                               // c3        , n - 1
        }
    }
}

#endif

