#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"

using namespace std;

namespace SortTest{
    void selectionSortTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        selectionSort(arr, n);
        SortTestHelper::printArray(arr, n);
    }

    void InsertionSortTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        insertionSort(arr, n);
        SortTestHelper::printArray(arr, n);
    }

    void optimizedISTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        optimizedIS(arr, n);
        SortTestHelper::printArray(arr, n);
    }

    void bubbleSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        bubbleSort(arr, n);
        SortTestHelper::printArray(arr, n);
    }

    void mergeSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        mergeSort(arr, n);
        SortTestHelper::printArray(arr, n);
    }
}

namespace TimeTest{
    void selectionSortTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        SortTestHelper::testSort("SelectionSort", selectionSort, arr, n);
    }

    void insertionSortTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        SortTestHelper::testSort("InsertionSort", insertionSort, arr, n);
    }

    void optimizedISTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        SortTestHelper::testSort("Optimized InsertionSort", optimizedIS, arr, n);
    }

    void bubbleSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        SortTestHelper::testSort("BubbleSort", bubbleSort, arr, n);
    }

    void mergeSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        SortTestHelper::testSort("mergeSort", mergeSort, arr, n);
    }
}

int main() {
    int count = 50000;
//    int n = 30;
//    SortTest::mergeSortTest(n);
    TimeTest::selectionSortTest(count);
    TimeTest::bubbleSortTest(count);
    TimeTest::insertionSortTest(count);
    TimeTest::optimizedISTest(count);
    TimeTest::mergeSortTest(count);
    return 0;
}