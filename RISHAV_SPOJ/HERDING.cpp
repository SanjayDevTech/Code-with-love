#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int c[]={1,0,-1,0};
int r[]={0,1,0,-1};
//       R D L U
int n,m,vis[1001][1001];
char arr[1001][1001];
map <char,int> mp;

bool valid(int x,int y)
{
    if(x<n&&y<m&&x>=0&&y>=0)
    return true;
    return false;
}

void bfs(pair <int,int> p,int cnt)
{
    vis[p.first][p.second]=cnt;
    //cout<<vis[0][0]<<" a";
    queue <pair <int,int> > q;
    q.push({p.first,p.second});

    pair <int,int> now;

    while(!q.empty())
    {
        now=q.front();
        int x=now.first,y=now.second;
        q.pop();
        int val=mp[arr[x][y]];
        int new_x=x+r[val],new_y=y+c[val];
        //cout<<new_x<<" "<<new_y<<'\n';
        //cout<<vis[new_x][new_y]<<" "<<valid(new_x,new_y);
        if(valid(new_x,new_y)&&!vis[new_x][new_y])
        {
            q.push({new_x,new_y});
            vis[new_x][new_y]=cnt;
            //cout<<vis[new_x][new_y]<<" ";
        }
        for(int i=0;i<4;i++)
        {
            new_x=x+r[i],new_y=y+c[i];
            if(valid(new_x,new_y)&&!vis[new_x][new_y])
            {
                if(i==0&&arr[new_x][new_y]=='W')
                {
                    vis[new_x][new_y]=cnt;
                    q.push({new_x,new_y});
                }
                if(i==1&&arr[new_x][new_y]=='N')
                {
                    vis[new_x][new_y]=cnt;
                    q.push({new_x,new_y});
                }
                if(i==2&&arr[new_x][new_y]=='E')
                {
                    vis[new_x][new_y]=cnt;
                    q.push({new_x,new_y});
                }
                if(i==3&&arr[new_x][new_y]=='S')
                {
                    vis[new_x][new_y]=cnt;
                    q.push({new_x,new_y});
                }
            }
        }
    }
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mp['E']=0, mp['S']=1, mp['W']=2, mp['N']=3;
    string s;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        arr[i][j]=s[j];
    }
    memset(vis,0,sizeof(vis));
    int cnt=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(vis[i][j]==0)
        {
            cnt++;
            bfs({i,j},cnt);

        }
    }
    //bfs({2,0},1);
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout<<vis[i][j]<<" ";
        cout<<'\n';
    }*/
    cout<<cnt<<'\n';
}
