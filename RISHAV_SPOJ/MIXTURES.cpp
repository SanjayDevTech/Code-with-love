#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int dp[101][101],n,arr[101];
int sum(int i,int j)
{
    int sum=0;
    for(int k=i;k<=j;k++)
    {
        sum+=arr[k];
        sum%=100;
    }
    return sum;
}
int fun(int start,int end)
{
    if(start>=end)
    return 0;

    if(dp[start][end]!=-1)
    return dp[start][end];

    int val=INT_MAX;
    for(int i=start;i<end;i++)
    val=min(val,fun(start,i)+fun(i+1,end)+sum(start,i)*sum(i+1,end));
    return dp[start][end]=val;
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    while(cin>>n)
    {
        //cin>>n;
        for(int i=1;i<=n;i++)
        cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        cout<<fun(1,n)<<'\n';
    }
}

