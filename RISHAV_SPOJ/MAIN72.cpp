#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int n,arr[100+1],dp[104][100001];
set <int> s;
int fun(int i,int sum)
{
    if(i==n+1)
    {
        s.insert(sum);
        return 0;
    }
    if(dp[i][sum]!=-1)
    return dp[i][sum];

    return dp[i][sum]=arr[i]+fun(i+1,sum+arr[i])+fun(i+1,sum);

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
        cin>>n;
        for(int i=1;i<=n;i++)
        cin>>arr[i];

        memset(dp,-1,sizeof(dp));
        fun(1,0);

        int res=0;
        for(auto i:s)
        {
            //cout<<i<<' ';
            res+=i;
        }
        cout<<res<<'\n';
        s.clear();
    }
}

