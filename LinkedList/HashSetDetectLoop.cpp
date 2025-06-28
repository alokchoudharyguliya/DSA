/*
 * Hashing Solution:
 * 	Traverse the list one by one and keep putting the node addresses in a Hash Table. At any point, if NULL is reached then return false and if next of current node points to any of previously stored nodes in Hash then return true.
 *
 */
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node*next;
};

void printList(struct Node*head){
	while(head!=NULL){
		cout<<head->data<<",";
		head=head->next;
	}
}
void append(Node**head, int new_data)
{
	struct Node* new_node=new Node;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head==NULL){
		*head=new_node;
		return;
	}
	struct Node*last=*head;
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=new_node;
}
bool detectLoop(Node*h)
{
	unordered_set<Node**>seen;
	while(h!=NULL){
		if(seen.find(&h)==seen.end()){
			return true;
		}
		seen.insert(&h);
		h=h->next;
	}
	return false;
}
int main(){
	struct Node*head=NULL;
	append(&head,9);
	append(&head,10);
	append(&head,11);
	append(&head,12);
	head->next->next->next=head;
//	printList(head);
	cout<<endl;
	detectLoop(head)?cout<<"Yes":cout<<"No Cycle";
	cout<<endl;
	return 0;
}

