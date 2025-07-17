#include<bits/stdc++.h>
using namespace std;
class LRUCache{
	public:
		class node{
			public:
				int key;
				int val;
				node*next;
				node*prev;
				node(int _key, int _val){
	key=_key;
	val=_val;
				}
		};
		node*head=new node(-1,-1);
		node*tail=new node(-1,-1);

		int cap;
		unordered_map<int,node*>m;
		LRUCache(int capacity){
			cap=capacity;
			head->next=tail;
			tail->prev=head;
		}
		void addNode(node*newnode){
		node*temp=head->next;
		}
};
int main(){
	Solution sol;
	
}
