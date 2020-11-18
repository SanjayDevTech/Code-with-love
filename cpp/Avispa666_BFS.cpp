#include <vector>
#include <queue>
#include <iostream>

int main() {
    int n = 5;
    std::vector<std::vector<int>> graph(n);

    graph[0].push_back(2); //add some edges for testing
    graph[0].push_back(3);
    graph[1].push_back(2);
    graph[3].push_back(1);
    graph[1].push_back(4);
    //BFS
    std::queue<int> q;
    std::vector<unsigned char> visited(n, 0);
    int start = 0;
    q.push(start);
    while (!q.empty()) {
        start = q.front();
        std::cout << start << " ";
        q.pop();
        for(int i : graph[start]) {
            if (visited[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    return 0;
}