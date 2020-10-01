#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dopamine ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
int maxi = INT_MAX, mini = INT_MIN;

bool visited[100005] = {false};
int col[100005];
vector<int>arr[100005];
void initialise(int a)
{
    for (int i = 0; i < a + 1; i++)
    {   col[i] = 0;
        visited[i] = false;
    }
}
bool isbipartite(int a, int b)
{
    visited[a] = true;
    col[a] = b;
    for (int child : arr[a])
    {
        if (!visited[child])
        {
            visited[child] = true;
            if (isbipartite(child, b ^ 1) == false)
                return false;
        }
        else
        {
            if (col[a] == col[child])
                return false;
        }
    }
    return true;
}
int32_t main()
{
    //serotonin();
    dopamine
    int t = 1;//cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;

        for (int i = 0; i < b; i++)
        {
            int q, w;
            cin >> q >> w;
            arr[q].push_back(w);
        }
        initialise(a);
        if (isbipartite(1, 0))
            cout << 1;
        else
            cout << 0;
    }
    return 0;
}
