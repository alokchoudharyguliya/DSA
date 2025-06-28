#include <bits/stdc++.h>
using namespace std;
struct StackNode
{
    int data;
    struct StackNode *next;
};
struct StackNode *newNode(int data)
{
    struct StackNode *stackNode = new StackNode;
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
int isEmpty(struct StackNode *root)
{
    return !root;
}
void push(struct StackNode **root, int data)
{
    struct StackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " pushed to stack\n";
}
int pop(struct StackNode **root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
int peek(struct StackNode *root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}
