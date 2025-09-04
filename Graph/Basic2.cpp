//Adj Matrix representation of Graph
#include<bits/stdc++.h>
using namespace std;
int main(){

    int n, m;
    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u][v]=1;
        adj[v][u]=1;
    }
}

// Adj List Representation of Graph
int n,m;
cin>>n>>m;
vector<int>[n+1];
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

1 2 3 4 5 6 7

// .begin(),.begin()+2-1,