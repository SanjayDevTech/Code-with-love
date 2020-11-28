
# Python to do bubbleSort in a recursive way
def bubbleSort(arr, size):
	if size == 1:
		return
	for i in range(size-1):
		if arr[i] > arr[i+1]:
			arr[i], arr[i+1] = arr[i+1], arr[i]
	bubbleSort(arr, size-1)
  
arr = [56,45,78,22,11,84] 
bubbleSort(arr, len(arr)) 

print ("Sorted Array :") 
for i in range(len(arr)): 
    print ("%d" %arr[i]),