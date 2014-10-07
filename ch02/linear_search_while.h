#ifndef LINEAR_SEARCH
#define LINEAR_SEARCH

template <class Iterator>
Iterator linear_search(Iterator first, Iterator last,
                       const typename std::iterator_traits<Iterator>::value_type& v)
{
    Iterator i = first;
    while (i != last && *i != v) {
        ++i;
    }
    return i;
}

#endif

