#include <bits/stdc++.h>
using namespace std;

vector<int> v[100];
bool visited[100];

void dfs (int x) {
    visited[x] = 1;
    for (int i : v[x]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans;
    return 0;
}
