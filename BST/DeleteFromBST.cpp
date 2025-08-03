#include<bits/stdc++.h>
using namespace std;
// Find where the node to deleted appears ? 
// Deleting can be done in two ways for a non-leaf node:
// 1.	Accept the left subtree as the new root which will take place of the node deleted. Join the right subtree to the right most node of the current subtree.
// 2.	Accept the right subtree as new root which will take place of the node deleted. Join the left subtree to the left most node of the current subtree.

// Edge case can be when either right subtree or left subtree is absent.

struct Node{
	int val;
	Node*left;
	Node*right;
	Node(int v):val(v),left(nullptr),right(nullptr){}

};

Node*findLastRight(Node*root){
	if(!root->right)return root;
	return findLastRight(root->right);

}
Node*helper(Node*root){
	if(root->left==NULL)return root->right;
	else if(!root->right)return root->left;

	Node*rightChild=root->right;
	Node*lastRight=findLastRight(root->left);
	lastRight->right=rightChild;
	return root->left;

}
Node*deleteNode(Node*root,int key){
	if(!root)return NULL;
	if(root->val==key)return helper(root);
	Node*dummy=root;
	while(root){
		if(root->val>key){
			if(root->left!=NULL&&root->left->val==key)
			{
			root->left=helper(root->left);
			break;

			}
			else{
				root=root->left;

			}

		}else{
		if(!root->right && root->right->val==key){
		root->right=helper(root->right);
		break;
		}
		else{
		root=root->right;
		}

		}

	}
	return dummy;

}

void printInorder(Node*root){
	if(!root)return;
	printInorder(root->left);
	cout<<root->val<<",";
	printInorder(root->right);
}
int main(){
        Node*root=new Node(10);
        root->left=new Node(5);
        root->right=new Node(13);
        root->left->left=new Node(3);
        root->left->left->left=new Node(2);
        root->left->left->right=new Node(4);
        root->left->right=new Node(6);
        root->left->right->right=new Node(9);
        root->right->left=new Node(11);
        root->right->right=new Node(14);
	deleteNode(root,10);
	printInorder(root);

}
