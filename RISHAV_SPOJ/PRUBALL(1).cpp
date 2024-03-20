#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int dp[51][1001];
int fun(int n,int h)
{
    if(n==1)
    return h;

    if(h==0||h==1)
    return h;

    if(dp[n][h]!=-1)
    return dp[n][h];

    int val=INT_MAX;
    for(int i=1;i<=h;i++)
    val=min(val,1+max(fun(n-1,h-i),fun(n,i-1)));
    return dp[n][h]=val;
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        int a,n,k;
        cin>>a>>n>>k;
        memset(dp,-1,sizeof(dp));
        cout<<a<<" "<<fun(n, k)<<'\n';
    }
}

