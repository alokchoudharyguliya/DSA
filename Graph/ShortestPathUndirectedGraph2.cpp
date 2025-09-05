#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// void printGraph(vector<int> adj[], int N)
// {
//     for (int i = 0; i < N; i++)
//     {
//         cout<<i<<"->";
//         for (auto it : adj[i])
//             cout <<it<<",";
//         cout<<"\n";
//     }
// }
vector<int>shortestPath(vector<vector<int>>&edges,int N,int M,int src){
    vector<int>adj[N];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int dis[N];
    for(int i=0;i<N;i++){
        dist[i]=1e9;
    }
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it]=1+dist[node];
                q.push(it);
            }
        }
    }
    vector<int>ans(N,-1);
    for(int i=0;i<N;i++){
        if(dist[i]!=1e9)ans[i]=dist[i];
    }
    return ans;
}
int main()
{
    int N = 9; 
    vector<int> adj[N];
    addEdge(adj, 1, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 2, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 7, 8);
    addEdge(adj, 6, 8);
    printGraph(adj, N);
}