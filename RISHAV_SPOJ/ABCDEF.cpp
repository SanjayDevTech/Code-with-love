#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    lld arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    unordered_map<lld,lld> mp;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    for(int k=0;k<n;k++)
    {
        lld val=arr[i]*arr[j]+arr[k];
        mp[val]++;
    }
    lld res=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    for(int k=0;k<n;k++)
    {
        if(arr[k]!=0)
        {
            lld val=(arr[i]+arr[j])*arr[k];
            res+=mp[val];
        }
    }
    cout<<res;
}
