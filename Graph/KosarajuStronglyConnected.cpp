#include<bits/stdc++.h>
using namespace std;
// Strongly connected component valid only for directed graph
// 3 is Reachable from 2 but not vice versa
// So we have to reverse the graph and then we won't be able to reach a SCC1 from SCC2.
// That is the definition that is SCC is such that every node inside it is reachable from all the other nodes.
//
// ------=====Kosaraju's Algorithm=====------
// 1. Sort all the edges according to finishing time 
// 2. Reverse the graph
// 3. Do a DFS

void dfs(int i,vector<int>&vis,vector<int>adj[],stack<int>&st){
	vis[i]=1;
//	cout<<i<<",";
	for(int t=0;t<adj[i].size();t++)
	{	
		if(!vis[adj[i][t]])
		{
			dfs(adj[i][t],vis,adj,st);
		}
	}
			st.push(i);

}
void dfs3(int node,vector<int>&vis,vector<int>adj[]){
		vis[node]=1;
		for(auto it:adj[node])
		{
			if(!vis[it])
			{
				dfs3(it, vis,adj);
			}
		}
}

int main(){
	int V=5;
	vector<int>adj[]={{2,3},
			{0},
			{1},
			{4},{}};
	stack<int>st;
//	vector<int>finishTime(V);
	vector<int>vis(V);
	for(int i=0;i<V;i++)
		vis[i]=0;

// DFS takes -> O(V+E)
	for(int i=0;i<V;i++){
		if(!vis[i]){
			dfs(i,vis,adj,st);
		}			
	}
	// Reverse the graph
// Reversing the graph takes -> O(V+E)
	vector<int>adjT[V];
	for(int i=0;i<V;i++)
	{	
		vis[i]=0;
		for(auto it:adj[i])
		adjT[it].push_back(i);
	}
// DFS takes -> O(V+E)
	int scc=0;
	while(!st.empty()){
		int node=st.top();
		st.pop();
		if(!vis[node])
		{
			scc++;
			dfs3(node,vis,adjT);
		}
	}
	cout<<scc;
//	cout<<st.size()<<endl;

//	while(!st.empty()){
//		cout<<st.top()<<",";
//		st.pop();
//	}
	return 0;
}
