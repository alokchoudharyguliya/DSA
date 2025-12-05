// previous approach uses O(n) space complexity which can be eliminated by leveraging the properties of a BST instead, a prerequisite is the BSTIterator
// BSTIterator class allows one to access the next and previous elements(in order predecessor and successor) in a BST

// Using the BSTIterator class implementation, initialise pointers 'i' and 'j' to the first and last elements of the BST's inorder traversal.
// These pointers are navigated throught the BST using the next() and before() functions of th BSTIterator, 
// The 'i' pointer progresses towards larger values with next(), while 'j' moves towards smaller values with before()

// This approach leverages on the BST properties to efficiently navigate through the elements and identify the pair satisfying the given sum without using any additional data structure to store the inorder traversal,

#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*right;
    TreeNode*left;
    TreeNode(int x):val(x),right(nullptr),left(nullptr){}
};

class  BSTIterator{
    private:
    stack<TreeNode*>myStack;
    bool reverse;
    public:
    BSTIterator(TreeNode*root, bool isReverse):reverse(isReverse){
        pushAll(root);
    }
    bool hasNext(){
        return !myStack.empty();
    }
    int next(){
        TreeNode*tmpNode=myStack.top();
        myStack.pop();
        if(!reverse)pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }
    private:
    void pushAll(TreeNode*node){
            while(node!=nullptr){
                myStack.push(node);
                if(reverse)node=node->right;
                else node=node->left;
        }
    }
};
class Solution{
    public:
    bool findTarget(TreeNode*root, int k){
        if(!root)return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k)return true;
            else if(i+j<k)i=l.next();
            else j=r.next();
        }
        return false;
    }
};
void printInOrder(TreeNode*root){
    if(!root)return;
    printInOrder(root->left);
    cout<<root->val<<",";
    printInOrder(root->right);
}
int main(){
    TreeNode*root=new TreeNode(7);
    root->left=new TreeNode(3);
    root->right=new TreeNode(15);
    root->right->left=new TreeNode(9);
    root->right->right=new TreeNode(20);
    cout<<"Initialized"<<endl;
    printInOrder(root);
    cout<<endl;
    Solution sol;
    int target=22;
    bool exists=sol.findTarget(root,target);
    if(exists)cout<<"exists"<<endl;
    else cout<<"Pair Not found"<<endl;
}

// Space complexity O(H) where H is the height of the Binary Search Tree as the BST Iterator class uses a stack to store the nodes. At maximum the size of such a stack will be equal to the height of the binary tree.