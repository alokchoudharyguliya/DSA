// It is type of online query problem
//
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
	public:
		vector<int>rank,parent,size;
		DisjointSet(int n);
		int findUPar(int node);
		void unionByRank(int u,int v);
};

DisjointSet::DisjointSet(int n){
	rank.resize(n+1,0);
	parent.resize(n+1);
	for(int i=0;i<=n;i++)
		parent[i]=i;
}
int DisjointSet::findUPar(int node){
	if(node==parent[node]) return node;
	return parent[node]=findUPar(parent[node]);
}
void DisjointSet::unionByRank(int u, int v){
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
bool isValid(int adjr,int adjc,int n,int m){
	return adjr>=0&&adjr<n&&adjc>=0&&adjc<m;
}
int main(){
	int n=4,m=5;
	vector<pair<int,int>>operators={{0,0},
				        {0,0},
					{1,1},
				        {1,0},
					{0,1},
					{0,3},
					{1,3},
					{0,4},
					{3,2},
					{2,2},
					{1,2},
					{0,2}};
//	vector<vector<int>>mat(n,vector<int>(m,0));
//	DisjointSet ds((n+1)*(m+1));
	DisjointSet ds(n*m);
	int vis[n][m];
	memset(vis, 0, sizeof vis);
	int cnt=0;
	vector<int>ans;
/*	for(int j=0;j<operators.size();j++){
		int row=operators[0];
		int col=operators[1];
		mat[row][col]=1;
		if(mat[operators[0]+1][operators[1]])
	}
*/
	//***********"IMPORTANT"********************
	for(auto it:operators)
	{
//		cout<<"HEy";
		int row=it.first;
		int col=it.second;
		if(vis[row][col]==1)
		{
			ans.push_back(cnt);
			continue;
		}
		vis[row][col]=1;
		cnt++;
		// top=row-1,col
		// right=row, col+1
		// bottom=row+1, col
		// left=row,col-1
		int dx[]={-1,0,1,0};//dc - horizontal change
		int dy[]={0,1,0,-1};//dr - vertical change
		for(int i=0;i<4;i++)
		{
			int adjr=row+dy[i];
			int adjc=col+dx[i];
			if(isValid(adjr,adjc,n,m)){
				if(vis[adjr][adjc]==1){
					int nodeNo=row*m+col;
					int adjNodeNo=adjr*m+adjc;	
					if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo))
					{
						ds.unionByRank(nodeNo,adjNodeNo);
						cnt--;
					}
				}
			}
		}
		ans.push_back(cnt);
	}
	for(auto i:ans)
		cout<<i<<",";
	return 0;
}
