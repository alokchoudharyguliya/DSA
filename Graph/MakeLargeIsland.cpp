#include <bits/stdc++.h>
using namespace std;
bool isValid(int newr,int newc,int n){
    return (newr>=0&&newc>=0&&newr<n&&newc<n);
}
class DisjointSet
{
public:
    vector<int> size, parent, rank;
    DisjointSet(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        size.resize(n, 1);
        rank.resize(n, 0);
    }
    int findUPar(int u)
    {
        if (parent[u] == u)
            return u;
        else
            return parent[u] = findUPar(parent[u]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
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
};
 
int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 1, 0, 1, 1},
                                {1, 1, 0, 1, 1},
                                {0, 0, 1, 0, 0},
                                {0, 0, 1, 1, 1}};
    int n = grid.size();
    // make the disjoint set represntation of the island from the given grid
    DisjointSet ds(n * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
                continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for (int t = 0; t < 4; t++)
            {
                int newr = i + dr[t];
                int newc = j + dc[t];
                if (isValid(newr, newc, n) && grid[newr][newc] == 1)
                {
                    int u = newr * n + newc;
                    int v = i * n + j;
                    ds.unionBySize(u, v);
                }
            }
        }
    }
    int mx=0;
    // store into the compoents set that is only unique ones
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==1)continue;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            set<int>components;
            for(int ind=0;ind<4;ind++){
                int newr=row+dr[ind];
                int newc=col+dc[ind];
                if(isValid(newr,newc,n)&&grid[newr][newc]==1)components.insert(ds.findUPar(newr*n+newc));
            }
            // the number of 1s in all the components
            int sizetotal=1;
            for(auto it: components){
                sizetotal+=ds.size[it];
            }
            mx=max(mx,sizetotal);
        }
        for(int cellNo=0;cellNo<n*n;cellNo++)
        mx=max(mx,ds.size[ds.findUPar(cellNo)]);
    }
    cout<<mx<<'\n';
}
