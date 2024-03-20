#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    set <int> s;
    map <int,int> mp;
    set <int> :: iterator its;
    lld n,res=0,val;
    while(t--)
    {
        cin>>n;
        while(n--)
        {
            cin>>val;
            s.insert(val);
            mp[val]+=1;
        }
        its=s.begin();
        int min,max;
        min=*its;
        mp[*its]--;
        if(mp[*its]==0)
        s.erase(min);
        its=s.end();
        its--;
        max=*its;
        mp[*its]--;
        if(mp[*its]==0)
        s.erase(max);
        res+=max-min;
    }
    cout<<res;
}

