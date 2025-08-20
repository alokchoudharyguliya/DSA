// Disjoint set
// findPeer() & Union()
//
// Rank array[]
// Parent array[]
//
// 1. Find ultimate parent of node u & v
// 2. Find rank of those ultimate parents
// 3. Connect smaller rank to larger rank always
#include<bits/stdc++.h>
using namespace std;
// parent={0,1,2,3,4,5};

// Why to attach smaller to larger?
// 1. Because the height doesnot increase when we do so.
// 2. Also, the traversal time is lesser compared to if do the opposite.

// There can be two union approaches that is "UNION BY RANK" and "UNION BY SIZE"
class DisjointSet{
	public:
	vector<int>rank,parent,size;
	DisjointSet(int n);
	int findUPar(int node);
	void unionByRank(int u,int v);
	void unionBySize(int u,int v);
};

void DisjointSet::unionByRank(int u,int v)
{
	int ulp_u=findUPar(u);
	int ulp_v=findUPar(v);
	if(ulp_u==ulp_v) return;
	if(rank[ulp_v]>rank[ulp_u])
		parent[ulp_u]=ulp_v;
	else if(rank[ulp_v]<rank[ulp_u]){
			parent[ulp_v]=ulp_u;
	}
	else{
			parent[ulp_v]=ulp_u;
			rank[ulp_u]++;
	}

}
void DisjointSet::unionBySize(int u,int v){
	int ulp_v=findUPar(v);
	int ulp_u=findUPar(u);

	if(ulp_u==ulp_v)return;

	if(size[ulp_v]<=size[ulp_u]){
		parent[ulp_v]=ulp_u;
		size[ulp_u]+=size[ulp_v];
	}
	else{
		parent[ulp_u]=ulp_v;
		size[ulp_v]+=size[ulp_u];
	}
		
}
int DisjointSet::findUPar(int node)
{
	if(node==parent[node])
		return node;
	else return parent[node]=findUPar(parent[node]); //alongside path compression
}
DisjointSet::DisjointSet(int n){
	rank.resize(n+1,0);
	size.resize(n+1,1);
	parent.resize(n+1);
	for(int i=0;i<=n;i++)
	{
		parent[i]=i;
	}
}

/* void addEdge(vector<int>adj[], int a, int b,vector<int>parent){
	parent[a]=b;
	rank[b]=rank
	adj[a].push_back(b);
}*/	

int main(){
//	vector<int>adj[];
//	vector<int>rank(V,0);
//	addEdge(0,1);
	DisjointSet ds(7);
	// ds.unionByRank(1,2);
	// ds.unionByRank(2,3);
	// ds.unionByRank(4,5);
	// ds.unionByRank(6,7);
	// ds.unionByRank(5,6);

	
	ds.unionBySize(1,2);
	ds.unionBySize(2,3);
	ds.unionBySize(4,5);
	ds.unionBySize(6,7);
	ds.unionBySize(5,6);
	for(int i=0;i<ds.rank.size();i++)
	{
		cout<<ds.rank[i];
	}
	cout<<endl;
	for(int i=0;i<ds.size.size();i++)
	{
		cout<<ds.size[i];
	}
	cout<<endl;
	// check 3 and 7
		if(ds.findUPar(3)==ds.findUPar(7)){
	cout<<"Same"<<endl;
	}
	else{
		cout<<"Not Same"<<endl;
	}
	ds.unionByRank(3,7);
	if(ds.findUPar(3)==ds.findUPar(7)){
	cout<<"Same"<<endl;
	}
	else{
		cout<<"Not Same"<<endl;
	}

return 0;
}
