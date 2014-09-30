#ifndef DEQUE_H
#define DEQUE_H

struct underflow : std::exception {
  const char* what() const noexcept {return "Deque underflow!\n";}
};

struct overflow : std::exception {
  const char* what() const noexcept {return "Deque overflow!\n";}
};

template <class T, size_t N>
class deque {
public:
    deque() : m_head{m_ar.data()},
              m_tail{m_ar.data()} {}

    void enqueue_front(const T& elem) {
        if (full()) {
            throw overflow();
        }
        m_head = prev(m_head);
        *m_head = elem;
    }

    void enqueue_back(const T& elem) {
        if (full()) {
            throw overflow();
        }
        *m_tail = elem;
        m_tail = next(m_tail);
    }

    T dequeue_front() {
        if (empty()) {
            throw underflow();
        }
        T result = *m_head;
        m_head = next(m_head);
        return result;
    }

    T dequeue_back() {
        if (empty()) {
            throw underflow();
        }
        m_tail = prev(m_tail);
        return *m_tail;
    }

    size_t max_size() const {
        return N;
    }

    bool empty() const {
        return m_head == m_tail;
    }

    bool full() const {
        return (m_head == next(m_tail));
    }

private:
    std::array<T, N + 1> m_ar;
    T* m_head;
    T* m_tail;

    T* next(const T* const elem) const {
        if (elem == m_ar.data() + N) {
            return const_cast<T*>(m_ar.data());
        }
        return const_cast<T*>(elem + 1);
    }

    T* prev(const T* const elem) const {
        if (elem == m_ar.data()) {
            return const_cast<T*>(m_ar.data() + N);
        }
        return const_cast<T*>(elem - 1);
    }
};
#endif
