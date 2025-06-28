#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int key)
{
    struct node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
};
void inorder(struct node *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->key<<" ";
    inorder(temp->right);
}
void insert(struct node *temp, int key)
{
    queue<struct node *> q;
    q.push(temp);
    while (!q.empty())
    {
        struct node *temp = q.front();
        q.pop();

        if (!temp->left)
        {
            temp->left = newNode(key);
            break;
        }
        else
        {
            q.push(temp->left);
        }

        if (!temp->right)
        {
            temp->right = newNode(key);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    struct node *root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    inorder(root);
    int key = 12;
    insert(root, key);
    cout << endl;
    inorder(root);
    return 0;
}