#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
	public:
		vector<int> parent, rank, size;
		DisjointSet(int n);
		int findUPar(int node);
		void unionByRank(int u,int v);
		void unionBySize(int u,int v);

};
DisjointSet::DisjointSet(int n)
{	
	rank.resize(n+1,0);
	size.resize(n+1,1);
	for(int i=0;i<=n;i++)
		parent.push(i);
}
int findUPar(int node)
{
	if(node==parent[node])
		return node;
	return parent[node]=findUPar(parent[node]);
}


int main(){

	return 0;
}
