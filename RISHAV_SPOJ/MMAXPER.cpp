#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int n;
string s;
int dp[1001][2];
int arr[1001][2];

int fun(int i,int ptr)
{
    if(i>n)           //ptr=0,if first length on x axis
    return dp[i][ptr]=0;

    if(dp[i][ptr]!=-1)
    return dp[i][ptr];

    if(ptr==0)
    return dp[i][ptr]=max(abs(arr[i-1][1]-arr[i][1])+arr[i][0] + fun(i+1,ptr),
                            abs(arr[i-1][1]-arr[i][0])+arr[i][1] + fun(i+1,ptr+1));

    if(ptr==1)
    return dp[i][ptr]=max(abs(arr[i-1][0]-arr[i][1])+arr[i][0]+fun(i+1,ptr-1),
                            abs(arr[i-1][0]-arr[i][0])+arr[i][1]+fun(i+1,ptr));
}
int main()
{
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++)
        cin>>arr[i][0]>>arr[i][1];

        int res=0;
        res=max(res,arr[1][1]+fun(2,1));

        memset(dp,-1,sizeof(dp));
        res=max(res,arr[1][0]+fun(2,0));

        cout<<res;
    }
}
