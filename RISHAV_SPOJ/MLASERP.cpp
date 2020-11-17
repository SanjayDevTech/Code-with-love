#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int r[]={1,0,-1,0};
int c[]={0,1,0,-1};
int w,h,vis[101][101];
char arr[101][101];

bool valid(int x,int y)
{
    if(x<h&&y<w&&x>=0&&y>=0&&arr[x][y]!='*')
    return true;
    return false;
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>w>>h;
        int x1,y1,x2,y2,ptr=0,res[h][w];
        string s;
        for(int i=0;i<h;i++)
        {
            cin>>s;
            for(int j=0;j<w;j++)
            {
                arr[i][j]=s[j];
                res[i][j]=101;
                if(arr[i][j]=='C')
                {
                    if(ptr==0)
                    {
                        x1=i;
                        y1=j;
                        ptr=1;
                    }
                    else
                    {
                        x2=i;
                        y2=j;
                    }
                }
            }
        }
        queue <pair <int,int> >q;
        pair <int,int> p;


        res[x1][y1]=-1;
        q.push({x1,y1});
        ptr=0;

        while(!q.empty())
        {
            p=q.front();
            int x=p.first;
            int y=p.second;

            q.pop();
            for(int i=0;i<4;i++)
            {
                int new_x=x+r[i], new_y=y+c[i];
                while(valid(new_x,new_y))
                {
                    if(res[new_x][new_y]>res[x][y]+1)
                    {
                        q.push({new_x,new_y});
                        res[new_x][new_y]=res[x][y]+1;
                        if(new_x==x2&&new_y==y2)
                        {
                            ptr=1;
                            break;
                        }
                    }
                    new_x+=r[i];
                    new_y+=c[i];
                }
                if(ptr==1)
                break;
            }
            if(ptr==1)
            break;
        }
        /*for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            cout<<res[i][j]<<" ";
            cout<<'\n';
        }*/
        cout<<res[x2][y2];
    }
}

