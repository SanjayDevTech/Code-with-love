#include <bits/stdc++.h>
using namespace std;

int KadaneAlgo(int arr[], int n)
{
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for(int i=0; i<n; ++i)
    {
        curr_sum += arr[i];
        if(curr_sum > max_sum) max_sum = curr_sum;
        if(curr_sum < 0) curr_sum = 0;
    }
    return max_sum;
}

int main()
{
    int n;
    cin >> n; // Input of size of Array
    int arr[n];
    for(int i=0; i<n; ++i) cin >> arr[i]; // Input of Array Elements
    int ans = KadaneAlgo(arr, n);
    cout << ans;
    return 0;
}