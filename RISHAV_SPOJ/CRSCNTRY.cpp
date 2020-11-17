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
    lld t;
    cin>>t;
    while(t--)
    {
        vector <int> res;
        int n=1;
        while(n!=0)
        {
            cin>>n;
            res.push_back(n);
        }
        int ans=0;
        n=1;
        while(1)
        {
            vector <int> temp;
            int a=1;
            while(a!=0)
            {
                cin>>a;
                temp.push_back(a);
            }

            if(temp[0]==0)
            break;

            int m=res.size(),n=temp.size();
            int dp[m+1][n+1];

            memset(dp,-1,sizeof(dp));

            /*for(int i=0;i<temp.size();i++)
            cout<<temp[i]<<" ";
            cout<<"\n";*/

            for(int i=0;i<=m;i++)
            {
                for(int j=0;j<=n;j++)
                {
                    if(i==0||j==0)
                    dp[i][j]==0;

                    else if(res[i-1]==temp[j-1])
                    dp[i][j]=1+dp[i-1][j-1];

                    else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }

            /*for(int i=0;i<=m;i++)
            {
                for(int j=0;j<=n;j++)
                cout<<dp[i][j]<<" ";
                cout<<"\n";
            }*/
            ans=max(ans,dp[m][n]);
        }
        cout<<ans<<"\n";
    }
}

