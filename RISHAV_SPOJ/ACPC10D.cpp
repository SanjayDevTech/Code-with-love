#include<bits/stdc++.h>
using namespace std;
using lld=long long int;
int a[100001],b[100001],c[100001];
int dp[100001][4];

int fun(int n)
{
    dp[1][2]=b[1];
    dp[1][3]=b[1]+c[1];

    dp[2][1]=dp[1][2]+a[2];
    dp[2][2]=min(min(dp[1][2]+b[2],dp[2][1]+b[2]),dp[1][3]+b[2]);
    dp[2][3]=min(min(dp[1][2]+c[2],dp[2][2]+c[2]),dp[1][3]+c[2]);

    for(int i=3;i<=n;i++)
    {
        dp[i][1]=min(dp[i-1][1]+a[i],dp[i-1][2]+a[i]);
        dp[i][2]=min(min(dp[i-1][1]+b[i],dp[i-1][2]+b[i]),min(dp[i-1][3]+b[i],dp[i][1]+b[i]));
        dp[i][3]=min(min(dp[i-1][3]+c[i],dp[i-1][2]+c[i]),dp[i][2]+c[i]);
    }
    return dp[n][2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int t=0;
    while(n!=0)
    {
        t++;
        for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
        int res=fun(n);
        cout<<t<<". "<<res<<"\n";
        cin>>n;
    }
}
