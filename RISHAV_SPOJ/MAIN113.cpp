#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld n,dp[35][4][4];

lld fun(int i,int last1,int last2)
{
    if(i==1)
    return dp[i][last1][last2]=1;

    if(dp[i][last1][last2]!=-1)
    return dp[i][last1][last2];

    if(last1+last2==3)
    return dp[i][last1][last2]=fun(i-1,1,last1)+fun(i-1,2,last1);

    else if((last1==1&&last2==3)||(last1==3&&last2==1))
    return dp[i][last1][last2]=fun(i-1,1,last1)+fun(i-1,3,last1);

    else if((last1==2&&last2==3)||(last1==3&&last2==2))
    return dp[i][last1][last2]=fun(i-1,2,last1)+fun(i-1,3,last1);

    else
    return dp[i][last1][last2]=fun(i-1,1,last1)+fun(i-1,2,last1)+fun(i-1,3,last1);

}
//-4%3=-1
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)
    fun(30,i,j);

    lld t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        lld res=0;
        for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        res+=dp[n-1][i][j];

        if(n==1)
        cout<<"3\n";
        else
        cout<<res<<'\n';
    }
}

