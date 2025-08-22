/*
 *
 * Given an array, print the next greater element (NGE) for every element, the first greater element on the right side of x in array
 * Element for which no greater element exist consider next element as -1
 *
 * [13,7,6,12]
 * 13->-1, 7->12, 6->12, 12->-1
 *
 *
 * Push the first element to stack
 * Pick the rest of the element one by one and follwo:
 * 	1. Mark the current element as next.
 * 	2. If the stack is not empty, compare top element of the stack with next.
 * 	3. If next is greatere than the top element. Pop element from the stack.
 * 		Next is the next greatere element for the popped element.
 * 	4. Keep popping from the stack while the popped element is smaller than next, next becomes the next greater element for all such popped elements.
 * 	5. Finally, push the next in the stack
 * After loop, pop all the elements from stack and print -1 as the next element for them.
 *
 *
 */

#include<bits/stdc++.h>
using namespace std;
void printNGE(vector<int>&arr,int n){
	stack<int>s;
	s.push(arr[0]);
	for(int i=0;i<n;i++){
	if(s.empty()){
	s.push(arr[i]);
	continue;
	}
	while(s.empty()==false&&s.top()<arr[i]){
		cout<<s.top()<<"==>"<<arr[i]<<endl;
		s.pop();
	}
	s.push(arr[i]);
	while(s.empty()==false){
	cout<<s.top()<<"==>"<<-1<<endl;
	s.pop();
	}
	}
}
int main(){
	vector<int>arr={13,7,6,12};
	printNGE(arr,4);
	return 0;
}

