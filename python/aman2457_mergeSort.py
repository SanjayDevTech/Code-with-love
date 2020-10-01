# -*- coding: utf-8 -*-
"""
Merge sort is a sorting technique based on divide and conquer technique. With worst-case time complexity being Ο(n log n), it is one of the most respected algorithms.

Merge sort first divides the array into equal halves and then combines them in a sorted manner.
"""

#merge function- a helper function which does the work for merging
def merge(left,right):
    i,j=0,0
    result=[]
    while i<len(left) and j<len(right):
        if left[i]<=right[j]:
            result.append(left[i])
            i=i+1
        else:
            result.append(right[j])
            j=j+1
    result+=left[i:]
    result+=right[j:]
    return result

#recursive approach for mergeSort.
def mergeSort(arr):
    if len(arr)<=1:
        return arr
    else:
        mid=int(len(arr)/2)
        left=mergsort(arr[:mid])
        right=mergsort(arr[mid:])
    return merge(left,right)

lis = [7,4,5,8,2,6,1,8,9]
print(mergeSort(lis))

