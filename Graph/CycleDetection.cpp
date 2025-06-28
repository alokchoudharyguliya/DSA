// Firstly consider are there any differences between cycle detection in directed VS undirected graphs??
// Approach: DFS can detect cycle in a graph but how?
// DFS of a connected graph produces a tree. 
// There is a cycle in a graph only if there is a back edge present in the graph.
// A back edge is an edge that is from a node to itself(self-loop) or one of its ancestor in the tree produced by DFS in the graph. The number of back-edges is same as the number of cycles
// Hence, the question can be twisted as ``find the number of back-edges``
// Now how to detect a back edge, we can keep track of vertices currently in recursion stack of function for DFS traversal. If we reach a vertex that is already in the recursion stack, then there is a cycle in the tree. 
// The edge that connects current vertex to the vertex in the recursion stack is a back edge. We can auxiliary array say, recStack[] to keep track of vertices in the recursion stack.
//
// Therefore for every visited vertex 'v' if there is an adjacent 'u' such that u is already visited and u is not a parent of v, then there is a cycle in the graph. If we don't find such an adjacent for any vertex, we say that there is no cycle.
//
// Will work for both directed and undirected graph.

#include<iostream>
#include<list>
// LIMITS.H
#include<limits.h>

using namespace std;
class Graph{
	int V;
	list<int>*adj;
	bool isCyclicUtil(int v, bool visited[], bool*rs);
	public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool*recStack)
{
	// check only if the node is not visited
	if(visited[v]==false)
	{
		// mark this node as visited and part of recursionStack
		visited[v]=true;
		recStack[v]=true;
		list<int>::iterator i;
		// now i have a node in my hand i have to recursively call for DFS and the cycle is found if the particular node is present inside the stack or we reached a visited node or there is any cycle in the child subtree DFS
		for(i=adj[v].begin();i!=adj[v].end();i++)
		{
			if(!visited[*i] && isCyclicUtil(*i, visited, recStack))
				return true;
			else if(recStack[*i])
				return true;
		}
	}
	recStack[v]=false;
	return false;
}
bool Graph::isCyclic(){
	// as it is DFS approach so we need a visited array 
	// and for this particular approach we will be simply storing recursiveStack as which all nodes were present inside the recursive call and not the actual names
	bool *visited=new bool[V];
	bool *recStack=new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
		recStack[i]=false;
	}
	// now for each of the node we call DFS to check for any cycle
	for(int i=0;i<V;i++)
		if(isCyclicUtil(i,visited,recStack))
				return true;
	return false;
}
int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	g.isCyclic()?cout<<"Graph contains cycle":cout<<"Graph doesn't contain cycle";
	return 0;
}
