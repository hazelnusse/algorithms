#ifndef FIND_INTS_THAT_SUM_TO_X
#define FIND_INTS_THAT_SUM_TO_X

#include <utility>
#include <map>
#include <iterator>
#include "merge_sort.h"
#include "binary_search.h"

namespace alg {

template <class Iterator, typename T = typename std::iterator_traits<Iterator>::value_type>
std::map<std::pair<T, T>, unsigned int>
find_ints_that_sum_to_x(Iterator begin,
                        Iterator end,
                        const T& x)
{
    std::map<std::pair<T, T>, unsigned int> pairs;
    for (Iterator i = begin; i != end; ++i) {   // n iterations
        auto result = alg::binary_search(begin, end, x - *i); // log2(n) complexity
        if (result != end) {
            if (*i < *result) {
                ++pairs[{*i, *result}];
            } else {
                ++pairs[{*result, *i}];
            }
        }
    }
    return pairs;
}

} // namespace alg

#endif

