#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*right;
	Node*left;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
vector<int>bottomView(Node*root){
	vector<int>ans;
	if(!root)return ans;
	map<int,int>mpp;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	while(!q.empty()){
		auto it=q.front();
		q.pop();
		Node*temp=it.first;
		int line=it.second;
		mpp[line]=temp->data;
		if(temp->left)
			q.push({temp->left,line-1});
		if(temp->right)
			q.push({temp->right,line+1});
	}
	for(auto it:mpp)
		ans.push_back(it.second);
	return ans;
}
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
vector<int>res=bottomView(root);
for(auto it:res)
	cout<<it<<",";
cout<<endl;
}
