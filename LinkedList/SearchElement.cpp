#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
		Node(int data){
			this->data=data;
			this->next=nullptr;
		}
		Node(int data, Node*nextNode){
			this->data=data;
			this->next=nextNode;
		}
};
void append(Node**head,int new_data){
	Node*newNode=new Node(new_data);
	if(*head==NULL){
		*head=newNode;
		return;
	}
	Node*temp=*head;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=newNode;
	return;			
}
void print(Node*head){
	while(head){
		cout<<head->data<<",";
		head=head->next;
	}
}
pair<Node*,int> search(Node*head, int val){
	if(head==NULL)
		return {nullptr,-1};
	Node*temp=head;
	int cnt=0;
	while(temp){
		if(temp->data==val){

			return make_pair(temp,cnt);
		}
		temp=temp->next;
		cnt++;
	}
	return {nullptr,-1};

}
int main(){	
	Node*head=new Node(11);
	append(&head,27);
	append(&head,43);
	append(&head,49);
	append(&head,15);
	print(head);
	pair<Node*,int>ans=search(head,43);
	cout<<endl;
	if(ans.first)
	{	cout<<ans.first->data<<" found at ";
		cout<<ans.second;
		cout<<endl;
	}
	else
		cout<<"Not found"<<endl;
}
