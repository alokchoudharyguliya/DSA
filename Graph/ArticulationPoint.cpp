/*
 *	low[] -> min of all adjacent nodes apart form parent & visited nodes
 *
 */

#include<bits/stdc++.h>
using namespace std;
int timer=0;
void dfs(int i, int parent, vector<int>&vis, int&tin[],int&low[],vector<int>&mark,vector<int>&adj[]){
	vis[i]=1;
	tin[i]=low[i]=timer++;
	for(auto it:adj[i])
	{
		if(it==parent)continue;
		if(!vis[it])
		{
			dfs(it,i,vid,tin,low,mark,adj);	
			low[i]=min(low[i],low[it]);
			if(low[it]>=tin[i] && parent!=-1)mark[i]=1;
		}
		else{

low[i]=min(low[i],tin[it]);
		}
	}
}
vector<int> main(){
	vector<int>adj[];

	int V=6;
	vector<int>vis(n,0);
	int tin[V];
	int low[V];
	vector<int>mark(n,0);
	for(int i=0;i<n;i++)
	{
		if(!vis[i]){
			dfs(i,-1,vis,tin,low,mark,adj);
		}
	}
	vector<int>ans;
	for(int i=0;i<n;i++)
	{
		if(mark[i]==1)
			ans.push_back(i);
	}
	if(ans.size()==0) return {-1};

	return ans;

}
