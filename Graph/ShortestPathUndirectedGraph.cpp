#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
		vector<int>shortestPath(vector<vector<int>>&edges,int V,int E,int src){

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
