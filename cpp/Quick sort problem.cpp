//Question

/*QUICK SORT PROBLEM:
Rahul is given an array of integers of size N. He is challenged to sort the array using the QuickSort algorithm. 
Please help him implement quicksort.

INPUT FORMAT:
The first line contains a number N.
The second line contains space-separated N integers.

OUTPUT FORMAT:
print the sorted array.

EXAMPLE:
Input:-
5
8 4 2 1 9

Output:-
1 2 4 8 9*/


//solution
#include <bits/stdc++.h>
using namespace std;
//function for partion of array
int partition(int a[],int lb,int ub){
  int start = lb;
  int end = ub;
  int pivot = a[lb];
  
  while(start<end){
    
    while(a[start]<=pivot)
      start++;
      
    while(a[end]>pivot)
      end--;
      
    if(start<end)
      swap(a[start],a[end]);
  }
  
  swap(a[lb], a[end]);
  return end;
}

//function for sorting using quick sort
void quick_sort(int a[],int lb,int ub){
  if(lb<ub){
    int loc = partition(a,lb,ub);
    quick_sort(a,lb,loc-1);
    quick_sort(a,loc+1,ub);
  }
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
      
    quick_sort(a,0,n-1);
    
    for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
  
  return 0;
}
	
