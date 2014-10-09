// Describe a O(n lg n) time algorithm that, given a set S of n integers and another
// integer x, determines whether or not there exist two elements in S whose sum is
// exactly x.
//

#include <algorithm>
#include <iostream>

#include "print.h"
#include "random_vector_test.h"
#include "find_ints_that_sum_to_x.h"

class Test_int_sum: public Test_random_vector {};

TEST_F(Test_int_sum, Idea) {
    if (v.size() > 1) {
        auto x = v[0] + v[1];
        std::cout << "unsorted random vector of integers" << std::endl;
        print(v);
        std::cout << "x = " << x << std::endl;
        alg::merge_sort(begin(v), end(v));                // n*log2(n)
        std::cout << "sorted random vector of integers" << std::endl;
        print(v);
        auto pairs = alg::find_ints_that_sum_to_x(begin(v), end(v), x);
        for (const auto& p : pairs) {
            std::cout << p.first.first << " + " << p.first.second << " = " <<
                p.first.first + p.first.second << ", count = " << p.second << std::endl;
        }
    }
}
