#include<bits/stdc++.h>
using namespace std;
// What is FLOOR- Floor of a value refers to the value of the largest node in the BST that is smaller than or equal to the given key.
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int v):data(v),left(nullptr),right(nullptr){}

};
int floorBST(Node*root,int key){
	int floor=-1;
	while(root){
		if(root->data==key){
			floor=root->data;
			return floor;
		}
		if(root->data>key){
		root=root->left;
		}
		else if(root->data<key){
			floor=root->data;
			root=root->right;

		}
	}
	
	return floor;
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
	int floor=floorBST(root,8);
	floor!=-1?cout<<"Floor of "<<8<<" is "<<floor<<endl:cout<<"Floor not found"<<endl;

}
