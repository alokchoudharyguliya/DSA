#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
		Node(int data1, Node*next1){
			data=data1;
			next=next1;
		}
		Node(int data1){
			data=data1;
			next=nullptr;
		}
};
Node*firstNode(Node*head){
	Node*slow=head;
	Node*fast=head;

	while(fast!=NULL && fast->next!=NULL){// if the LL is acyclic then in worst case the fast pointer will first reach the end either by getting to last node or by jumping from second last node to NULL taking a jump of two nodes
	slow=slow->next;
	fast=fast->next->next;

	if(slow==fast)
	{	
		cout<<"Fast and slow met at"<<slow->data<<endl;
		slow=head;

		// Find the first node of the loop
		 while(slow!=fast){
		 slow=slow->next;
		 fast=fast->next;
		 }
		 return slow;

		cout<<"Cycle Detected"<<endl;
		}
	}
	return NULL;
}
int main(){
	Node*node1=new Node(1);
	Node*node2=new Node(2);
	node1->next=node2;
	Node*node3=new Node(3);
	node2->next=node3;
	Node*node4=new Node(4);
	node3->next=node4;
	Node*node5=new Node(5);
	node4->next=node5;	
	// make the loop connection
	node5->next=node3;
	Node*head=node1;

	Node*loopStartNode=firstNode(head);
	if(loopStartNode)
		cout<<loopStartNode->data<<endl;
	else
		cout<<"No loop detected"<<endl;
	return 0;
}	
