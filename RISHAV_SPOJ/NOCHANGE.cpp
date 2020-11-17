#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

//-4%3=-1
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int v[k+1],sum[k+1]={0};
        for(int i=1;i<=k;i++)
        {
            cin>>v[i];
            sum[i]=sum[i-1]+v[i];
        }
        int dp[n+1]={0};
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]!=1)
            {
                for(int j=1;j<=k;j++)
                {
                    if(i-sum[j]>=0&&dp[i-sum[j]])
                    {
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        if(dp[n])
        cout<<"YES";
        else
        cout<<"NO";
    }
}

