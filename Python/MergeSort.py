# -*- coding:utf-8 -*-

def merge_sort(array):
    """
    归并排序  D&C 分而治之思想
    与快速排序的区别是它是先分后治的算法
    """
    if len(array) < 2:
        return array
    mid = len(array) // 2
    left_arr = merge_sort(array[:mid])      # 分
    right_arr = merge_sort(array[mid:])     # 分
    return merge(left_arr, right_arr)       # 治

def merge(left, right):
    """并"""
    arr = []
    l_idx = r_idx = 0
    l_len, r_len = len(left), len(right)
    # 每次将两边数组的最小值加入到arr中
    while l_idx < l_len and r_idx < r_len:
        if left[l_idx] < right[r_idx]:
            arr.append(left[l_idx])
            l_idx += 1
        else:
            arr.append(right[r_idx])
            r_idx += 1
    # 因为总有一边数组还没有归并到arr中, 需做剩余部分的归并处理
    if l_len == l_idx:
        arr.extend(right[r_idx:])
    elif r_len == r_idx:
        arr.extend(left[l_idx:])
    return arr