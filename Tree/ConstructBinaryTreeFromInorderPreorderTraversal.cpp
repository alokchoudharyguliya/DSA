#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*right;
	Node*left;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
// inorder allows us to identify a node and its left and right subtree, while preorder traversal ensures we always encounter the root node first.
// we locate the root node in the inorder traversal, which splits the array into left and right subtrees.

void printInorder(Node*root){
	if(!root)return;
	printInorder(root->left);
	cout<<root->data<<",";
	printInorder(root->right);
}
void printVector(vector<int>arr){
	for(auto it:arr)
		cout<<it<<",";
	cout<<endl;
}

Node*buildTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart, int inEnd, map<int,int>&inMap){
	if(preStart>preEnd||inStart>inEnd)return NULL;
	Node*root=new Node(preorder[preStart]);
	int inRoot=inMap[root->data];
	int numsLeft=inRoot-inStart;
	root->left=buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
	root->right=buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
	return root;
}

Node*build(vector<int>inorder,vector<int>preorder){
	map<int,int>inMap;
	// Store the number and their indices in the inorder traversal
	for(int i=0;i<inorder.size();i++)
		inMap[inorder[i]]=i;
	Node*root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
	return root;
}

int main(){
	vector<int>inorder={9,3,15,20,7};
	vector<int>preorder={3,9,20,15,7};
	printVector(inorder);
	cout<<endl;
	printVector(preorder);
	Node*root=build(preorder,inorder);
	printInorder(root);
}
