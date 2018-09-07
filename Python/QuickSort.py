# -*- coding:utf-8 -*-

def quick_sort(array):
    """
    快速排序 D&C 分而治之思想
    与归并排序的区别是它是先治后分的算法
    """
    if len(array) < 2:                              # 基线条件
        return array
    left_arr = []
    right_arr = []
    pivot = array[0]                                # 基准值
    partition(pivot, left_arr, right_arr, array)    # 治
    left_arr = quick_sort(left_arr)                 # 分
    right_arr = quick_sort(right_arr)               # 分
    return left_arr + [pivot] + right_arr

def partition(pivot, left_arr, right_arr, array):
    """
    分区
    """
    for i in range(1, len(array)):
        if pivot > array[i]:
            left_arr.append(array[i])
        else:
            right_arr.append(array[i])