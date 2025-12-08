#include<bits/stdc++.h>
using namespace std;
 
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int value){
        data=value;
        prev=nullptr;
        next=nullptr;
    }
};
class Solution{
    public:
    Node*head=nullptr;
    void insertAtEnd(int value){
        Node*newNode=new Node(value);
        if(!head){
            head=newNode;
            return;
        }
        Node*current=head;
        while(current->next){
            current=current->next;
        }
        current->next=newNode;
        newNode->prev=current;
    }
    Node*removeDuplicates(){
        if(!head)return nullptr;
        Node*curr=head;

        // Traverse the list until the second last node
        while(curr!=nullptr&&curr->next!=nullptr){
            Node*nextDistinct=curr->next;
            // Skip and delete all nodes with same value as current
            while(nextDistinct!=nullptr&&nextDistinct->data==curr->data){
                Node*duplicateNode=nextDistinct;
                nextDistinct=nextDistinct->next;
                delete duplicateNode;
            }
            curr->next=nextDistinct;
            if(nextDistinct!=nullptr){
                nextDistinct->prev=curr;
            }
            curr=curr->next;
        }
        return head;
    }
    void printList(){
        Node*curr=head;
        while(curr){
            cout<<curr->data<<",";
            curr=curr->next;
        }
        cout<<endl;
    }
};


int main(){
    Solution sol;
    vector<int>values={1, 2, 2, 2, 3, 4, 4, 5, 5, 6};
    for(int val:values)
    sol.insertAtEnd(val);

    sol.printList();

    sol.removeDuplicates();
    sol.printList();
}