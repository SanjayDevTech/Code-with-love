//program to detect cycle in an undirected graph
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

// defining global variables
bool cycle;
ll vis[100005];
vector<ll> matrix[100005];

// Function to perform Depth-First-Search on the graph
void dfs(ll a, ll parent)
{
    // cout<<a<<" ";
    vis[a] = 1;
    //rec[a]=1;
    for (ll i = 0; i < matrix[a].size(); i++)
    {
        ll u = matrix[a][i];
        if (vis[u] == 1 && a != parent)
        {
            cycle = true;
            //cout<<"cycle detected\n";
            continue;
        }
        else if (vis[u] && a == parent)
            continue;
        dfs(u, a);
        // cout<<a<<" ";
    }
    //rec[a]=0;
}

int main()
{
    ll n, m;
    cout << "\nEnter no of vertices: ";
    cin >> n;
    cout << "\nEnter no of edges: ";
    cin >> m;
    // loop for inputing the graph and storing it in matrix
    cout << "Enter the adjacent vertices: for eg if vertex 1 and 2 are adjacent and vertex 2 and 3 are adjacent\n";
    cout << "You enter - \n 1 2\n 2 3\n and so on\n Enter now:\n";
    for (ll i = 0; i < m; ++i)
    {
        ll a, b;
        cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1, 1);
    if (cycle)
        cout << "cycle detected\n";
    else
        cout << "cycle not detected\n";

    return 0;
}