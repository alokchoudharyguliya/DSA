#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adjLis[], int u, int v)
{
    adjLis[u].push_back(v);
    adjLis[v].push_back(u);
}
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
    int n = 7;
    vector<int> adjLis[n];
    addEdge(adjLis, 0, 1);
    addEdge(adjLis, 1, 2);
    addEdge(adjLis, 2, 3);
    addEdge(adjLis, 3, 5);
    addEdge(adjLis, 4, 5);
    addEdge(adjLis, 6, 4);
    addEdge(adjLis, 4, 0);
    printGraph(adjLis, n);
    int parent = -1;
    queue<pair<int, int>> q;
    vector<int> vis(n, 0);
    vis[0] = 1;
    q.push({0, parent});
    while (!q.empty())
    {
        int node = q.front().first;
        parent = q.front().second;
        q.pop();
        for (auto it : adjLis[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, node});
            }
            else if (it != parent)
            {
                cout << node << "," << it;
                cout << "Cycle";
                return true;
            }
        }
    }
    cout << "No Cycle";
}