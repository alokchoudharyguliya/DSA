#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
	Node(int data1, Node*next1):data(data1), next(next1){}
	Node(int data1):data(data1),next(nullptr){}
};
void printLL(Node*head){
	while(head){
		cout<<head->data<<",";
		head=head->next;
	}
}
Node*DeleteNthNodeFromEnd(Node*head, int N){
	if(head==NULL)
		return NULL;
	int cnt=0;
	Node*temp=head;
	// calculate the length of LL as cnt
	while(temp!=NULL){
		cnt++;
		temp=temp->next;
	}
	// If N is same as length of LL cnt then remove the first node only
	if(cnt==N){
		Node*newhead=head->next;
		delete (head);
		return newhead;
	}
	int res=cnt-N;// res is the position from starting
	temp=head;
	while(temp!=NULL){
		res--;
		if(res==0)
			break;// break when we reach res-th position from starting
		temp=temp->next;
	}

	Node*delNode=temp->next;// delete the next node
	temp->next=temp->next->next;// join the broken bond
	delete(delNode);
	return head;
}

int main(){
	// Nth Node from End means L-N+1th node from start
	// so calculate the L lenght of the linked list
	// then go to L-Nth node and delete the next node and connect the ends
	// 
	// Two edge cases
	// 	1. N=1
	// 		means last node of LL is to be deleted
	// 	2. N=L
	// 		means first node of LL is to be deleted
	vector<int>arr={1,2,3,4,5};
	int N=3;
	Node*head=new Node(arr[0]);
	head->next=new Node(arr[1]);
	head->next->next=new Node(arr[2]);
	head->next->next->next=new Node(arr[3]);
	head->next->next->next->next=new Node(arr[4]);
	head=DeleteNthNodeFromEnd(head,N);
	printLL(head);
}
