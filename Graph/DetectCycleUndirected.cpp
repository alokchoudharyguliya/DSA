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
        cout << endl;
    }
}
bool bfs(vector<int> adjLis[], vector<int> &vis, int n, int i, int parent)
{
    vis[i]=1;
    queue<pair<int,int>> q;
    q.push({i,-1});
    while (!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for (auto it : adjLis[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it,node});
            }
            else if (it != parent)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n = 7;
    vector<int> adjLis[n];
    addEdge(adjLis, 0, 1);
    addEdge(adjLis, 1, 4);
    addEdge(adjLis, 4, 6);
    addEdge(adjLis, 6, 5);
    addEdge(adjLis, 2, 5);
    addEdge(adjLis, 2, 3);
    addEdge(adjLis, 0, 2);
    printGraph(adjLis, n);
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            if(bfs(adjLis, vis, n, i, -1)){cout<<"Cycle";return true;}
    }
    cout<<"No Cycle";
    return false;
}