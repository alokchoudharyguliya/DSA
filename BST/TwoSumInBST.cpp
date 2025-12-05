// the inorder traversal of a BST gives a sorted sequence, on this sorted sequence we can apply the Two Sum problem to return the pair with sum equal to K, this can be done by initializing two pointers at the sequence starts and end, navigating based on their sum compared to the target. 
// this approach leverages the sorted nature of the inorder traversal of a BST
// inorder traversal which returns elements in ascending order, the inorder traversal of a BST can be obtained by traversing the tree in the recursive order, left subtree-> root -> right subtree

// After getting the inorder traversal, we'll have a sorted sequence, initialize two pointers, one at the beginning (left end) and the other at the end (right side) of the sequence, as the sequence is sorted.
// If the sum of the values at these pointer is less than the target, increment the left pointer, this will move towards larger values, 
// If the sum is greater than the target, decrement the right pointer, this will move towards smaller value.
// If the sum is equal return the pair of values.

#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};
class Solution{
    private:
    void inorderTraversal(TreeNode*root, vector<int>&inorder){
        if(!root)return;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
    }
    public:
    bool findTarget(TreeNode*root, int k){
        vector<int>inorder;
        inorderTraversal(root, inorder);
        int left=0;
        int right=inorder.size()-1;
        while(left<right){
            int sum=inorder[left]+inorder[right];
            if(sum==k)return true;
            else if(sum<k)left++;
            else right--;
        }
        return false;
    }
};
int main(){
    TreeNode*root=new TreeNode(7);
    root->left=new TreeNode(3);
    root->right=new TreeNode(15);
    root->right->left=new TreeNode(9);
    root->right->right=new TreeNode(20);
    Solution sol;
    int target=22;
    bool exists=sol.findTarget(root,target);
    if(exists)cout<<"Pair exists"<<endl;
    else cout<<"No Pair"<<endl;
    return 0;
}