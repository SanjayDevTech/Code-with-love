#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

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
        int k,l,m,n;
        cin>>k>>l>>m;

        int dp[1000001]={0};
        dp[1]=1;
        for(int i=2;i<=1000000;i++)
        {
            if(!dp[i-1])
            dp[i]=1;

            if(i-k>=0&&!dp[i-k])
            dp[i]=1;

            if(i-l>=0&&!dp[i-l])
            dp[i]=1;
        }

        while(m--)
        {
            cin>>n;
            if(dp[n]==1)
            cout<<"A";
            else
            cout<<"B";

        }
    }
}
