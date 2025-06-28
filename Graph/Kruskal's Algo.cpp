// Logic "We sort the edges and then start creating a MST by taking unions"
//  	 "Union will ensure that we don't connect edges having same ultimate parent"
//  	 "Thus finally we'll get a Minimum Spanning Tree"
// Time complexity here is represented in terms of "alpha"
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
		vector<int>rank,parent,size;
	public:
		DisjointSet(int n);
		int findUPar(int node);
		void unionByRank(int u,int v);
};

DisjointSet::DisjointSet(int n){
	rank.resize(n+1,0);
	parent.resize(n+1);
	for(int i=0;i<=n;i++)
	{
		parent[i]=i;
	}
}

int DisjointSet::findUPar(int node){
	if(parent[node]==node)
		return node;
	else return parent[node]=findUPar(parent[node]);

}

void DisjointSet::unionByRank(int u,int v){
	int ulp_u=findUPar(u);
	int ulp_v=findUPar(v);
	if(ulp_u==ulp_v) return;
	if(rank[ulp_u]<rank[ulp_v]){
		parent[ulp_u]=ulp_v;
	}
	else if(rank[ulp_u]>rank[ulp_v])
	{
		parent[ulp_v]=ulp_u;
	}
	else{
		parent[ulp_v]=ulp_u;
		rank[ulp_u]++;
	}
}
void addEdge(vector<pair<int,int>>adj[],int u,int v,int wt){
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}

void printGraph(vector<pair<int,int>>adj[],int V)
{
	for(int j=0;j<V;j++)
	{
		cout<<j<<"->";
		vector<pair<int,int>>::iterator it;
		for(it=adj[j].begin();it!=adj[j].end();it++)
		{
			cout<<"{"<<(*it).first<<","<<(*it).second<<"}";
		}
		cout<<endl;
	}
}
// storing 1:=[{4,1},{2,2}]
// 	   2:=[{1,2}]
// 	   4:=[{1,1}]

int spanningTree(int V, vector<pair<int,int>>adj[]){
	vector<pair<int,pair<int,int>>> edges;// NOTE: EDGES - "vector<pair<int,pair<int,int>>>edges;"
	for(int i=0;i<V;i++)
	{
		for(auto it:adj[i])
		{
			int adjNode=it.first;
			int wt=it.second; 
			int node=i;

			//edges.push_back(make_pair(wt,make_pair(node,adjNode)));
			edges.push_back({wt,{node,adjNode}});
		}
	}
	for(int i=0;i<V;i++)
	{
		cout<<"{"<<edges[i].first<<","<<edges[i].second.first<<","<<edges[i].second.second<<"}"<<endl;
	}
	
	sort(edges.begin(),edges.end());
	for(int i=0;i<V;i++)
	{
		cout<<"{"<<edges[i].first<<","<<edges[i].second.first<<","<<edges[i].second.second<<"}"<<endl;
	}
	int mstWt=0;
	DisjointSet ds(V);
	for(auto it:edges){
		int wt=it.first;
		int u=it.second.first;
		int v=it.second.second;
		
		if(ds.findUPar(u)!=ds.findUPar(v)){
			ds.unionByRank(u,v);
			mstWt+=wt;
		}
	}
	return mstWt;
}
int main(){
	int V=7;
	vector<pair<int,int>>adj[V];
	addEdge(adj,1,2,2);
	addEdge(adj,4,5,9);
	addEdge(adj,1,5,4);	
	addEdge(adj,2,4,3);
	addEdge(adj,4,3,5);
	addEdge(adj,3,6,8);
	addEdge(adj,2,6,7);
	addEdge(adj,3,2,3);
	addEdge(adj,1,4,1);
	printGraph(adj,V);
	cout<<spanningTree(V,adj)<<endl;
	return 0;
}
