#ifndef goog_BST_cpp
#define goog_BST_cpp

#include "BST.h"
#include "TreeElement.hpp"
#include <iostream>

namespace goog {

    template <typename T>
    void BST<T>::add(T value)
    {
        if (root == NULL) {
            TreeElement<T> *new_root = new TreeElement<T>(value);
            root = new_root;
        }
        else root->add(value);
    }

    template <typename T>
    void BST<T>::print_inorder(TreeElement<T> *node)
    {
        if (node->left != NULL) print_inorder(node->left);
        std::cout << node->value << std::endl;
        if (node->right != NULL) print_inorder(node->right);
    }

    template <typename T>
    void BST<T>::print_preorder(TreeElement<T> *node)
    {
        std::cout << node->value << " " << node->left << " " << node->right << std::endl;
        if (node->left != NULL) print_preorder(node->left);
        if (node->right != NULL) print_preorder(node->right);
    }

    template <typename T>
    void BST<T>::print_postorder(TreeElement<T> *node)
    {
        if (node->left != NULL) print_postorder(node->left);
        if (node->right != NULL) print_postorder(node->right);
        std::cout << node->value << std::endl;
    }

    template <typename T>
    TreeElement<T>* BST<T>::search(TreeElement<T> *node, T value)
    {
        TreeElement<T> *current_node = node;

        while (current_node != NULL) {
            if (current_node->value == value) return current_node;
            else if (current_node->value < value) current_node = current_node->right;
            else current_node = current_node->left;
        }

        throw "not found";
    }

    template <typename T>
    TreeElement<T>* BST<T>::successor(TreeElement<T> *node)
    {
        if (node->right != NULL) return minimum(node->right);

        TreeElement<T>* current_node = node;
        while (true) {
            if (current_node->parent != NULL &&
                current_node->parent->right == current_node)
                    current_node = current_node->parent;
            else break;
        }
        return current_node->parent;
    }

    template <typename T>
    TreeElement<T>* BST<T>::minimum(TreeElement<T> *node)
    {
        if (node->left == NULL) return node;
        return minimum(node->left);
    }

    template <typename T>
    TreeElement<T>* BST<T>::maximum(TreeElement<T> *node)
    {
        if (node->right == NULL) return node;
        return maximum(node->right);
    }

    template <typename T>
    void BST<T>::delete_node(TreeElement<T> *node)
    {
        if (node->left == NULL && node->right == NULL) {
            if (node == root) {
                root = NULL;
                return delete node;
            }

            if (node->parent->right == node) node->parent->right = NULL;
            if (node->parent->left == node) node->parent->left = NULL;
            delete node;
        } else if (node->left != NULL && node->right == NULL) {
            if (node == root) {
                root = node->left;
                node->left->parent = NULL;
            } else {
                if (node->parent->right == node)
                    node->parent->right = node->left;
                else if (node->parent->left == node)
                    node->parent->left = node->left;
                node->left->parent = node->parent;
            }
            delete node;
        } else if (node->left == NULL && node->right != NULL) {
            if (node == root) {
                root = node->right;
                node->right->parent = NULL;
            } else {
                if (node->parent->right == node)
                    node->parent->right = node->right;
                else if (node->parent->left == node)
                    node->parent->left = node->right;
                node->right->parent = node->parent;
            }
            delete node;
        } else {
            TreeElement<T> *next = successor(node);
            TreeElement<T> *new_node = new TreeElement<T>(next->value);

            new_node->parent = node->parent;
            new_node->left = node->left;
            new_node->right = node->right;
            new_node->left->parent = new_node;
            new_node->right->parent = new_node;
            if (node->parent->right == node) node->parent->right = new_node;
            else if (node->parent->left == node) node->parent->left = new_node;

            if (node == root) root = new_node;

            delete node;
            delete_node(next);
        }
    }

}

#endif
