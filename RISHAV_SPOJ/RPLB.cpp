#include<bits/stdc++.h>
using namespace std;

int dp[1004][1004],arr[1004],n,K;

int fun(int i,int k)
{
    if(i>=n)
    return dp[i][k]=0;

    if(dp[i][k]!=-1)
    return dp[i][k];

    if(arr[i]>k)
    return dp[i][k]=fun(i+1,k);

    return dp[i][k]=max(arr[i]+fun(i+2,k-arr[i]),fun(i+1,k));
}


//Driver program
int main()
{
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        cin>>n>>K;

        for(int i=0;i<n;i++)
        cin>>arr[i];

        memset(dp,-1,sizeof(dp));

        cout<<"Scenario #"<<j<<": "<<fun(0,K)<<"\n";
    }
}
