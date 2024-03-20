/** Reverse an array**/
#include<iostream>
using namespace std;
void Reverse(int arr[],int n);
int main()
{
    int t, n, i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
        cin>>arr[i];
        Reverse(arr, n);
        cout<<endl;
    }
    return 0;
}
void Reverse(int arr[],int n)
{
    int i, temp;
    for(i=0;i<n/2;i++)
    {
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
    cout<<"Reverse of the array is: "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

/**
Output:
2
5
8 6 9 2 3
Reverse of the array is:
3 2 9 6 8
7
1 2 3 5 6 7 8
Reverse of the array is:
8 7 6 5 3 2 1

Process returned 0 (0x0)   execution time : 39.424 s
Press any key to continue.
**/
