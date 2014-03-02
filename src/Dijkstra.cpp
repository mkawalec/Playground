#ifndef goog_Dijkstra_cpp
#define goog_Dijkstra_cpp

#include "Dijkstra.hpp"
#include "NaiveMPQ.hpp"
#include "Stack.h"

#include <cstdlib>
#include <iostream>
#include <climits>

namespace goog {

    template <typename T>
    void Dijkstra<T>::add_nodes(GraphNode<T>* current_root, int depth)
    {
        if (depth > 5) return;

        for (int i = 0; i < rand()%5; ++i) {
            GraphNode<T> *new_node = new GraphNode<T>;
            current_root->conns[current_root->edges] = new_node;
            current_root->distances[current_root->edges] = rand()%20;
            current_root->edges++;

            add_nodes(new_node, depth + 1);
        }
        return;
    }

    template <typename T>
    void Dijkstra<T>::delete_node(GraphNode<T> *to_delete)
    {
        for (int i = 0; i < to_delete->edges; ++i)
            if (to_delete->conns[i] != NULL)
                delete_node(to_delete->conns[i]);
        if (to_delete != NULL) delete to_delete;
    }


    template <typename T>
    Dijkstra<T>::Dijkstra()
    {
        srand(123);
        vertex_queue = new NaiveMPQ<GraphNode<T>*>;
        start = new GraphNode<T>;
        add_nodes(start);
    }

    template <typename T>
    Dijkstra<T>::~Dijkstra()
    {
        //delete_node(start);
    }

    template <typename T>
    void Dijkstra<T>::print_nodes_preorder(GraphNode<T> *current, int depth)
    {
        std::cout << depth << " " << current->distance
            << " " << current->value << std::endl;

        for (int i = 0; i < current->edges; ++i)
            print_nodes_preorder(current->conns[i], depth + 1);
    }

    template <typename T>
    void Dijkstra<T>::find_distances()
    {
        Stack<GraphNode<T>*> my_stack;
        my_stack.push(start);

        while (true) {
            GraphNode<T> *current_node;
            try {
                current_node = my_stack.pop();
            } catch (const char e[]) { break; }

            for (int i = 0; i < current_node->edges; ++i)
                my_stack.push(current_node->conns[i]);

            current_node->distance = INT_MAX;
            if (current_node == start) current_node->distance = 0;

            current_node->previous = NULL;
            vertex_queue->add_with_priority(current_node,
                    current_node->distance);
            std::cout << "adding " << current_node << std::endl;
        }

        while (!vertex_queue->is_empty()) {
            GraphNode<T>* current = vertex_queue->extract_min();
            for (int i = 0; i < current->edges; ++i) {
                int dist = current->distance + current->distances[i];
                if (dist < current->conns[i]->distance) {
                    current->conns[i]->distance = dist;
                    current->conns[i]->previous = current;
                    vertex_queue->change_priority(current->conns[i], dist);
                    std::cout << "changing " << current->conns[i] << std::endl;
                }
            }
        }
    }
}




#endif
