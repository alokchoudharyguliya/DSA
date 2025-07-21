#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left,*right;
	Node(int data){
		this->data=data;
		this->left=this->right=NULL;
	}
};
void levelOrderTraversal(Node*root){
	if(!root) return;
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		Node*ele=q.front();
		cout<<ele->data<<",";
//		int val=q.top().data;
		q.pop();
		if(ele->left)
			q.push(ele->left);
		if(ele->right)
			q.push(ele->right);
	}

}
int main(){
	Node*root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);

	levelOrderTraversal(root);
}
