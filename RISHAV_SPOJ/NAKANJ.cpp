#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int x[10]={-1,-1,-2,-2,2,2,1,1};
int y[10]={-2,2,-1,1,-1,1,-2,2};

int bfs(int a,int b,int c,int d)
{
    pair <int,int> p;
    int moves[8+1][8+1],vis[8+1][8+1];
    memset(moves,0,sizeof moves);
    memset(vis,0,sizeof vis);
    queue <pair<int,int>> q;
    p.first=a;
    p.second=b;
    q.push(p);
    vis[a][b]=1;
    while(!q.empty())
    {
        p=q.front();
        int m=p.first,n=p.second;
        //cout<<m<<" "<<n<<endl;
        q.pop();
        if(m==c&&n==d)
        return moves[c][d];
        else
        {
            for(int i=0;i<8;i++)
             {
                m=p.first+x[i],n=p.second+y[i];
                if(m>0&&m<9&&n>0&&n<9&&vis[m][n]==0)
                {
                    vis[m][n]=1;
                    moves[m][n]=moves[p.first][p.second]+1;
                    q.push(make_pair(m,n));
                }
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
        string s1,s2;
        cin>>s1>>s2;
        int a,b,c,d,res;
        a=s1[0]-'a'+1;
        b=s1[1]-'0';
        c=s2[0]-'a'+1;
        d=s2[1]-'0';
        res=bfs(a,b,c,d);
        cout<<res<<"\n";
    }
}

