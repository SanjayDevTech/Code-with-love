#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld m,wt[1001],val[1001];
lld dp[1001][1001];
string s;
//-4%3=-1
lld max(lld a,lld b)
{
    if(a>b)
    return a;
    return b;
}

lld fun(int i,int w)
{
    if(i<0||w<=0)
    return 0LL;
    if(dp[i][w]!=-1)
    return dp[i][w];
    if(wt[i]>w)
    return dp[i][w]=fun(i-1,w);
    return dp[i][w]=max(val[i]+fun(i-1,w-wt[i]),fun(i-1,w));
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        lld w;
        cin>>w>>m;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        cin>>wt[i]>>val[i];
        cout<<"Hey stupid robber, you can get ";
        cout<<fun(m-1,w)<<".\n";
    }
}

