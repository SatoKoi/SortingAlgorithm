#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

#include <iostream>
#include "InsertionSort.h"

using namespace std;

template <typename T>
int __partition(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    // 选择随机基准值
    T pivot = arr[l];
    // < pivot值的数组索引位置
    int j = l;
    for (int i = l+1; i <= r; ++i) {
        if(pivot > arr[i]) {
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[j], arr[l]);
    return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r) {
    if (r - l <= 15) {
        optimizedIS(arr, l, r);
        return;
    }
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n) {
    // 使用随机种子
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

template <typename T>
int __dbPartition(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T pivot = arr[l];
    // arr[l+1...i] <= v; arr(j...r] >= v;
    int i = l+1, j = r;
    while(true) {
        // 如果i未越界, 且arr[i]小于基准值, i自增
        while (i <= r && arr[i] < pivot) i++;
        // 如果j未越界, 且arr[j]大于基准值, j自减
        while (j >= l+1 && arr[j] > pivot) j--;
        // 如果i > j, 说明扫描完所有的索引项, 停止partition
        if(i > j) break;
        // 如果都不满足, 则说明arr[i] >= pivot && arr[j] <= pivot
        // 交换两者顺序, 使得小于pivot的数组元素在左边, 反之在右边
        swap(arr[i], arr[j]);
        i ++;
        j --;
    }
    // 最后将基准值放在两端数组的中间
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __dbQuickSort(T arr[], int l, int r) {
    if(r - l <= 15) {
        optimizedIS(arr, l, r);
        return;
    }
    int p = __dbPartition(arr, l, r);
    __dbQuickSort(arr, l, p-1);
    __dbQuickSort(arr, p+1, r);
}

// 双路快速排序
template <typename T>
void dbQuickSort(T arr[], int n) {
    srand(time(NULL));
    __dbQuickSort(arr, 0, n-1);
}

// 三路快速排序
// 将arr[l...r]分为 <pivot; ==pivot; >pivot三部分
// 之后递归对 <pivot, >pivot两部分进行排序
template <typename T>
void __quickSortThreeWays(T arr[], int l, int r) {
    if(r - l <= 15) {
        optimizedIS(arr, l, r);
        return;
    }
    // partition
    // 选择随机基准值
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T pivot = arr[l];

    // lt作为<pivot数组的最后索引
    int lt = l;
    // gt作为>pivot数组的最前索引
    int gt = r + 1;
    // i作为==pivot数组的最后索引
    int i = l + 1;
    while(i < gt) {
        if(arr[i] < pivot) {
            swap(arr[i++], arr[++lt]);
        }
        else if(arr[i] > pivot) {
            swap(arr[i], arr[--gt]);
        }
        else{
            i++;
        }
    }
    swap(arr[l], arr[lt]);
    __quickSortThreeWays(arr, l, lt-1);
    __quickSortThreeWays(arr, gt, r);
}

template <typename T>
void quickSortThreeWays(T arr[], int n){
    srand(time(NULL));
    __quickSortThreeWays(arr, 0, n-1);
}
#endif //ALGORITHM_QUICKSORT_H
