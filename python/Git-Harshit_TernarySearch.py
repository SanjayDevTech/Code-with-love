# Ternary Search Program in Python 3
def Ternary_Search(sorted_list, search_value):
    "Python Function to implement Ternary Search to search for search_value in sorted_list, sorted in ascending order"
    list_size = len(sorted_list)

    left_index  = 0
    right_index = list_size-1

    while left_index <= right_index:
        partition1_index = left_index + (right_index-left_index)//3
        partition2_index = right_index - (right_index-left_index)//3

        if sorted_list[partition1_index] == search_value:       # Checking for search_value match with partition1_index 
            return partition1_index
        elif sorted_list[partition2_index] == search_value:     # Checking for search_value match with partition2_index
            return partition2_index
        elif sorted_list[partition1_index]>search_value:        # This condition ensures value could be in first part out of three parts
            right_index = partition1_index-1
        elif sorted_list[partition2_index]<search_value:        # This condition ensures value could be in third/last part out of three parts
            left_index = partition2_index + 1
        else:                                                   # This condition ensures value could be in second part out of three parts
            left_index = partition1_index+1
            right_index = partition2_index-1

    return -1    # Invalid Positive Index (0-Based), not in mathematical range [0, list_size)

# Executing a sample function usage program only when the Python Program is executed
if __name__ == "__main__":
    exemplary_sorted_list = [00, 10, 20, 30, 40, 50, 60, 70, 80, 90]
    search_element = 90

    # Getting positive index (if any) for which search element could be found and located in the exemplary_sorted_list
    element_index = Ternary_Search(exemplary_sorted_list, search_element)

    # Validating the returned index, to check for the prescence of search_element in exemplary_sorted_list
    if 0 <= element_index < len(exemplary_sorted_list):print("Element {} found in {} at index {}".format(element_index, exemplary_sorted_list, element_index)) 
    else: print("Element {} was not found in {}".format(element_index, exemplary_sorted_list))
