#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    int j=1,cnt=0;
    for(int i=0;i<n;i++)
    {
        while(j<n&&arr[j]-arr[i]<=k)
        j++;
        j--;
        if(arr[j]-arr[i]==k)
        cnt++;
    }
    cout<<cnt;

}

