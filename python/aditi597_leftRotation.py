#Author : ADITI JAIN
#Date : 03-10-2020
#Algorithm to rotate the elements of array by d elements.
# Input: arr=[1,2,3,4,5]  , d=2
# Output: arr=[3,4,5,1,2]

array = list(map(int, input().split())) # taking an array as input from the user where
                                        # user has to enter integer elements seperated by spaces.
d = int(input())  #taking the number of positions to be rotated at a time.
print(arr[d:]+arr[:d])   #concatenating the first half to the end of the 
                         #array and shifting the second half to the beginning.
