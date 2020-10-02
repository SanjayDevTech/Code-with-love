#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld n,arr[1001];
lld dp[1001][1001];
string s;
//-4%3=-1
lld max(lld a,lld b)
{
    if(a>b)
    return a;
    return b;
}

lld fun(int start,int end)
{
    if(start>end)
    return 0LL;

    if(dp[start][end]!=-1)
    return dp[start][end];

    lld a1=arr[start];
    if(arr[start+1]>=arr[end])
    a1+=fun(start+2,end);
    else
    a1+=fun(start+1,end-1);
    lld a2=arr[end];
    if(arr[start]>=arr[end-1])
    a2+=fun(start+1,end-1);
    else
    a2+=fun(start,end-2);
    return dp[start][end]=max(a1,a2);
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    for(int j=1;j>=0;j++)
    {
        cin>>n;
        if(n==0)
        break;
        lld sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        memset(dp,-1,sizeof(dp));
        lld res=fun(1,n);
        cout<<"In game "<<j<<", the greedy strategy might lose by as many as "<<res-sum+res<<" points.\n";
    }
}

