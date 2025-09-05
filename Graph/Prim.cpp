// The following code is like we are performing BFS on a connected graph so we need to check Prim's MST for disconnected graph then the case is different also what if the graph has negative weights or the graph has parallel edges
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>adj[],int u,int v,int wt){
	adj[u].push_back({v,wt});
	adj[v].push_back({u,wt});
}
// Here we won't simply find the sum but get the edges completely
int main(){
	int V=5;
	vector<vector<int>>adj[V]
	;
// 	={{{1,2},{3,6}},
// 	{{0,2},{2,3},{4,5},{3,8}},
// 	{{1,3},{4,7}},
// 	{{0,6},{1,8}},
// 	{{1,5},{2,7}},
// };
// addEdge(adj,0,1,2);
// addEdge(adj,1,2,3);
// addEdge(adj,4,1,5);
// addEdge(adj,0,3,6);
// addEdge(adj,2,4,7);
// addEdge(adj,3,1,6);

// // Case for which early vis marking will fail
addEdge(adj,0,1,10);
addEdge(adj,1,2,1);
addEdge(adj,0,2,2);

	vector<int>vis(V,0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // default-maxHeap
	int S=0;
	int sum=0;
	// vis[S]=1; Early marking visited of the node
	pq.push({0,S});
	while(!pq.empty()){
		auto it=pq.top();
		pq.pop();
		int wt=it.first;
		int node=it.second;
		if(vis[node])continue;
		vis[node]=1;
		sum+=wt;
		// mark visited and take the sum only after we have chosen the node that is we have popped it from among all the minimum nodes, the task of selecting the minium edge is done by the priority queue and if we directly take any non-visited neighbor that is wrong
		cout<<wt<<","<<node<<"\n";
		for(auto iit:adj[node]){
			if(!vis[iit[0]]){
				// vis[iit[0]]=1;
				// sum+=iit[1];
				pq.push({iit[1],iit[0]});
			}
		}
	}
	cout<<sum;
	return 0;
}
