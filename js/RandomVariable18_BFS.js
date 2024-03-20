//Queue  to be used for BFS
class Queue{
	
	/* front()           back()
	 *        \          /
	 * 		    |---|---|-
	 *Pop() --->| 2 | 3 | 5 <---Push(5)
    *deletes 2  |---|---|-
    * 
	  */
	  
	constructor()
	{
		this._data=[];
		this._length=0;
	}
	push(val)
	{
		this._data.push(val);
		this._length++;
	}
	pop()
	{
		if(this._data.length!=0)
		{
			this._length--;
			return this._data.shift();
		}
		return null;
	}
	front()
	{
		if(this._data.length!=0)
			return this._data[0];
		return null;	
	}
	back()
	{
		return this._data[this._length-1]
	}
	
	isEmpty()
	{
		return this._data.length==0;
	}
};

////Class for Graph
class Graph{
	constructor(N,directed=false)
	{
		this._numOfNodes=N;
		this.adj=new Array(N);
		this._numOfEdges=0;
		this._isDirected=directed;
		for(let i=1;i<=this._numOfNodes;i++)
		{
			this.adj[i]=[];
		}
	}
	add_edge(u,v)
	{
		this.adj[u].push(v);
		this._numOfEdges++;
		if(!this.directed)
		{
			this.adj[v].push(u);
		}
	}
	// Maintains the number of nodes
	get number_of_nodes()
	{
		return this._numOfNodes;
	}
	// Maintains the number of edges
	get number_of_edges()
	{
		return this._numOfEdges;
	}
	// BFS
	BFS(root=1)
	{
		let Q=new Queue();
		Q.push(root);
		let visited=[];
		for(let i=1;i<=this._numOfNodes;i++)
		{
			visited[i]=false;
		}
		visited[root]=true;
		
		/*
		 * First we take the root  O
		 * Then we take the first level 
		 *         O
		 * 		  / \
		 *       O   O   <---Level 1
		 * Then the second level for the first adjacent node
		 * 
		 * 		  O
		 *       / \
		 *      O   O    <--- Level 1
 		 *     /|\
		 *    O O O      <--- Level 2
		 * Then the second level for the second adjacent node and so on...
		 */
	
		while(!Q.isEmpty())
		{
			let node = Q.pop();
			
			console.log(node);
			for(let i=0;i<this.adj[node].length;i++)
			{
				if(!visited[this.adj[node][i]])
				{
					Q.push(this.adj[node][i]);
					visited[this.adj[node][i]]=true;
				}
			}
		}
	}
};


G=new Graph(5);
G.add_edge(1,2);
G.add_edge(1,3);
G.add_edge(3,4);
G.add_edge(2,4);
G.add_edge(3,5);
G.BFS(1);
//This is the simple graph
//   1
//  / \
//  2  3
//   \ /\
//    4  5 
