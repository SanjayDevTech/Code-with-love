#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int


int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lld t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int res=0,s1=0,s2=0,s3=0,s0=0;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            s0+=1;

            else if(s[i]=='8'&&s0>0)
            s1=max(s0,s1)+1;

            else if(s[i]=='0'&&s1>0)
            s2=max(s1,s2)+1;

            else if(s[i]=='7'&&s2>0)
            s3=max(s2,s3)+1;
        }
        cout<<s3;
    }
}

