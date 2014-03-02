#ifndef goog_Queue_h
#define goog_Queue_h

namespace goog {

    template <typename T>
    class Queue {
    private:
        T* data_store;
        int start=0, end=0, current_size=8;

        void resize(int new_size);

    public:
        Queue();
        virtual ~Queue();

        void push(T element);
        T pop();
    };
}

#include "Queue.cpp"
#endif
