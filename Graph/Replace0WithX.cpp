#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &adj, int row, int col, int delrow[], int delcol[], vector<vector<int>> &vis)
{
    vis[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int newrow = row + delrow[i];
        int newcol = col + delcol[i];
        if (newrow >= 0 && newcol >= 0 && newrow < adj.size() && newcol < adj[0].size() && vis[newrow][newcol] == 0 && adj[newrow][newcol] == 'O')
        {
            // adj[newrow][newcol] = 'X';
            dfs(adj, newrow, newcol, delrow, delcol, vis);
        }
    }
}
int main()
{
    vector<vector<char>> adj = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'O', 'X', 'X'}, {'X', 'X', 'O', 'O'}};
    // inner zeros are always possible to convert to X
    // Those zeros which are at boundary or are connected to any O which is at boundary
    int delrow[] = {0, -1, 0, 1};
    int delcol[] = {1, 0, -1, 0};
    int n = adj.size();
    int m = adj[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        if (!vis[0][i] && adj[0][i] == 'O')
        {
            dfs(adj, 0, i, delrow, delcol, vis);
        }
        if (!vis[n - 1][i] && adj[n - 1][i] == 'O')
            dfs(adj, n - 1, i, delrow, delcol, vis);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i][0] && adj[i][0] == 'O')
            dfs(adj, i, 0, delrow, delcol, vis);
        if (!vis[i][m - 1] && adj[i][m - 1] == 'O')
            dfs(adj, i, m - 1, delrow, delcol, vis);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout<<vis[i][j]<<",";
            if(vis[i][j]){
                adj[i][j]='X';
            }
            cout<<adj[i][j]<<",";
        }
        cout<<endl;
    }
}