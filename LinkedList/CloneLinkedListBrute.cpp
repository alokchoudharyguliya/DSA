// Copy into a unorderd_map
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node() : data(0), next(nullptr), random(nullptr) {};
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
    Node(int x, Node *nextNode, Node *randomNode) : data(x), next(nextNode), random(randomNode) {}
};
void printClonedLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data;
        cout << ", Random: ";
        if (head->random != nullptr)
            cout << head->random->data;
        else
            cout << "nullptr";
        cout << endl;
        head = head->next;
    }
}
Node *cloneLL(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, Node *> mpp; // wil store key and value both as Nodes that is key is original node and value is the new copy node
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        Node *copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head]; // return the head of copied LinkedList
}

int main()
{
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;
    printClonedLinkedList(head);
    Node *clonedList = cloneLL(head);
    cout << "After cloning, Cloned List is" << endl;
    printClonedLinkedList(clonedList);
}