DFSRec(adj, s, visited, parent)
{
    visited[s] = true;
    for
        every adjacent u of s
        {
            if (visited[u] == true)
                if (DFSRec(adj, u, visited, s) == true)
                    return true;
                else if (u != parent)
                    return true;
            return false;
        }
}
DFS(adj, V)
{
    visited[V]={false};
    for(int i=0;i<V;i++)
    if(visited[i]==false)
        if(DFSRec(adj,i,visited,-1)==true)
        return true;
    return false;
}