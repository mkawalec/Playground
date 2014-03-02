#ifndef goog_BST_h
#define goog_BST_h

#include "TreeElement.hpp"

namespace goog {

    template <typename T>
    class BST {
    protected:
        TreeElement<T> *root=NULL;

    public:
        virtual ~BST() { root->delete_subtree(); }

        void add(T element);

        TreeElement<T>* search(TreeElement<T> *node, T value);
        T search(T value) { return search(root, value)->value; }

        TreeElement<T>* successor(TreeElement<T> *node);
        T successor(T value) { return successor(search(root, value))->value;}

        TreeElement<T>* minimum(TreeElement<T> *node);
        TreeElement<T>* maximum(TreeElement<T> *node);

        void delete_node(TreeElement<T> *node);
        void delete_node(T value){ delete_node(search(root, value));}

        void print_inorder(TreeElement<T> *node);
        void print_inorder() { print_inorder(root);}

        void print_preorder(TreeElement<T> *node);
        void print_preorder() { print_preorder(root);}

        void print_postorder(TreeElement<T> *node);
        void print_postorder() { print_postorder(root);}

    };
}

#include "BST.cpp"
#endif
