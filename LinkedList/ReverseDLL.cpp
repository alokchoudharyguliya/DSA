/* Brute Force - Use a Stack to store the doubly linked list nodes and the retrieve those from the stack and put those into the DLL again
 * 
 *
 *
 *
 *
 */
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
		Node*back;
		Node(int data1, Node*next1, Node*back1):data(data1), next(next1), back(back1){}
		Node(int data1):data(data1), next(nullptr), back(nullptr){}
};

Node*convertArr2DLL(vector<int>arr){
	Node*head=new Node(arr[0]);// have a node for prev
	Node*prev=head; 


	for(int i=1;i<arr.size();i++){
		// starting from prev as temp, and a new Node as temp run the loop
		Node*temp=new Node(arr[i],nullptr,prev);
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
	if(head==NULL|| head->next==NULL){ // if the DLL is empty or it has only one node then there is no meaning of reversing the DLL
		return head;
	}
	stack<int>st;
	Node*temp=head;
	while(temp){
		st.push(temp->data);
		temp=temp->next;
	}
	temp=head;

	while(temp){ // list is already connected only we will be replacing the values from the stack
		temp->data=st.top();
		st.pop();
		temp=temp->next;
	}
	return head;
}

int main(){
	vector<int>arr={12,5,8,7,4};
	Node*head=convertArr2DLL(arr);
	cout<<"Double Linked List"<<endl;
	print(head);
	cout<<"Reverse"<<endl;
	head=reverseDLL(head);
	print(head);

}
