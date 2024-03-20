#include <bits/stdc++.h>
using namespace std;

#define lld long long int

lld count(lld arr[],lld n,lld val)
{
    lld sum=0;
    for(int i=0;i<n;i++)
    sum+=val/arr[i];
    return sum;
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        lld n,t;
        cin>>n>>t;
        lld beg=1,arr[n],max=-1;;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(max<arr[i])
            max=arr[i];
        }
        lld end=t*max,mid;
        max=end;
        while(beg<end)
        {
            //cout<<beg<<" "<<end<<"\n";
            mid=(beg+end)/2;
            lld res=count(arr,n,mid);
            if(res>=t)
            {
                end=mid;
                if(max>mid)
                max=mid;
            }
            else
            beg=mid+1;
        }
        cout<<max<<"\n";
    }
}


