#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    while(1)
    {
        int n,k,m,a,b;
        cin>>n>>k>>m;

        if(n==-1)
        break;

        int vis[n+1];
        memset(vis,-1,sizeof(vis));
        unordered_map <int,int> key;

        while(k--)
        {
            cin>>a>>b;
            key[a]=b;
            vis[b]=-2;
        }
        vector <int> v[n+1];
        while(m--)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector <int> door;
        queue <int> q;
        if(vis[1]==-1)
        {
            q.push(1);
            vis[1]=1;
        }

        while(!q.empty())
        {
            int val=q.front();
            q.pop();

            if(val==n)
            break;

            for(int i=0;i<v[val].size();i++)
            {
                if(vis[ v[val][i] ]==-1)
                {
                    q.push(v[val][i]);
                    vis[v[val][i]]=1;
                    vis[ key[v[val][i]] ]=-1;
                    key[ v[val][i] ]=-1;
                }
                if( vis[ v[val][i] ]==-2)
                door.push_back(v[val][i]);
            }
            for(int i=0;i<door.size();i++)
            {
                if(vis[door[i]]==-1)
                {
                    q.push(door[i]);
                    vis[door[i]]=1;
                    door.erase(door.begin()+i);
                }
            }
        }
        /*for(int i=1;i<=n;i++)
        cout<<vis[i]<<" ";
        cout<<"\n";*/

        if(vis[n]==1)
        cout<<"Y\n";
        else
        cout<<"N\n";
    }
}

