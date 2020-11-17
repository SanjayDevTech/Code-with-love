#include<bits/stdc++.h>
using namespace std;
using lld=long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld n,m,c;
    cin>>n>>m>>c;
    lld arr[n+1];
    for(int i=1;i<=n;++i)
    cin>>arr[i];
    multiset<int> s;
    vector <int> v;
    for(int i=1;i<=n;i++)
    {
        s.insert(arr[i]);
        if(i>m)
            s.erase(s.find(arr[i-m]));
        if(i>=m)
           if(*(--s.end())-(*s.begin())<=c)
                v.push_back(i-m+1);

    }
    if(v.empty())
        cout<<"NONE\n";
    else
        for(int i=0;i<v.size();++i)
        cout<<v[i]<<"\n";
}
