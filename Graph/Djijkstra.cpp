#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
// Numerical value binary 00111111 ~1e9 declared as a very large number

// typedef ===> Integer Pair
typedef pair<int,int>iPair;
// we store the graph as adjacency list storing the (dest,weight) for each node 
void addEdge(vector<pair<int,int>>adj[],int u,int v,int wt)
{
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}

void shortestPath(vector<pair<int,int>>adj[], int V,int src){

       //	define a priority queue
       //	just like queue is a keepInMind in case of a BFS Traversal here a priority queue is, aka min-heap implemented using priority_queue
       //	But why does we need a priority queue and on which basis do we take priority of, we could have used a simple queue ?
       //	But no, we need a priority queue to select the next neighbor which is the closest to the current node and not any other
       priority_queue<iPair,vector<iPair>,greater<iPair>>pq;
	// Now for storing the distances create a vector that will store single source shortest distances of any X node to all the other nodes
	vector<int>dist(V,INF);
	// Insert source itself in priority queue and initialise its distance as 0
	pq.push(make_pair(0,src));
	dist[src]=0;

	while(!pq.empty())
	{
	// The first vertex in pair is the minimum distance vertex, extract it from priority queue
	// Vertex label is stored in second of pair, it has to be done this way to keep the vertices stored distance (distance must be first item in pair) 
	// we cannot use Vertex labels as the sorting parameter
	int u=pq.top().second; // which is the label of the closest next neighbor node
	pq.pop();

	// Now we need to get all the adjacents of this closest nodes
		for(auto x:adj[u])
		{
			int v=x.first;
			int weight=x.second;
			if(dist[v]>dist[u]+weight)
			{
				dist[v]=dist[u]+weight;
				pq.push(make_pair(dist[u], v));
			}
		}
	}
	printf("Vertex Distance from Source");
	for(int i=0;i<V;i++)
		printf("%d\t\t%d\n",i,dist[i]);
}

int main(){
	int V=9;
	vector<iPair>adj[V];
	addEdge(adj,0,1,4);
	addEdge(adj,0,7,8);
	addEdge(adj,1,2,8);
	addEdge(adj,1,7,11);
	addEdge(adj,2,3,7);
	addEdge(adj,2,8,2);
	addEdge(adj,2,5,4);
	addEdge(adj,3,4,9);
	addEdge(adj,3,5,14);
	addEdge(adj,4,5,10);
	addEdge(adj,5,6,2);
	addEdge(adj,6,7,1);
	addEdge(adj,6,8,6);
	addEdge(adj,7,8,7);
	shortestPath(adj,V,0);
	return 0;
}

