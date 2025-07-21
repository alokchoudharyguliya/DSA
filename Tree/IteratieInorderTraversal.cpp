#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*right;
	Node*left;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};

void inorder(Node*root,vector<int>&res){
	if(!root) return;
	inorder(root->left,res);
	res.push_back(root->data);
	inorder(root->right,res);

}

/*
vector<int>inOrder(Node*root){
	vector<int>res;
	inorder(root,res);
	return res;
}
*/


int main(){
	Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	vector<int>result=inOrder(root);
	cout<<"Inorder Traversal"<<endl;
	for(int val:result)
		cout<<val<<" ";
	return 0;

}

