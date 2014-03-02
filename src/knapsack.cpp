#include <iostream>
using namespace std;

struct item {
    int value, weight;
};

int main()
{
    int items_n, tot_weight;
    cin >> tot_weight;
    cin >> items_n;

    item *items = new item[items_n];
    for (int i = 0; i < items_n; ++i) {
        cin >> items[i].value;
        cin >> items[i].weight;
    }

    int *values = new int[tot_weight + 1];
    values[0] = 0;

    for (int i = 1; i <= tot_weight; ++i) {
        int max_w = 0;
        for (int j = 0; j < items_n; ++j) {
            if (items[j].weight > i) continue;

            int new_max = items[j].value + values[i - items[j].weight];
            if (new_max > max_w)
                max_w = new_max;
        }
        values[i] = max_w;
    }

    cout << "Max value is " << values[tot_weight] << endl;
}
