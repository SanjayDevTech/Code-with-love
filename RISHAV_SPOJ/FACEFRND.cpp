#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    cin>>n;
    a=n;
    set <int> s;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b;
        s.insert(a);
        while(b--)
        {
            cin>>c;
            s.insert(c);
        }
    }
    cout<<s.size()-a;
}


