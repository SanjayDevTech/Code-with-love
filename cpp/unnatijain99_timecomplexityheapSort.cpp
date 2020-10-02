#include<iostream>
#include<stdlib.h>
#include<process.h>
#include<time.h>
using namespace std;
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 

    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 

    // If largest is not root 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 

        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 

    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 

        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

int main() {
	int a[10000], size=10000, ch, i;
	cout<<"Quick Sort\nEnter your Choice:\n1. Best Case\n2. Worst Case\n3. Average Case\n4. Exit\t";
	cin>>ch;
	switch(ch) {
		case 1: for(i=0; i<10000; i++) {
					a[i] = i+1;
				}
				break;
		case 2: for(i=10000; i>0; i--) {
					a[10000-i] = i;
				}
				break;
		case 3: srand(time(NULL));
				for(i=0; i<10000; i++) {
					a[i] = rand() % 10000 + 1;
				}
				break;
		case 4: exit(0);
				break;
		default: cout<<"Wrong Choice!";
				 break;
	}
	clock_t start, end;
	start = clock();
	heapSort(a, size);
	end = clock();
	cout<<"Time Taken: "<<(double)(end-start)/CLK_TCK;
}
