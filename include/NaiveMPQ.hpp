#ifndef goog_NaiveMPQ_hpp
#define goog_NaiveMPQ_hpp

namespace goog {

    template <typename T>
    class NaiveMPQ {
    private:
        T* data_store;
        int *priorities;
        int end=0, current_size=8;

        void resize(int new_size);

    public:
        NaiveMPQ();
        ~NaiveMPQ() { delete[] data_store; delete[] priorities;}

        void add_with_priority(T element, int priority);
        void change_priority(T element, int priority);
        T extract_min();
        bool is_empty();
    };
}

#include "NaiveMPQ.cpp"
#endif
