#include<bits/stdc++.h>
using namespace std;
// for BFS we will need a Queue for storing the ahead childs that is the childs in the next level whil we traverse the current level
// also so in case of graph so that we don't consider a parent as neighbor ahead we need a Visited array
void addEdge(vector<int>adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int>adj[],int V)
{
	// Here we use a simple approach of printing each array element which is a vector of the array of vertex
	for(int v=1;v<=V;v++)
	{
	cout<<"Adjacency List of vertex "<<v<<" is ";
	for(auto i:adj[v])
		cout<<i<<",";
	cout<<endl;
	}
}
void BFS(vector<int> adj[],int V){
	bool visited[V+1];
	for(int i=1;i<=V;i++)
	visited[i]=false;
	queue<int>q;
	// explicitly store the root node into the queue and start a loop, keep enqueuing neighbor elements till the queue gets empty

	int s=1;
	visited[s]=true;
	q.push(s);
	while(!q.empty())
	{
	int node=q.front();
	q.pop();
	cout<<node<<" ";
	for(int i=0;i<adj[node].size();i++)
		if(visited[adj[node][i]]==false){
			visited[adj[node][i]]=true;
			q.push(adj[node][i]);
		}
	}
}
int main(){
	//Here we are using 1-based indexing so we need to take one more than number of vertices
	int V=6;
	vector<int>adj[V+1];
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,2,4);
	addEdge(adj,2,5);
	addEdge(adj,3,5);
	addEdge(adj,4,5);
	addEdge(adj,4,6);
	addEdge(adj,5,6);
	printGraph(adj,V);
	BFS(adj,V);

	return 0;
}
