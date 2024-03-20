#include <bits/stdc++.h>
using namespace std;

#define lld long long int

vector <int> lst[100000];
int prime[100000]={0};
vector <int> v;

void seive()
{
    for(int i=4;i<=9999;i+=2)
    prime[i]=1;
    for(int i=3;i<=sqrt(9999);i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=9999;j+=i)
            prime[j]=1;
        }
    }
    for(int i=1000;i<=9999;i++)
    if(prime[i]==0)
        v.push_back(i);
}

void fun()
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            vector <int> temp;
            int val=v[i],val1=v[j];
            while(val>0)
            {
                int x=val%10;
                int y=val1%10;
                temp.push_back(abs(x-y));
                val/=10;
                val1/=10;
            }
            sort(temp.begin(),temp.end());
            if(temp[0]==0&&temp[1]==0&&temp[2]==0&&temp[3]!=0)
            lst[v[i]].push_back(v[j]);
        }
    }
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    seive();
    fun();
    while(t--)
    {
        int vis[100000]={0};
        int res[100000]={-1};
        memset(res,-1,sizeof(res));
        int n,k,a,b;
        cin>>n;
        cin>>k;
        queue <int> q;
        q.push(n);
        vis[n]=1;
        res[n]=0;
        while(!q.empty())
        {
            a=q.front();
            //cout<<a<<" "<<res[a]<<endl;
            q.pop();
            if(a==k)
            break;
            for(int i=0;i<lst[a].size();i++)
            {
                if(vis[lst[a][i]]==0)
                {
                    vis[lst[a][i]]=1;
                    res[lst[a][i]]=res[a]+1;
                    q.push(lst[a][i]);
                }
            }
        }
        if(res[k]==-1)
        cout<<"Impossible\n";
        else
        cout<<res[k]<<"\n";
    }
    return 0;
}
