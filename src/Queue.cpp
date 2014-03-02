#ifndef goog_Queue_cpp
#define goog_Queue_cpp

namespace goog {

    template <typename T>
    void Queue<T>::resize(int new_size)
    {
        // TODO: deal with new_size smaller
        T* new_store = new T[new_size];
        for (int i = start; i < end; ++i)
            new_store[i-start] = data_store[i%current_size];

        delete[] data_store;
        data_store = new_store;

        current_size = new_size;
        end -= start;
        start = 0;
    }

    template <typename T>
    Queue<T>::Queue()
    {
        data_store = new T[current_size];
    }

    template <typename T>
    Queue<T>::~Queue()
    {
        delete[] data_store;
    }

    template <typename T>
    void Queue<T>::push(T element)
    {
        if ((start - end)%current_size == 0 && start != end) resize(2 * current_size);
        data_store[(end++)%current_size] = element;
    }

    template <typename T>
    T Queue<T>::pop()
    {
        if (start%current_size == end%current_size)
            throw "empty queue";

        return data_store[start++%current_size];
    }
}


#endif
