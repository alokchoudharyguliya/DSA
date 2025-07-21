#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val){
		data=val;
		left=right=NULL;
	}
};
void preOrder(Node*root){
	if(root==NULL) return;
	cout<<root->data;
	if(root->left)
	preOrder(root->left);
	if(root->right)
	preOrder(root->right);
}
void postOrder(Node*root){
	if(root==NULL) return;
	if(root->left)
	postOrder(root->left);
	if(root->right)
		postOrder(root->right);
	cout<<root->data;
}
void inOrder(Node*root){
	if(root==NULL) return;
	if(root->left)
		inOrder(root->left);
	cout<<root->data;
	if(root->right)
		inOrder(root->right);
}
int main(){
	Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->right=new Node(5);
	preOrder(root);
	cout<<endl;
	postOrder(root);
	cout<<endl;
	inOrder(root);
}
