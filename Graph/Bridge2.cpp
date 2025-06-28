#include<bits/stdc++.h>
using namespace std;
int timer=1;
void dfs(int node, int parent, vector<int>&vis, vector<vector<int>>connection, int tim[], int low[],vector<vector<int>>&bridges){ // analogue to bridge

	vis[node]=1;
	tim[node]=low[node]=++timer;// first assign and then increase the value
	for(auto it:connection[node]){
		if(it==parent) continue;
		if(vis[it]==0){
			dfs(it, node, vis, connection, tim, low,bridges);
			low[node]=min(low[node],low[it]);
			if(low[it]>tim[node])
					bridges.push_back({it, node});
		}
		else{
			low[node]=min(low[node],low[it]);
		}
	}

}
int main(){
	vector<vector<int>>connection={{1,2},{0,2,3},{0,1},{1}};
	int n=connection.size();
	vector<int> vis(n,0);
	int tim[n];//disc
	int low[n]; 
	vector<vector<int>> bridges;
	dfs(0,-1, vis,connection,tim,low, bridges);
	for(auto it:bridges){
		cout<<it[0]<<" "<<it[1];
	}
	return 0;

}
