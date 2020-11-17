#include <bits/stdc++.h>
using namespace std;

#define lld long long int

lld count(lld arr[],lld n,lld val)
{
    lld sum=0;
    for(int i=0;i<n;i++)
    if(arr[i]>val)
    sum+=arr[i]-val;
    return sum;
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld n,k;
    cin>>n>>k;
    lld arr[n],max=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(max<arr[i])
        max=arr[i];
    }
    lld beg=0,mid,end=max,in;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        lld out=count(arr,n,mid);
        if(out==k)
        {
            in=mid;
            break;
        }
        else if(out<k)
        end=mid-1;
        else
        beg=mid+1;
        in=mid;
    }
    if(count(arr,n,in)<k)
    cout<<in-1;
    else
    cout<<in;
}


