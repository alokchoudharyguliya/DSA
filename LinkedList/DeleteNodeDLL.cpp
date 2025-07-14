#include<bits/stdc++.h>
using namespace std;
class DNode{
	public:
		int data;
		DNode*prev;
		DNode*next;
		DNode(int x, DNode*nextNode,DNode*prevNode):data(x), next(nextNode), prev(prevNode){}
		DNode(int x){
			data=x;
			next=nullptr;
				prev=nullptr;
		}
		void printDLL();
};
void DNode::printDLL(){
	DNode*temp=this;
	while(temp){
		cout<<temp->data<<",";
		temp=temp->next;
	}
	cout<<endl;
}
DNode*convertArr2DLL(vector<int>arr){
	DNode*head=new DNode(arr[0]);
	DNode*prev=head;
	for(int i=1;i<arr.size();i++)
	{
		DNode*newNode=new DNode(arr[i],nullptr,prev);
		prev->next=newNode;
		prev=prev->next;
	}
	return head;
}
DNode*insertAtTail(DNode*head,int x){
	DNode*newNode=new DNode(x);
	if(head==nullptr)return newNode;

	DNode*tail=head;
	while(tail->next){
		tail=tail->next;
	}
	tail->next=newNode;
	newNode->prev=tail;
	return head;
}
DNode*deleteHead(DNode*head){
	if(head==nullptr||head->next==nullptr)return nullptr;

	DNode*prev=head;
	head=prev->next;
	head->prev=nullptr;
	delete(prev);
	return head;
}
int main(){
	vector<int>arr={12,5,8,7,4};
	// DNode*head=new DNode(1);
	DNode*head=convertArr2DLL(arr);
	head->printDLL();
	cout<<endl;
	head=insertAtTail(head,10);
	head->printDLL();
	head=deleteHead(head);
	cout<<endl;
	head->printDLL();
	

}
