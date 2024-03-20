#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int mod=100000,arr[1100001];
    arr[1]=0;
    arr[2]=1;
    for(int i=3;i<1100001;++i)
    arr[i]=(arr[i-1]%mod+arr[i-2]%mod)%mod;
    int a,b;
    for(int j=1;j<=t;j++)
    {
        priority_queue <int> PQ;
        cin>>a>>b;
        for(int i=a;i<=a+b;i++)
        PQ.push(-arr[i]);
        int x=PQ.size();
        if(x>100)
        x=100;
        cout<<"Case "<<j<<": ";
        while(x--)
        {
            cout<<-PQ.top()<<" ";
            PQ.pop();
        }
        cout<<"\n";
    }
}
