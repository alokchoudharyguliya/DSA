#include<bits/stdc++.h>

using namespace std;

class DisjointSet{
	public:
		vector<int>rank, size, parent;
		DisjointSet(int n);
		int findUPar(int node);
		void unionByRank(int u, int v);
		void unionBySize(int u, int v);
};
DisjointSet(){
	rank.resize(n+1,0);
	size.resize(n+1,1);
	parent.resize(n+1);
	for(int i=0;i<n;i++)
		parent[i]=i;
}
int DisjointSet::findUPar(int node){
	if(node==parent[node])
		return node;
	return parent[node]=findUPar(parent[node]);
}
void DisjointSet::unionBySize(int u,int v){
	int ulp_u=findUPar(u);
	int ulp_v=findUPar(v);
	if(ulp_u==ulp_v)return;
	if(size[ulp_u]<size[ulp_v])
	{
		parent[ulp_u]=ulp_v;
		size[ulp_v]+=size[ulp_u];
	}
	else{
		parent[ulp_v]=ulp_u;
		size[ulp_u]=+size[ulp_v];
	}
}
void DisjointSet::unionByRank(int u,int v){
	int ulp_u=findUPar(u);
	int ulp_v=findUPar(v);
	if(ulp_u==ulp_v) return;
	if(rank[ulp_u]<rank[ulp_v])
	{
		parent[ulp_u]=ulp_v;
	}
	else if(rank[ulp_u]>rank[ulp_v]){
		parent[ulp_v]=ulp_u;
	}
	else{
		parent[ulp_v]=ulp_u;
		rank[ulp_u]++;		
	}
}
int main(){
		
	return 0;
}
