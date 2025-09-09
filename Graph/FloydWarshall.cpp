#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> shortest_distance(vector<vector<int>> &g)
    {

        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g.size(); j++)
            {
                if (g[i][j] == -1)
                    g[i][j] = 1e9;
                if (i == j)
                    g[i][j] = 0;
            }
        }
        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g.size(); j++)
            {
                for (int k = 0; k < g.size(); k++)
                {
                    if (g[i][j] > g[i][k] + g[j][k])
                        g[i][j] = g[i][k] + g[k][j];
                    // g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g.size(); j++)
            {
                if (g[i][j] == 1e9)
                    g[i][j] = -1;
            }
        }
    }
};
int main()
{
    int v = 3;
    vector<vector<in>> g(v, vector<int>(v, -1));
    g[0][1] = 2;
    g[1][0] = 2;
    g[1][2] = 3;
    g[3][0] = 3;
    g[3][1] = 5;
    g[3][2] = 4;

    Solution obj;
    obj.shortest_distance(g);
    for (auto row : g)
    {
        for (auto col : row)
        {
            cout << col << ",";
        }
        cout << "\n";
    }
}