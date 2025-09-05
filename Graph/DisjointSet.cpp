#include <bits/stdc++.h>
using namespace std;
class Disjoint
{
    vector<int> rank, parent,size; // -> rank considers the height only and not the number of nodes
public:
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n+1,1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        else
            return parent[node] = findUPar(parent[node]); // this compresses the disjoint set data structure
    }
    void unionByRank(int u, int v)
    {
        int u_par = findUPar(u);
        int v_par = findUPar(v);
        if(u_par==v_par)return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int u_par=findUPar(u);
        int v_par=findUPar(v);
        if(u_par==v_par)return;
        if(size[u_par]<size[v_par]){
            parent[u_par]=v_par;
            size[v_par]+=size[u_par];
        }
        else{
            parent[v_par]=u_par;
            size[u_par]+=size[v_par];
        }
    }
};
int main()
{
    Disjoint ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUPar(3)==ds.findUPar(7))cout<<"Same\n";
    else cout<<"Not same\n";
    ds.unionByRank(3,7);
    if(ds.findUPar(3)==ds.findUPar(7))cout<<"Same\n";
    else cout<<"Not same\n";
}