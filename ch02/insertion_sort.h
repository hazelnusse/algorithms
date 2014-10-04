#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

template <class Iterator>
void insertion_sort(Iterator first, Iterator last)
{
    // Handle bad input:
    //     last - first == 1, i.e., one element in container, already sorted
    //     last - first <= 0, i.e., invalid container iterators
    if (last - first <= 1) {
        return;
    }

    for (auto j = first + 1; j != last; ++j) {
        auto key = *j;
        auto i = j - 1;
        while (i > first - 1 && *i > key) {
            *(i + 1) = *i;
            --i;
        }
        *(i + 1) = key;
    }
}
#endif
