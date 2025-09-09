#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	
	Node(int val):data(val),left(nullptr),right(nullptr){}
	void printInorder();
	void printinorder();
	vector<vector<int>preInPostTraversal();
};
vector<vector<int>>preInPostTraversal()
{
	vector<int>pre,in,post;
	if(root==NULL)
		return {};
	stack<pair<Node*,int>>st;
	st.push({root,1});
	while(!st.empty()){
		auto it=st.top();
		st.pop();
		if(it.second==1){
			pre.push_back(it.first->data);
			it.second=2;
			st.push(it);
			if(it.first->left)st.push({it.first->left,1});
		}
		else if(it.second==2){
		in.push_back(it.first->data);
		it.second=3;
		st.push(it);
		if(it.first->right)
			st.push(it.first->right,1):

		}
	}


}
	
void Node::printinorder(){
	this==NULL?void():
		(
		 this->left->printinorder(),
		 cout<<this->data<<" ",
		 this->right->printinorder()
		);

}
void Node::printInorder(){
	if(this==NULL){
		return;
	}else
	{
		this->left->printInorder();
		cout<<this->data<<" ";
		this->right->printInorder();
	}
}

int main(){
	Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->printInorder();

}
