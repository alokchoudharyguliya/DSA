#include <bits/stdc++.h>
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
			next=NULL;
		}
};

Node*detectLoop(Node*head){
	Node*temp=head;
	unordered_map<Node*, int>mpp;
	while(temp){
		if(mpp.count(temp)!=0) // means temp already exists in the map
			return temp;
		mpp[temp]=1;
		temp=temp->next;
	}
	return nullptr;
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
	node5->next=node2;
	Node*head=node1;

	Node*loopStartNode=detectLoop(head);
	if(loopStartNode)
		cout<<"Loop detected. Starting node of loop is "<< loopStartNode->data;
	else
		cout<<"No loop detected"<<endl;

}
