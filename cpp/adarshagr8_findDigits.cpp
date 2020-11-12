#include<bits/stdc++.h>
using namespace std;

vector<int> digits(int n){
    vector<int> ans;
    while(n){
        ans.push_back(n % 10);
        n /= 10;
    }
    return ans;
}
