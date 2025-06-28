/*
 *
 * Reverse a Linked List by changing links between nodes
 *
 * 1. Three Pointers Solution:
 * 	Using three auxiliary three pointers prev, current, next
 *
 * 	Initially 
 * 	1 -><- prev=head=2 <- cur=3  next=4
 *	cur->next=prev
 *	prev=cur
 *	cur=next
 *	next=cur->next
 *	cur->next=prev
 *	....
 *	....
 *
 *	while(current!=NULL){
 *		next=current->next;
 *		curr->next=prev;
 *		prev=cur;
 *		cur=next; *
 *	}
 *	*head_ref=prev;
 *
 */

#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node*next;
};
void append(struct Node**head_ref, int new_data){
	struct Node*new_node=new Node;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL)
	{
		*head_ref=new_node;
		return;
	}
	struct Node*last=(*head_ref);
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=new_node;
	return;
}
void printList(struct Node*head){
	if(head==NULL)return;
	while(head!=NULL){
		cout<<head->data<<",";
		head=head->next;
	}
}
void reverse(struct Node**head){
	struct Node*next, *curr, *prev;
	prev=NULL;
	curr=*head;
	next=NULL;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;;
	}
	*head=prev;
}
int main(){
	struct Node*head=NULL;
//	head->data=1;
//	printList(head);
	append(&head,5);
	append(&head,6);
	append(&head,7);
	printList(head);
	reverse(&head);
	printList(head);
return 0;
}
