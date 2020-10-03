/* Program to cyclically rotate an array by one */

#include <stdio.h> 

void rotate(int arr[], int n) 
{ 
int x = arr[n-1], i; 
for (i = n-1; i > 0; i--) 
	arr[i] = arr[i-1]; 
arr[0] = x; 
} 

int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5}, i; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	printf("Given array is\n"); 
	for (i = 0; i < n; i++) 
		printf("%d ", arr[i]); 

	rotate(arr, n); 

	printf("\nRotated array is\n"); 
	for (i = 0; i < n; i++) 
		printf("%d ", arr[i]); 

	return 0; 
}
