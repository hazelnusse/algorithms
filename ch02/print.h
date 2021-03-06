#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <iterator>

template <class Container>
void print(const Container& c, std::ostream& os = std::cout) {
    std::copy(begin(c), end(c),
        std::ostream_iterator<typename Container::value_type>(os, ", "));
    os << "\n";
}

#endif

