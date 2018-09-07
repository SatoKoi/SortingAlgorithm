#ifndef ALGORITHM_MERGESORT_H
#define ALGORITHM_MERGESORT_H

#include <iostream>
#include "InsertionSort.h"
#include "SortTestHelper.h"

using namespace std;

template <typename T>
T* deepcopy(T arr[], int l, int r){
    T *aux = new int[r-l+1];
    for (int i = l; i <= r; ++i) {
        aux[i-l] = arr[i];
    }
    return aux;
}

template <typename T>
void __merge(T arr[], int l, int mid, int r) {
    // 深拷贝arr
    T *aux = deepcopy(arr, l, r);
    for (int i = l; i <= r; ++i) {
        aux[i-l] = arr[i];
    }
    int i = l, j = mid + 1;
    // 遍历r - l次
    for (int k = l; k <= r; ++k) {
        if(i > mid) {
            arr[k] = aux[j-l];
            j++;
        }
        else if(j > r) {
            arr[k] = aux[i-l];
            i++;
        }
        else if(aux[i-l] < aux[j-l]) {
            arr[k] = aux[i-l];
            i++;
        }
        else {
            arr[k] = aux[j-l];
            j++;
        }
    }
}

// 归并排序需要使用辅助空间
template <typename T>
void __mergeSort(T arr[], int l, int r) {
    // 设置基线条件
    /*
    if(l >= r) {
        return;
    }
    */
    // 此处在归并时, 若数组元素个数小于16则使用优化的插入排序进行排序
    if (r - l <= 15) {
        optimizedIS(arr, l, r);
        return;
    }
    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n-1);
}
#endif //ALGORITHM_MERGESORT_H
