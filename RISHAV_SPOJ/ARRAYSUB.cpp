#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    lld arr[t+1];
    for(int i=1;i<=t;i++)
    cin>>arr[i];
    lld m;
    cin>>m;
    vector <int> v;
    multiset <int> s;
    for(int i=1;i<=t;i++)
    {
        s.insert(arr[i]);
        if(i>m)
        s.erase(s.find(arr[i-m]));
        if(i>=m)
        v.push_back(*--s.end());
    }
    for(int i=0;i<v.size();++i)
    cout<<v[i]<< " ";
}

