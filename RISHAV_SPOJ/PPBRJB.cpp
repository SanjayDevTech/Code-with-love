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

    int dp[41];
    dp[1]=1,dp[2]=1,dp[3]=1,dp[4]=2;
    for(int i=5;i<=40;i++)
    dp[i]=dp[i-1]+dp[i-4];

    int prime[217287]={0};
    for(int i=2;i<=sqrt(217286);i++)
    {
        if(prime[i]==0)
        {
            for(int j=2*i;j<=217286;j+=i)
            prime[j]=1;
        }
    }
    int cnt[217287]={0};
    for(int i=2;i<=217286;i++)
    {
        cnt[i]=cnt[i-1];
        if(prime[i]==0)
        cnt[i]++;
    }

    lld t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<cnt[dp[n]]<<"\n";
    }
}

