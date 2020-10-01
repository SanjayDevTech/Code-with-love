// Created by ganesh bhandarkar
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
const int N = 100000;
vector<int> l[N];
//DFS
vector<bool> visited(5,false);
using ll = long long;
void dfs(int i){	
	if(visited[i])return;
	cout<<i<<" ";
	visited[i]=true;
	for(auto u:l[i])dfs(u);
}
//BFS
vector<bool> visistedbfs(5,false);
void bfs(int i){
	queue<int> q;
	q.push(i);
	visistedbfs[i]=true;
	while(!q.empty()){
		int f = q.front();
		cout<<f<<" ";
		q.pop();
		for(auto x:l[f]){
			if(!visistedbfs[x]){
				q.push(x);
				visistedbfs[x]=true;
			}
		}
	}

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;   
    int v,u;
    for(int i=0;i<n;i++){
    	cin>>v>>u;
    	l[v].push_back(u);
    	l[u].push_back(v);
    }
    for(int i=0;i<n;i++){
    	cout<<i<<"->";
    	for(int val:l[i]){
    		cout<<val<<" ";
    	}
    	cout<<endl;
    }
    dfs(0);
    cout<<"\n";
    bfs(0);
    return 0;
}