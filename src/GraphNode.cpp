#ifndef goog_GraphNode_cpp
#define goog_GraphNode_cpp

#include "GraphNode.hpp"
#include <cstdlib>
#include <iostream>

namespace goog {

    template <typename T>
    GraphNode<T>::GraphNode()
    {
        conns = new GraphNode<T>*[200];
        for (int i = 0; i < 200; ++i) conns[i] = NULL;

        distances = new int[200];
        value = rand();
    }
}

#endif
