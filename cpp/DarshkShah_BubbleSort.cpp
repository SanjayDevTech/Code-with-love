// C++ program for implementation of Bubble sort 
#include <bits/stdc++.h> 
using namespace std; 
/**
    In the bubble sort approach to sort an array,
    we first compare two adjacent numbers, and swap if they are not in the correct order
    Hence, after the first pass the heaviest/ largest emement reaches the end.
    This comparison is done n - 1 times
    and the inner loop runs upto n - i - 1 times as after every iteration we have 1 element
    correctly at the end ie. after i iterations, there will be i at the end.
    
    Sample run:
    
    Input: 2 6 8 1
    
    PASS 1:
     2 6 8 1
     2 6 8 1
     2 6 1 8
    end of pass 1
    
    PASS 2:
    2 6 1 8
    2 1 6 8
    end of pass 2
    
    PASS 3:
    1 2 6 8
    end of pass 3
     
*/

void bubbleSort(int arr[], int n) 
{ 
	int i, j, temp; 
	for (i = 0; i < n-1; i++)	 
	    for (j = 0; j < n-i-1; j++) 
    		if (arr[j] > arr[j+1]) 
    		{
    		    temp = arr[j+1];
    		    arr[j+1] = arr[j];
    		    arr[j] = temp;
    		}
} 

int main() 
{ 
	int arr[] = {36, 64, 22, 34, 83, 25, 49, 12, 15, 22}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	bubbleSort(arr, n); 
	cout<<"Sorted array: \n"; 
	
	for(int i = 0;i<n;i++)
	    cout<<arr[i]<<" ";
	cout<<"\n";
	return 0; 
} 

//Contributed by Darsh K Shah
