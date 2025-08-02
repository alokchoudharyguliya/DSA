#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
Node*LCA(Node*root,Node*p,Node*q){
if(root==NULL||root==p||root==q)return root;
Node*left=LCA(root->left,p,q);
Node*right=LCA(root->right,p,q);
if(!left)return right;
else if(!right)return left;
else return root;

}
int main(){
Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(7);
	cout<<LCA(root,root->left->left,root->left->right)->data;
}
