#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int count(int arr[],int n,int val)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i]/val;
    return sum;
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n!=0)
    {
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(arr,arr+n);
        int res=0,ptr=0;
        for(int i=0;i<n-2;i++)
        {
            int k=i+2;
            for(int j=i+1;j<n-1;j++)
            {
                int sum=arr[i]+arr[j];
                for(k=k;k<n;k++)
                {
                    if(arr[k]>sum)
                    {
                        ptr=1;
                        break;
                    }
                }
                if(ptr==1)
                res+=n-k;
                ptr=0;
            }
        }
        cout<<res<<endl;
        cin>>n;
    }
}


