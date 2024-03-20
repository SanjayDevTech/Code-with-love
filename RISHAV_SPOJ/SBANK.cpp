#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        map <string,int> mp;
        map <string,int> :: iterator it;
        int n;
        cin>>n;
        string s,s1,s2,s3,s4,s5;
        while(n--)
        {
            cin>>s>>s1>>s2>>s3>>s4>>s5;
            s+=s1+s2+s3+s4+s5;
            mp[s]++;
        }
        for(it=mp.begin();it!=mp.end();it++)
        {
            s=it->first;
            for(int i=0;i<s.size();i++)
            {
                if(i==2||i==10||i==14||i==18||i==22||i==26)
                cout<<" ";
                cout<<s[i];
            }
            cout<<" "<<it->second<<"\n";
        }
        cout<<"\n";
    }
}



