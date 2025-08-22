#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),right(nullptr),left(nullptr){}
};

int findHeightLeft(Node*root){

	int height=0;
	while(root){
		height++;
		root=root->left;}
	return height;
}
int findHeightRight(Node*right){
	int height=0;
	while(right){
		height++;
		right=right->right;
	}
	return height;
}

int countNodes(Node*root){
	if(!root)return 0;
	int lh=findHeightLeft(root);
	int rh=findHeightRight(root);
	if(lh==rh)return (1<<lh)-1;
	return 1+countNodes(root->left)+countNodes(root->right);
}


int main(){
Node*root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
root->right->left=new Node(6);

cout<<countNodes(root);

}
