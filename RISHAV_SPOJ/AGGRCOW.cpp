#include <bits/stdc++.h>
using namespace std;

#define lld long long int

bool count(int arr[],int n,int val,int c)
{
    int cow=1,qty=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]-qty>=val)
        {
            cow++;
            qty=arr[i];
            if(cow==c)
            return true;
        }
    }
    return false;
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(arr,arr+n);
        int beg=arr[0],end=arr[n-1],max=-1;;
        while(beg<=end)
        {
            //cout<<beg<<" "<<end<<"\n";
            int mid=(beg+end)/2;
            if(count(arr,n,mid,c))
            {
                beg=mid+1;
                if(max<mid)
                max=mid;
            }
            else
            end=mid-1;
        }
        cout<<max<<"\n";
    }
}


