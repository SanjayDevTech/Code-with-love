#Python program to do bubble sort

# Function to do bubble sort 

def bubbleSort(arr): 
    n = len(arr) 
    
    for i in range(n): 
        for j in range(0, n-i-1): 
        
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
  
arr = [56,45,78,22,11,84] 
bubbleSort(arr) 

print ("Sorted Array :") 
for i in range(len(arr)): 
    print ("%d" %arr[i]),  
