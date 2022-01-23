#!/usr/bin/env python
# -*- coding:utf-8 -*-
# @Time  : 17/1/2022 下午 6:50
# @Author: xiaoni
# @File  : quicksort.py

'''
    任然存在
'''

def quicksort(aa, low, high):
    if low >= high:
        return
    p = aa[low]
    lowtem = low
    hightem = high

    while lowtem < hightem:
        while lowtem < hightem and aa[hightem] >= p:
            hightem = hightem - 1
        aa[lowtem] = aa[hightem]
        while lowtem < hightem and aa[lowtem] <= p:
            lowtem = lowtem + 1
        aa[hightem] = aa[lowtem]

    aa[lowtem] = p
    quicksort(aa, low, lowtem - 1)
    quicksort(aa, lowtem + 1, high)


if __name__ == "__main__":
    n = int(input())
    a = [int(x) for x in input().split()]
    quicksort(a, 0, len(a) - 1)
    for i in range(len(a) ):
        print(a[i], end='')
        print(" ", end='')
