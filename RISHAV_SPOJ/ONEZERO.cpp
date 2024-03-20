#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int R[]={0, 0, -1, 1};
int C[]={-1, 1, 0, 0};
int N;
string fun(int n)
{
    queue <string> q;
    q.push("1");
    while(!q.empty())
    {
        string now=q.front();
        int val=0;
        for(int i=0;i<now.size();i++)
        val=(val*10+(now[i]-'0'))%n;
        if(val==0)
        return now;
        q.pop();
        string temp1=now+"0";
        string temp2=now+="1";
        q.push(temp1);
        q.push(temp2);
    }
}
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        cin>>N;
        string res=fun(N);

        cout<<res<<'\n';

    }
}

