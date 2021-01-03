#Python Implementation of Quick Sort
#Written by GhostUSer on 1.10.2020

'''Quick sort is based on the divide-and-conquer approach based on the idea of choosing one element as a pivot element 
and partitioning the array around it such that: Left side of pivot contains all the elements 
that are less than the pivot element Right side contains all elements greater than the pivot.

It reduces the space complexity and removes the use of the auxiliary array that is used in merge sort. 
Selecting a random pivot in an array results in an improved time complexity in most of the cases.'''

def quick_sort(arr):
    if len(arr)<=1:
        return arr
    else:
        pivot=arr[len(arr)//2]
        left=[x for x in arr if x<pivot]
        middle=[x for x in arr if x==pivot]
        right=[x for x in arr if x>pivot]
        return quick_sort(left)+middle+quick_sort(right)


arr=[32,33,34,57,68,99,123,1,2,46,47,48,27,30,31,52,124,53,54,58,59,13,24,25]
result=quick_sort(arr)
print(*result)

#Uncomment for input type
'''
#Enter the array
arr=list(map(int, input().split()))
print(quick_sort(arr)) 
'''