#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 100;

void quicksort(int *array, int size)
{
    if (size < 2) return;

    int exchange = 0,
        pivot = rand()%size,
        tmp;

    tmp = array[pivot];
    array[pivot] = array[size - 1];
    array[size - 1] = tmp;

    for (int i = 0; i < size - 1; ++i) {
        if (array[i] < array[size - 1]) {
            tmp = array[i];
            array[i] = array[exchange];
            array[exchange] = tmp;
            exchange += 1;
        }
    }

    tmp = array[exchange];
    array[exchange] = array[size - 1];
    array[size - 1] = tmp;

    quicksort(array, exchange);
    quicksort(array + exchange + 1, size - exchange - 1);
}

int main(int argc, char *argv[])
{
    int numbers[SIZE];
    srand(111);

    for (int i = 0; i < SIZE; ++i)
        numbers[i] = rand()%100;

    quicksort(numbers, SIZE);

    for (int i = 0; i < SIZE; ++i)
        cout << numbers[i] << " ";
    cout << endl;

    return 0;
}
