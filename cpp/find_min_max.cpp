#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    // n is the length of array

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

     // sort the array
     sort(a,a+n);

     // first term is the min term
     // last term is the max term

     cout<<"The min term is "<<a[0]<<endl;
     cout<<"The max term is "<<a[n-1]<<endl;

}
