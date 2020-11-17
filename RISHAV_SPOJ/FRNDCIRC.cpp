#include<bits/stdc++.h>
using namespace std;
using lld=long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int arr[100001];
    while(t--)
    {
        memset(arr,-1,sizeof(arr));
        int q,cnt=0;
        cin>>q;
        string s1,s2;
        unordered_map <string,int> mp;
        while(q--)
        {
            int val,res1,res2,par1,par2,a,b,ptr;
            cin>>s1>>s2;

            if(mp[s1]==0)
            mp[s1]=++cnt;
            if(mp[s2]==0)
            mp[s2]=++cnt;
            a=mp[s1];
            b=mp[s2];
            ptr=a;

            val=a;
            while(arr[val]>0)
            val=arr[val];
            par1=val;
            res1=arr[val];
            val=b;
            while(arr[val]>0)
            val=arr[val];
            res2=arr[val];
            par2=val;

            if(par1!=par2)
            {
                if(res1<=res2)
                {
                    arr[par2]=par1;
                    arr[par1]=res1+res2;
                    val=b;
                    while(arr[val]!=par1)
                    {
                        val=arr[b];
                        arr[b]=par1;
                        b=val;
                    }
                }
                else
                {
                    arr[par1]=par2;
                    arr[par2]=res1+res2;
                    val=a;
                    while(arr[val]!=par2)
                    {
                        val=arr[a];
                        arr[a]=par2;
                        a=val;
                    }
                }
            }
            val=ptr;
            while(arr[val]>0)
            val=arr[val];
            cout<<-1*arr[val]<<"\n";
        }
    }
}
