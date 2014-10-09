#ifndef SUM_N_BIT_BINARY_INTEGERS_H
#define SUM_N_BIT_BINARY_INTEGERS_H

namespace alg {

/** Formal problem statement:
 * Input: Two sequences of N bits, stored in two n-element arrays A and B
 * Output: One sequence of N+1 bits, stored in one (n+1)-element array C which
 * contains the sum of A & B.
 */
template <std::size_t N>
std::bitset<N + 1> sum(const std::bitset<N>& a, const std::bitset<N>& b) {

    std::bitset<N + 1> c;
    bool carry = false;
    for (std::size_t i = 0; i != N; ++i ) {
        if (a[i] && b[i]) {
            if (carry) {
                c[i] = true;
            } else {
                c[i] = false;
            }
            carry = true;
        } else if (a[i] || b[i]) {
            if (carry) {
                c[i] = false;
            } else {
                c[i] = true;
            }
        } else {
            if (carry) {
                c[i] = true;
            } else {
                c[i] = false;
            }
            carry = false;
        }
    }
    if (carry) {
        c[N] = true;
    } else {
        c[N] = false;
    }
    return c;
}

} // namespace alg

#endif

