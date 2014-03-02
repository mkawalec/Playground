#include "GraphNode.hpp"
#include "Dijkstra.hpp"
#include <iostream>
using namespace std;
using namespace goog;

int main(int argc, char *argv[])
{
    Dijkstra<int> my_dijkstra;

    my_dijkstra.find_distances();
    my_dijkstra.print_nodes_preorder();

    return 0;
}
