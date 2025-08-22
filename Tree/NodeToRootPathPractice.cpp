#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}
};
bool getPath(Node*root,vector<int>&arr,int target){
		if(!root)return false;
		arr.push_back(root->data);
		if(root->data==target)return true;
		if(getPath(root->left,arr,target)||getPath(root->right,arr,target))return true;
		arr.pop_back();
		return false;

}
vector<int>solve(Node*root,int target){
	vector<int>ans;
	if(!root)return ans;
	getPath(root,ans,target);
	return ans;
}
int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
	root->right->left = new Node(5);
	int target=4;
	vector<int>ans=solve(root,4);
	for(auto it:ans)
		cout<<it<<",";
}
