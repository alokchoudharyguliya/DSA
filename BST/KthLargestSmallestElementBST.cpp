#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
void printInorder(Node*root){
	if(!root)return;
	printInorder(root->left);
	cout<<root->data<<",";
	printInorder(root->right);
}
void inorder(Node*node,vector<int>&arr){
	if(!node)return;
	inorder(node->left,arr);
	arr.push_back(node->data);
	inorder(node->right,arr);
	return;

}
pair<int,int>findKth(Node*node,int k){

	vector<int>arr;
	inorder(node,arr);
	int kLargest=arr[arr.size()-k];
	int kSmallest=arr[k-1];
	return make_pair(kSmallest,kLargest);

}
int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    printInorder(root);
	cout<<endl;
	int k=3;
	pair<int,int>kthElements=findKth(root,k);
	cout<<kthElements.first<<kthElements.second<<endl;
}
