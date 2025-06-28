/*
 *
 * We have a linkedList 
 * head=[1,2,3,4,5]
 * k=2
 * after rotation toward right
 * head=[4,5,1,2,3]
 *
 * Approach Move the last element to first for each k
 *
 *
 * Better approach is:
 * 	Calculate the length of the list
 * 	Connect the last node to the first node, converint it to a circular linked list
 * 	Iterate to cut the link of the last node and state a node of k%length of the list rotated
 */
#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int num;
		node*next;
		node(int a){
			num=a;
			next=NULL;
		}
};

void insertNode(node* &head, int val){
	node*newNode=new node(val);
	if(head==NULL){
		head=newNode;
		return;
	}
	node*temp=head;
	while(temp->next!=NULL) temp=temp->next;

	temp->next=newNode;
	return;
}

node*rotateRight(node*head,int k)
{
	if(head==NULL||head->next==NULL||k==0) return head;
	node*temp=head;
	int length=1;
	while(temp->next!=NULL){
		++length;
		temp=temp->next;
	}
	temp->next=head;
	k=k%length;
	int end=length-k;

	while(end--)temp=temp->next;
	head=temp->next;	
	temp->next=NULL;
	return head;
}
void printList(node*head){
	while(head->next!=NULL){
		cout<<head->num<<"->";
		head=head->next;
	}
	cout<<head->num<<endl;
	return;
}
int main(){
	node*head=NULL;
	insertNode(head,1);
	insertNode(head,2);
	insertNode(head,3);
	insertNode(head,4);
	insertNode(head,5);
	insertNode(head,6);

	cout<<"Original List"<<endl;
	printList(head);
	int k=2;
	node*newHead=rotateRight(head,k);
	cout<<endl;
	printList(newHead);
	return 0;
}
