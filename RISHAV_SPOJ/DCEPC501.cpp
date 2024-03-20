#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld n,arr[100001];
lld dp[100001];
//-4%3=-1

lld max(lld a,lld b)
{
    if(a>b)
    return a;
    return b;
}

lld fun(int i)
{
    if(i>n)
    return 0LL;
    if(dp[i]!=-1)
    return dp[i];
    else
    {
        lld a1=0,a2=0,a3=0;
        if(i<=n)
        a1=arr[i]+fun(i+2*1);
        if(i+1<=n)
        a2=arr[i]+arr[i+1]+fun(i+2*2);
        if(i+2<=n)
        a3=arr[i]+arr[i+1]+arr[i+2]+fun(i+2*3);
        return dp[i]=max(a1,max(a2,a3));
    }
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++)
        cin>>arr[i];
        cout<<fun(1)<<"\n";
    }
}


