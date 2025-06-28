//  ------------------"VERY IMPORTANT QUESTION TO PRACTICE"--------------------------
#include<bits/stdc++.h>
using namespace std;
// Merge people having any intersection say in the contact book and they must be sorted after merge
// 
// John-a@g.com, b@g.com
// Raj-r@g.com, c@g.com
// John-a@g.com, d@g.com
// Raj-s@g.com, t@g.com
// John-e@g.com
// Then after merge we will have
//
// John-a@g.com, b@g.com, d@g.com
// Raj-c@g.com, r@g.com, s@g.com, t@g.com
// John-e@g.com
//
// BREAKING THE PROBLEM INTO PARTS
// 1. XXX Identify those who have intersection XXX
// 2. Merge them - "Union dynamically"
// 3. Sort them
class DisjointSet{
	public:
		vector<int>parent, rank, size;
		DisjointSet(int V);
		int findUPar(int node);
		void unionByRank(int u,int v);
};
DisjointSet::DisjointSet(int n){
	parent.resize(n+1);
	rank.resize(n+1,0);	
	for(int i=0;i<=n;i++)
		parent[i]=i;
}
int DisjointSet::findUPar(int node){
	if(node==parent[node])
	return node;
	else return parent[node]=findUPar(parent[node]);	
}
void DisjointSet::unionByRank(int u,int v){	
	int ulp_u=findUPar(u);
	int ulp_v=findUPar(v);

	if(ulp_u==ulp_v)
		return;
	if(rank[ulp_u]<rank[ulp_v])
	{
		parent[ulp_u]=ulp_v;
	}
	else if(rank[ulp_u]>rank[ulp_v])
	{
		parent[ulp_v]=ulp_u;
	}
	else{
		parent[ulp_v]=ulp_u;
		rank[ulp_u]++;
	}
	
}
int main(){
	int n;
	vector<vector<string>>edge={{"john","j1@com","j2@com","j3@com"},
				    {"john","j4@com"},
				    {"raj","r1@com","r2@com"},
				    {"john","j1@com","j5@com"},
				    {"raj","r2@com","r3@com"},
				    {"mary","m1@com"}};
	n=edge.size();
	DisjointSet ds(edge.size());
	unordered_map<string,int>mapMailNode;
	for(int j=0;j<edge.size();j++)
	{
		for(int i=1;i<edge[j].size();i++)
		{
			if(mapMailNode.find(edge[j][i])==mapMailNode.end())
				mapMailNode[edge[j][i]]=j;
			else{
				int u=mapMailNode[edge[j][i]];
				ds.unionByRank(u,j);
			}
		}
	}


	vector<string>mergedMail[n];
	unordered_map<string,int>::iterator t;
//	for(t=mapMailNode.begin();t!=mapMailNode.end();t++)
	for(auto t:mapMailNode)
	{
		string mail=t.first;
		mergedMail[ds.findUPar(t.second)].push_back(mail);
	}

	vector<string>ans[n];
	for(int i=0;i<n;i++)
	{
		if(mergedMail[i].size()==0) continue;
		ans[i].push_back(edge[i][0]);
		sort(mergedMail[i].begin(),mergedMail[i].end());
		for(int j=0;j<mergedMail[i].size();j++)
		{
			ans[i].push_back(mergedMail[i][j]);
		}
	}	
	for(auto it:ans)
		for(auto sit:it)
			cout<<sit<<",";
		
	cout<<endl;
	for(auto it:mapMailNode)
		cout<<it.first<<it.second<<endl;
	return 0;
	}
