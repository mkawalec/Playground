#ifndef goog_TreeElement_cpp
#define goog_TreeElement_cpp

#include "TreeElement.hpp"

namespace goog {

    template <typename T>
    void TreeElement<T>::add(T new_value) {
        if (new_value > value) {
            if (right == NULL) {
                TreeElement<T> *new_element = new TreeElement<T>(new_value);
                new_element->parent = this;
                right = new_element;
            }
            else right->add(new_value);
        } else {
            if (left == NULL) {
                TreeElement<T> *new_element = new TreeElement<T>(new_value);
                new_element->parent = this;
                left = new_element;
            }
            else left->add(new_value);
        }
    }
}

#endif
