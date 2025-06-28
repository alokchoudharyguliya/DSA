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
	vector<int>rank,parent;
	public:
	DisjointSet(int n);
	int findUPar(int node);
	void unionByRank(int u,int v);
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
void Disjoint::unionBySize(int u,int v){
	int ulp_v=findUPar(v);
	int ulp_u=findUPar(u);

	if(ulp_u==ulp_v)return;

	if(rank[ulp_u]<=rank[ulp_v]){
		parent[ulp_u]=ulp_v;
		size[ulp_v]+=size[ulp_u];
	}
	else{
		parent[ulp_v]=ulp_u;
		size[ulp_u]+=size[ulp_v];
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
	ds.unionByRank(1,2);
	ds.unionByRank(2,3);
	ds.unionByRank(4,5);
	ds.unionByRank(6,7);
	ds.unionByRank(5,6);
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
