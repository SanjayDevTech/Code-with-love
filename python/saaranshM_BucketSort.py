# Python program for Bucket Sort

# function for bucket sort
def bucket_sort(list_to_be_sorted):
    """
    Bucket Sort is a comparison-type algorithm which assigns elements of a list we want to sort in Buckets, or Bins.
    The contents of these buckets are then sorted, typically with another algorithm. After sorting, the contents of the
    buckets are appended, forming a sorted collection.

    Bucket Sort can be thought of as a scatter-order-gather approach towards sorting a list, due to the fact that the
    elements are first scattered in buckets, ordered within them, and finally gathered into a new, sorted list.

    list_to_be_sorted: list
    The list which as to be sorted.
    """

    """
    Find maximum value in the list and use length of the list to determine which
    value in the list goes into which bucket 
    """
    max_val = max(list_to_be_sorted)
    bucket_size = max_val / len(list_to_be_sorted)

    # Creating the buckets with n as the length of the input list
    bucket_list = []
    for _ in range(len(list_to_be_sorted)):
        bucket_list.append([])

    # Putting list elements to different buckets based on their size
    for i in range(len(list_to_be_sorted)):
        j = int(list_to_be_sorted[i] / bucket_size)
        if j != len(list_to_be_sorted):
            bucket_list[j].append(list_to_be_sorted[i])
        else:
            bucket_list[len(list_to_be_sorted) - 1].append(list_to_be_sorted[i])

    # Sorting elements inside the bucket using insertion sort
    for k in range(len(list_to_be_sorted)):
        insertion_sort(bucket_list[k])

    # Concatenate buckets with sorted elements into a single list
    sorted_list = []
    for x in range(len(list_to_be_sorted)):
        sorted_list = sorted_list + bucket_list[x]
    return sorted_list


# implemented insertion sort for sorting the buckets
def insertion_sort(bucket):
    for i in range(1, len(bucket)):
        var = bucket[i]
        j = i - 1
        while j >= 0 and var < bucket[j]:
            bucket[j + 1] = bucket[j]
            j = j - 1
        bucket[j + 1] = var


# Test Code
list_to_be_sorted = [0.1, 0.01, 3, 0.85, 9.43, 8.43, 6.33]
print("Original List:")
print(list_to_be_sorted)
sorted_list = bucket_sort(list_to_be_sorted)
print("Sorted List:")
print(sorted_list)
