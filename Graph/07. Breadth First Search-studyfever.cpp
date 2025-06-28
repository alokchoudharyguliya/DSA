#include<queue>
#include"04. Adjacency List implementation.cpp"

void BFS(vector<int>adj[],int i,bool visited[]){
    queue<int>q;
    q.push(i);
    visited[i]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int w:adj[u])
            if(visited[w]==false)
                {
                    visited[w]=true;
                    q.push(w);
                }
    }

}
void BFSDis(vector<int> adj[],int v)
{   
    bool visited[v+1];
    for(int i=0;i<=v;i++)
        visited[i]=false;

    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)   
            {BFS(adj,i,visited);
            cout<<"\n";}
    }
    return;
}
// int main()
// {
//     vector<int> adj[9];
//     addEdge(adj,0,2);
//     addEdge(adj,0,1);
//     addEdge(adj,1,2);
//     addEdge(adj,3,4);
//     addEdge(adj,5,6);
//     addEdge(adj,5,7);
//     addEdge(adj,7,8);
//     BFSDis(adj,9);
//     return 0;
// }