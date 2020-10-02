#include<bits/stdc++.h>
using namespace std;
using lld=long long int;

int main()
{

    lld n,k,i,rsum=0,sum=0,ptr=0;
    cin>>n>>k;
    lld arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    vector <int> v;
    for(i=0;i<n;i++)
    {
        if(sum+arr[i]<=k)
        {
            v.push_back(i);
            sum+=arr[i];
            if(sum>rsum)
            rsum=sum;
        }
        else
        {
            while(sum+arr[i]>k&&ptr<v.size())
            {
                sum-=arr[v[ptr]];
                ptr++;
            }
            if(sum+arr[i]<=k)
            {
                v.push_back(i);
                sum+=arr[i];
            }
            if(sum>rsum)
            rsum=sum;
        }
    }
    cout<<rsum;
}
