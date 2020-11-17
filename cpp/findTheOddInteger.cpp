/*
  * This program finds the integer which appears odd number of times
  * Problem : https://edabit.com/challenge/wgnmQTbfssuhvZHqe
*/

#include<bits/stdc++.h>
using namespace std;

int findOdd(vector<int> ar) {
    int ans = 0;
    for(int i=0; i<ar.size(); i++) {
        ans ^= ar[i];
    }
    return ans;
}
int main() {
    int n;
    vector<int> ar;
    cout << "Enter number of integers in the array: ";
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        ar.push_back(x);
    }
    cout << findOdd(ar) << endl;
    return 0;
}
