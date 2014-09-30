#ifndef QUEUE_H
#define QUEUE_H

struct underflow : std::exception {
  const char* what() const noexcept {return "Queue underflow!\n";}
};

struct overflow : std::exception {
  const char* what() const noexcept {return "Queue overflow!\n";}
};

template <class T, size_t N>
class queue {
public:

    queue() :
        m_head{m_ar.data()},
        m_tail{m_ar.data()},
        m_empty{true},
        m_full{false} {

    }

    void enqueue(const T& elem) {
        if (full()) {
            throw overflow();
        }
        *m_tail = elem;
        auto next_tail = next(m_tail);
        if (next_tail == m_head) {
            m_full = true;
        }
        m_tail = next_tail;
        m_empty = false;
    }

    T dequeue() {
        if (empty()) {
            throw underflow();
        }
        T result = *m_head;
        m_full = false;
        m_head = next(m_head);
        if (m_head == m_tail) {
            m_empty = true;
        }
        return result;
    }

    bool empty() const {
        return m_empty;
    }

    bool full() const {
        return m_full;
    }

    size_t max_size() const {
        return N;
    }

private:
    std::array<T, N> m_ar;
    T* m_head;
    T* m_tail;
    bool m_empty;
    bool m_full;

    T* next(const T* const elem) const {
        if (elem == m_ar.data() + N - 1) {
            return const_cast<T*>(m_ar.data());
        }
        return const_cast<T*>(elem + 1);
    }

    const T* prev(T* elem) const {
        if (elem = m_ar.data()) {
            return m_ar.data() + N - 1;
        }
        return elem - 1;
    }
};

#endif

