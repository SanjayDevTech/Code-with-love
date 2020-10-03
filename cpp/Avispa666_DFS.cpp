#include <vector>
#include <queue>
#include <iostream>

int n = 5;
std::vector<std::vector<int>> graph(n);
std::vector<int> state(n, 0);

void dfs(int v) {
    state[v] = 1;
    std::cout << v << " ";
    for(int i : graph[v]) if (state[i] == 0) dfs(i);
    state[v] = 2;
}

int main() {
    graph[0].push_back(2); //add some edges for testing
    graph[0].push_back(3);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[1].push_back(4);
    dfs(0);
    return 0;
}


