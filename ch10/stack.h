#ifndef STACK_H
#define STACK_H

#include <array>
#include <exception>

struct underflow : std::exception {
  const char* what() const noexcept {return "Stack underflow!\n";}
};

struct overflow : std::exception {
  const char* what() const noexcept {return "Stack overflow!\n";}
};

template <class T, size_t N>
class stack {
public:
    stack() : m_top(m_ar.data() - 1) {

    }

    void push(const T& elem) {
        if (!full()) {
            *++m_top = elem;
        } else {
            throw overflow();
        }
    }

    T pop() {
        if (!empty()) {
            return *m_top--;
        }
        throw underflow();
    }

    bool empty() const {
        if (m_top == m_ar.data() - 1) {
            return true;
        }
        return false;
    }

    bool full() const {
        if (m_top == m_ar.data() + N - 1) {
            return true;
        }
        return false;
    }

    size_t max_size() const {
        return N;
    }

private:
    std::array<T, N> m_ar;
    T* m_top;

};

#endif
