#pragma once
#include <iostream>
#include <functional>

template<typename T>
class BST {
    struct Node { T data; Node *left, *right; Node(T d) : data(d), left(nullptr), right(nullptr) {} };
    Node *root_ = nullptr;

    Node* insert_(Node* n, const T& v) {
        if (!n) return new Node(v);
        if (v < n->data) n->left  = insert_(n->left,  v);
        else             n->right = insert_(n->right, v);
        return n;
    }

    Node* findMin_(Node* n) { return n->left ? findMin_(n->left) : n; }

    Node* delete_(Node* n, const T& v) {
        if (!n) return nullptr;
        if      (v < n->data) n->left  = delete_(n->left,  v);
        else if (v > n->data) n->right = delete_(n->right, v);
        else {
            if (!n->left)  { auto r = n->right; delete n; return r; }
            if (!n->right) { auto l = n->left;  delete n; return l; }
            Node* m = findMin_(n->right);
            n->data  = m->data;
            n->right = delete_(n->right, m->data);
        }
        return n;
    }

    bool search_(Node* n, const T& v) const {
        if (!n) return false;
        if (v == n->data) return true;
        return v < n->data ? search_(n->left, v) : search_(n->right, v);
    }

    int  height_(Node* n) const { return n ? 1 + std::max(height_(n->left), height_(n->right)) : 0; }
    int  count_ (Node* n) const { return n ? 1 + count_(n->left) + count_(n->right) : 0; }

    void inorder_  (Node* n, std::function<void(const T&)> fn) const { if (n) { inorder_(n->left, fn); fn(n->data); inorder_(n->right, fn); } }
    void preorder_ (Node* n, std::function<void(const T&)> fn) const { if (n) { fn(n->data); preorder_(n->left, fn); preorder_(n->right, fn); } }
    void postorder_(Node* n, std::function<void(const T&)> fn) const { if (n) { postorder_(n->left, fn); postorder_(n->right, fn); fn(n->data); } }

    void destroy_(Node* n) { if (n) { destroy_(n->left); destroy_(n->right); delete n; } }

public:
    ~BST() { destroy_(root_); }
    void insert(const T& v)         { root_ = insert_(root_, v); }
    void remove(const T& v)         { root_ = delete_(root_, v); }
    bool contains(const T& v) const { return search_(root_, v); }
    int  height()             const { return height_(root_); }
    int  count()              const { return count_(root_);  }

    void inorder  (std::function<void(const T&)> fn) const { inorder_  (root_, fn); }
    void preorder (std::function<void(const T&)> fn) const { preorder_ (root_, fn); }
    void postorder(std::function<void(const T&)> fn) const { postorder_(root_, fn); }
};
