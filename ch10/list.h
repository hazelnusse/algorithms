#ifndef LIST_H
#define LIST_H

template <class T>
struct list_elem {
    T key;
    list_elem* next;
    list_elem* prev;
};

template <class T>
class list {
public:
    list() : m_head{nullptr} {}
    ~list() {
        while (m_head != nullptr) {
            remove(m_head);
        }
    }

    void insert(const T& key) {
        list_elem<T>* x= new list_elem<T>{key, m_head, nullptr};
        if (m_head) {
            m_head->prev = x;
        }
        m_head = x;
    }

    list_elem<T>* search(const T& key) {
        list_elem<T>* x = m_head;
        while (x != nullptr && x->key != key) {
            x = x->next;
        }
        return x;
    }

    void remove(list_elem<T>* x) {
        if (x == nullptr)
            return;

        if (x->prev != nullptr) {   // x is not the head of the list
            x->prev->next = x->next;
        } else {
            m_head = x->next;
        }

        if (x->next != nullptr) {
            x->next->prev = x->prev;
        }

        delete x;
    }

    bool empty() const {
        return m_head == nullptr;
    }
private:
    list_elem<T>* m_head;

};

#endif

