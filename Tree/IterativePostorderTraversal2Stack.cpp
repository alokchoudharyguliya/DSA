#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
vector<int> postOrder(Node*root){
	vector<int>postorder;
	if(root)return postorder;
	stack<Node*>st1,st2;
	st1.push(
}
void printVector(const vector<int>&vec){
	for(int num:vec)
		cout<<num<<" ";
	cout<<endl;
}
int main(){
	Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);

	vector<int>res=postOrder(root);
	cout<<"PostOrder traversal";
	printVector(res);
	return 0;

}
