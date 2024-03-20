#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld dp[65][10];
int n;
//-4%3=-1
lld fun(int cnt,int i)
{
    if(cnt==n)
    return 1;

    if(dp[cnt][i]!=0)
    return dp[cnt][i];

    lld sum=0;
    for(int j=0;j<=9;j++)
    {
        if(j>=i)
        sum+=fun(cnt+1,j);
   }
   return dp[cnt][i]=sum;
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
       int a;
       cin>>a>>n;
       lld res=0;
       for(int i=0;i<=9;i++)
       {
           memset(dp,0,sizeof(dp));
           res+=fun(1,i);
       }
       cout<<a<<" "<<res<<"\n";
    }
}
