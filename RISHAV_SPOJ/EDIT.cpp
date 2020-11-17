#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int iscapital(char x)
{
 if (x>='A'&&x<='Z')    return 1;

 else  return 0;
}

int main()
{
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    string s;
    while(cin>>s)
    {
        int n=s.size();
        int res=0,cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(iscapital(s[i]))
            cnt1++;
            if(!iscapital(s[i]))
            cnt2++;
            i++;
            if(i<n)
            {
                if(!iscapital(s[i]))
                cnt1++;
                if(iscapital(s[i]))
                cnt2++;
            }
        }
        cout<<min(cnt1,cnt2)<<"\n";
    }
}
