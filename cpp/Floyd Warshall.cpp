#include<bits/stdc++.h>
using namespace std;
int INF=100000;
int main(){
	int V=4;
	int graph[V][V] = { {0, 5, INF, 10},   //graph
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}}; 
    int dist[V][V]; //distance matrix
    for(int i=0;i<V;i++){  
        for (int j=0;j<V;j++){
            dist[i][j]=graph[i][j];
    	}
    }
    for(int k=0;k<V;k++){  
        for(int i=0;i<V;i++){   
            for(int j=0;j<V;j++){  
                if(dist[i][k]+dist[k][j]<dist[i][j]){  
                    dist[i][j]=dist[i][k]+dist[k][j];  
                }
            }  
        }  
    }
    // printing distances
    for(int i=0;i<V;i++){  
        for(int j=0;j<V;j++){  
            if(dist[i][j]==INF) cout<<"INF"<<" ";  
            else cout<<dist[i][j]<<" ";  
        }  
        cout<<endl;  
    }  
    return 0; 
}
