#include<bits/stdc++.h>
using namespace std;
int V; //number of vertices in graph
int E; //number of edges in graph
vector<tuple<int,int,int>> graph; //graph
void bellmanFord(){
	int dist[V]; //distance array from source
	for(int i=0;i<V;i++){
        dist[i]=INT_MAX; 
	}
    dist[0] = 0; 
    for(int i=1;i<=V-1;i++) { 
        for(int j=0;j<E;j++) { 
            int u=get<0>(graph[j]);
            int v=get<1>(graph[j]);
            int weight=get<2>(graph[j]);
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]) 
                dist[v]=dist[u]+weight; 
        } 
    }  
    for (int i=0;i<E;i++) { 
        int u=get<0>(graph[i]);
        int v=get<1>(graph[i]);
        int weight=get<2>(graph[i]);
        if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])  { 
            printf("Graph contains negative weight cycle"); 
            return; // If negative cycle is detected simply return 
        } 
    } 
	
	for(int i=0;i<V;i++){
		cout<<dist[i]<<" ";
	} 
}
int main(){

	cin>>V>>E;
	for(int i=0;i<E;i++){
		int x,y,w;
		cin>>x>>y>>w;
		graph.push_back(make_tuple(x,y,w));
	}
	bellmanFord();

    return 0; 
}
