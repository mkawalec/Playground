#ifndef goog_NaiveMPQ_cpp
#define goog_NaiveMPQ_cpp

#include "NaiveMPQ.hpp"
#include <climits>
#include <iostream>

namespace goog {

    template <typename T>
    void NaiveMPQ<T>::resize(int new_size)
    {
        T *new_store = new T[new_size];
        int *new_priorities = new int[new_size];

        for (int i = 0; i < end; ++i) {
            new_store[i] = data_store[i];
            new_priorities[i] = priorities[i];
        }

        delete[] data_store;
        delete[] priorities;
        data_store = new_store;
        priorities = new_priorities;

        current_size = new_size;
    }

    template <typename T>
    NaiveMPQ<T>::NaiveMPQ()
    {
        data_store = new T[current_size];
        priorities = new int[current_size];
    }

    template <typename T>
    void NaiveMPQ<T>::add_with_priority(T element, int priority)
    {
        if (end == current_size) resize(2 * current_size);

        data_store[end] = element;
        priorities[end] = priority;

        end++;
    }

    template <typename T>
    void NaiveMPQ<T>::change_priority(T element, int priority)
    {
        for (int i = 0; i < end; ++i) {
            if (data_store[i] == element) {
                priorities[i] = priority;
                return;
            }
            //std::cout << data_store[i%current_size] << " " << element << std::endl;
        }
        std::cout << "not found" << std::endl;
    }

    template <typename T>
    T NaiveMPQ<T>::extract_min()
    {
        int min_priority=INT_MAX, min_index=0;
        for (int i = 0; i < end; ++i) {
            if (priorities[i] < min_priority) {
                min_index = i;
                min_priority = priorities[i];
            }
        }

        T to_return = data_store[min_index];
        for (int i = min_index; i < end-1; ++i)
            data_store[i] = data_store[i+1];
        end--;

        return to_return;
    }

    template <typename T>
    bool NaiveMPQ<T>::is_empty()
    {
        if (end == 0) return true;
        return false;
    }
}

#endif
