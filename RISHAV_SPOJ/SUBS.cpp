#include <bits/stdc++.h>
using namespace std;

#define lld long long int
bool comp(string y,string x)
{
    lld n,o,p,cnt=0;
    for(int i=0; i<y.size(); i++)
    {
        if(y[i]==x[cnt])
        cnt++;
        if(cnt==x.size())
        break;
    }
    if(cnt==x.size())
        return 1;
    else
        return 0;
}
string match(string x,lld mid)
{   string s="";
    for(int i=0; i<x.size(); i++)
        for(int j=0; j<mid; j++)
        s+=x[i];
    return s;
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string x,y;
    while(t--)
    {
        x=y="";
        cin>>x>>y;
        int hp=y.size()/x.size();
        int beg=0,end=hp,res=0;
        while(beg<=end)
        {
            lld mid=(beg+end)/2;
            if(comp(y,match(x,mid)))
            {
                if(res<mid)
                res=mid;
                beg=mid+1;
            }
            else
            end=mid-1;
        }
        cout<<res<<"\n";
    }
}
