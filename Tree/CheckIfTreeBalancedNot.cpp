#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{

public:
    bool isBalanced(Node *root)
    {
        if (root == nullptr)
            return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }
    int height(Node *root)
    {
        if (!root)
            return 0;
        int lheight = height(root->left);
        int rheight = height(root->right);
        // return 1 + max(height(root->left), height(root->right));
        return 1 + max(rheight, lheight);
    }
};
int main()
{
    Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->right->left = new Node(4);
    // root->right->right = new Node(5);
    // root->right->left->left = new Node(6);
    // root->right->left->left->left = new Node(7);
    // root->right->right = new Node(8);
    // root->right->right->right = new Node(9);
    // root->right->right->right->right = new Node(10);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->right->right = new Node(6);
    // root->left->right->right->right = new Node(7);
    Solution sol;
    sol.isBalanced(root) ? (cout << "Balanced" << endl) : (cout << "Not Balanced" << endl);
}