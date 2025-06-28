#inlcude<bits/stdc++.h>
using namespace std;

class Disjoint{
	public:
		vector<int>rank, parent, size;
		DisjoineSet(int n);
		int findUPar(int node);
		void unionBySize(int u, int v);
};
DisjointSet::DisjointSet(int n){
	parent.resize(n+1);
	rank.resize(n+1,0);
	size.resize(n+1,1);

	for(int h=0;h<=n;h++)
	parent[h]=h;
}

int main(){

	return 0;
}

