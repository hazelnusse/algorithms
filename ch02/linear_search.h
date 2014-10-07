#ifndef LINEAR_SEARCH
#define LINEAR_SEARCH

template <class Iterator>
Iterator linear_search(Iterator begin, Iterator end,
                       const typename std::iterator_traits<Iterator>::value_type& v)
{
    Iterator i;
    for (i = begin; i != end; ++i) {
        if (*i == v) {
            break;
        }
    }
    return i;
}

#endif

