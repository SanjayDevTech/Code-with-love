#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool is_perf_sq = 0;
    for (int i = 1; i*i <= n; ++i) {
        if(i*i == n) {
            is_perf_sq = 1;
        }
    }
    if(is_perf_sq) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}
