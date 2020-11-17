#include<bits/stdc++.h>
using namespace std;

int dp[1024][30][80];
int n_ox,n_ni,N;
int ox[1024],ni[1024],wt[1024];

int fun(int i,int o,int n)
{
    if(o==0&&n==0)
    return dp[i][o][n]=0;

    if(dp[i][o][n]!=-1)
    return dp[i][o][n];

    if(i==0)
    return 999999999;

    return dp[i][o][n]=min( fun(i-1,o,n), wt[i-1] + fun(i-1, max(0,o-ox[i-1]) , max(0,n-ni[i-1]) ) );
}


//Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n_ox>>n_ni>>N;
        for(int i=0;i<N;i++)
        cin>>ox[i]>>ni[i]>>wt[i];

        memset(dp,-1,sizeof(dp));

        cout<<fun(N,n_ox,n_ni)<<"\n";
    }
}
