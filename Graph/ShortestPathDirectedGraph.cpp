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
			int vis[E]={0};
			stack<int>st;
			for(int i=0;i<E;i++){
				if(!vis[i])
					topoSort(i,adj,vis,st);

			}
			vector<int>dist[E];
			for(int i=0;i<E;i++){
				dist[i]=1e9;
			}
			dist[0]=0;
			while(!st.empty()){
				int node=st.top();
				st.pop();
				for(auto it:adj[node]){
					int v=it.first;
					int wt=it.second;

					if(dist[node]+wt<dist[v]){
						dist[v]=dist[node]+wt;
					}

				}

			}
			for(int i=0;i<E;i++)
				if(dist[i]==1e9)dist[i]=-1;
			return dist;
		}
};
int main(){
	int V=6,E=7;
	vector<vector<int>>edges={{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
	Solution sol;
	vector<int>ans=sol.shortestPath(V,E,edges);

}
