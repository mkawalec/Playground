#ifndef goog_Stack_h
#define goog_Stack_h


namespace goog {

    template <typename T>
    class Stack {
    private:
        int current_size = 8;
        int stack_pointer = -1;

        T* data_store;
        void resize(int new_size);

    public:
        Stack();
        Stack(int start_size) : current_size(start_size) { Stack();}

        virtual ~Stack();

        void push(T item);
        T pop();
    };
}

#include "Stack.cpp"

#endif
