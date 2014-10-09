#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <functional>
#include <iterator>

namespace alg {

template <typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void insertion_sort(Iterator first, Iterator last, Compare comp = Compare())
{
    // Handle bad input:
    //     last - first == 1, i.e., one element in container, already sorted
    //     last - first <= 0, i.e., invalid container iterators
    if (last - first <= 1) {
        return;
    }

    for (Iterator j = first + 1; j != last; ++j) {
        auto key = *j;      // make a copy of element
        Iterator i = j - 1;
        while (i > first - 1 && comp(key, *i)) {
            *(i + 1) = *i;
            --i;
        }
        *(i + 1) = key;
    }
}

} // namespace alg

#endif

