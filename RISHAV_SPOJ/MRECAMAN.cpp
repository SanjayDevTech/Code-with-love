#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main()
{
	// your code goes here
    int arr[500001];
    arr[0]=0;
    bool check[100000000];
    check[0]=true;
    for(int i=1;i<500001;i++)
    {
        int temp=arr[i-1]-i;
        if(temp<0||check[temp])
        temp=arr[i-1]+i;
        arr[i]=temp;
        check[temp]=true;
    }
    int n;
    while(1)
    {
        cin>>n;
        if(n==-1)
        break;
        cout<<arr[n]<<"\n";
    }
}


