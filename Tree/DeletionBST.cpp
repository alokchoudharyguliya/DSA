#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};
void inorder(struct node *root)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->key;
    inorder(temp->right);
}
void deletDeepest(struct node *root, struct node *d_node)
{
    queue<struct node *> q;
    q.push(root);

    struct node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}
void deletion(struct node *root, int key)
{
    queue<struct node *> q;
    q.push(root);
    struct node *temp;
    struct node *key_node = NULL;

    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->key == key)
            key_node = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    int x = temp->key;
    deletDeepest(root, temp);
    key_node->key = x;
}
void insert(struct node *temp, int key)
{
}
int main()
{
    struct node *root = node(10);
    root->left = node(11);
    root->right = node(7);
    root->left->left = node(12);
    root->right = node(9);
    root->right->left = node(15);
    root->right->right = node(8);
    cout << "Inorder traversal before deletion:";
    inorder(root);
    int key = 11;
    deletion(root, key);
    cout << endl;
    cout << "Inorder traversal after deletion:";
    inorder(root);
    return 0;
}