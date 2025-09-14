#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }
        // string dir = "DLRU";
        if(i+1<n&&!vis[i+1][j]&&a[i+1][j])
        {
            vis[i][j]=1;
            solve(i+1,j,a,n,ans,move+"D",vis);
            vis[i][j]=0;
        }

        if(j-1>=0&&!vis[i][j-1]&&a[i][j-1])
        {
            vis[i][j]=1;
            solve(i,j-1,a,n,ans,move+"L",vis);
            vis[i][j]=0;
        }

        if(j+1<n&&!vis[i][j+1]&&a[i][1+j])
        {
            vis[i][j]=1;
            solve(i,j+1,a,n,ans,move+"R",vis);
            vis[i][j]=0;
        }

        if(i-1>=0&&!vis[i-1][j]&&a[i-1][j])
        {
            vis[i][j]=1;
            solve(i-1,j,a,n,ans,move+"U",vis);
            vis[i][j]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        // int di[] = {-1, 0, 0, 1}; // he we want this to be in order as DLRU-{(0,-1),(-1,0),(1,0),(0,1)}
        // int dj[] = {0, -1, 1, 0};
        if (m[0][0] == 1)
            solve(0, 0, m, n, ans, "", vis);
        return ans;
    }
};
int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    Solution sol;
    vector<string> ans = sol.findPath(m, 4);
    for (auto it : ans)
        cout << it << "<";
}