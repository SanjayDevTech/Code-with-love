#MO’s Algorithm (Query Square Root Decomposition) ---


# Python program to compute sum of ranges for different range queries. 

# Function that accepts array and list of queries and print sum of each query 
def printQuerySum(arr,Q): 
	
	for q in Q: # Traverse through each query 
		L,R = q # Extract left and right indices 
		s = 0
		for i in range(L,R+1): # Compute sum of current query range 
			s += arr[i] 
			
		print("Sum of",q,"is",s) # Print sum of current query range 

# Driver script 
arr = [1, 1, 2, 1, 3, 4, 5, 2, 8] 
Q = [[0, 4], [1, 3], [2, 4]] 
printQuerySum(arr,Q) 

