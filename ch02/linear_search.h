#ifndef LINEAR_SEARCH
#define LINEAR_SEARCH

template <class Iterator>
Iterator linear_search(Iterator first, Iterator last,
                       const typename std::iterator_traits<Iterator>::value_type& v)
{
    Iterator it;
    for (it = first; it != last; ++it) {
        if (*it == v) {
            break;
        }
    }
    return it;
}

#endif

