/*
 * Head of a singly linked list of n nodes and an integer, k < n
 * Reverse the order of each group of k consecutive nodes, if n not divisible by k,
 * then last group of remaining nodes should remain unchanged
 *
 * Breaking the list into segments of K nodes and reversing each segment individually
 * Starting from the head, the algo traverses the list to identify segments of K nodes
 *
 * On finding a segment, it reverses it returning the modified list
 * If a segment has less than K nodes left(ie remaining nodes at the end) they are left unaltered
 *
 * Algorithm:
 * 	Initialize a pointer temp to the head of the linked list
 * 	Using temp traverse to the Kth Node iteratively
 *
 * 	On reaching the Kth Node, preserve the Kth Node's next node as nextNode and set the Kth Node's next pointer to null.
 * 	This effectively breaks the linked list in a smaller list of size k that can be reversed and attached back
 *
 */



#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node*next;
	Node(int data,Node*next){
		this->data=data;
		this->next=next;
	}
	Node(int data){
	this->data=data;
	this->next=nullptr;
	}
};
void printLinkedList(Node*head)
{	
	Node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}

Node* kReverse(Node*head,int k)
{
	Node*prevLast=NULL;
	Node*temp=head;

	while(temp!=NULL)
	{
		Node*kthNode=getKthNode(temp,k);
		if(kthNode==NULL) // means not a complete group, remaining leave unaltered
		{
			// If there was any previous group then join the remaning temp to previousGroup
			if(prevLast){
				prevLast->next=temp;
			}
			break;
		}	
		Node*nextNode=kthNode->next;
		kthNode->next=NULL;
		

	}
}
int main(){
	Node*head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(3);
	head->next->next->next=new Node(4);
	printLinkedList(head);
	kReverse(head,4);
}
