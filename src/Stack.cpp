#ifndef goog_Stack_cpp
#define goog_Stack_cpp

#include "Stack.h"

namespace goog {

    template <typename T>
    void Stack<T>::resize(int new_size)
    {
        // TODO: what to do if new_size < current_size?
        T* new_store = new T[new_size];
        for (int i = 0; i < stack_pointer + 1; ++i) new_store[i] = data_store[i];

        delete[] data_store;
        data_store = new_store;
        current_size = new_size;
    }

    template <typename T>
    Stack<T>::Stack()
    {
        data_store = new T[current_size];
    }

    template <typename T>
    Stack<T>::~Stack()
    {
        delete[] data_store;
    }

    template <typename T>
    void Stack<T>::push(T item)
    {
        if (stack_pointer >= current_size - 1)
            resize(2 * current_size);

        ++stack_pointer;
        data_store[stack_pointer] = item;
    }

    template <typename T>
    T Stack<T>::pop()
    {
        if (stack_pointer < 0)
            throw "Stack empty";
        return data_store[stack_pointer--];
    }
}


#endif
