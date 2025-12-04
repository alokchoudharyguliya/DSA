// inorder successor means for a num X its successor will be for sure greater than X

// Initialize a variable successor as the maximum integer value,
// Traverse the binary search tree based on the key value
// If the current node value is smaller than the key, move to its right child
// If the current node value is greater than the key, update successor to the minimum between the current successor, and the current node value, then move to the left child
// Continue this process until the traversal reaches a null node

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *successor = nullptr;
        while (root != nullptr)
        {
            if (p->val >= root->val)
            {
                root = root->right;
            }
            else
            {
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
};
void printInorder(TreeNode *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << ",";
    printInorder(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    cout << "BST" << endl;
    printInorder(root);
    cout << endl;
    TreeNode *p = root->left->right;
    Solution sol;
    TreeNode *successor = sol.inorderSuccessor(root, p);
    if (successor)
        cout << successor->val << endl;
    else
        cout << "Inorder successor doesn't exit";
}