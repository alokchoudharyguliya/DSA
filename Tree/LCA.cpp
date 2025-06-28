// Naive Approach


// Optimized Approach -  We assume that the numbers are present in the binary tree
// Traverse the tree starting from the root node.
// If any of the given keys(n1 and n2) matches with root, then the root is LCA
// (assuming that both keys are present)
// If root doesn't match with any of the keys, we recur for left and right subtrees.
// The node which has one key present in its left subtree and other key present in the right subtree is the LCA.
// If  both keys lie in left subtree, then subtree has LCA also, otherwise LCA lies in the right subtree

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

node *newNode(int k)
{
    node *temp = new node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

bool findPath(node *root, vector<int> &path, int k)
{
    if (root == NULL)
        return false;
    // Store this node in path vector.
    // The node will be removed if
    // not in path from root to k
    path.push_back(root->key);
    // see if the k is same as root's key
    if (root->key == k)
        return true;
    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
        return true;
    // If not present in subtree rooted with root,
    // remove root from path[] and return false
    path.pop_back();
    return false;
}
int findLCA(node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
    {
        if (path1[i] != path2[i])
            break;
    }
    return path1[i - 1];
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4,5) = " << findLCA(root, 4, 5);
    return 0;
}