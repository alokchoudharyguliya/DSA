#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node*next;
};

void printList(Node*node){
		while(node!=NULL){
			cout<<node->data<<" ";
			node=node->next;	
		}
}
void push(struct Node**head_ref, int new_data)
{
	Node*new_node=new Node;
	new_node->data=new_data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node; // dereferencing the pointer to head
}

void insertAfter(struct Node*prev_node, int new_data){
	if(prev_node==NULL){
		return;
	}
	Node*new_node=new Node;

	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
	
}

void append(Node**head_ref, int new_data)
{
	// Allocate Node
	Node*new_node=new Node;
	new_node->data=new_data;
	new_node->next=NULL;
	struct Node*last=*head_ref;
	// Check if the list is empty
	if(*head_ref==NULL){
		*head_ref=new_node;
		return;
	}
	// Else go till the last of LL
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=new_node;
	return;
}
// Find the previous node of the node to be deleted
// Change the next of previous node
// Free memory for the node to be deleted
void deleteNode(Node**head_ref,int key,){
	struct Node*temp=*head_ref, &prev;
	if(temp!=NULL && temp->data==key){
		*head_ref=temp->next; // Here we have modified the head_pointer that we received from the main function
		free(temp);
		return;
	}
	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)	return;
	prev->next=temp->next;
	free(temp);
}
void deleteNodePos(struct Node**head_ref,  int pos)
{
	if(*head_ref==NULL) return;

	struct Node*temp=*head_ref;

	if(position==0){
		head_red=temp->next;
		free(temp);
		return;
	}

	for(int i=0;temp!=NULL && i<position-1; i++){
		temp=temp->next;
	}
	if(temp==NULL||temp->next==NULL) return;
	struct Node*next=temp->next->next;
	free(temp->next);
	temp->next=next;
}
// Finiding the node just previous to it and updating its next pointer
// struct Node*temp=node_ptr->next;
// node_ptr->data=temp->data;
// node_ptr->next=temp->next;
// free(temp);
// This will fail if the node to be deleted is the last node of LL
int main(){
	struct Node*head=NULL;
	struct Node*second=NULL;
	struct Node*third=NULL;

	head = new Node;
	second=new Node;
	third=new Node;

	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->next=NULL;
	third->data=3;
	printList(head);
	return 0;
}

