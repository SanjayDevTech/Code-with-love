#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int r,c,vis[101][101][2];
char arr[101][101];
int R[]={0, 0, -1, 1};
int C[]={-1, 1, 0, 0};

bool valid(int a,int b)
{
    if(a>=0&&a<r&&b>=0&&b<c&&arr[a][b]!='W')
    return true;
    return false;
}
int bfs(pair <int,int> p,int pos)
{
    queue < pair <int,int> > q1;
    queue <int> q2;
    int now;
    q1.push({p.first,p.second});
    q2.push(pos);
    vis[p.first][p.second][pos]=0;

    while(!q1.empty())
    {
        int x=q1.front().first;
        int y=q1.front().second;
        int format=q2.front();

        if(x==r-1 || x==0 || y==0 || y==c-1) return vis[x][y][format];

        q1.pop();
        q2.pop();
        for(int i=0;i<4;i++)
        {
            int new_x=x+R[i];
            int new_y=y+C[i];
            if(valid(new_x,new_y))
            {
                if(format==1&&arr[new_x][new_y]=='D')
                continue;
                if(arr[new_x][new_y]=='C')
                now=1;
                else if(arr[new_x][new_y]=='O')
                now=0;
                else
                now=format;
                if(vis[new_x][new_y][now]==101)
                {
                    vis[new_x][new_y][now]=1+vis[x][y][format];
                    q1.push({new_x,new_y});
                    q2.push(now);
                }

            }
        }
    }
    return -2;
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    while(1)
    {
        cin>>r>>c;

        if(r<0)
        break;
        int x,y;
        string s;
        for(int i=0;i<r;i++)
        {
            cin>>s;
            for(int j=0;j<c;j++)
            {
                arr[i][j]=s[j];
                if(s[j]=='H')
                x=i,y=j;
            }
        }
        //memset(vis, 0x7f, sizeof(vis));
        for(int i=0;i<=r;i++)
        for(int j=0;j<=c;j++)
        vis[i][j][0]=vis[i][j][1]=101;

        int res=bfs({x,y},1);
        cout<<res+1<<'\n';

    }
}

