#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
		vector<int>shortestPath(vector<vector<int>>&edges,int V,int E,int src){
			vector<int>adj[V];
			for(auto it:edges)
			{
			adj[it[0]].push_back(it[1]);
			adj[it[1]].push_back(it[0]);
			}
			int dist[V];
			for(int i=0;i<V;i++)dist[i]=1e9;
			dist[src]=0;
			queue<int>q;
			q.push(src);
			while(!q.empty()){
				int node=q.front();
				q.pop();
				for(auto it:adj[node])
				{
					if(dist[node]+1<dist[it]){
						dist[it]=dist[node]+1;
						q.push(it);
					}

				}

			}
			vector<int>ans(V,-1);
			for(int i=0;i<V;i++){
				if(dist[i]!=1e9)
					ans[i]=dist[i];
			}
			return ans;
		}
};
int main(){
	int V=9, E=10;
	vector<vector<int>>edges={{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
	Solution sol;
	vector<int>ans=sol.shortestPath(edges,V,E,0);
	for(auto it:ans)
		cout<<it<<",";
	return 0;
}
