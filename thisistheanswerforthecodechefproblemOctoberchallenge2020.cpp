#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(t--)
    {
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        int a[n];
        for(int i =0;i<n;i++)
        {
            a[i]=i;
        }a[x]=0;

        for(int i =0;i<n;i++)
        {
             x=(x+k)%n;
            
            a[x]=0;
        } int c=0;
        for(int i =0;i<n;i++)
        {  cout<<a[i]<<" ";
            if(a[i]==y)
            {
                c++;
            }
        }
		cout<<endl;cout<<c<<endl;
        if(c==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}
