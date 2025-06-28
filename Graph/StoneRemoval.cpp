// ----======<<<<<"IMPORTANT">>>>>======------
/*
 * How many stones can we remove that have more than one stone in their row or column
 * 
 * Focussing on the ultimate parent, create disjoint set
 * ....
 * ....
 *
 * We simply count the number of components, each components all the stones can be removed except the last stone which will remain alone
 *
 * Total number of stones - Total number of component will give us the answer
 */
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
	public:
		vector<int>parent,rank,size;
		DisjointSet(int n);
		int findUPar(int node);
		void unionBySize(int u,int v);
		void unionByRank(int u,int v);
};
DisjointSet::DisjointSet(int n){
	parent.resize(n+1);
	rank.resize(n+1,0);
	size.resize(n+1,1);
	for(int i=0;i<=n;i++)
		parent[i]=i;
}
int DisjointSet::findUPar(int node){
	if(node==parent[node])return node;
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
		size[ulp_u]+=size[ulp_v];
	}
}
void DisjointSet::unionByRank(int u,int v)
{
	
}
int main(){
	vector<vector<int>>grid={{1,0,1,0},
				 {0,0,0,1},
				 {0,0,0,0},
				 {1,0,1,0},
				 {0,0,0,1}};
	// Say if we were given the coordinates of stones
	vector<vector<int>>stones={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
	// Now we have to find the maximum column and row that the stone coordinates fo till
	int maxCol=0;
	int maxRow=0;
	for(auto it:stones)
	{
		maxCol=max(maxCol,it[1]);
		maxRow=max(maxRow,it[0]);
	}

//	int row=grid.size();
//	int col=grid[0].size();
//      Convert this grid into DisjointSet
//
	DisjointSet ds(maxRow+maxCol+1);
//	for each cell.. check in it's row i and col j all must have same uPar
//	Not each cell rather a more efficient approach we consider "a row itself as a node" and "a col as the subsequent node of the set"
//	for(int i=0;i<maxRow;i++)
//	{
//		for(int t=0;t<maxCol;t++)
//		{
//			if(grid[i][t]==1){
//				ds.unionBySize(i,maxRow+t);
//			}
//		}
//	}
	unordered_map<int,int>stoneNodes;
	for(auto it:stones)
	{
		int nrow=it[0];
		int ncol=it[1]+maxRow+1;	
		ds.unionBySize(nrow,ncol);	
		stoneNodes[nrow]=1;
		stoneNodes[ncol]=1;
	}
	int cnt=0;
	for(auto it:stoneNodes){
		if(ds.findUPar(it.first)==it.first){
			cnt++;
		}
	}
	cout<<stoneNodes.size()-cnt<<endl;
//	for(auto it:ds.parent)
//		cout<<it<<",";
	return 0;
}
