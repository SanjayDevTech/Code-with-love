#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld n;
    cin>>n;
    while(n!=0)
    {
        lld val=n;
        map <lld,lld> mp;
        map <lld,lld> :: iterator it;
        while (n % 2 == 0)
        {
            mp[2]++;
            n = n/2;
        }
        for(lld i=3;i<=sqrt(n);i+=2)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    mp[i]++;
                    n/=i;
                }
            }
        }
        if(n>1)
        mp[n]++;
        for(it=mp.begin();it!=mp.end();it++)
        {
            cout<<it->first<<"^"<<it->second<<" ";
        }
        cout<<endl;
        cin>>n;
    }
}

