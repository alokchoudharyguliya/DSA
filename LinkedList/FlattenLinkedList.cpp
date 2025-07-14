#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
	public:
		int data;
		Node*next;
		Node*child;
//		Node(): data(0), next(NULL), child(NULL){}
//		Node(int x):data(x), next(NULL), child(NULL){}
//		Node(int x, Node*nextNode, Node*childNode):data(x), next(nextNode), child(childNode){}
	Node(int data){
		this->data=data;
		this->next=NULL;
		this->child=NULL;
	}
	Node(int data, Node*next, Node*child){
		this->data=data;
		this->next=next;
		this->child=child;
	}
	Node(){
		this->data=0;
		this->next=NULL;
		this->child=NULL;
	}
};

//Node*merge(Node*list1, Node*list2){


//}
Node*convertArrToLinkedList(vector<int>&arr){
	Node*dummyNode=new Node(-1);
	Node*temp=dummyNode;

	for(int i=0;i<arr.size();i++)
	{
		temp->child=new Node(arr[i]);
		temp=temp->child;
	}
	return dummyNode->child;
}
Node*flattenLinkedList(Node*head){
	vector<int>arr;
	while(head!=nullptr){
	Node*t2=head;
	while(t2!=nullptr){
	arr.push_back(t2->data);
	t2=t2->child;
	}
	head=head->next;
	}
	sort(arr.begin(),arr.end());
	return convertArrToLinkedList(arr);
}
void printLinkedList(Node*head){
	while(head!=nullptr){
		cout<<head->data<<",";
		head=head->child;
	}
	cout<<endl;
}
void printOriginalLinkedList(Node*head,int depth){
	while(head!=NULL){
		cout<<head->data;
		if(head->child)
		{
			cout<<"->";
			printOriginalLinkedList(head->child,depth);
		}
	
		if(head->next){
			cout<<endl;
			for(int i=0;i<=depth;i++)
			{
				cout<<"| ";
			}
		}
		head=head->next;
		depth++;
	}
}

int main(){
	Node*head=new Node(5);
	head->child=new Node(14);
	head->next=new Node(10);
	head->next->child=new Node(4);
	head->next->next=new Node(12);
	head->next->next->child=new Node(20);
	head->next->next->child->child=new Node(13);

	head->next->next->next=new Node(7);
	head->next->next->next->child=new Node(17);

	printOriginalLinkedList(head,0);
	// head->child->child!=NULL?cout<<"YES":cout<<"NO";
	cout<<endl;
	Node*flattened=flattenLinkedList(head);
	printLinkedList(head);
	
	
}
