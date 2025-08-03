#include<bits/stdc++.h>
using namespace std;
// What is CEIL ? Ceiling of a value refers to the value of the smallest node in the binary search tree that is greater than or equal to the given key.
// The strategy to find the `ceil` value is to keep track of the smallest node value encountered that is greater than or equal to the key. Traverse the tree recursively and move through it until it reaches the end or locates the key.
// During the traversal, at every node, if the key matches the node’s values, it directly assigns the node’s value as the ceiling and concludes the search. If the key is greater than the current node’s value, the algorithm navigates to the right subtree to potentially find a larger value and if the key is smaller the algorithm updates the ceil value with the current node’s values and explores the left subtree for potentially smaller values.
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
int findCeil(Node*root,int key){
	int ceil=-1;
	while(root){
		if(root->data==key){
			ceil=root->data;
			return ceil;
		}
		if(key>root->data)
			root=root->right;
		else
		{
			// this node's value is greater than key so it might be ceil until i find any other smaller than current ceil but greater than or equal to target
			ceil=root->data;
			root=root->left;

		}
	}
	return ceil;

}
void printInorder(Node*root){
	if(!root)return;
	printInorder(root->left);
	cout<<root->data<<",";
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
	printInorder(root);
	cout<<endl;
	int target=8;
	int ceil=findCeil(root,target);
	if(ceil!=-1)
		cout<<"Ceil of "<<target<<" is "<<ceil<<endl;
	else
		cout<<"No ceil found";
	return 0;
}
