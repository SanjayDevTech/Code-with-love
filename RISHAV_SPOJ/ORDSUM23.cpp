#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int


int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[1000001], mod = 1000000007;
    memset(arr,0,sizeof(arr));

    arr[2]=1,arr[3]=1;
    for(int i=4;i<1000001;i++)
    {
        arr[i]=arr[i-2]+arr[i-3];
        arr[i]%=mod;
    }

    //for(int i=4;i<=20;i++)
    //cout<<i<<" "<<arr[i]<<'\n';

    lld t;
    cin>>t;
    //t=1;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<arr[n]<<'\n';
    }
}

