#include<bits/stdc++.h>
using namespace std;
using lld=long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld n,m,k,a,b,ptr=0;
    cin>>n>>m;
    k=m;
    vector <int> lst[n+1];
    int vis[n+1]={0};
    cin>>a>>b;
    lst[a].push_back(b);
    lst[b].push_back(a);
    m--;
    int start=a;
    while(m--)
    {
        cin>>a>>b;
        lst[a].push_back(b);
        lst[b].push_back(a);
    }
    queue <int> q;
    q.push(start);
    vis[start]=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(int i=0;i<lst[a].size();i++)
        if(vis[lst[a][i]]==0)
        {
            vis[lst[a][i]]=1;
            q.push(lst[a][i]);
        }
    }
    for(int i=1;i<=n;i++)
    if(vis[i]==0)
    ptr=1;
    if(n-k==1&&ptr==0)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}

