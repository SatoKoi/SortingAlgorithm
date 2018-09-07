#ifndef ALGORITHM_BUBBLESORT_H
#define ALGORITHM_BUBBLESORT_H

#include <iostream>

using namespace std;

template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
#endif //ALGORITHM_BUBBLESORT_H
