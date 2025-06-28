#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<int> adj[],int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[],int V)
{
    for(int i=0;i<V;i++)
    {
        for(int x:adj[i])
        cout<<x<<" ";
        cout<<"\n";
    }
}
int main()
{
    int V=4;
    vector<int> adj[3];
    addEdge(adj,0,1);
    printGraph(adj,V);
    cout<<adj[0].front();    
    return 0;
}