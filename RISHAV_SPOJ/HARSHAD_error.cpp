#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

    bool arr[1000001];
    memset(arr, true, sizeof(arr));


    int i,k,j;
    for(i=1;i<1000001;i++)
    {
        int val=i;
        int sum=0;
        while(val>0)
        {
            sum+=val%10;
            val/=10;
        }
        if(sum+i<1000001)
        {
            sum+=i;
            arr[sum]=false;
        }
    }
    bool arr1[1000001];
    memset(arr1, true, sizeof(arr1));
    arr1[1]=false;
    arr1[0]=false;
    for(long i=2;i<sqrt(1000001);i++)
    {
        if(arr1[i]==true)
        {
            for(long j=i*i;j<1000001;j+=i)
            arr1[j]=false;
        }
    }
    k=0;
    int cnt[1000001]={0};
    for(i=1;i<1000001;i++)
    {
        if(arr[i]&&arr1[i])
        cnt[i]=++k;
        else
        cnt[i]=k;
        //cout<<cnt[i]<<" "<<i<<endl;
    }

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,res=0;
        cin>>a>>b;
        res=cnt[b]-cnt[a];
        if(cnt[a]==cnt[b])
        {
            if(cnt[a]==0)
            cout<<0<<endl;
            else
            {
                if(cnt[a-1]!=cnt[b])
                cout<<1<<endl;
            }
        }
        else
        {
            if(cnt[a-1]!=cnt[a])
            res++;
            cout<<res<<endl;
        }
        /*for(int i=a;i<=b;i++)
        if(arr[i]&&arr1[i])
        res++;
        cout<<res<<endl;*/
    }
 return 0;
}

