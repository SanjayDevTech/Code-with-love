#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

//-4%3=-1
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lld t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n],index[100001];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int cnt[1000001]={0};
        int res=0,val;
        for(int i=0;i<n;i++)
        {
            val=1+cnt[arr[i]-1];
            cnt[arr[i]]=val;
            res=max(val,res);
        }
        cout<<res;
    }
}

