#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int n,dp[2001][2001];
string s1,s2;
int l1,l2;

int fun(int a,int b)
{
    if(a==l1)
    return dp[a][b]=l2-b;

    if(b==l2)
    return dp[a][b]=l1-a;

    if(dp[a][b]!=-1)
    return dp[a][b];

    if(s1[a]==s2[b])
    return dp[a][b]=fun(a+1,b+1);

    return dp[a][b]=1+min(fun(a+1,b),min(fun(a,b+1),fun(a+1,b+1)));
}

int main()
{
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        l1=s1.size();
        l2=s2.size();
        memset(dp,-1,sizeof(dp));
        cout<<fun(0,0)<<"\n";

        /*for(int i=0;i<=l1;i++)
        {
            for(int j=0;j<=l2;j++)
            cout<<dp[i][j]<<" ";
            cout<<"\n";
        }*/

    }
}
