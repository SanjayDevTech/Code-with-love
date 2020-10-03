#include<bits/stdc++.h>

using namespace std;

void fndepthfirstserach(int currentvertex,vector<int> &v,vector<vector<int>> g,int n)
{
	int i;
	//marking the starting vertex as visited
	v[currentvertex]=1;
	
	for(i=0;i<n;i++)
		//if the vertex that is connected to current vertex is not visited then applying DFS for that vertex
		if(g[currentvertex][i]&& !v[i])
			//here the starting vertex is the non visited vertex
			fndepthfirstserach(i,v,g,n);
}

int main(void)
{
	int i,j,k;
	int numvert,vert;
	
	cout<<"Enter the no. of vertices: ";
	cin>>numvert;
	
	vector<int> visited(numvert,0);
	vector<vector<int>> graph(numvert,vector<int>(numvert));
	
	cout<<"Enter the adjacency matrix here:\n";
	for(i=0;i<numvert;i++)
		for(j=0;j<numvert;j++)
			cin>>graph[i][j];
	
	cout<<"Enter the source vertex: ";
	cin>>vert;
	
	fndepthfirstserach(vert-1,visited,graph,numvert);
	
	for(k=0;k<numvert;k++)
	{	
		if(visited[k])
			cout<<"\n vertex "<<k+1<<" reachable\n";	
		else
			cout<<"\n vertex "<<k+1<<" not reachacble\n";
	}
	return 0;
}
