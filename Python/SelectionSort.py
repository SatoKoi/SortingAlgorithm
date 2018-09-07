# -*- coding:utf-8 -*-
def selection_sort(array):
    """
    选择排序
    时间复杂度 O(n^2)
    最坏情况 n(n-1)/2
    """
    new_arr = []
    # 外层循环控制循环次数
    # 每趟循环将找出最小的元素放到new_arr中
    for i in range(len(array)):
        smallest_index = find_smallest(array)
        new_arr.append(array.pop(smallest_index))
    return new_arr

def find_smallest(array):
    """每次寻找最小的元素"""
    smallest = array[0]
    arr_index = 0
    for i in range(1, len(array)):
        if smallest > array[i]:
            smallest = array[i]
            arr_index = i
    return arr_index


if __name__ == '__main__':
    arr = [3, 5, 6, 1, 2, 7, 9, 8, 4, 0]
    arr = selection_sort(arr)
    print(arr)