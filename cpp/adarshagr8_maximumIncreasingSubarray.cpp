#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
        cur += a[i];
        cur = max(cur, 0);
        ans = max(ans, cur);
    }
    cout << ans << endl;
}