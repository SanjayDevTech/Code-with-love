
#include<bits/stdc++.h>
using namespace std;

class Graph{
	public:
	int V;
	set<int> *edj;

	Graph(int v){
		V = v+1;
		edj = new set<int>[V];
	}
	
	void add_edj(int u, int v, bool bidir = false){
		edj[u].insert(v);
		if(bidir)
			edj[v].insert(u);
	}
	
	void print(){
		for (int i=1;i<V;i++){
			printf("%d ->",i);
			for (auto edge: edj[i])
				printf("%d ", edge);
			printf("\n");
		}
	}

	template<size_t t>
	void dfs(int v, list<int> *tsort,bitset<t> &vis){
		vis[v] = 1;
		for (auto u:edj[v]){
			if( not vis[u]){
				dfs(u, tsort, vis);
			}
		}
		tsort->push_front(v);
	}
	
	list<int> *top_sort(){
		

		list<int> *tsort = new list<int>();
		int *indeg = new int[V]{0};

		queue<int> *Q = new queue<int>();
		for (int i=1;i<V;i++)
			for(int v: edj[i])
				indeg[v]++;
				
		for (int i=1;i<V;i++)
			if(not indeg[i])
				Q->push(i);
		while(not Q->empty()){
			int node = Q->front();
			Q->pop();
			tsort->push_back(node);
			for(auto i:edj[node]){
				indeg[i]--;
				if(not indeg[i])
					Q->push(i);
			}
		}
		return tsort;
	}
	~Graph(){
		delete[] edj;
	}
};

int main(){
	Graph *g = new Graph(5);
	
	g->add_edj(1,2);
	g->add_edj(3,2);
	g->add_edj(4,3);
	g->add_edj(1,4);
	g->add_edj(1,5);
	g->add_edj(5,2);
	auto t_sort = g->top_sort();
	for(auto it = t_sort->begin(); it!=t_sort->end(); it++){
		cout<< *it<<" ";
	}
	return 0;
}
