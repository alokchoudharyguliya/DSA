#include<bits/stdc++.h>
using namespace std;
void bfs(int row,int col, vector<vector<int>>&adjMat,vector<vector<int>>&vis){
    vis[row][col]=1;
    // int dx={};
    // int dy={}; 
    // we want to look for neighbor in all the 8 directions
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        // traverse the neighbor and mark them visited
        for(int deltRow=-1;deltRow<=1;deltRow++){
            for(int deltCol=-1;deltCol<=1;deltCol++)
            {
                int nrow=row+deltRow;
                int ncol=col+deltCol;
                if(nrow>=0&&nrow<adjMat.size()&&ncol>=0&&ncol<adjMat[0].size()&&!vis[nrow][ncol]&&adjMat[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    // cout<<nrow<<","<<ncol<<';';
                }
            }
        }
    }

}
void numIsland(vector<vector<int>>&adMat){
    int m=adMat[0].size();
    int n=adMat.size();
    int cn=0;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]&&adMat[i][j]==1){
            cn++;
            bfs(i,j,adMat,vis);}
        }
    }
    cout<<cn;
}
int main(){
    int n=5,m=4;
    vector<vector<int>>adjMat(n,vector<int>(m,0));
    // vector<int>adjMat[];
    // int adjMat[m+1][n+1];
    // taking u and v that is the node number between which there exists and edge
    // for m number of edges
    int numberofmarked=8;
    for(int i=0;i<numberofmarked;i++){
        int u,v;
        cin>>u>>v;
        adjMat[u][v]=1;
    }
    // vector<vector<int>>vis;
    // int visMat[m+1][n+1];
    numIsland(adjMat);

}