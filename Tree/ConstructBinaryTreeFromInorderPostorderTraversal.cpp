#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr), right(nullptr){}
};

Node*buildTreePostIn(vector<int>&inorder,int inS,int inE,vector<int>&postorder,int pS,int pE,map<int,int>&inMap){
	// BASE CONDITION: when the subtree is empty return NULL
	if(pS>pE||inS>inE)return NULL;
	// select the last element of postorder which will be the root
	Node*root=new Node(postorder[pE]);
	// find its position in the inorder array
	int inRoot=inMap[postorder[pE]];
	// Number of nodes in left subtree
	int numsLeft=inRoot-inS;
	root->left=buildTreePostIn(inorder,inS,inRoot-1,postorder,pS,pS+numsLeft-1,inMap);
	root->right=buildTreePostIn(inorder,inRoot+1,inE,postorder,pS+numsLeft,pE-1,inMap);
	return root;
}

Node*buildTree(vector<int>&inorder,vector<int>&postorder){
	if(inorder.size()!=postorder.size())
		return NULL;
	map<int,int>inMap;
	for(int i=0;i<inorder.size();i++)
		inMap[inorder[i]]=i;
	return buildTreePostIn(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);
}

void printInorder(Node*root){
	if(!root)return;
	printInorder(root->left);
	cout<<root->data<<",";
	printInorder(root->right);

}
int main(){
vector<int>inorder={40,20,50,10,60,30};
vector<int>postorder={40,50,20,60,30,10};
Node*root=buildTree(inorder,postorder);
printInorder(root);
}
