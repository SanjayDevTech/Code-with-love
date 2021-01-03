#include<bits/stdc++.h>
using namespace std;
#define N 100005
int sz[N], in[N], out[N], head[N], parent[N], depth[N];
vector<int> g[N];
void dfs_sz(int v, int p, int d) {
	parent[v] = p;
    sz[v] = 1;
    depth[v] = d;
    for(auto &u: g[v]) {
    	if(u!=p){
	        dfs_sz(u,v,d+1);
	        sz[v] += sz[u];
	        if(sz[u] > sz[g[v][0]]) {
	            swap(u, g[v][0]);
	        }
    	}
    }
}

int t = 0;
void dfs_hld(int v, int p) {
    in[v] = ++t;
    for(auto u: g[v]) {
    	if(u!=p){
	        head[u] = (u == g[v][0] ? head[v] : u);
	        dfs_hld(u,v);
    	}
    }
    out[v] = t;
}

bool is_ancestor(int par, int child){
	if(par == 0) return true;
	if(child == 0) return false;
	if(in[par]<=in[child] and out[par]>=out[child]) return true;
	return false;
}
SegTree st;
data query(int a,int b){
	data res();
	for(;head[a]!=head[b];b=parent[head[b]]){
		if(depth[head[a]] >depth[head[b]])
			swap(a,b);
		data cur = st.query(in[head[b]],in[b]);
		st.merge(res, res, cur);
	}
	if(depth[a]>depth[b])
		swap(a,b);
	data last = st.query(in[a],in[b]);
	st.merge(res, res, last);
	return res;
}