#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const int SIZE = 100;

int* radixsort(int *array, int size, int level=0)
{
    if (level > 32 || size < 2) return array;

    int *left = new int[size],
        *right = new int[size],
        current_left = 0,
        current_right = 0;

    for (int i = 0; i < size; ++i) {
        if ((array[i] >> (31 - level))%2 == 0) {
            left[current_left] = array[i];
            current_left += 1;
        } else {
            right[current_right] = array[i];
            current_right += 1;
        }
    }

    left = radixsort(left, current_left, level + 1);
    right = radixsort(right, current_right, level + 1);

    for (int i = 0; i < size; ++i) {
        if (i < current_left)
            array[i] = left[i];
        else
            array[i] = right[i - current_left];
    }

    delete[] left;
    delete[] right;
    return array;
}


int main(int argc, char *argv[])
{
    int numbers[SIZE];
    srand(111);

    for (int i = 0; i < SIZE; ++i)
        numbers[i] = rand()%100;

    radixsort(numbers, SIZE);

    for (int i = 0; i < SIZE; ++i)
        cout << numbers[i] << " ";
    cout << endl;

    return 0;
}

