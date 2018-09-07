#ifndef ALGORITHM_INSERTIONSORT_H
#define ALGORITHM_INSERTIONSORT_H
#include <iostream>

using namespace std;

template <typename T>
void insertionSort(T arr[], int n) {
    // 每次遍历一旦发现后面的值小于前面的值,
    // 则在数组中往前寻找直到找到合适的位置插入
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; --j) {
            swap(arr[j], arr[j-1]);
        }
    }
}

template <typename T>
void optimizedIS(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && e < arr[j-1]; --j) {
            // 若e > arr[j-1] 则arr[j-1]后移一位
            arr[j] = arr[j-1];
        }
        // 选择合适的位置直接插入
        arr[j] = e;
    }
}

template <typename T>
void optimizedIS(T arr[], int l, int r) {
    for (int i = l; i <= r; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > l && e < arr[j-1]; --j) {
            // 若e > arr[j-1] 则arr[j-1]后移一位
            arr[j] = arr[j-1];
        }
        // 选择合适的位置直接插入
        arr[j] = e;
    }
}
#endif //ALGORITHM_INSERTIONSORT_H
