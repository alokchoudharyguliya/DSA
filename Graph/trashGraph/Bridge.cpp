#include<bits/stdc++.h>
using namespace std;
#define NIL -1
class Graph{
	public:
	int V;
	vector<int>vis;
	vector<vector<int>>adj;	
	Graph(int V){
		this->V=V;
		adj.resize(V);
	}

	void addEdge(int u,int v);
	void DFS(int node);
	void BFS(int V);
	void DFSUtil(int i, vector<int>&v);
	void bridge();
};
void Graph::bridgeUtil(){
	static int time=0;
	vis[u]=true;
	disc[u]=low[u]=++time;
	list<int>::iterator it;
	// for all vertices adjacent to the current node in the DFS Call
	for(i=adj[u].begin();i!=adj[u].end();i++)
	{
		int v=*i;
		if(!vis[i]){
			parent[v]=u;
			bridgeUtil(v,vis,disc,low,parent);
			low[u]=min(low[u],low[v]);
			if(low[v]>disc[u])
				cout<<u<<" "<<v<<endl;
		}
		else if(v!=parent[u]){
			low[u]=min(low[u],disc[v]);
		}
	}

}
void Graph::bridge(){
	bool*vis=new bool[V];
	int*low=new int[V];
	int*parent=new int[V];
	int*disc=new int[V];
	bridgeUtil();

}
void Graph::addEdge(int u,int v){
//	cout<<"Con";
	adj[u].push_back(v);
//	cout<<"tinue";
	adj[v].push_back(u);	

}
void Graph::DFSUtil(int i,vector<int>&vis){
	vis[i]=1;
	cout<<i<<",";
	for(auto it:adj[i])
		if(!vis[it]){
		//	cout<<it<<",";
			DFSUtil(it,vis);
		//	cout<<i<<",";
		}
}
void Graph::DFS(int src){
	vis.resize(V,0);
//	vis[src]=true;
//	cout<<src<<",";
	DFSUtil(src,vis);
}

void Graph::BFS(int src){
	vis.resize(V,0);
	vis[src]=1;
	cout<<src<<",";
	queue<int>q;
	q.push(src);
	while(!q.empty()){
	int node=q.front();
	q.pop();
		for(auto it:adj[node])
		{
			if(!vis[it]){
				q.push(it);
				vis[it]=1;
				cout<<it<<",";
			}
		}
	}
	for(int i=0;i<V;i++)
		vis[i]=0;
}

int main(){
	int V=7;
	Graph g(V);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,1);
	g.addEdge(1,6);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(4,5);
	g.addEdge(3,5);
	g.BFS(0);
	cout<<endl;
	g.DFS(0);
	return 0;}
