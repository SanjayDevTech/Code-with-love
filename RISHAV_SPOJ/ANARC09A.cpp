#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0;
    string s;
    while(1)
    {
        t++;
        cin>>s;
        if(s[0]=='-')
        break;
        else
        {
            stack <char> stk;
            //cout<<"J";
            stk.push(s[0]);
            for(int i=1;i<s.size();i++)
            {
                if(s[i]=='}')
                {
                    if(stk.size()>0&&stk.top()=='{')
                    stk.pop();
                    else
                    stk.push('}');
                }
                else
                stk.push('{');
            }
            int res=0,cnto=0,cntc=0;
            while(stk.size()!=0)
            {
                char ch=stk.top();
                stk.pop();
                if(ch=='{')
                cnto++;
                else
                cntc++;
            }
            res=cnto/2+cntc/2+2*(cnto%2);
            cout<<t<<". "<<res<<"\n";
        }
    }
}


