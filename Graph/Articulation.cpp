// Concept lies in finding even after removal of this node can i 
// Bridge in a graph - Any edge whose removal breaks down the graph into two or more components.
//
#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int>*adj;
	void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[])
	public:
		Graph(int V);
		void addEdge(int v, int w);
		void AP();
};

Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

// A recursive function that find articulation points using DFS traversal
// u --> the vertex to be visited next
// visited[]-->keeps tract of visited vertices
// disc[]-->Stores discovery times of visited vertices
// parent[]-->stores parent vertices in DFS tree
// ap[]-->store articulation points
//
void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[],bool ap[])
{
	static int time=0;
	int children=0;
	visited[u]=true;
	disc[u]=low[u]=++time;

	list<int>::iterator i;
	for(i=adj[u].begin();i!=adj[u].end();++i)
	{
		int v*=i;
		if(!visited[v])
		{
			children++;
			parent[v]=u;
			APUtil(v,visited,disc,low,parent,ap);
			low[u]=min(low[u],low[v]);

			if(parent[u]==NULL&&
		}
	}
}

int main(){

	return 0;
}
