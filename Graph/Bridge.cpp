// For every edge (u,v), do following
// 	- Remove (u,v) from graph
// 	- See if graph remains connected (We can either use BFS or DFS)
// 	- Add (u,v) back to the graph

// We do DFS traversal of the given graph. In DFS tree an edge (u,v) (u is parent of v in DFS tree) is bridge if there does not exist any other alternative to reach u or an ancestor of u from subtree rooted with v. 

// The value of low[v] indicates earliest visited vertex reachable from subtree rooted with v. The condition for an edge (u,v) to a bridge is, "low[v] > disc[u]"
#include<bits/stdc++.h>
using namespace std;

// we need to track the DFS timings that is when we faced a node in DFS traversal = tim[]
// min lowest time insertion of all adjacent node apart from parent = low[] 

class Graph{
	int V;
	list<int>*adj;
	vector<int>parent;
	void bridgeUtil(int v, bool visited[], int disc[], int low[]);
	public:
		Graph(int V);
		void addEdge(int v, int w);
		void bridge();
		void DFS();
};

Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}
/*
 * A recursive function that finds and prints bridges using DFS traversal
 * u-> THe vertex to be visited next
 * visited[]-> Keeps tract of visisted vertices
 * disc[]-> sotres discovery times of visited vertices
 * parent[]-> sotres parent vertices in DFS tree
 *
 */
void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[])
{
	static int time=0;
	visited[u]=true;
	disc[u]=low[u]=++time;
	list<int>::iterator i;
	for(i=adj[u].begin();i!=adj[u].end();i++)
	{
		int v=*i; // v is current adjacent of u
		if(!visited[*i])
		{
			parent[v]=u;
			bridgeUtil(v,visited,disc,low);

			low[u]=min(low[u],low[v]);
			if(low[v]>disc[u])
				cout<<u<<" "<<v<<endl;
		}
		else if(v!=parent[u]){	
			low[u]=min(low[u],disc[v]);
		}
	}

}

// DFS based function to find all bridges
// It uses recursive function bridgeUtil()
void Graph::bridge(){
	bool*visited=new bool[V];
	int*disc=new int[V];
	int*low=new int[V];
//	int*parent=new int[V];

	for(int i=0;i<V;i++)
	{		parent.push_back(-1);
		visited[i]=false;
	}
	for(int i=0;i<V;i++)
	{	
//		cout<<i;
		if(visited[i]==false){
			bridgeUtil(i, visited, disc, low);
		}
	}

}
void DFS(){

}
int main()
{
  // Create graphs given in above diagrams
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.bridge();

    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.bridge();

    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.bridge();
	
	return 0;
}

/*
 * DFS 
 *
 *
 * time[] - DFS time insertion, the step when you reach a node
 * low[] - min lowest time insertion of all adjacent nodes apart from parent, lowest of all the times of insertion, but don't considering the "parent"
 */
