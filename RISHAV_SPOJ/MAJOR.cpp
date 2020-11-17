#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        int n,val,in;
        cin>>n;
        in=n;
        map <int,int> mp;
        while(n--)
        {
            cin>>val;
            mp[val]++;
        }
        if(in%2!=0)
        in++;
        in/=2;
        map <int,int> :: iterator it;
        int ptr=0,res=0;
        for(it=mp.begin();it!=mp.end();it++)
        if(it->second>in)
        {
            ptr=1;
            res=it->first;
            break;
        }
        if(ptr==1)
        cout<<"YES "<<res<<"\n";
        else
        cout<<"NO\n";
    }
}

