#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld n,k,a,b;
lld dp[51][51];

lld fun(int start,int cnt)
{
    if(cnt==k+1&&start==b)
    return 1;

    if(cnt==k+1&&start!=b)
    return 0;

    if(dp[start][cnt]!=-1)
    return dp[start][cnt];

    else
    {
        //if(start+1==n+1 ? 1 : start+1 != start-1 ? start-1 : n)
        return dp[start][cnt]=fun(start+1==n+1 ? 1 : start+1,cnt+1)+fun(start-1 ? start-1 : n ,cnt+1);
        //else
        //return dp[start][cnt]=fun(start+1==n ? 1 : start+1,cnt+1);
    }
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    while(1)
    {
        cin>>n>>k;

        if(n==-1&&k==-1)
        break;

        cin>>a>>b;
        memset(dp,-1,sizeof(dp));
        cout<<fun(a,1)<<'\n';
    }
}

