from typing import List


def merge(array_one: List[int], array_two: List[int]) -> List[int]:
    '''
    Merge two sorted subarrays into a single sorted array
    '''
    pointer_one = pointer_two = 0
    merged_array = []

    # repeatedly choose the smallest element
    # until one of the list gets exhausted
    while (
            pointer_one < len(array_one) and
            pointer_two < len(array_two)
        ):
        # choose the smallest element among the two

        if array_one[pointer_one] < array_two[pointer_two]:
            merged_array.append(array_one[pointer_one])
            pointer_one += 1
        else:
            merged_array.append(array_two[pointer_two])
            pointer_two += 1
        
    # Insert the remaining elements if any

    while pointer_one < len(array_one):
        merged_array.append(array_one[pointer_one])
        pointer_one += 1

    while pointer_two < len(array_two):
        merged_array.append(array_two[pointer_two])     
        pointer_two += 1

    return merged_array

def merge_sort(array: List[int]) -> List[int]:
    '''
    Merge Sort function
    '''
    # base case
    if len(array) <= 1:
        # if there are less than or
        # equal to 1 element in array
        # return it
        return array
    
    mid = len(array) // 2
    # divide array into left and right subarrays
    # and sort them
    left_half = merge_sort(array[ :mid])
    right_half = merge_sort(array[mid:])
    # merge and return the sorted arrays
    return merge(left_half, right_half)

def generate_test_case(min_num: int, max_num: int, length: int) -> List[int]:
    '''
    Generate test cases for sorting
    '''
    from random import randint
    test_case = [randint(min_num, max_num) for _ in range(length)]
    print('Test case is')
    print(test_case)
    print('\n\n')
    return test_case

if __name__ == '__main__':
    test_case = generate_test_case(0, 1000, 100)
    print('Sorted array')
    print(merge_sort(test_case))
    