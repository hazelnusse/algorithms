#ifndef BTREE_H
#define BTREE_H
#include <iostream>

template <class T>
struct btree_node {
    T key;
    btree_node* parent;
    btree_node* left;
    btree_node* right;
};

template <class T>
class btree {
public:
    btree() : m_root{nullptr} {}
private:
    btree_node<T>* m_root;

};

template <class T>
void inorder_tree_walk(const btree_node<T>* const x) {
    if (x) {
        inorder_tree_walk(x->left);
        std::cout << x->key << std::endl;
        inorder_tree_walk(x->right);
    }
}

template <class T>
void inorder_tree_walk_nonrecursive(const btree_node<T>* const x) {
    const btree_node<T>* current_node = x;
    while (current_node) {
        if (current_node->left) {
            current_node = current_node->left;
        } else if (current_node->right) {
            current_node = current_node->right;
        } else {
            std::cout << current_node->key << std::endl;
        }
    }
}

template <class T>
void preorder_tree_walk(const btree_node<T>* const x) {
    if (x) {
        std::cout << x->key << std::endl;
        inorder_tree_walk(x->left);
        inorder_tree_walk(x->right);
    }
}

template <class T>
void postorder_tree_walk(const btree_node<T>* const x) {
    if (x) {
        inorder_tree_walk(x->left);
        inorder_tree_walk(x->right);
        std::cout << x->key << std::endl;
    }
}

#endif

