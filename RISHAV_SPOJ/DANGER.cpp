#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n,cnt;
    n=(s[0]-'0')*10+(s[1]-'0');
    while(n!=0)
    {
        cnt=s[3]-'0';
        while(cnt>0)
        {
            n*=10;
            cnt--;
        }
        int val=log2(n);
        n-=pow(2,val);
        val=2*n+1;
        cout<<val<<"\n";
        cin>>s;
        n=(s[0]-'0')*10+(s[1]-'0');
    }
}
