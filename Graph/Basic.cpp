#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int u,int v){
	(adj[u].push_back(v));
	(adj[v].push_back(u));
}
void printGraph(vector<int>adj[],int V){
	for(int v=0;v<V;v++)
	{
		cout<<"Adjacency List of Vertex "<<v;
		for(auto X:adj[v])cout<<"->"<<X;
		printf("\n");
	}
}


int main(){

	int V=5;
	vector<int> adj[V];
	// this is a array of vectors;
	// There can be two representations of a graph
	// 1. Adjacency Matrix - direct representation of weights
	// 	how much weight between which two nodes
	// 	0   1   2   3
	//   0  0   1   1   1
	//   1	    0   
	//   2		0
	//   3		    0
	//
	// 2. Adjacency List 
	//
	//  0-> connected to whom
	//
	//  0->[1,2]
	//  1->[0,2]
	//  2->[0,1]
	//
	addEdge(adj,0,1);
	addEdge(adj,0,4);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,2,3);
	addEdge(adj,3,4);
	// above graph in adjacency list will be represented as
	// 0->1,4
	// 1->0,2,3,4
	// 2->1,3
	// 3->1,2,4
	// 4->0,1,3
	printGraph(adj,V);
	return 0;
}

