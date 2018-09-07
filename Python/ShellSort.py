# -*- coding:utf-8 -*-

def shell_sort(array):
    """
    希尔排序
    在直接插入排序的基础上增加了增量这一概念
    使得相互比较得以以一个较大的步长来完成
    减少了循环次数
    """
    gap = len(array) // 2
    # gap = 0终止循环
    while gap:
        # 遍历各个增量相关数组
        for i in range(gap, len(array)):
            # 后面等同于直接插入排序
            j = i - gap
            if array[i] < array[j]:
                while j >= 0:
                    if array[i] < array[j]:
                        array[i], array[j] = array[j], array[i]
                    i, j = j, j - gap
        gap //= 2
    return array
