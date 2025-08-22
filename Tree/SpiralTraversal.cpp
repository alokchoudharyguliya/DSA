#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){};
};
void spiralTraversal(Node*root){
	if(!root)return;
	queue<Node*>q;
	q.push(root);
	vector<Node*>res;
	bool level=false;
	while(!q.empty()){
		int levelSize=q.size();
		for(int i=0;i<levelSize;i++){
		Node*ele=q.front();
		res.push_back(ele);
		q.pop();
		//Totally wrong approach
		// if(level)
		// {if(ele->left)
		// 	q.push(ele->left);
		// if(ele->right)
		// 	q.push(ele->right);
		// }
		// else{
		// 	if(ele->right)
		// 		q.push(ele->right);
		// 	if(ele->left)
		// 		q.push(ele->left);
		// }}
		// level=!level;
	}
	for(auto it:res)
		cout<<it->data<<",";
}
int main()
{
	Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	spiralTraversal(root);
}
