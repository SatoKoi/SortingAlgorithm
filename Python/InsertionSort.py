# -*- coding:utf-8 -*-
def insertion_sort(array):
    """
    直接插入排序
    """
    # 外层循环控制插入排序遍历次数
    for i in range(1, len(array)):
        # 相互比较
        if array[i-1] > array[i]:
            # 如果发现前面的元素大于后面的
            # 则将后面的元素逐步比较之前的元素, 插入到正确的位置
            for j in reversed(range(1, i+1)):
                if array[j-1] > array[j]:
                    array[j-1], array[j] = array[j], array[j-1]
    return array