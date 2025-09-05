#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adjLis[], int u, pair<int,int> v)
{
    adjLis[u].push_back({v.first,v.second});
}
void printGraph(vector<pair<int,int>> adjLis[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<i<<"->";
        for (auto it : adjLis[i])
        {
            cout <<"{"<< it.first << ",";
            cout<<it.second<<"}";
        }
        cout << "\n";
    }
}

void toposort(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&st){
    vis[node]=1;
    for(auto it:adj[node]){
        int v=it.first;
        if(!vis[v])toposort(v,adj,vis,st);
    }
    st.push(node);
}


int main()
{
    int V = 7;
    vector<pair<int, int>> adjLis[V];
    addEdge(adjLis, 0, {1, 2});
    addEdge(adjLis, 1, {3, 1});
    addEdge(adjLis, 2, {3, 3});
    addEdge(adjLis, 4, {0, 3});
    addEdge(adjLis, 4, {2, 1});
    addEdge(adjLis, 5, {4, 1});
    addEdge(adjLis, 6, {4, 2});
    addEdge(adjLis, 6, {5, 3});
    printGraph(adjLis, V);
    // vector<int>vis[]={0};
    int vis[V]={0};
    stack<int>st;
    for(int i=0;i<V;i++)
    if(!vis[i])
    toposort(0,adjLis,vis,st);
    while(!st.empty()){
        int node=st.top();
        st.pop();
        cout<<node;
    }
}