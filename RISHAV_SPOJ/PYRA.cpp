#include<bits/stdc++.h>
using namespace std;
using lld=long long int;

lld vis[10001];
lld res[10001];
vector <int> lst[10001];

void dfs(int a)
{
    for(int i=0;i<lst[a].size();i++)
    {
        if(vis[lst[a][i]]==0)
        {
            vis[lst[a][i]]=1;
            dfs(lst[a][i]);
            res[a]+=1+res[lst[a][i]];
        }
    }
    res[a]+=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        lld n,k,a,b,sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
			lst[i].clear();
			vis[i] = 0;
			res[i] = 0;
		}
		k=n;
		k--;
        while(k--)
        {
            cin>>a>>b;
            lst[a].push_back(b);
            lst[b].push_back(a);
        }
        vis[0]=1;
        dfs(0);
        for(int i=0;i<n;i++)
        {
            sum+=res[i];
            //cout<<res[i]<<" ";
        }
        cout<<sum<<"\n";
    }
}
