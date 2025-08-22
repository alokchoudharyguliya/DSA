#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};

vector<vector<int>>levelOrder(Node*root){
	vector<vector<int>>res;
	if(!root)return res;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		int size=q.size();
		vector<int>ans;
		for(int i=0;i<size;i++){
		Node*temp=q.front();
		q.pop();
		ans.push_back(temp->data);
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
		}
		res.push_back(ans);

	}
	return res;
}

vector<int>rightSide(Node*root){
	vector<int>res;
	vector<vector<int>>levelOrderTraversal=levelOrder(root);
	for(auto level:levelOrderTraversal){
		res.push_back(level.back());
	}
	return res;
}
vector<int>leftSide(Node*root){
	vector<int>res;
	vector<vector<int>>levelOrderTraversal=levelOrder(root);
	for(auto level:levelOrderTraversal){
	res.push_back(level.front());

	}
	return res;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<int>rightView=rightSide(root);
    for(auto node:rightView){
		cout<<node<<",";
    }
    cout<<endl;
    vector<int>leftView=leftSide(root);
    for(auto node:leftView){
		cout<<node<<",";
    }
    cout<<endl;

}
