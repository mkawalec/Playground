#include <iostream>
#include <cstdlib>

#include "BST.h"
using namespace std;
using namespace goog;

int main(int argc, char *argv[])
{
    BST<int> my_tree;
    srand(1333);

    for (int i = 5; i >= 0; --i) my_tree.add(rand()%20);
    //my_tree.add(1);
    my_tree.add(111);
    my_tree.add(10);
    my_tree.add(9);

    std::cout << "Inorder" << std::endl;
    my_tree.print_inorder();

    std::cout << "Preorder" << std::endl;
    my_tree.print_preorder();

    std::cout << "Postorder" << std::endl;
    my_tree.print_postorder();

    std::cout << "Search for 111: " << my_tree.search(111) << std::endl;
    std::cout << "Catching exception: ";
    try {
        my_tree.search(123);
    } catch (const char exc[]) {
        std::cout << "caught" << std::endl;
    }

    std::cout << "successor of 10 is " << my_tree.successor(10) << std::endl;
    std::cout << "deleting nodes " << std::flush;
    my_tree.delete_node(111);
    std::cout << "first " << std::flush;
    my_tree.delete_node(10);
    std::cout << "second " << std::flush;
    my_tree.delete_node(3);
    std::cout << "third " << std::endl;
    my_tree.print_inorder();


    return 0;
}
