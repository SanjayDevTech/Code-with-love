#include<bits/stdc++.h>
#include<climits>
using namespace std;

int ms(int a[], int num)
{
    int max_end_here=0,max_so_far=INT_MIN;
    for(int i=0;i<num;i++)
    {
        max_end_here=max_end_here+a[i];
        if(max_so_far<max_end_here)
            max_so_far=max_end_here;
        if(max_end_here<0)
            max_end_here=0;
    }
    return max_so_far;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int res=ms(a, n);
    cout<<res;
    return 0;
}
