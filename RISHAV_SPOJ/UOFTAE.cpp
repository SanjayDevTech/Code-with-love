#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int n,m,arr[201],mod=1e9+7;
lld dp[201][201];

lld fun(int i,int left)
{
    if(i>n-1||left<0)
    return 0;

   if(i==n-1)
   return left<=arr[i];

    if(dp[i][left]!=-1)
    return dp[i][left];

    lld res=0;
    for(int j=0;j<=min(arr[i],left);j++)
    {
        res+= fun(i+1,left-j);
        res%=mod;
    }

    return dp[i][left]=res;
}
//-4%3=-1
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a,b;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            m-=a;
            b-=a;
            arr[i]=b;
        }
        memset(dp,-1,sizeof(dp));
        cout<<fun(0,m)<<"\n";
        /*for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<" ";
            cout<<'\n';
        }*/
    }
}
