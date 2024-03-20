#include<bits/stdc++.h>
using namespace std;
using lld=long long int;
lld dp[1001];

void fun()
{
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;

    for(int i=4;i<=1000;i++)
    {
        dp[i]=i;
        for(int j=1;j<=sqrt(i);j++)
        {
            int temp=j*j;
            if(temp<=i)
            dp[i]=min(dp[i],1+dp[i-temp]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int t,a;
    cin>>t;
    fun();
    while(t--)
    {
        cin>>a;
        cout<<dp[a]<<"\n";
    }
}
