#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld n;
lld dp[5001];
string s;
//-4%3=-1


lld fun(int i)
{
    int c=(s[i-1]-'0')*10+(s[i]-'0');
    if(s[i]!='0')
    dp[i]=1;
    if(c<=26&&c>9)
    dp[i]+=1;

    for(int i=2;i<n;i++)
    {
        c=(s[i-1]-'0')*10+(s[i]-'0');
        if(s[i]!='0')
        dp[i]+=dp[i-1];
        if(c<=26&&c>9)
        dp[i]+=dp[i-2];
    }
    return dp[n-1];
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    string s1="0";
    while(1)
    {
        cin>>s;
        if(s==s1)
        break;
        memset(dp,0,sizeof(dp));
        n=s.size();
        dp[0]=1;
        int res;
        if(s.size()>1)
        res=fun(1);
        cout<<dp[n-1]<<"\n";
        //for(int i=0;i<n;i++)
        //cout<<dp[i]<<" ";
    }
}

