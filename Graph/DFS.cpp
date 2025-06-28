#include<bits/stdc++.h>
using namespace std;

// Instead of explicitly defining a graph using vector, let's define a class
class Graph{
	int V;
	list<int>*adj;
	void DFSUtil(int v, bool visited[]);
	public:
		Graph(int V);
		void addEdge(int v,int w);
		void DFS(int v);
		void BFS(int v);
};
Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
	// this is not like the vector representation and it is a linkedlist representation

}
// This is the external declaration of a function aka method i.e. addEdge
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}
void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v]=true;
	cout<<v<<" ";
	// VERY IMPORTANT TO REMEMBER -> ITERATOR DECLARATION FOR A LIST
	list<int>::iterator i;
	// Here we start with the adjacency list representation of v which is specified by user and then for each of it's neighbor perform DFS recursively mark as visited also.
	for(i=adj[v].begin();i!=adj[v].end();i++)
		if(!visited[*i]){
//			visited=true;
			DFSUtil(*i, visited);
		}
}
void Graph::DFS(int v)
{
	// note that here V is a member attribute and not any other variable and is privately accessible that is for a class private is the default access specifier while for struct it is public
	bool*visited= new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	DFSUtil(v,visited);
}

void Graph::BFS(int v)
{
	// so we have V and adj as private members that we can use anywhere inside class methods
	// for BFS we need a Visited array and a Queue
	// initialize the visited array as 0 or false
	bool visited[V]={false};
	//	or 
	//	bool*visited=new bool[false];

	// now we need a queue
	queue<int>q;
	visited[v]=true;
	q.push(v);
	while(!q.empty())
	{
	int node=q.front();
	cout<<node<<",";
	q.pop();
	list<int>::iterator i;

	for(i=adj[node].begin();i!=adj[node].end();i++){
		if(!visited[*i]){
			visited[*i]=true;
			q.push(*i);
		}
	}
	}
}
// Basic Idea of DFS is to recursively or using a stack to go to last/depth, backtrack from there and then try for other non-visited neighbor
//
// Here our basic approach is to define a graph using linkedlist 
// initialize the list when creating a object of the class Graph that is defining the nodes/vertices but yet not connected
// now inside the graph we need to add the edges
//
// We define a DFS method that needs a DFSUtil function to use for making recursive calls
// * also note that there we need a pass by reference visited array declared as bool* visited = new bool[V]; that is a pointer to an array of bools pass it as it is that is DFSUtil(v,visited);
int main(){
 	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	g.DFS(2);
	g.BFS(2);
	return 0;
}
