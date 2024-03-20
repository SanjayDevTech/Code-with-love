#include<bits/stdc++.h>
using namespace std;
using lld=long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    queue <int> q;
    q.push(s);
    int vis[f+1]={0};
    int res[f+1]={-1};
    memset(res,-1,sizeof(res));
    res[s]=0;
    vis[s]=1;
    while(!q.empty())
    {
        int a=q.front();
        if(a==g)
        break;
        q.pop();
        if(a+u<=f&&vis[a+u]==0)
        {
            vis[a+u]=1;
            res[a+u]=res[a]+1;
            q.push(a+u);
        }
        if(a-d>0&&vis[a-d]==0)
        {
            vis[a-d]=1;
            res[a-d]=res[a]+1;
            q.push(a-d);
        }
    }
    if(res[g]==-1)
    cout<<"use the stairs";
    else
    cout<<res[g];
}

