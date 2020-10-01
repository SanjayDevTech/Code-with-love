#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    //Input sorted array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int num;
    cin >> num; //check if this number is present in the above array
    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == num) {
            cout << "Number is present in the given array";
            return 0;
        }
        if(arr[mid] > num) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << "Number is not present in the given array";
    return 0;
}
