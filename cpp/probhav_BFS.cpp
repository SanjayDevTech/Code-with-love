#include<bits/stdc++.h>
using namespace std;
#define int long long
#define dopamine ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
int maxi = INT_MAX, mini = INT_MIN;

bool visited[100005] = {false};
int dist[100005];
vector<int>arr[100005];
void initialise(int a)
{
    for (int i = 0; i < a + 1; i++)
    {   dist[i] = -1;
        visited[i] = false;
    }
}

int dfs(int a, int b)
{
    queue<int>q;
    q.push(a);
    dist[a] = 0;
    while (!q.empty())
    {
        int r = q.front();
        q.pop();
        visited[r] = true;
        for (int i = 0; i < arr[r].size(); i++ )
        {
            if (!visited[arr[r][i]])
            {
                visited[arr[r][i]] = true;
                dist[arr[r][i]] = dist[r] + 1;
                q.push(arr[r][i]);

            }
        }
    }
    return dist[b];
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
            arr[w].push_back(q);
        }
        initialise(a);
        int e, r;
        cin >> e >> r;
        cout << dfs(e , r ) << "\n";
    }
    return 0;
}

