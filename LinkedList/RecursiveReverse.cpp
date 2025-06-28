/*
 * Passing a single pointer, making previous node of current node as his next node to reverse the linked list.
 *
 * Return the pointer of next node to his previous(current) node and then make the previous node as the next node of returned node and then returning the current node.
 *
 * First traverse till the last node and making the last node as the head node of reversed linked list and then applying the above procedure in the recursive manner.
 *
 */
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node*next;
};
void append(struct Node**head,int new_data){	
	struct Node*new_node=new Node;
	new_node->data=new_data;
	new_node->next=NULL;

	if(*head==NULL)
	{	
		(*head)=new_node;
		return;
	}

	struct Node*last=(*head);
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new_node;
}
void printList(struct Node*head){
	while(head!=NULL){
		cout<<head->data;
		head=head->next;
	}
}
Node*reverse(Node*node,struct Node**head){
	if(node==NULL)
		return NULL;
	if(node->next==NULL){
		*head=node;
			return node;
	}
	Node*temp=reverse(node->next,head);
	temp->next=node;
	node->next=NULL;
	return node;
}
int main(){
	struct Node*head=NULL;
	append(&head,5);
	append(&head,6);
	append(&head,7);
	printList(head);
	reverse(head,&head);
	printList(head);
}
