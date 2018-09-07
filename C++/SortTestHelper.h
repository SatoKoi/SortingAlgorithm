#ifndef ALGORITHM_SORT_TEST_HELPER_H
#define ALGORITHM_SORT_TEST_HELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{
    // 生成有n个元素的随机数组, 每个元素的随机范围为[rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR){
        assert(rangeL <= rangeR);
        int* arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    // 生成n个近乎有序的数组
    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; ++i) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
    }

    template <typename T>
    void printArray(T arr, int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }

    template <typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    /* @author: KoiSato
     * sort 为void类型的排序算法函数指针
     * 打印排序算法运行的时间
     * */
    template <typename T>
    double testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {
        double lastingTime;
        clock_t startTime = clock(); // 时钟周期
        sort(arr, n);
        clock_t endTime = clock();
        lastingTime = double(endTime - startTime) / CLOCKS_PER_SEC;
        assert(isSorted(arr, n));
        cout << sortName << " : " << lastingTime << " s" << endl;
        return lastingTime;
    }

    int* copyIntArray(int a[], int n) {
        int* arr = new int[n];
        // copy(头指针, 尾指针, 目标对象);
        copy(a, a+n, arr);
        return arr;
    }
}
#endif
