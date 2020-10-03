/*IN INVERSE PERMUTTION IS A PERMUTATION WHICH YOU WILL GET BY INSERTING POSITION OF AN ELEMENT AT THE POSITION SPECIFIED BY THE ELEMENT VALUE IN THE ARRAY.


#include<iostream>
using namespace std;
int main()
{
  int n;cin>>n;
  int arr[n], narr[n]={0};
  for(int i=0;i<n;i++)
    {cin>>arr[i];}
  for(int i=0;i<n;i++)
    { narr[arr[i]]=i;  }
    
  for(int i=0;i<=n;i++)
     {cout<<narr[i]<<" ";}
     cout<<endl;
return 0;
}
