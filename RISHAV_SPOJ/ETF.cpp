#include <bits/stdc++.h>
using namespace std;

int totient(int n)
{
    int result =n;

    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            n/=i;
            result-=result/i;
        }
    }
    if(n>1)
    result-=result/n;
    return result;
}
int main() {
	// your code goes here

    long t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        int res=totient(a);
        cout<<res<<endl;

    }
}

