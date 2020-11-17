#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int main()
{
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld arr[52],power[52];
    arr[1]=1, power[1]=1;
    lld sum=1;
    for(int i=2;i<=51;i++)
    {
        power[i]=power[i-1]*2;
        arr[i]=power[i]+sum;
        sum+=arr[i];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<power[n]<<" "<<arr[n]<<"\n";
    }
}
