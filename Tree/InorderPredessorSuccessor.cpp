#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    TreeNode*inorderSuccessor(TreeNode*root,TreeNode*p){
        vector<int>inorder;
        InorderTraversal(root,inorder);
        int idx=binarySearch(inorder,p->val);
        if(idx==(int)inorder.size()-1||idx==-1)return nullptr;
        return new TreeNode(inorder[idx+1]);
    }
    void InorderTraversal(TreeNode*root,vector<int>&inorder){
        if(root==nullptr)return;
        InorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        InorderTraversal(root->right,inorder);
    }
    int binarySearch(vector<int>&arr,int target){
        int left=0,right=(int)arr.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr[mid]==target)return mid;
            else if(arr[mid]<target)left=mid+1;
            else right=mid-1;
        }
        return left==(int)arr.size()?-1:left;
    }
};

void printInOrder(TreeNode*root){
    if(root==nullptr)return;
    printInOrder(root->left);
    cout<<root->val<<" ";
    printInOrder(root->right);
}

int main(){
    TreeNode*root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right->right=new TreeNode(7);

    // printInOrder(root);

    TreeNode*p=root->left->right;
    Solution solution;
    TreeNode*successor=solution.inorderSuccessor(root,p);
    if(successor!=nullptr)
    cout<<p->val<<successor->val<<endl;
    else
    cout<<p->val<<endl;
}
// for predecessor just check for idx==0 or -1 and then return the idx-1 th element