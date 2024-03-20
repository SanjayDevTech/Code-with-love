#include<bits/stdc++.h>
using namespace std;
using lld=long long int;
lld arr[2001],dp[2001][2001];

lld fun(lld start,lld end,lld age)
{
    if(start>end)
    return 0;

    if(dp[start][end]!=-1)
    return dp[start][end];

    dp[start][end]=max(arr[start]*age+fun(start+1,end,age+1),arr[end]*age+fun(start,end-1,age+1));
    return dp[start][end];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    lld sum=fun(1,n,1);
    /*for(int i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
    cout<<dp[i][j]<<" ";cout<<"\n";}*/
    cout<<sum;
}
