#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 1000;

// Why is it impossible to stack-allocate with variable size?

int* mergesort(int *array, int size)
{
    if (size < 2) return array;

    int right_size = size - size / 2;
    int *left = mergesort(array, size / 2),
        *right = mergesort(array + size / 2, size - size / 2);

    // Merge
    int *merged = new int[size];
    int left_i = 0,
        right_i = 0;

    for (int i = 0; i < size; ++i) {
        if (left_i < size / 2 && (right_i >= right_size || left[left_i] < right[right_i])) {
            merged[i] = left[left_i];
            left_i += 1;
        } else {
            merged[i] = right[right_i];
            right_i += 1;
        }
    }

    for (int i = 0; i < size; ++i)
        array[i] = merged[i];

    delete[] merged;
    return array;
}


int main(int argc, char *argv[])
{
    int numbers[SIZE];
    srand(111);

    for (int i = 0; i < SIZE; ++i)
        numbers[i] = rand()%100;

    mergesort(numbers, SIZE);

    for (int i = 0; i < SIZE; ++i)
        cout << numbers[i] << " ";
    cout << endl;

    return 0;
}
