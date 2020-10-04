//Sort an array of 0’s 1’s 2’s without using extra space or sorting algo
/*
--> Dutch National Flag Algorithm OR 3-way Partitioning:

At first, the full array is unknown. There are three indices – low, mid and high. Initially, the value of low = mid = 1 and high = N.

1. If the ith element is 0 then swap the element to the low range, thus shrinking the unknown range.

2. Similarly, if the element is 1 then keep it as it is but shrink the unknown range.

3. If the element is 2 then swap it with an element in high range.

--> Algorithm:

1. Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).

2. Traverse the array from start to end and mid is less than high. (Loop counter is i)

3. If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1

4. If the element is 1 then update mid = mid + 1

5. If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed

6. Print the output array
*/
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to sort the input array, 
// the array is assumed 
// to have values in {0, 1, 2} 
void sort(int a[], int arr_size) 
{ 
    int lo = 0; 
    int hi = arr_size - 1; 
    int mid = 0; 
  
    // Iterate till all the elements 
    // are sorted 
    while (mid <= hi) { 
        switch (a[mid]) { 
  
        // If the element is 0 
        case 0: 
            swap(a[lo++], a[mid++]); 
            break; 
  
        // If the element is 1 . 
        case 1: 
            mid++; 
            break; 
  
        // If the element is 2 
        case 2: 
            swap(a[mid], a[hi--]); 
            break; 
        } 
    } 
} 
  
// Function to print array arr[] 
void printArray(int arr[], int arr_size) 
{ 
    for (int i = 0; i < arr_size; i++) 
        cout << arr[i] << " "; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    sort(arr, n); 
  
    cout << "array after segregation "; 
  
    printArray(arr, n); 
  
    return 0; 
} 
