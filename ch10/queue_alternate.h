#ifndef QUEUE_ALTERNATE_H
#define QUEUE_ALTERNATE_H

struct underflow : std::exception {
  const char* what() const noexcept {return "Queue underflow!\n";}
};

struct overflow : std::exception {
  const char* what() const noexcept {return "Queue overflow!\n";}
};

template <class T, size_t N>
class queue_alternate {
public:

    queue_alternate() :
        m_head{m_ar.data()},
        m_tail{m_ar.data()}
    {

    }

    void enqueue(const T& elem) {
        if (full()) {
            throw overflow();
        }
        *m_tail = elem;
        m_tail = next(m_tail);
    }

    T dequeue() {
        if (empty()) {
            throw underflow();
        }
        T result = *m_head;
        m_head = next(m_head);
        return result;
    }

    bool empty() const {
        return m_head == m_tail;
    }

    bool full() const {
        return (m_head == next(m_tail));
    }

    size_t max_size() const {
        return N;
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
};

#endif

