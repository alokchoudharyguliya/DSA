// floor of a value refers to the value of the largest node in the BST, that is smaller than or equal to the given key, If the floor node does not exist return nullptr
// track the largest node encountered that is smaller than or equal to the key. It traverses the tree, either finding the exact key or reaching  the nodes, that approach the given key's value
// if key matches the node's values, it directly assigns the node's value as the floor and conclude
// if the key is smaller than node's value, then navigate to the left subtree, to find a smaller value and if the key is larges then, floor value update to the current node's value and explore the right subtree for potentially larger values
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*right;
    TreeNode*left;
    TreeNode(int x):val(x), left(nullptr),right(nullptr){}
};
class Solution{
    public:
    int floorInBST(TreeNode*root,int target){
        int floorV=-1;
        while(root!=nullptr){
            if(root->val<target){
                floorV=root->val;
                root=root->right;
            }
            else if(root->val==target)
            {
                floorV=target;
                break;
                return target;
            }
            else{
                root=root->left;
            }
        }
        return floorV;
    }
};
void printInorder(TreeNode*root){
    if(!root)return;
    printInorder(root->left);
    cout<<root->val<<",";
    printInorder(root->right);
}
int main(){
    TreeNode*root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(13);
    root->left->left=new TreeNode(3);
    root->left->left->left=new TreeNode(2);
    root->left->left->right=new TreeNode(4);
    root->left->right=new TreeNode(6);
    root->left->right->right=new TreeNode(9);
    root->right->left=new TreeNode(11);
    root->right->right=new TreeNode(14);

    cout<<endl;
    printInorder(root);
    cout<<endl;
    Solution sol;
    int target=8;
    int floorVal=sol.floorInBST(root,target);
    cout<<floorVal<<endl;
}