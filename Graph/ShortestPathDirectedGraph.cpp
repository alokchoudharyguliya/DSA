// Directed Acyclic Graph, find the shortest path from the source to all other nodes in this DAG.
//
#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
		vector<int>shortestPath(int V,int E,vector<vector<int>>&edges){
			vector<pair<int,int>>adj[V];
			for(int i=0;i<E;i++)
			{
				int u=edges[i][0];
				int v=edges[i][1];
				int wt=edges[i][2];
				adj[u].push_back({v,wt});
			}
		}
};
int main(){
	int V=6,E=7;
	vector<vector<int>>edges={{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
	Solution sol;
	vector<int>ans=sol.shortestPath(V,E,edges);

}
