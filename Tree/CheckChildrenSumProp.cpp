// sum of its children's values(if they exist) should be equal to the node's value
// if a child is missing, its value is 0
// node value can be increased by any positive integer any number of times, but decrementing any node value is not allowed.
// a value for a NULL node can be assumed as 0.
// we cannot change the structure of the given binary tree.


// we traverse and if sum of children is lesser than parent then we increase one of child, else if sum of children is greater than parent we increase parent
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node*left;
	Node*right;
	Node(int v):val(v),left(nullptr),right(nullptr){}
};
void changeTree(Node*root){
	if(!root)return;

	int child=0;
	if(root->left)child+=root->left->val;
	if(root->right)child+=root->right->val;

	if(child>=root->val)
		root->val=child;
	else{
		if(root->left)
			root->left->val=root->val;
		else if(root->right){
			root->right->val=root->val;

		}
	}
	changeTree(root->left);
	changeTree(root->right);
	int tot=0;
	if(root->left)tot+=root->left->val;
	if(root->right)tot+=root->right->val;
	if(root->left||root->right)root->val=tot;
}
void inorderTraversal(Node*root){
	if(!root)return;
	inorderTraversal(root->left);
	cout<<root->val<<",";
	inorderTraversal(root->right);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    inorderTraversal(root);
    changeTree(root);
    cout<<endl;
    inorderTraversal(root);

}
