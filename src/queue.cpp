#include <iostream>
#include "Queue.h"
using namespace std;
using namespace goog;

int main(int argc, char *argv[])
{
    Queue<int> my_queue;

    for (int i = 0; i < 20; ++i) my_queue.push(i);
    for (int i = 0; i < 20; ++i) cout << my_queue.pop() << endl;

    for (int i = 0; i < 20; ++i) my_queue.push(i);
    for (int i = 0; i < 20; ++i) my_queue.pop();

    for (int i = 0; i < 20; ++i) my_queue.push(i);
    for (int i = 0; i < 20; ++i) cout << my_queue.pop() << endl;

    return 0;
}
