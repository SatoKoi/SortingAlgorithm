#ifndef ALGORITHM_SELECTIONSORT_H
#define ALGORITHM_SELECTIONSORT_H

#include <iostream>

using namespace std;

template <typename T>
void selectionSort(T arr[], int n) {
    // 每次选出最小值的索引, 并将其与首位置进行交换
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}
#endif
