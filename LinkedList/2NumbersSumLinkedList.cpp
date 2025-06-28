/*
 * Two numbers are represented as Linked List given the pointers in reverse order
 * 
 * 8->9->2 representing 298
 * ^
 * |
 *
 * 7->6->4 representing 467
 * ^
 * |
 *
 * then give a new linkedList head representing the sum as 755
 *
 * 5->5->7
 * ^
 * |
 *
 *
 * 1. 	Keep track of carry using a variable and simulate digits-by-digits sum starting from the head of hte list, which contains the least significant digit.
 *
 * Create a dummy node which is the head of new linked list
 * Create a node temp, initialise it with dummy
 * Initialize carry to 0
 * Loop through list l1 and l2 until we reach both ends, and until carry is present
 * 	Set Sum=l1.val + l2.val + carry
 * 	Update Carry=sum/10
 * 	Create a new node with digit value of (sum%10) and set it to tempnode's next, then advance temp node to next.
 * 	Advance both l1 and l2
 *
 * Return dummy's next node.
 *
 *
 * There can be three cases
 * 	l1=[0,1]
 * 	l2=[0,1,2]
 *	when one list is longer than other
 *
 *	l1=[]
 *	l2=[0,1]
 *	when one list is null, which means an empty list
 *
 *	l1=[9,9]
 *	l2=[1]
 *	the sum could have an extra carry of one at end
 */

/*
class Solution{

	public:
		Node*addTwoNumbers(Node*l1, Node*l2){
			Node*dummy=new Node;
			Node*temp=dummy;
			int carry=0;
			while(l1!=NULL || l2!=NULL || carry){
				int sum=0;
				if(l1!=NULL){
					sum+=l1->val;
					l1=l1->next;
				}
				if(l2!=NULL){
					sum+=l2->val;
					l2=l2->next;
				}
				sum+=carry;
				carry=sum/10;
				Node*node=new Node;
				node->data=sum%10;
				temp->next=node;
				temp=temp->next;
			}

		}
		return dummy->next;
}
}
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node*next;
};

Node* TwoNumberAddLinkedList(Node*l1, Node*l2){
	int carry=0;
	Node*dummy=new Node;

      
	Node*temp=dummy;
        while(l1!=NULL || l2!=NULL || carry){
	       int sum=0;
		if(l1!=NULL)
		{
			sum+=l1->data;
			l1=l1->next;
		}
		if(l2!=NULL){
			sum+=l2->data;
			l2=l2->next;
		}
		sum+=carry;
		carry=sum/10;

		Node*ans=new Node;
		ans->data=sum%10;
		temp->next=ans;
		temp=temp->next;
       }
		return dummy->next;

}

void append(struct Node**head,int new_data){
	struct Node*new_node=new Node;
	new_node->data=new_data;
	new_node->next=NULL;

	if(*head==NULL)
	{
		*head=new_node;
		return;
	}
	struct Node*last=*head;

	while(last->next!=NULL){
		last=last->next;
	}
	last->next=new_node;
}
void printList(struct Node*head){
	while(head!=NULL){
		cout<<head->data<<",";
		head=head->next;
	}
}

int main(){
	struct Node*head=NULL;
	append(&head,8);
	append(&head,9);
	append(&head,4);
	struct Node*head2=NULL;
	append(&head2,2);
	append(&head2,5);
	printList(head2);
	printList(head);
	 struct Node*ans=TwoNumberAddLinkedList(head,head2); printList(ans);
	return 0;
}
