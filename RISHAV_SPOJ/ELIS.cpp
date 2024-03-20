#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int n,dp[30],arr[30];


int main()
{
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    t=1;
    while(t--)
    {

        //memset(dp,0,sizeof(dp));
        //memset(vis,-1,sizeof(vis));
        cin>>n;
        for(int i=0;i<n;i++)
        cin>>arr[i];

        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i])
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        res=max(res,dp[i]);

        cout<<res<<"\n";
    }
}
