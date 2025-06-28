#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>>adj[],int a, int b,int wt)
{
	adj[a].push_back({b,wt});
	adj[b].push_back(make_pair(a,wt));
}
void printAdjGraph(vector<pair<int,int>>adj[],int V)
{
// 	vector<int>::iterator i;
	for(int j=0;j<V;j++){
		
		// for(i=adj[j].begin();i!=adj[j].end();i++)
		for(auto i:adj[j])
			cout<<i.second<<",";
	cout<<endl;
	}
}
void shortestPath(int V,int src,vector<pair<int,int>>adj[]){
	// 1. Based on BFS
	// 2. Minimum to be selected from amongst the neighbors
	// 3. Use Min-Heap or Priority-Queue
	//
	// 4. distance vector
	vector<int>dist(V,INT_MAX);
	// will store (weight, neighbor label)
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	// now what ?
	// single src? and explore neighbors BFSly
	pq.push(make_pair(0,src));
	dist[src]=0;
	while(!pq.empty()){
	int node=pq.top().second;
//	cout<<node;
	pq.pop();
		// vector<>::iterator i;
		for(auto i:adj[node])
		{
			int wt=i.second;
			if(dist[i.first]>dist[node]+wt)
			{	dist[i.first]=dist[node]+wt;
				pq.push(make_pair(dist[i.first],i.first));
			}
		}
	}
	for(auto i:dist)
		cout<<i<<",";
}
// 1. Create the graph -> 2 approaches
// 	a. create separate class
// 	b. use vector<int> adj[] - adjacency list representation
int main()
{	
	int V=9;
	vector<pair<int,int>>adj[V];
	addEdge(adj,0,1,4);
	addEdge(adj,0,7,8);
	addEdge(adj,1,2,8);
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
	shortestPath(9,0,adj);
//	printAdjGraph(adj,V);
	return 0;
}
