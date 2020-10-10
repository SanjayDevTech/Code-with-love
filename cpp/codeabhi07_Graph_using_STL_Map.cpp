#include<iostream>
#include<list>
#include<map>
#include<iterator>
using namespace std;

class Graph {

int V;
map<int , list<int> > adj;

public:
    Graph (int V){
    this->V=V;
    }

    void addEdge(int u,int v)
    {
            adj[u].push_back(v);
            adj[v].push_back(u);
    }

    void printAllEdges()
    {
        map<int, list<int> >::iterator it;
        for(it=adj.begin();it!=adj.end();it++){
            cout<<it->first<<"->";
            for(int i: it->second){
                cout<<i<<" ";
            }
            cout<<endl;
        }

    }

};


int main()
{
    Graph g(5);
    g.addEdge(2,7);
    g.addEdge(7,9);
    g.addEdge(4,2);
    g.addEdge(7,5);
    g.addEdge(2,5);

    g.printAllEdges();


    return 0;
}
