/*
 * Floyd's Cycle Finding Algorithm = Fastest Method
 *
 * Traverse linked list using two poitners.
 * Move one pointer by one step and another pointer by two step.
 * If these pointer meet at the same node then there is a loop. If pointers do not meet then linkedlist doesn't have a loop.
 *
 * If there is a circle then there will be overlap.
 */

#include<bits/stdc++.h>
using namespace std;
	

struct Node{
	 int data;
	 struct Node*next;
};

bool detectLoop(Node*head)
{
	Node*slow_p=head, *fast_p=head;
	while(slow_p&&fast_p&&fast_p->next)
	{
		slow_p=slow_p->next;
		fast_p=fast_p->next->next;
		if(slow_p==fast_p)
				return true;
	}
	return false;
}

void append(struct Node**head, int new_data){
	struct Node*new_node=new Node;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head==NULL)
	{
		*head=new_node;
		return;
	}
	struct Node*last=(*head);
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new_node;
}

void printList(struct Node*head)
{
	while(head!=NULL){
			cout<<head->data<<",";
			head=head->next;
	}
}

int main(){
	struct Node*head=NULL;
	append(&head,8);
	append(&head,9);

	printList(head);
	head->next->next=head;
	cout<<endl;
	detectLoop(head)?cout<<"Cycle":cout<<"NoCycle";
	cout<<endl;
	return 0;
}
