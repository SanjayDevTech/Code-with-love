#include <bits/stdc++.h>
 
int bSearch(int arr[], int l, int r, int x) 
{ 
  while (l <= r) 
  { 
    int m = l + (r-l)/2; 
    if (arr[m] == x)  
        return m;    
    if (arr[m] < x)  
        l = m + 1;  
    else 
         r = m - 1;  
  } 
  return -1;  
} 
  
int main() 
{ 
   int n;
   cin>>n;
   int arr[n];
   int x;
   cin>>x;
  for(int i=0;i<n;i++)
   cin>>arr[i];
  int ans=bSearch(arr,0,n-1,x);
  if(ans==-1)
  cout<<"Element not found\n";
  else
  cout<<"Element found at index "<<ans<<"\n";
  
   return 0; 
} 