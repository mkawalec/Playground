#ifndef goog_GraphNode_hpp
#define goog_GraphNode_hpp

namespace goog {

    template <typename T> class Dijkstra;

    template <typename T>
    class GraphNode {
        template <typename U>
        friend class Dijkstra;

    private:
        T value;
        GraphNode<T> **conns;
        int *distances;
        int edges = 0;
        int distance;
        GraphNode<T> *previous;

    public:
        GraphNode();
        GraphNode(T new_value) : value(new_value) { GraphNode(); }
        virtual ~GraphNode() { delete conns; delete distances;}
    };
}

#include "GraphNode.cpp"
#endif
