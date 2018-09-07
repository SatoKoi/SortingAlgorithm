#ifndef ALGORITHM_HEAPSORT_H
#define ALGORITHM_HEAPSORT_H

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

template <typename Item>
class MaxHeap {
private:
    Item *data;
    int capacity;
    int count;

    void shiftUp(int k) {
        // 如果存在父节点, 且父节点大于子节点的值
        while(k/2 >= 1 && data[k] > data[k/2]) {
            swap(data[k], data[k/2]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        // 如果存在子节点
        while(2*k <= count) {
            int j = 2*k;
            if(j+1 <= count && data[j] < data[j+1]) {
                j += 1;
            }
            // 如果父节点大于子节点, 则无需继续操作
            if(data[j] <= data[k])
                break;
            swap(data[j], data[k]);
            k = j;
        }
    }
public:
    MaxHeap(int capacity) {
        data = new Item[capacity+1];
        this->capacity = capacity;
        this->count = 0;
    }

    MaxHeap(Item arr[], int capacity) {
        data = new Item[capacity + 1];
        this->capacity = capacity;
        for (int i = 0; i < capacity; ++i) {
            data[i+1] = arr[i];
        }
        count = capacity;

        // 找出所有存在子节点的父节点, 进行heapify操作
        for (int i = count / 2; i >= 1; --i) {
            shiftDown(i);
        }
    }

    ~MaxHeap(){
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Item item) {
        assert(capacity > count);
        data[++count] = item;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);
        Item ret = data[1];
        swap(data[1], data[count--]);
        shiftDown(1);
        return ret;
    }

    void printHeap() {
        double cnt = 0.0;
        int layer=0;    // 层数
        int len;        // 每层长度
        int j=1;        // 每层索引
        int total=0;    // 总长
        string split=" ";   // 分隔符
        while(pow(2, cnt) <= count) {
            len = (total + (int)pow(2, cnt)) < count ? (int)pow(2, cnt) : count - total;
            for (int i = j; i <= len+j-1; ++i) {
//                if (layer >= 1) {
//                    for (int k = 0; k < len - j; ++k) {
//                        cout << "/\t\\";
//                    }
//                }
                cout << data[i] << split;
            }
            cout << endl;
            j += len;
            total += len;
            layer++;
            cnt++;
        }
    }
};

template <typename T>
void heapSort(T arr[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(n);
    for (int i = 0; i < n; ++i) {
        maxHeap.insert(arr[i]);
    }
    for (int i = n-1; i >= 0 ; --i) {
        arr[i] = maxHeap.extractMax();
    }
}

template <typename T>
void optimizedHS(T arr[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);
    for (int i = n-1; i >= 0 ; --i) {
        arr[i] = maxHeap.extractMax();
    }
}

template <typename T>
void __shiftDown(T arr[], int n, int k) {
    // 如果存在子节点
    while(2*k+1 < n) {
        int j = 2*k+1;
        // 如果存在右节点, 且右节点大于左节点, 则使用该点与父节点进行交换
        if (j + 1 < n && arr[j+1] > arr[j])
            j += 1;
        // 如果父节点大于应被交换的节点, 则说明堆已最大化
        if (arr[k] >= arr[j])
            break;
        // 否则直接进行交换
        swap(arr[k], arr[j]);
        k = j;
    }
}

template <typename T>
void localHeapSort(T arr[], int n) {
    // heapify构建最大堆
    for (int i = (n-1)/2; i >= 0; i--) {
        __shiftDown(arr, n, i);
    }

    // 最大值置于最后
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}

#endif //ALGORITHM_HEAPSORT_H
