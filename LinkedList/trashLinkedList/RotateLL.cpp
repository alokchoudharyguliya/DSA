#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
		Node(int new_data){
			data=new_data;
			next=NULL;
		}
		Node(int new_data,Node*next){
			data=new_data;
			this->next=next;
		}
};
void insertNode(Node**head, int val)
{
	Node*new_node=new Node(val);
	if(*head==NULL){
		*head=new_node;
		return;
	}

	Node*temp=*head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
}
void printList(Node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}

}
int main(){
	Node*head=NULL;
	insertNode(&head,3);
	insertNode(&head,2);
	insertNode(&head,5);
	insertNode(&head,1);
	insertNode(&head,4);
	insertNode(&head,7);
	printList(head);
	return 0;
}	
