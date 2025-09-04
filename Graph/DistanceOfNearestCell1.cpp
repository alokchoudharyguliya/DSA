#include <bits/stdc++.h>
using namespace std;
void printGraph(vector<int> adjLis[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (auto it : adjLis[i])
            cout << it << ",";
        cout << "\n";
    }
}
int main()
{
    int n;
    vector<int> adjLis[3] = {{1, 0, 1}, {1, 1, 0}, {1, 0, 0}};
    // printGraph(adjLis, 3);
    vector<int> vis[3];
    vector<int> dis[3];
    for (int i = 0; i < 3; i++)
    {   
        vis[i]={0,0,0};
        dis[i] = adjLis[i];
    }
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (adjLis[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j]=1;
            }else{

                vis[i][j]=0;
            }
        }
    }
    // printGraph(vis, 3);
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int step=q.front().second;
        q.pop();
        int delRow[]={0,-1,0,1};
        int delCol[]={1,0,-1,0};
        dis[row][col]=step;
        for(int i=0;i<4;i++){
            int newrow=row+delRow[i];
            int newcol=col+delCol[i];
            if(newrow>=0&&newrow<adjLis[0].size()&&newcol<adjLis[0].size()&&vis[newrow][newcol]==0){
                vis[newrow][newcol]=1;
                q.push({{newrow,newcol},step+1});
            }
        }
    }
    printGraph(dis, 3);
}