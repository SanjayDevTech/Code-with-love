// Java program to print DFS traversal from a given given graph 
import java.io.*; 
import java.util.*; 


class Graph 
{ 
	private int V; 

	
	private LinkedList<Integer> adj[]; 

	
	Graph(int v) 
	{ 
		V = v; 
		adj = new LinkedList[v]; 
		for (int i=0; i<v; ++i) 
			adj[i] = new LinkedList(); 
	} 

	
	void addEdge(int v, int w) 
	{ 
		adj[v].add(w); 
	} 

	
	void dfsUtil(int v,boolean visited[]) 
	{ 
		
		visited[v] = true; 
		System.out.print(v+" "); 

		
		Iterator<Integer> i = adj[v].listIterator(); 
		while (i.hasNext()) 
		{ 
			int n = i.next(); 
			if (!visited[n]) 
				dfsUtil(n, visited); 
		} 
	} 
    public void dfsTraversal(int v){
      	boolean visited[] = new boolean[V];   
      	dfsUtil(0, visited); 
    }
	
	

	public static void main(String args[]) 
	{ 
		Graph g = new Graph(4); 

		g.addEdge(0, 1); 
		g.addEdge(0, 2); 
		g.addEdge(1, 2); 
		g.addEdge(2, 0); 
		g.addEdge(2, 3); 
		g.addEdge(3, 3); 
	

		System.out.println("The Depth First Traversal is "); 
	    g.dfsTraversal(0);

		
	} 
} 
