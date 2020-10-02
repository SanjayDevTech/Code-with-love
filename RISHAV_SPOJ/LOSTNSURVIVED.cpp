#include<bits/stdc++.h>
using namespace std;
using lld=long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    memset(arr,-1,sizeof(arr));
    multiset <int> s;
    for(int i=1;i<=n;i++)
    s.insert(arr[i]);
    while(q--)
    {
        int val,res1,res2,par1,par2,a,b,ptr;
        cin>>a>>b;

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
            s.erase(s.find(res1));
            s.erase(s.find(res2));
            s.insert(res1+res2);

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

        /*for(auto it=s.begin();it!=s.end();++it)
        cout<<*it<<" ";
        cout<<"\n";
        for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
        cout<<"\n\n";*/

        if(s.size()>1)
        {
        val=(*--s.end())-(*s.begin());
        cout<<val<<"\n";
        }
        else
        cout<<"0\n";
    }
}
