#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int n;
string s;
int dp[6101][6101];

int fun(int start,int end)
{
    if(start>=end)
    return dp[start][end]=0;

    if(dp[start][end]!=-1)
    return dp[start][end];

    if(s[start]==s[end])
    return dp[start][end]=fun(start+1,end-1);

    return dp[start][end]=1+min(fun(start+1,end),fun(start,end-1));
}
int main()
{
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>s;
        cout<<fun(0,s.size()-1)<<"\n";
    }
}
