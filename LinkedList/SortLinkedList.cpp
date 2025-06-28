#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct	Node*next;
};
void append(Node**head,int new_data){
	struct Node*new_node=new Node;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head==NULL)
	{
		*head=new_node;
		return;
	}
	struct Node*last=*head;
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=new_node;
}
void printList(Node*head){
	while(head!=NULL){
		cout<<head->data<<",";
		head=head->next;
	}
}

Node*findMiddle(Node*head){
	if(head==nullptr || head->next==nullptr)
			return head;
	Node*slow=head;
	Node*fast=head->next;

	while(fast!=nullptr && fast->next!=nullptr){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
Node*mergeTwoSortedLinkedLists(Node*list1,Node*list2){
	Node*dummyNode=new Node;
	dummyNode->data=-1;
	dummyNode->next=NULL;
	Node*temp=dummyNode;
	while(list1!=nullptr&&list2!=nullptr){
		if(list1->data<=list2->data){
			temp->next=list1;
			list1=list1->next;
		}
		else{
			temp->next=list2;
			list2=list2->next;
		}
		temp=temp->next;
	}
	if(list1!=nullptr)
		temp->next=list1;
	else
		temp->next=list2;
	return dummyNode->next;
}
Node*sortLL(Node*head){
	if(head==nullptr || head->next==nullptr)
		return head;
	Node*middle=findMiddle(head);
	Node*right=middle->next;
	middle->next=nullptr;
	Node*left=head;

	left=sortLL(left);
	right=sortLL(right);
	return mergeTwoSortedLinkedLists(left,right);
}
int main(){
	struct Node*head=NULL;
	append(&head,9);
	append(&head,2);
	append(&head,1);
	printList(head);
	head=sortLL(head);
	printList(head);
	return 0;

}
