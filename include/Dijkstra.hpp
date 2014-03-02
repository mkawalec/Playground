#ifndef goog_Dijkstra_hpp
#define goog_Dijkstra_hpp

#include "GraphNode.hpp"
#include "NaiveMPQ.hpp"

namespace goog {

    template <typename T>
    class Dijkstra {
    protected:
        GraphNode<T> *start=NULL;
        NaiveMPQ<GraphNode<T>*> *vertex_queue;

        void add_nodes(GraphNode<T>* current_root, int depth=0);
        void delete_node(GraphNode<T>* to_delete);

    public:
        Dijkstra();
        virtual ~Dijkstra();

        virtual void find_distances();
        void print_nodes_preorder(GraphNode<T> *current, int depth=0);
        void print_nodes_preorder() { print_nodes_preorder(start);}
    };
}

#include "Dijkstra.cpp"
#endif
