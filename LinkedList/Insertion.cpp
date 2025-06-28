/*
 *
 * Insert 1. Beginning
 * 	  2. After a given node
 * 	  3. End
 */
#include<bits/stdc++.h>

using namespace std;
struct Node{
	int data;
	struct Node*next;
};

void push(struct Node**head_ref, int new_data){
	Node*new_node=new Node;
	new_node->data=new_data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}
void insertAfter(struct Node*prev_node, int new_data){
	if(prev_node==NULL){
		printf("Given previous node cannot be NULL");
		return;
	}
	Node*new_node=new Node;
	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
}
void append(struct Node**head_ref, int new_data){
	Node*new_node=new Node;
	struct Node*last=*head_ref;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL){
		*head_ref=new_node;
		return;
	}
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=new_node;
	return;
}
// Deletion of Node
void deleteNode(struct node**head_ref, int key){
	struct Node*temp=*head_ref, *prev;
	if(temp!=NULL && temp->data==key){
		*head_ref=temp->next;
		free(temp);
		return;
	}
}
int main(){
	return 0;
}
