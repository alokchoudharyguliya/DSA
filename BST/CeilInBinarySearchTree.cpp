// traverse the tree recursively and move through it until it reaches the end or locates the key, During the traversal, at every node, if the key matches the node's values, it directly assigns the node's values as the ceiling and concludes the search
// If the key is greater than the current node's value, the algo, navigates to the right subtree to potetially find a larger value and if the key is smaller the algorithm updates the ceil value with the current node's value, and explore the left subtree or potentially smaller value
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};
class Solution
{
    public:
    int findCeil(TreeNode *root, int target)
    {
        int ceil=-1;
        while(root){
            if (target < root->val)
            {
                ceil = root->val;
                root = root->left;
            }
            else if(root->val==target)
            {
                return target;
            }else
            {
                root = root->right;
            }
        }
        return ceil;
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
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    cout << endl;
    printInorder(root);
    cout << endl;
    Solution sol;
    int target = 8;
    int ceil = sol.findCeil(root, target);
    cout<<ceil<<endl;
}