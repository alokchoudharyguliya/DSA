#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
		int shortestPath(vector<vector<int>>&grid,pair<int,int>src,pair<int,int>dst){
		// Edge case : If the source is only the destination
			if(src.first==dst.first&&src.second==dst.second)return 0;
	queue<pair<int,pair<int,int>>q;
	int n=grid.size();
	int m=grid[0].size();

	vector<vector<int>>dist(n,vector<int>(m,1e9));
	dist[src.first][src.second]=0;
	q.push({0,{src.first,src.second}});
	int dr={0,-1,0,1};
	int dc={1,0,-1,0};

	while(!q.empty())
	{
		auto it=q.front();
		q.pop();
		int dis=it.first;
		int r=it.second.first;
		int c=it.second.second;

		for(int i=0;i<4;i++){
			int newr=r+dr[i];
			int newc=c+dc[i];
			if(newr>=0&&newr<n&&newc>=0&&newc<m&&grid[newr][newc]==1&&dis+1<dist[newr][newc])
		{
			dist[newr][newc]=1+dis;

			if(newr==dest.first&&newc==dest.second)
				return dis+1;
			q.push({1+dis,{newr,newc}});
		}
		}

	}
	return -1;
	}
};
int main(){
	pair<int,int>src,dst;
	src.first=0;
	src.second=1;
	dst.first=2;
	dst.second=2;
	vector<vector<int>>grid={{1,1,1,1},
					{1,1,0,1},
					{1,1,1,1},
					{1,1,0,0},
					{1,0,0,1}};
	Solution sol;
	int res=sol.shortestPath(grid,src,dst);
	cout<<res<<endl;
	return 0;
}
