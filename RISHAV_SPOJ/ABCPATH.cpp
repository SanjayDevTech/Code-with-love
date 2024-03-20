#include<bits/stdc++.h>
using namespace std;
using lld=long long int;

lld vis[10001];
lld res[10001];
vector <int> lst[10001];

int x[]={-1,-1,-1,0,1,1,1,0};
int y[]={-1,0,1,1,1,0,-1,-1};
int dfs(int a)
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
    int h,w;
    cin>>h>>w;
    int t=0;
    while(h!=0)
    {
        t++;
        string s;
        s="";
        int arr[h+1][w+1];
        int vis[h+1][w+1],res[h+1][w+1];
        for(int i=1;i<=h;i++)
        {
            cin>>s;
            for(int j=1;j<=w;j++)
            {
                arr[i][j]=s[j-1]-'A'+1;
                vis[i][j]=0;
                res[i][j]=-1;
            }
        }
        int mx=0,fimax=0;
        for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            mx=0;
            if(arr[i][j]==1)
            {
                int a=i,b=j;
                mx=1;
                queue <pair<int,int> >q;
                q.push(make_pair(a,b));
                vis[a][b]=1;
                res[a][b]=1;
                while(!q.empty())
                {
                    pair <int,int> p;
                    p=q.front();
                    a=p.first;  b=p.second;
                    //cout<<a<<" "<<b<<endl;
                    q.pop();
                    for(int n = 0; n < 8; n++)
                    {
                        int f=a+x[n],s=b+y[n];
                        if(f>0&&f<=h&&s>0&&s<=w&&vis[f][s]==0&&arr[f][s]==arr[a][b]+1)
                        {
                            vis[f][s]=1;
                            res[f][s]=res[a][b]+1;
                            if(res[f][s]>mx)
                            mx=res[f][s];
                            q.push(make_pair(f,s));
                            //cout<<mx<<"V"<<f<<"V"<<s<<endl;
                        }
                    }
                }
                if(mx>fimax)
                fimax=mx;
                for(int k=1;k<=h;k++)
                for(int l=1;l<=w;l++)
                {
                    vis[k][l]=0;
                    res[k][l]=-1;
                }
            }
        }
        cout<<"Case "<<t<<": ";
        cout<<fimax<<"\n";
        cin>>h>>w;
    }
}
