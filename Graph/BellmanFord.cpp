#include<bits/stdc++.h>
using namespace std;

// New approach of creating a graph
// Define Edge
// Use Edge inside the Graph
// Edge consist of src, dest, weight members integers
// Graph consist of number of Vertices and number of Edges and a Edge pointer to the next edge
// Now creating the Graph using these parts
struct Edge{
	int src,dest,weight;
};

struct Graph{
	int V,E;
	struct Edge*edge;
};
struct Graph* createGraph(int V,int E)
{
	// this function returns a pointer to the structure Graph
	struct Graph* graph=new Graph; // here we have created a pointer and made it to point to a new Structure, in C we used to use malloc to allocate memory space and here we use new keyword
	// Of the struct's V and E we want to give some value that is the number of vertices and the number of edges
	// what about the edge pointer, the edge pointer simply points to a array of edges that is a array of struct Edges where Edge struct have src, dest, weight
	graph->V=V;
	graph->E=E;
	graph->edge=new Edge[E];
	return graph;
}

void printArr(int dist[],int n){
	printf("Vertex Distance from source");
	for(int i=0;i<n;i++)
		printf("%d\t\t%d\n",i,dist[i]);
}

void BellmanFord(struct Graph*graph,int src)
{
	// Calculate shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph.
	// Do following for each edge u-v:
	// 	If dist[v] > dist[u] + weight of edge uv, then update dist[v] as dist[v] = dist[u]+weigh of edge uv
	// Report if there is a negative weight cycle in graph. Do following for each edge u-v. If dist[v] > dist[u]+weight of edge uv, then "Graph contains negative weight cycle".
	//
	int V=graph->V;
	int E=graph->E;
	// Either use this
	// vector<int>dist(V,INT_MAX);
	int dist[V];

	for(int i=0;i<V;i++)
		dist[i]=INT_MAX;
	// Initiate it from somewhere
	dist[src]=0;
	// Relax all edges |V|-1 times. A simple shortest path from src to any other vertex can have at-most |V| edges
	// KEEP IN MIND: Run a loop V-1 times
	for(int i=1;i<=V-1;i++)
	{
		for(int j=0;j<E;j++)
		{
			int u=graph->edge[j].src;
			int v=graph->edge[j].dest;
			int weight=graph->edge[j].weight;
			if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
				dist[v]=dist[u]+weight;
		}
	}
	// Check for negative cycles. Above step guarantees shortest distances if graph doesn't contain negative weight cycle. If we get a shorter path, then there is a cycle.
	for(int i=0;i<E;i++)
	{
		int u=graph->edge[i].src;
		int v=graph->edge[i].dest;
		int weight=graph->edge[i].weight;
		if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
			printf("Graph contains negative weight cycle");
	}
	printArr(dist,V);

}
int main()
{
	int V=5;
	int E=8;
	struct Graph*graph=createGraph(V,E);
	graph->edge[0].src=0;
	graph->edge[0].dest=1;
	graph->edge[0].weight=-1;


    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
	
    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
	BellmanFord(graph,0);
	return 0;
}
