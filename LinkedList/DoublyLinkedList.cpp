/*
 *
 *
 *
 */
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node*next;
	struct Node*prev;
};
void printList(struct Node*head)
{
	struct Node*temp=head;
	if(head==NULL)return;
	while(temp!=NULL)
	{	
		cout<<temp->data;
		temp=temp->next;
	}
}
void append(struct Node**head_ref,int new_data){
	Node*new_node=new Node;
	struct Node*last=*head_ref;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL){
		new_node->prev=NULL;
		*head_ref=new_node;
	return;
	}
	while(last->next!=NULL) // last->next=NULL represents the last node in DLL
	{
		last=last->next;
	}
	last->next=new_node;
	new_node->prev=last;
	return;

}
int main(){
	struct Node*head=NULL;
	append(&head, 6);
	append(&head, 7);
	append(&head, 1);
	append(&head,4);
	printList(head);
}
