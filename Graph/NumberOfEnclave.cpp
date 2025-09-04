#include <bits/stdc++.h>
using namespace std;
int main()
{
    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};
    queue<pair<int, int>> q;
    vector<vector<int>> adjMat = {{0, 0, 0, 1, 1},
                                  {0, 1, 1, 1, 0},
                                  {0, 1, 1, 0, 0},
                                  {0, 1, 1, 0, 0},
                                  {0, 0, 0, 1, 1}};
    int vis[adjMat.size()][adjMat[0].size()] = {0};
    // for(int i=0;i<adjMat.size();i++){
    //     dfs(adjMat[i][0],delrow,delcol);
    //     dfs(adjMat[i][adjMat[0].size()-1],delrow,delcol);
    // }
    // for(int i=0;i<adjMat[0].size();i++){
    //     dfs(adjMat[0][i],delrow,delcol);
    //     dfs(adjMat[adjMat.size()-1][i],delrow,delcol);
    // }
    int n=adjMat.size();
    int m=adjMat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if (adjMat[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j]=1;
                }
            }
        }
    }
    // cout<<"Hey";
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            // cout<<"Hey";
            int newcol = col + delcol[i];
            int newrow = row + delrow[i];
            if (newcol >= 0 && newrow >= 0 && newrow < adjMat.size() && newcol < adjMat[0].size() && !vis[newrow][newcol] && adjMat[newrow][newcol] == 1)
            {
                // cout<<newrow<<","<<newcol<<";";
                q.push({newrow, newcol});
                vis[newrow][newcol] = 1;
            }
        }
    }
    int cnt=0;
    for (int i = 0; i < adjMat.size(); i++)
    {
        for (int j = 0; j < adjMat[0].size(); j++)
        {
            if(vis[i][j]==0&&adjMat[i][j]==1)
            cnt++;
        }
    }
    cout<<cnt;
}