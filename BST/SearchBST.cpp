#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
Node*searchBST(Node*root,int target){
	while(root){
	if(root->data==target)return root;
	if(root->data<target)root=root->right;
	else if(root->data>target)root=root->left;
	}
	return NULL;
}
void printInorder(Node*root){
	if(!root)return;
	printInorder(root->left);
	cout<<root->data<<",";
	printInorder(root->right);
}
int main(){
	Node*root=new Node(5);
	root->left=new Node(3);
	root->right=new Node(8);
	root->left->left=new Node(2);
	root->left->right=new Node(4);
	root->right->left=new Node(6);
	root->right->right=new Node(10);

	printInorder(root);
	cout<<endl;
	int target=6;
	Node*res=searchBST(root,target);
	res?cout<<target<<" found in the BST"<<endl:cout<<"Not found"<<endl;
}
