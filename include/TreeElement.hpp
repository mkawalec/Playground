#ifndef goog_TreeElement_h
#define goog_TreeElement_h

#include "BST.h"

namespace goog {

    template <typename T>
    class TreeElement {
        template <typename U>
        friend class BST;

    private:
        TreeElement<T> *left=NULL, *right=NULL, *parent=NULL;
        T value;

    public:
        TreeElement(T new_value) : value(new_value) { }
        void delete_subtree()
        {
            if (left != NULL) left->delete_subtree();
            if (right != NULL) right->delete_subtree();
            delete this;
        }

        void add(T new_value);
    };
}

#include "TreeElement.cpp"
#endif
