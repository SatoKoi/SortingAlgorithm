#ifndef ALGORITHM_SELECTIONSORT_H
#define ALGORITHM_SELECTIONSORT_H

#include <iostream>

using namespace std;

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int min = arr[i];
        for (int j = i+1; j < n; ++j) {
            if (min < arr[j])
                min = arr[j];
        }
        arr[i] = min;
    }
}
#endif
