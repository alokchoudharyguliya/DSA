// Talking about boundary simply means left boundary, right boundary and the bottom boundary
// nodes must not be considered twice like the bottom boundary corners and right and left boundary
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int val) : data(val), right(nullptr), left(nullptr) {}
};
class Solution
{
public:
    bool isLeaf(Node *root)
    {
        return !root->left && !root->right;
    }
    void addLeftBoundary(Node *root, vector<int> &res)
    {

        Node *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    void addRightBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
            res.push_back(temp[i]);
    }
    void addLeaves(Node *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        if (root->left)
            addLeaves(root->left, res);
        if (root->right)
            addLeaves(root->right,res);
    }
    vector<int> printBoundary(Node *root)
    {
        vector<int>res;
        if (!root)
            return res;
        if (!isLeaf(root))
            res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};
void printResult(const vector<int>&rest){
    for(int val:rest){
        cout<<val<<",";
    }
    cout<<endl;
}
int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution sol;
    vector<int> res = sol.printBoundary(root);
    printResult(res);
}
