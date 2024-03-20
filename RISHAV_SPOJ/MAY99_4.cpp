#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld mod=10000007;

lld fun(int n, int k)
{
    lld C[k+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;  // nC0 is 1

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
            C[j] = (C[j] + C[j-1])%mod;
    }
    return C[k]%mod;
}


int main()
{
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,r;
    cin>>n>>r;
    if(n<r)
    cout<<"-1\n";
    else
    cout<<fun(n-r+r-1,r-1);
}
