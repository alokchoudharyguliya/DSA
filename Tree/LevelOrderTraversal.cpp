// Algorithm
// 1. Create an empty queue q
// 2. Push the root node of tree to q. That is q.push(root).
// 3. Loop while the queue is not empty:
//     +   Pop the top node from queue and print the node.
//     +   Enqueue node's children (first left then right children) to q.
//     +   Repeat the process until queue is not empty.

#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void printLevelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Level order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}

// Create a struct newNode
// struct newNode
// {
//     int data;
//     struct newNode *left, *right;
// };

// Perform a levelOrderTraversal using a queue
// Push the first element into the queue and then
// run a while loop until the queue is not empty
// now push each of the right and left element and
// repeat for each element of the queue
// void levelOrderTraversal(struct newNove *root)
// {
//     if (root == nullptr)
//         return;
//     queue<newNode *> q;
//     q.push();
//     while (!q.empty())
//     {
//         node = q.top();
//         cout << node->data;
//         q.pop();
//         if (node->left != nullptr)
//             q.push(node->left);
//         if (node->right != nullptr)
//             q.push(node->right);
//     }
// }