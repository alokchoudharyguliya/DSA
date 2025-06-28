// Prim's Algorithm - in simple words it simply from the present mstTree expands the tree by selecting those leaf nodes that have minimum edge weights ahead
//
// a Greedy Algorithm, starts with an empty spanning tree, idea is to maintain two sset of vertices. First set contains the vertices already included in the MST, the other set contains the vertices not yet included.
// At every step, it considers all the edges that connect the two sets, and picks the minimum weight edge from these edges. After picking the edge, it moves the other endpoint of the edge to the set containing MST.
//
#include<bits/stdc++.h>
using namespace std;

#define V 5

int minKey(int key[], bool mstSet[])
{
	int min=INT_MAX, min_index;
	for(int v=0;v<V;v++)
		if(mstSet[v]==false && key[v]<min)
			min=key[v], min_index=v;
	return min_index;
}

/* int printMST(int parent[], int graph[V][V])
{
	cout<<"Edge \t Weight\n";
	for(int i=1; i<V;i++)
		cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<"\n";
}
*/

//void primMST(int graph[V][V]){
void primMST(vector<pair<int,int>>graph[]){

	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
	vector<pair<int,int>>MST;
	vector<int>parent(V,-1);
	vector<bool> visited(V,	false);
	pq.push(make_pair(0,0)); // we will store weight on the first part of pair
	int sum=0;
	while(!pq.empty()){
	int node=pq.top().second;
	int weight=pq.top().first;
	pq.pop();

if(visited[node])continue; // ESPECIAL ONE
	visited[node]=true;
			sum+=weight;

//	if(pq.top().second!=-1){
//		MST.push_back({pq.top().second, parent[pq.top().second]});

//	}
		for(auto i:graph[node])
		{
			if(!visited[i.first]){
			pq.push(make_pair(i.second,i.first));
			}
		}
	}
	cout<<sum;
}
void addEdge(vector<pair<int,int>>adj[],int a,int b,int wt)
{
	adj[a].push_back({b,wt});
	adj[b].push_back({a,wt});
}
int main()
{
//	int V=5;
	// How is the graph represented?
	// A undirected weighted graph represented as adjacency Matrix
	int graph[V][V]={ { 0,2,0,6,0 },
			  { 2,0,3,8,5 },
			  { 0,3,0,0,7 },
			  { 6,8,0,0,9 },
			  { 0,5,7,9,0 } };
	vector<pair<int,int>>adj[V];
	addEdge(adj,0,1,2);
	addEdge(adj,0,3,6);
	addEdge(adj,1,2,3);
	addEdge(adj,1,3,8);
	addEdge(adj,1,4,5);
	addEdge(adj,2,4,7);
	addEdge(adj,3,4,9);
	// primMST(graph);
	primMST(adj),V;
	return 0;
}
