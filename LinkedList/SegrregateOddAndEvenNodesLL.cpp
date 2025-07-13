// Segregate even and odd nodes in a linked list
// Given a LL of ints.
// Modify the LL all the even numbers appear before the odd numbers in LL
// Note that order of even and odd numbers should remain the same.
//
//
// From the Original LL remove the odd and even nodes and then create two LL one having all the even nodes in order and other having odd nodes
// Join the tail of even nodes LL to the head of odd nodes LL
#include<bits/stdc++.h>
using namespace std;
class ListNode{
	public:
		int val;
		ListNode*next;
		ListNode(int x){
			val=x;
			next=nullptr;
		}
};
ListNode*head,*tail;

void InsertatLast(int x){
	ListNode*newNode=new ListNode(x);
	if(head==NULL)
	{		head=newNode;tail=newNode;
	return;}
	else{
	tail=tail->next=newNode; //firstly the tail->next will change to newNode and later tail will get assigned to tail->next; 
				 //That is the order of assignment is from Left to Right
	}	

}
void PrintList(ListNode*head){
	ListNode*curr=head;
	for(;curr!=nullptr;curr=curr->next){

	cout<<curr->val<<"->";
	}
	cout<<endl;
}
ListNode*SegregateOddEven(){
	ListNode*oddHead=new ListNode(-1), *oddTail=oddHead;
	ListNode*evenHead=new ListNode(-1),*evenTail=evenHead;
	ListNode*curr=head, *temp;
	while(curr){
		temp=curr;
		curr=curr->next;
		temp->next=nullptr;
		if(temp->val & 1)
		{

			oddTail->next=temp;
			oddTail=temp;
		}
		else{
			evenTail->next=temp;
			evenTail=temp;
		}
	}
	evenTail->next=oddHead->next;
	return evenHead->next;

}
int main(){
	InsertatLast(1);
	InsertatLast(2);
	InsertatLast(3);
	InsertatLast(4);
	cout<<endl;
	PrintList(head);
	ListNode*newHead=SegregateOddEven();
	PrintList(newHead);
}
