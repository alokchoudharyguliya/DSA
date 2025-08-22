#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
int widthOfBinaryTree(Node*root){
	if(!root)return 0;
	int ans=0;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	while(!q.empty()){
		int size=q.size();
		int mmin=q.front().second;
		int first,last;
		for(int i=0;i<size;i++){
			int cur_id=q.front().second-mmin;
			Node*node=q.front().first;
			q.pop();
			if(i==0)
				first=cur_id;
			if(i==size-1)
				last=cur_id;
			if(node->left)q.push({node->left,cur_id*2+1});
			if(node->right)q.push({node->right,cur_id*2+2});


		}
		ans=max(ans,last-first+1);
	}
	return ans;
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
    cout<<widthOfBinaryTree(root);
}
