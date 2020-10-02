#include<bits/stdc++.h>
using namespace std;
using lld=long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld n,m=0,k,a,b,ptr=0,i;
    cin>>n;
    k=n;
    vector <int> lst[n+1];
    int res[n+1];
    memset(res,-1,sizeof(res));
    int vis[n+1]={0};
    while(n--)
    {
        cin>>a>>b;
        lst[a].push_back(b);
        lst[b].push_back(a);
    }
    queue <int> q;
    q.push(1);
    vis[1]=1;
    res[1]=0;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(int i=0;i<lst[a].size();i++)
        if(vis[lst[a][i]]==0)
        {
            vis[lst[a][i]]=1;
            res[lst[a][i]]=res[a]+1;
            q.push(lst[a][i]);
        }
    }
    for(i=1;i<=k;i++)
    {
        if(res[i]>m)
        {
            m=res[i];
            ptr=i;
        }
    }
    memset(res,-1,sizeof(res));
    memset(vis,0,sizeof(vis));
    q.push(ptr);
    res[ptr]=0;
    vis[ptr]=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(int i=0;i<lst[a].size();i++)
        if(vis[lst[a][i]]==0)
        {
            vis[lst[a][i]]=1;
            res[lst[a][i]]=res[a]+1;
            q.push(lst[a][i]);
        }
    }
    ptr= *max_element(res,res+k+1);
    cout<<ptr;
}

