// --------------"GOOD QUESTION"-------------------
// On seeing the question we see components => Graph in intuition 
// Dynamically changing the graph and checking => Disjoint Set
//
// Making a Large Island
// Convert a sinlge 0 to 1 and find the size of larges Island possible 
//
// Convert the (row,col) matrix into cell numbers
// Try converitng all the other zeros or not even convert just look around
// Check if there has been any duplication of parent's by first storing them in a 'set' 
// Find size of adjacent neihbor's ultimate parent
//
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
	public:
		vector<int>rank, size, parent;
		DisjointSet(int n);
		int findUPar(int node);
		void unionBySize(int u,int v);
		void unionByRank(int u, int v);
};
DisjointSet::DisjointSet(int n){	
	rank.resize(n+1,0);
	size.resize(n+1,1);
	parent.resize(n+1);
	for(int i=0;i<n;i++)
		parent[i]=i;
}
int DisjointSet::findUPar(int node)
{
	if(node==parent[node])
		return node;
	return parent[node]=findUPar(parent[node]);
}
void DisjointSet::unionBySize(int u,int v){
	int ulp_u=findUPar(u);
	int ulp_v=findUPar(v);
	if(ulp_u==ulp_v) return;
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
bool isValid(int newr, int newc, int n){
	return newr>=0&&newc>=0&&newr<n&&newc<n;
}
int main(){
	vector<vector<int>>grid={{1,1,0,1,1},
				 {1,1,0,1,1},
				 {1,1,0,1,1},
				 {0,0,1,0,0},
				 {0,0,1,1,1},
				 {0,0,1,1,1}};
//	grid={{1,1},
//		{1,1}};
	
	int n=grid.size();
	DisjointSet ds(n*n);
 	for(int row=0;row<n;row++)
	{
		for(int col=0;col<n;col++)
		{
			if(grid[row][col]==0) continue;
			int dr[]={-1,0,1,0};
			int dc[]={0,-1,0,1};
			for(int i=0;i<4;i++)
			{
				int newr=row+dr[i];
				int newc=col+dc[i];
				if(isValid(newr,newc,n)&&grid[newr][newc]==1){
					// int noNode=row*n+col;
					// int newNode=newr*n+newc;
					 ds.unionBySize(newr*n+newc, row*n+col);
				}
			}
		}
	}
	int mx=0;
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			if(!grid[row][col]){
				int dr[]={-1,0,1,0};
				int dc[]={0,-1,0,1};
				set<int>components;// will store the ulitmate parent of the components
				for(int ind=0;ind<4;ind++)
				{
					int newr=row+dr[ind];
					int newc=col+dc[ind];
					if(isValid(newr,newc,n)){
						if(grid[newr][newc]==1){
							components.insert(ds.findUPar(newr*n+newc));
						}
					}
				}
				int sizeTotal=1;
				for(auto it:components){
					sizeTotal+=ds.size[it];
				}
				mx=max(mx,sizeTotal);
			}
		}
		for(int cellNo=0;cellNo<n*n;cellNo++){
			mx=max(mx,ds.size[ds.findUPar(cellNo)]);
		}

	}
		cout<<mx<<endl;
	return 0;
}
