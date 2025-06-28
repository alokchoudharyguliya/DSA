/*
 * Node Count Difference Solution:
 * 	Get the count of the nodes in the first list, let count be c1.
 * 	Get a count of the nodes in the second list, let count be c2.
 * 	Get the difference of counts d=abs(c1-c2).
 * 	Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
 * 	Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node by comparing the address of the nodes).
 */

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node*next;
};

int getCount(Node*head)
{
	int cnt=0;
	while(head!=NULL){
		cnt++;
		head=head->next;
	}
	return cnt;

}
int utility(int d, Node*head1, Node*head2);
int getIntersectionNode(Node*head1, Node*head2)
{
	int c1=getCount(head1);
	cout<<"C1 "<<c1<<endl;	
	int c2=getCount(head2);
	cout<<"C2 "<<c2<<endl;
	int d;

		if(c1>c2)
		{
			d=c1-c2;
			return utility(d,head1,head2);
		}
		else{
			d=c2-c1;
			return utility(d,head2,head1);
		}
}

int utility(int d, Node*head1, Node*head2)
{
	Node*current1=head1;
	Node*current2=head2;
	cout<<d<<endl;
	for(int i=0;i<=d-1;i++)
	{
		cout<<"{"<<current1->data<<"-"<<current2->data<<"}";
		if(current1==current2)
			return current1->data;
		current1=current1->next;
		current2=current2->next;
	}
	return -1;
}

void append(struct Node**head, int new_data)
{
	struct Node*new_node=new Node;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head==NULL)
	{
		*head=new_node;
		return;
	}
	struct Node*last=*head;
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
	append(&head,7);
	append(&head,9);
	append(&head,10);
	printList(head);
	cout<<endl;
	struct Node*head2=NULL;
	append(&head2,6);
	append(&head2,5);
	printList(head2);
//	cout<<head->next->next->data<<endl;
//	cout<<head2->next->data<<endl;
	head2->next=head->next->next;
	cout<<getCount(head2)<<endl;
	cout<<getIntersectionNode(head,head2);

	return 0;
}
