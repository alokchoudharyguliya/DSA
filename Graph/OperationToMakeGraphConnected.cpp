// We need to make a component wise graph that is, having some components that are not connected, connected by using minimum number of existing edges
// Here we cannot use any of the edge rather we can only use edges that make a cycle to that is we cannot use bridges to make the graph connencted
#include<bits/stdc++.h>
using namespace std;

// Make Disjoint Graph and you will have some edges that won't be included in the disjoint graph, those will be the edges that make cycle, so we can simply use a count of these edges and that will be the answer

class DisjointSet{
	public:
	vector<int>rank, parent, size;
	DisjointSet(int n);
	int findUPar(int node);
	void unionByRank(int u,int v);
};

DisjointSet::DisjointSet(int n){
	parent.resize(n+1);
	rank.resize(n+1,0);
	for(int i=0;i<n;i++)
		parent[i]=i;
}
void DisjointSet::unionByRank(int u,int v){
	int ulp_u=findUPar(u);
	int ulp_v=findUPar(v);
	if(ulp_v==ulp_u)return;

	if(rank[ulp_u]<rank[ulp_v])
	{
		parent[ulp_u]=ulp_v;
	}
	else if(rank[ulp_u]>rank[ulp_v])
	{
		parent[ulp_v]=ulp_u;
	}
	else{
		parent[ulp_u]=ulp_v;
		rank[ulp_v]++;
	}
}

int DisjointSet::findUPar(int node){
	if(node==parent[node])return node;
	else return parent[node]=findUPar(parent[node]);
}

int main(){
	int V=9;
	vector<vector<int>>edge={{0,1},
				  {0,3},
				  {0,2},
				  {1,2},
				  {2,3},
				  {4,5},
				  {5,6},
				  {7,8}};
	DisjointSet ds(V);
	int cntExtras=0;
	for(auto it:edge)
		if(ds.findUPar(it[0])!=ds.findUPar(it[1]))
		ds.unionByRank(it[0],it[1]);
		else
			cntExtras++;
	int cnt=0;
	for(int i=0;i<V;i++)
		if(ds.parent[i]==i)
			cnt++;
	cntExtras==cnt-1?cout<<cntExtras:cout<<"Not Possible";
	
	return 0;
}
