#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*random;
    node():data(0), next(nullptr), random(nullptr){};
    node(int x):data(x), next(nullptr), random(nullptr){}
    node(int x, node*nextNode, node*randomNode):data(x), next(nextNode), random(randomNode){}
};
void insertCopyInBetween(node*head){
    node*temp=head;
    while(temp){
        node*nextEle=temp->next; // store the next into somewhere
        node*copy=new node(temp->data); // create a new copy node
        copy->next=nextEle; // assign the stored next into the next of the new node
        temp->next=copy; // make the new copy node as the next of inital temp head
        temp=nextEle; // assign the next node to temp
    }
}
void connectRandomPointers(node*head){
    node*temp=head;
    while(temp!=NULL){
        node*copyNode=temp->next; // we already connected the copy node as next so now the next node is the copy of current head

        if(temp->random){
            copyNode->random=temp->random->next; // assign the copyNode's random as the next node of temp's random which is the copy node itself of temp's random
        }
        else{
            copyNode->random=NULL;
        }
        temp=temp->next->next; // next node is the copy node of current node

    }
}
node*getDeepCopyList(node*head){
    node*temp=head;
    node*dummyNode=new node(-1);// used for returning the correct head back, that is copyLL's head
    node*res=dummyNode;
    while(temp!=NULL){
        res->next=temp->next; // storing the copy node of current node
        res=res->next;
        temp->next=temp->next->next; // skipping one node in between
        temp=temp->next;
    }
    return dummyNode->next;
}
node*cloneLL(node*head){
    if(!head)return nullptr;
    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}
void printClonedLinkedList(node*head){
    while(head!=nullptr){
        cout<<head->data;
        if(head->random!=nullptr)
        cout<<", Random: "<<head->random->data;
        else
        cout<<", Random: nullptr";
        cout<<endl;
        head=head->next;
    }
}
int main()
{
    node*head=new node(7);
    head->next=new node(14);
    head->next->next=new node(21);
    head->next->next->next=new node(29);

    head->random=head->next->next;
    head->next->random=head;
    head->next->next->random=head->next->next->next;
    head->next->next->next->random=head->next;
    // cout<<head->data;
    printClonedLinkedList(head);
    node*clonedList=cloneLL(head);
    cout<<"After Cloning Cloned LL is"<<endl;
    printClonedLinkedList(clonedList);
    return 0;
}
