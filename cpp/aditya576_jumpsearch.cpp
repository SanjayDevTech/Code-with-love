/*Jump search is a searching algorithm on sorted arrays.
The idea is to check fewer elements than linear search by 
jumping ahead by fixed steps,instead of searching all elements
*/

#include <bits/stdc++.h> 
using namespace std;   
int jumpSearch(int arr[], int x, int n) 
{ 
    int step = sqrt(n); 
    int prev = 0; 
    while (arr[min(step, n)-1] < x) 
    { 
        prev = step; 
        step += sqrt(n); 
        if (prev >= n) 
            return -1; 
    }
    while (arr[prev] < x) 
    { 
        prev++; 
        if (prev == min(step, n)) 
            return -1; 
    } 
    if (arr[prev] == x) 
        return prev; 
      return -1; 
} 
int main() 
{ 
    int i,n,x;
    cout<<"No. of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter elements:";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter element to search:";
    cin>>x;
    int index = jumpSearch(a,x,n); 
    if(index==-1){
        cout<<x<<" is not found\n";
    }
    else
        cout << "\nNumber " << x << " is at index " << index; 
} 
  