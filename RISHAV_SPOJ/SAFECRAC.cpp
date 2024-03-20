#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld mod=1000000007,n,dp[100001][11];

lld fun(int i,int val)
{
    if(i==1)
    return dp[i][val]=1;

    if(dp[i][val]!=-1)
    return dp[i][val];

    if(val==1)
    return dp[i][val]=(fun(i-1,2)+fun(i-1,4))%mod;

    if(val==2)
    return dp[i][val]=(fun(i-1,1)+fun(i-1,3)+fun(i-1,5))%mod;

    if(val==3)
    return dp[i][val]=(fun(i-1,2)+fun(i-1,6))%mod;

    if(val==4)
    return dp[i][val]=(fun(i-1,1)+fun(i-1,5)+fun(i-1,7))%mod;

    if(val==5)
    return dp[i][val]=(fun(i-1,2)+fun(i-1,4)+fun(i-1,6)+fun(i-1,8))%mod;

    if(val==6)
    return dp[i][val]=(fun(i-1,3)+fun(i-1,5)+fun(i-1,9))%mod;

    if(val==7)
    return dp[i][val]=(fun(i-1,8)+fun(i-1,4)+fun(i-1,0))%mod;

    if(val==8)
    return dp[i][val]=(fun(i-1,5)+fun(i-1,7)+fun(i-1,9))%mod;

    if(val==9)
    return dp[i][val]=(fun(i-1,6)+fun(i-1,8))%mod;

    if(val==0)
    return dp[i][val]=fun(i-1,7)%mod;
}


int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    for(int i=0;i<10;i++)
    fun(100000,i);

    int t;
    cin>>t;
    while(t--)
    {
        lld res=0;
        cin>>n;


        for(int i=0;i<10;i++)
        {
            res+=dp[n][i];
            res%=mod;
        }
        cout<<res<<'\n';
    }

}

