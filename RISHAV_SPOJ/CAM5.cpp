#include <bits/stdc++.h>
using namespace std;

#define lld long long int

vector<int> g[100005];
int vis[100005];

void dfs(int a)
{
    stack <int> s;
    s.push(a);
    vis[a]=1;
    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        for(int i=0;i<g[val].size();i++)
        {
            if(vis[g[val][i]]==0)
            {
                s.push(g[val][i]);
                vis[g[val][i]]=1;
            }
        }
    }
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<100005;i++){g[i].clear();}
        memset(vis,0,sizeof(vis));
        int n,k,a,b;
        cin>>n;
        cin>>k;
        while(k--)
        {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                res++;
                dfs(i);
            }
        }
        cout<<res<<"\n";
    }
}

