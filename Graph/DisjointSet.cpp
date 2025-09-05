#include<bits/stdc++.h>
using namespace std;
class Disjoint{
    vector<int>rank, parent; // -> rank considers the height only and not the number of nodes
    public:
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(parent[node]==node)return node;
        else return parent[node]=findUPar(parent[node]); // this compresses the disjoint set data structure
    }
    int unionByRank(int u,int v){
        
    }
};
int main(){

}