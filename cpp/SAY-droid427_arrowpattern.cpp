/*This program will print the arrow pattern in C++
Write to program to print the right arrow pattern and the left arrow pattern formed of stars. Input is an odd number n which represents height and width of pattern to be printed.
Example:n=9
Output:
    *
     *               
      *  
       *
*********
       *
      *
     *
    *

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        cout<<" ";
        for(int k=0;k<i;k++)
        cout<<" ";
        cout<<"*\n";
    }
    for(int i=0;i<n;i++)
    cout<<"*";
    cout<<"\n";
    for(int i=1;i<n/2+1;i++)
    {
        for(int j=0;j<n/2;j++)
        cout<<" ";
        for(int k=n/2;k>i;k--)
        cout<<" ";
        cout<<"*\n";
    }

}