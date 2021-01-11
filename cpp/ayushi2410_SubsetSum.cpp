#include <bits/stdc++.h> 
using namespace std;
bool isSubsetSum(int set[], int n, int sum) 
{ 
    if (sum == 0) 
        return true; 
    if (n == 0) 
        return false; 
    if (set[n - 1] > sum) 
        return isSubsetSum(set, n - 1, sum);  
    return isSubsetSum(set, n - 1, sum) 
           || isSubsetSum(set, n - 1, sum - set[n - 1]); 
} 
  
int main() 
{   
    int n;
    cin>>n;
    int set[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int sum;cin>>sum; 
    if (isSubsetSum(set, n, sum) == true) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 
    return 0; 
} 
