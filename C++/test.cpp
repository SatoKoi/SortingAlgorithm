#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

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

    void quickSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        quickSort(arr, n);
        SortTestHelper::printArray(arr, n);
    }

    void dbQuickSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        dbQuickSort(arr, n);
        SortTestHelper::printArray(arr, n);
    }

    void quickSortThreeWaysTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        quickSortThreeWays(arr, n);
        SortTestHelper::printArray(arr, n);
    }

    void heapSortTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        heapSort(arr, n);
        SortTestHelper::printArray(arr, n);
    }

    void optimizedHSTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        optimizedHS(arr, n);
        SortTestHelper::printArray(arr, n);
    }

    void localHeapSortTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        localHeapSort(arr, n);
        SortTestHelper::printArray(arr, n);
    }
}

namespace TimeTest{
    const int TIME = 3;
    int __TIME = TIME;

    void commonTest(double (*sortTest)(int), int n) {
        double average = 0.0;
        while(__TIME--) {
            average += sortTest(n);
        }
        cout << "Average Time: " << average / TIME << " s"<< endl;
        __TIME = TIME;
    }

    double selectionSortTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("SelectionSort", selectionSort, arr, n);
    }

    double insertionSortTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("InsertionSort", insertionSort, arr, n);
    }

    double optimizedISTest(int n) {
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("Optimized InsertionSort", optimizedIS, arr, n);
    }

    double bubbleSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("BubbleSort", bubbleSort, arr, n);
    }

    double mergeSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("MergeSort", mergeSort, arr, n);
    }

    double quickSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("QuickSort", quickSort, arr, n);
    }

    double dbQuickSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("DoubleWays QuickSort", dbQuickSort, arr, n);
    }

    double quickSortThreeWaysTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("ThreeWays QuickSort", quickSortThreeWays, arr, n);
    }

    double heapSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("HeapSort", heapSort, arr, n);
    }

    double optimizedHSTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("Optimized HeapSort", optimizedHS, arr, n);
    }

    double localHeapSortTest(int n){
        int *arr = SortTestHelper::generateRandomArray(n, 0, n);
        return SortTestHelper::testSort("Local HeapSort", localHeapSort, arr, n);
    }
}

int main() {
    int count = 5000000;
    int n = 30;
//    SortTest::mergeSortTest(n);
//    SortTest::quickSortTest(n);
//    SortTest::dbQuickSortTest(n);
//    SortTest::quickSortThreeWaysTest(n);
//    SortTest::heapSortTest(n);
//    SortTest::optimizedHSTest(n);
//    SortTest::localHeapSortTest(n);
//    TimeTest::commonTest(TimeTest::quickSortTest, count);
//    TimeTest::commonTest(TimeTest::dbQuickSortTest, count);
//    TimeTest::commonTest(TimeTest::quickSortThreeWaysTest, count);
    TimeTest::commonTest(TimeTest::heapSortTest, count);
    TimeTest::commonTest(TimeTest::optimizedHSTest, count);
    TimeTest::commonTest(TimeTest::localHeapSortTest, count);
    return 0;
}