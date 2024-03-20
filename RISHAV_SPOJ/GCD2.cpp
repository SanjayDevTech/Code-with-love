#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int mod(string num, int a) {
    int res = 0;

    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;

    return res;
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int a;
	    string b;
	    cin>>a>>b;
	    if(a==0)
	    cout<<b<<endl;
	    else{
	    int c=mod(b,a);
	    int d=gcd(a,c);
	    cout<<d<<endl;
	    }
	}
	return 0;
}
