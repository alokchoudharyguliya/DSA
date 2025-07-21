#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int val){
		this->val=val;
		this->right=NULL;
		this->left=NULL;
	}
//	TreeNode(int val, TreeNode*left, TreeNode*right):val(val),right(right),left(left){}
};
class Solution{
	public:
		vector<int>preOrderTraversal(TreeNode*root){
			vector<int>preorder;
			if(root==nullptr)
				return preorder;
			stack<TreeNode*>st;
			st.push(root);
			while(!st.empty())
			{
				root=st.top();
				st.pop();
				preorder.push_back(root->val);

				if(root->right)st.push(root->right);
									if(root->left)st.push(root->left);
			}
			return preorder;
		}
};


int main(){
	TreeNode*root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	Solution sol;
	vector<int>result=sol.preOrderTraversal(root);
	for(int val:result)
		cout<<val<<" ";
	cout<<endl;
	cout<<"Preorder Traversal";
}
