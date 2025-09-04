#include <bits/stdc++.h>
using namespace std;
// #define detectCycleinUndirectedGraph dfs;
void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u - 1].push_back(v);
    adjList[v - 1].push_back(u);
}
void printAdjRepresentation(vector<int> adjList[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (auto it : adjList[i])
            cout << it << ",";
        cout << "\n";
    }
}
void detectCycleinUndirectedGraph(vector<int>adjList[], int n, vector<int> &vis, int src)
{
    vis[src] = 1;
    for(auto it:adjList[src-1])
    {   cout<<vis[it];
        if (!vis[it])
        {
            detectCycleinUndirectedGraph(adjList, n, vis,it);
        }else{
            cout<<"Cycle";
        }
    }
}
int main()
{
    // adjList representation;
    int n = 7;
    vector<int> adjList[n];
    addEdge(adjList, 1, 2);
    addEdge(adjList, 5, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 6, 3);
    addEdge(adjList, 5, 7);
    addEdge(adjList, 6, 7);
    addEdge(adjList, 4, 3);
    vector<int> vis(n+1, 0);
    printAdjRepresentation(adjList, n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i+1])
        {
            detectCycleinUndirectedGraph(adjList, n, vis, i+1);
        }
    }
}