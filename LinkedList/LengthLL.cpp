#include<bits/stdc++.h>
using namespace std;
class Node{

	public:
		int data;
		Node*next;
	Node(int x):data(x), next(nullptr){}
	Node(int x, Node*nextNode):data(x), next(nextNode){}
	int lengthOfLL(){
		Node*temp=this;
		int cnt=0;
		while(temp){
			cnt++;
			temp=temp->next;
		}
		return cnt;
	}
};

/* int Node::lengthOfLL(){

}
*/
void append(Node**head,int new_val){
	Node*newNode=new Node(new_val);
	if(*head==NULL)
	{
		*head=newNode;
		return;
	}
	Node*temp=*head;
//	cout<<temp->data;
	while(temp->next!=nullptr){
		temp=temp->next;
	}
	temp->next=newNode;
//	
//
//	return head;
}
int main(){
	Node*head=nullptr;
	append(&head,1);
	append(&head,2);
	append(&head,3);

	cout<<head->lengthOfLL()<<endl;

}
