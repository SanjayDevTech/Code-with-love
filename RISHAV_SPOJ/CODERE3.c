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
    lld t;
    cin>>t;
    while(t--)
    {
        int n,res=0;
        cin>>n;
        int arr[n],lis[n],lds[n];

        for(int i=0;i<n;i++)
        cin>>arr[i];

        for(int i=0;i<n;i++)
        {
            lis[i]=1;
            for(int j=0;j<i;j++)
            if(arr[i]>arr[j])
            lis[i]=max(lis[i],lis[j]+1);
        }

        for(int i=n-1;i>=0;i--)
        {
            lds[i]=1;
            for(int j=n-1;j>i;j--)
            if(arr[i]>arr[j])
            lds[i]=max(lds[i],lds[j]+1);
        }

        //for(int i=0;i<n;i++)
        //cout<<lis[i]<<" "<<lds[i]<<'\n';

        for(int i=0;i<n;i++)
        res=max(res,lis[i]+lds[i]-1);

        cout<<res<<'\n';
    }
}

