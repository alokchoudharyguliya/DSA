// we take 1 indexed method

#include <bits/stdc++.h>
using namespace std;
// #define detectCycleinUndirectedGraph dfs;
void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
void printAdjRepresentation(vector<int> adjList[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (auto it : adjList[i])
            cout << it << ",";
        cout << "\n";
    }
}
bool detectCycleinUndirectedGraph(vector<int> adjList[], int n, vector<int> &vis, int src, int parent)
{
    vis[src] = 1;
    for (auto it : adjList[src])
    {
        // cout << it;
        if (!vis[it])
        {
            if(detectCycleinUndirectedGraph(adjList, n, vis, it, src))return true;
        }
        else if (it != parent)
        {
            // cout << "Cycle";
            return true;
        }
    }
    return false;
}
int main()
{
    // adjList representation;
    int n = 7;
    vector<int> adjList[n+1];
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 5);
    addEdge(adjList, 5, 7);
    addEdge(adjList, 6, 7);
    addEdge(adjList, 3, 6);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 1, 3);

    
    vector<int> vis(n+1, 0);
    printAdjRepresentation(adjList, n);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if(detectCycleinUndirectedGraph(adjList, n, vis, i, -1)){cout<<"Cycle";return 0;}
        }
    }
    cout<<"Not Cycle";
}