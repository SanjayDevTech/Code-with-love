#include<bits/stdc++.h>
using namespace std;
using lld=long long int;
lld dp[10001];

lld fun(lld arr[],lld n)
{
    if(n==0)
    return 0;
    if(n==1)
    dp[1]=arr[1];
    if(dp[n]!=-1)
    return dp[n];
    dp[n]=max(arr[n]+fun(arr,n-2),fun(arr,n-1));
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    for(lld j=1;j<=t;j++)
    {
        //memset(dp,-1,sizeof(dp));
        lld n;
        cin>>n;
        for(lld i=0;i<=n;i++)
        dp[i]=-1;
        lld arr[n+1];
        for(lld i=1;i<=n;i++)
        cin>>arr[i];
        lld res=fun(arr,n);
        //for(lld i=0;i<=n;i++)
        //cout<<dp[i]<<" ";
        cout<<"Case "<<j<<": "<<res<<"\n";
    }
}
