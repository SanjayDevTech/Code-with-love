#include<bits/stdc++.h>
using namespace std;
using lld=long long int;

int x[]={-1,0,1,0};
int y[]={0,1,0,-1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    while(h!=0)
    {
        vector <int> res;
        vector <pair<int,int>> v;
        int cnt=0,arr[h+1][w+1];
        int vis[h+1][w+1];
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]==1)
                v.push_back(make_pair(i,j));
                vis[i][j]=0;
            }
        int mx=0,fimax=0;
        for(int i=0;i<v.size();i++)
        {
            int a=v[i].first,b=v[i].second;
            if(vis[a][b]==0)
            {
                cnt++;
                int siz=1;
                queue <pair<int,int> >q;
                q.push(make_pair(a,b));
                vis[a][b]=1;
                while(!q.empty())
                {
                    pair <int,int> p;
                    p=q.front();
                    a=p.first;  b=p.second;
                    q.pop();
                    for(int n=0;n<4;n++)
                    {
                        int f=a+x[n],s=b+y[n];
                        if(f>0&&f<=h&&s>0&&s<=w&&vis[f][s]==0&&arr[f][s]==1)
                        {
                            siz++;
                            vis[f][s]=1;
                            q.push(make_pair(f,s));
                        }
                    }
                }
                res.push_back(siz);
            }
        }
        sort(res.begin(),res.end());
        cout<<cnt<<"\n";
        for(int i=0;i<res.size();i++)
        {
            cnt=1;
            while(i+1<res.size()&&res[i+1]==res[i])
            {
                cnt++;
                i++;
            }
            cout<<res[i]<<" "<<cnt<<"\n";
        }
        cin>>h>>w;
    }
}
