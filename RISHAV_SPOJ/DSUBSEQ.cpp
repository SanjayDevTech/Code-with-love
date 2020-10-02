#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        int n=s.size(),mod=1000000007 ;
        int dp[n+1],arr[26];
        dp[0]=1;   //empty string

        memset(arr,-1,sizeof(arr));
        for(int i=1;i<=n;i++)
        {
            dp[i]=(dp[i-1]*2)%mod;

            if(arr[s[i-1]-'A']!=-1)
            dp[i]=(dp[i]-dp[arr[s[i-1]-'A']]+mod)%mod;
            arr[s[i-1]-'A']=i-1;

            //dp[i]=(dp[i]+mod)%mod;
        }
        /*for(int i=0;i<=n;i++)
        cout<<dp[i]<<" ";
        cout<<'\n';*/
        cout<<dp[n]<<'\n';
    }
}

