#ifndef ALGORITHM_BUBBLESORT_H
#define ALGORITHM_BUBBLESORT_H

#include <iostream>

using namespace std;

template <typename T>
void BubbleSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int len = n - i - 1;
        for (int j = 0; j < len; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
        arr[len]
    }
}
#endif //ALGORITHM_BUBBLESORT_H
