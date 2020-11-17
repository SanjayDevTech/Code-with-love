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
    int t;
    cin>>t;
    lld arr[3]={0};
    string s;
    while(t--)
    {
        cin>>s;
        if(s[0]=='1'&&s[2]=='2')
        arr[0]++;
        else if(s[0]=='1')
        arr[1]++;
        else
        arr[2]++;
    }
    lld res=0;
    if(arr[1]>=arr[2])
    {
        res+=arr[2];
        arr[1]-=arr[2];
        arr[2]=0;
        lld sum=2*arr[0]+arr[1];
        if(sum%4!=0)
        res++;
        res+=sum/4;
    }
    else
    {
        res+=arr[2];
        if(arr[0]%2!=0)
        res++;
        res+=arr[0]/2;
    }
    res++;
    cout<<res;
}


