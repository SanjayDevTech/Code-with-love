# Python to do insertionSort in a recursive way
def insertionSort(arr, size): 
    if size <= 1: 
        return
      
    insertionSort(arr, size-1)
	
    last = arr[size-1] 
    j = size-2
	
    while (j >= 0 and arr[j] > last): 
        arr[j+1] = arr[j] 
        j = j-1
  
    arr[j+1]=last 

arr = [56,45,78,22,11,84] 
insertionSort(arr, len(arr)) 

print ("Sorted Array :") 
for i in range(len(arr)): 
    print ("%d" %arr[i]),