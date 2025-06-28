#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
	vector<int>rank,size,parent;
	public:
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

int DisjointSet::findUPar(int node){
	if(node==parent[node]) return node;
	else return parent[node]=findUPar(parent[node]); // will first assign and then return parent[node]
}
void DisjointSet::unionByRank(int u,int v)
{
	int ulp_u=findUPar(u);
	int ulp_v=findUPar(v);

	if(ulp_u<ulp_v)
	{
		parent[ulp_u]=ulp_v;
	}
	else if(ulp_u>ulp_v)
	{
		parent[ulp_v]=ulp_u;
	}
	else{
		parent[ulp_v]=ulp_u;
		rank[ulp_u]++;
	}
}
int main(){
	int V=7;
	vector<vector<int>>adj={{0,1,0,0,0,0,0},
				{1,0,1,0,0,0,0},
				{0,1,0,0,0,0,0},
				{0,0,0,0,1,0,0},
				{0,0,0,1,0,0,0},
				{0,0,0,0,0,0,1},
				{0,0,0,0,0,1,0}};
//	printAdjMatGraph
	DisjointSet ds(V+1);
	for(int i=0;i<V;i++)
		for(int j=i;j<V;j++)
			if(adj[i][j]==1){ds.unionByRank(i,j);
			cout<<i<<","<<j<<" added"<<endl;}
	int n=0;
//	for(int i=1;i<V;i++){
//		cout<<ds.findUPar(i)<<":";
/*		if(ds.findUPar(i-1)!=ds.findUPar(i))
 *		*/
	for(int i=0;i<V;i++){
		if(ds.findUPar(i)==i){ // We could have declared parent as public access specifier then use "if(ds.parent[i]==i){"
//			cout<<ds.findUPar(i)<<",";
//
			n++;
	}
		
	}
	cout<<n<<endl;

	return 0;
}
