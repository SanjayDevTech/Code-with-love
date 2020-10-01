#include <iostream>
#include <vector>
using namespace std;

// Data structure to store graph edges
struct Edge {
	int src, dest;
};

// Class to represent a graph object
class Graph{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int N){
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);

		// add edges to the Directed graph
		for (auto &edge: edges)
			adjList[edge.src].push_back(edge.dest);
	}
};

// Perform DFS on graph and set departure time of all
// vertices of the graph
void DFS(Graph const &graph, int v, vector<bool>
	&discovered, vector<int> &departure, int& time){
	// mark current node as discovered
	discovered[v] = true;

	// set arrival time
	time++;

	// do for every edge (v -> u)
	for (int u : graph.adjList[v]){
		// u is not discovered
		if (!discovered[u])
			DFS(graph, u, discovered, departure, time);
	}

	// ready to backtrack
	// set departure time of vertex v
	departure[time] = v;
	time++;
}

// performs Topological Sort on a given DAG
void doTopologicalSort(Graph const& graph, int N){
	// departure[] stores the vertex number using departure time as index
	vector<int> departure(2*N, -1);

	// Note if we had done the other way around i.e. fill the
	// array with departure time by using vertex number
	// as index, we would need to sort the array later

	// stores vertex is discovered or not
	vector<bool> discovered(N);
	int time = 0;

	// perform DFS on all undiscovered vertices
	for (int i = 0; i < N; i++)
		if (!discovered[i])
			DFS(graph, i, discovered, departure, time);

	// Print the vertices in order of their decreasing
	// departure time in DFS i.e. in topological order
	for (int i = 2*N - 1; i >= 0; i--)
		if (departure[i] != -1)
			cout << departure[i] << " ";
}

// Topological Sort Algorithm for a DAG using DFS
int main(){
	// vector of graph edges as per above diagram
	vector<Edge> edges ={
		{0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4},
		{5, 1}, {7, 0}, {7, 1}
	};

	// Number of nodes in the graph
	int N = 8;

	// create a graph from edges
	Graph graph(edges, N);

	// perform Topological Sort
	doTopologicalSort(graph, N);

	return 0;
}