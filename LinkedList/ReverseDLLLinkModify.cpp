#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
		Node*prev;
		Node(int data1):data(data1), next(nullptr), prev(nullptr){}
		Node(int data1, Node*nextPtr, Node*prevPtr):data(data1), next(nextPtr), prev(prevPtr){}
		// Node*convertArr2DLL(vector<int>arr){};
};

Node* convertArr2DLL(vector<int>arr){
	Node*head=new Node(arr[0]);
//	Node*temp=head;
	Node*prev=head;

	for(int i=1;i<arr.size();i++)
	{
		Node*temp=new Node(arr[i],nullptr, prev);
		prev->next=temp;
		prev=temp;
	}
	return head;
}

void print(Node*head){
	while(head){
		cout<<head->data<<",";
		head=head->next;
	}
}
Node*reverseDLL(Node*head){
	if(head==NULL|| head->next==NULL)return head;
	Node*prevNode=NULL;
	Node*current=head;
	while(current!=NULL){
		prevNode=current->prev;
		current->prev=current->next;
		current->next=prevNode;
		current=current->prev;
	}
	// when current became NULL before that we assigned prevNode to the prev of then current which later got updated
	// so prev at the end will be assigned to the second last node
	// return the pointer to the last node
	return prevNode->prev;
}
int main(){
	vector<int>arr={1,3,2,4};
	Node*head=convertArr2DLL(arr);
	cout<<"Initial DLL"<<endl;
	print(head);
head=reverseDLL(head);
cout<<endl;
	print(head);
}
