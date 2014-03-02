#include <iostream>
#include "Stack.h"
using namespace std;
using namespace goog;

int main(int argc, char *argv[])
{
    Stack<int> my_stack;

    for (int i = 0; i < 20; ++i) my_stack.push(i);

    for (int i = 0; i < 20; ++i) cout << my_stack.pop() << endl;
}

