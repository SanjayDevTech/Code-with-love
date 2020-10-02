#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld max(lld a,lld b)
{
    if(a>b)
    return a;
    return b;
}
lld dp[10000000];

lld fun(int n)
{
    if(n<10000000)
    return dp[n];

    return max(n,fun(n/2)+fun(n/3)+fun(n/4));
}
int main()
{
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lld t,n;
    //cin>>t;
    //t=1;
    for(int i=1;i<10000000;i++)
    dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);

    while(cin>>n)
    {
        cout<<fun(n)<<"\n";
    }
}
