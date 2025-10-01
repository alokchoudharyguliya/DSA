// [0] -> name , rest elements are -> emails
// criteria for merging is if they have a common mail and not if the name of two lists is same
#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
public:
    vector<int> size, parent, rank;
    DisjointSet(int n);
    int findUPar(int u) {
        if (parent[u] == u)
            return u;
        else
            return parent[u] = findUPar(parent[u]); // compression
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v)return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; // joined ulp_v below ulp_u
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v)return;
        if (size[ulp_u] <= size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
DisjointSet::DisjointSet(int n) {
    rank.resize(n, 0);
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i <n; i++) {
        parent[i] = i;
    }
}
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mapMailNode(n);
        DisjointSet ds(n);
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mapMailNode.find(accounts[i][j])==mapMailNode.end()){
                        // means not available then put into the map with a new
                        // node number
                        mapMailNode[accounts[i][j]] =
                            i; // map of "mail@gmail.com"->node_number
                    }
                else {
                    // means mail id already assigned to a node number
                    // cout<<mapMailNode[accounts[i][j]];
                    ds.unionByRank(i, mapMailNode[accounts[i][j]]);
                }
            }
        }
        // now we have a map of mail1 -> 0, mail2 -> 1, mail3->0....
        // now get it this way number to mail id list
        // johnnybravo@mail.com,3mary@mail.com,2john00@mail.com,1john_newyork@mail.com,0johnsmith@mail.com,0
        // for(auto it:mapMailNode)
        // cout<<it.first<<","<<it.second;
        vector<vector<string>> mergeMail(n);
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergeMail[node].push_back(mail);
        }
        // for(auto it:mergeMail)
        // {for(auto i:it)
        // cout<<i<<",";
        // cout<<endl;}
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergeMail[i].size() == 0)
                continue;
            vector<string> temp;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            temp.push_back(accounts[i][0]);
            for (auto it : mergeMail[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        // first assign the nodes to the respective names and then assign their
        // mails to nodes convert this ds to a vector having node mapped to list
        // of mails
        return ans;
    }
};