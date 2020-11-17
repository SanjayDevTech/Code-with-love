#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,c,val;
    cin>>n>>c;
    vector <int> arr;
    map <int,int> mp;
    set <int> s;
    map <int,int> :: iterator it;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        if(s.find(val)==s.end())
        {
            s.insert(val);
            arr.push_back(val);
        }
        mp[val]++;
    }
    vector <int> v;
    for(it=mp.begin();it!=mp.end();++it)
    {
        int qty=it->second;
        v.push_back(qty);
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--)
    {
        int cnt=1,val=v[i];
        while(i>=1&&val==v[i-1])
        i--;
        vector <int> arr1;
        for(it=mp.begin();it!=mp.end();++it)
        if(it->second==val)
        arr1.push_back(it->first);
        while(arr1.size()!=0)
        {
            int ptr=0;
            for(int j=0;j<arr.size();j++)
            {
                for(int k=0;k<arr1.size();k++)
                {
                    if(arr[j]==arr1[k])
                    {
                        while(val--)
                        cout<<arr[j]<<" ";
                        mp[arr[j]]=0;
                        arr1.erase(arr1.begin()+k);
                        ptr=1;
                        val=v[i];
                        break;
                    }
                }
                if(ptr==1)
                break;
            }
        }
    }
}



