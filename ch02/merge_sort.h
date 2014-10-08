#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <functional>
#include <iterator>
#include <vector>

// Assumptions:
// begin <= middle < end
template <typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void merge(Iterator begin, Iterator middle, Iterator end, Compare comp = Compare())
{
    using T = typename std::iterator_traits<Iterator>::value_type;
    std::vector<T> L(begin, middle), R(middle, end);

    typename std::vector<T>::const_iterator i = L.cbegin(), j = R.cbegin();
    for (; begin != end; ++begin) {
        if (i == L.end()) {                 // left pile is empty
            std::copy(j, R.cend(), begin);
            break;
        } else if (j == R.end()) {          // right pile is empty
            std::copy(i, L.cend(), begin);
            break;
        } else if (comp(*i, *j)) {          // top left < top right
            *begin = *i++;
        } else {                            // top left >= top right
            *begin = *j++;
        }
    }
}

template <typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void merge_sort(Iterator begin, Iterator end, Compare comp = Compare())
{
    auto distance = std::distance(begin, end);  // constant if Iterator is RandomAccessIterator
    if (distance > 1) {
        Iterator mid = begin;                   // constant
        std::advance(mid, distance / 2);        // constant if Iterator is RandomAccessIterator
        merge_sort(begin, mid, comp);
        merge_sort(mid, end, comp);
        merge(begin, mid, end, comp);
    }
}

#endif
