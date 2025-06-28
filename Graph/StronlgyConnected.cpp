#include<bits/stdc++.h>
// Connected Component approach-super easy considering that we have numbers present on the nodes, so we simply run for loop, taking a unvisited arrray
using namespace std;
class Graph{
	int V;// No. of vertices
	list<int>*adj; // Pointer to array containing adjacency lists
	void DFSUtil(int v, bool visited[]);
	public:
	Graph(int V);
	void addEdge(int v, int w);
	void connectedComponents();
};
void Graph::connectedComponents(){
	bool*visited=new bool[V];
	for(int v=0;v<V;v++)
		visited[v]=false;

	for(int v=0;v<V;v++){
		if(visited[v]==false){
			DFSUtil(v,visited);
			cout<<endl;
	}
	}
	// cout<<endl;
}
void Graph::DFSUtil(int v,bool visited[]){
	visited[v]=true;
	cout<<v<<" ";
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
		if(!visited[*i])
			DFSUtil(*i, visited);
}
Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
int main(){
	Graph g(5);
	g.addEdge(1,0);
	g.addEdge(1,2);
	g.addEdge(3,4);
	g.connectedComponents();
	return 0;
}
