#include<bits/stdc++.h>
using namespace std;
// What is a completet binary tree - a binary tree where all levels, except possibly the last one, are completely filled, and the nodes in last level are as left as possible.
// Brute force - Traverse the binary tree INORDER and count the number of nodes, but here neither we use the fact that binary tree is complete nor we detect it(though it is given that it is a complete binary tree)
//
//
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
void inorder(Node*root,int&count){
	if(!root)return;
	count++;
	inorder(root->left,count);
//	cout<<root->data<<",";
	inorder(root->right,count);
}
int countNodes(Node*root){
	if(!root)return 0;
	int count=0;
	inorder(root,count);
	return count;

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
	cout<<countNodes(root);
}
