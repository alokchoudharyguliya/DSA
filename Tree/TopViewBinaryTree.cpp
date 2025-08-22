#include<bits/stdc++.h>
using namespace std;
// again horizontal index usage, but this time we skip if the horizontal index already is present inside the map, that is we only insert the first time horizontal index appearance
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
class Solution{

	public:
	vector<int>topView(Node*root){
		vector<int>ans;
		if(!root)return ans;
		map<int,int>mpp;
		queue<pair<Node*,int>>q;
		q.push({root,0});
		while(!q.empty()){
			auto it=q.front();
			q.pop();
			Node*node=it.first;
			int line=it.second;
			if(mpp.find(line)==mpp.end())
				mpp[line]=node->data;
			if(node->left)
				q.push({node->left,line-1});
			if(node->right)
				q.push({node->right,line+1});

		}
		for(auto it:mpp)
			ans.push_back(it.second);
			return ans;
	}
};
int main(){
	Node*root=new Node(1);
	    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);
    Solution sol;
    vector<int>topView=sol.topView(root);
    for(auto it:topView)
	    cout<<it<<",";

}
