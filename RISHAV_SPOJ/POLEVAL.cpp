#include <bits/stdc++.h>
using namespace std;

long horner(long poly[], long n, long x) {
    long result = poly[0];
    for (int i=1; i<=n; i++)
        result = result*x + poly[i];

    return result;
}

int main() {
	// your code goes here

    long n=1,t=1;
    cin>>n;
    while(n!=-1)
    {
        cout<<"Case "<<t<<":\n";
        long poly[n+1];
        for(int i=0;i<=n;i++)
        cin>>poly[i];
        int q;
        cin>>q;
        while(q--)
        {
            long x;
            cin>>x;
            long res=horner(poly,n,x);
            cout<<res<<endl;
        }
        t++;
        cin>>n;
    }
}

