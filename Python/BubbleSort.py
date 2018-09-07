# -*- coding:utf-8 -*-
def bubble_sort(array):
    """
    冒泡排序
    时间复杂度 O(n^2)
    最差情况 n(n-1)/2
    """
    new_array = []
    # 外层循环控制排序趟数
    for i in range(len(array)):
        array_len = len(array) - i - 1
        # 内层循环控制排序次数和范围
        for j in range(array_len):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
        # 每次将排序的最大数放在最后
        new_array.insert(0, array[array_len])
    return new_array