#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld dp[201][201][2],vis[201][201];
int r,c;
string arr[201];
//-4%3=-1
lld fun(int x,int y,int i)
{
    if(x>r || y>c || y<0 || x<0 || arr[x][y]=='#')
    return 0;

    if(dp[x][y][i]!=-1)
    return dp[x][y][i];

    if(i==1)
    {
        int a=0,b=0;
        if(y+1<c)
        {
            if(arr[x][y+1]=='T')
            a=1+fun(x,y+1,i);
            if(arr[x][y+1]=='0')
            a=fun(x,y+1,i);
        }
        if(x+1<r)
        {
            if(arr[x+1][y]=='T')
            b=1+fun(x+1,y,i-1);
            if(arr[x+1][y]=='0')
            b=fun(x+1,y,i-1);
        }
        return dp[x][y][i]=max(a,b);
    }
    else
    {
        int a=0,b=0;
        if(y-1>=0)
        {
            if(arr[x][y-1]=='T')
            a=1+fun(x,y-1,i);
            if(arr[x][y-1]=='0')
            a=fun(x,y-1,i);
        }
        if(x+1<r)
        {
            if(arr[x+1][y]=='T')
            b=1+fun(x+1,y,i+1);
            if(arr[x+1][y]=='0')
            b=fun(x+1,y,i+1);
        }
        return dp[x][y][i]=max(a,b);
    }
}

int main()
{
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {

        memset(dp,-1,sizeof(dp));
        //memset(vis,-1,sizeof(vis));
        cin>>r>>c;
        for(int i=0;i<r;i++)
        cin>>arr[i];

        int res=0;
        if(arr[0][0]=='T')
        res++;
        res+=fun(0,0,1);

        /*for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            cout<<dp[i][j][1]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            cout<<dp[i][j][0]<<" ";
            cout<<"\n";
        }*/
        cout<<res<<"\n";

    }
}
