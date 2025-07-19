#include<bits/stdc++.h>
using namespace std;
// First the condition is to ask the median's definition that is for odd number of elements median is the center element while for even number of elements median is the average of middle two elements
//	if(size%2!=0)
//		return temp[size/2];
//	else
//		return (temp[size/2]+temp[(size-1)/2])/2;
//
// 
//
// Naive approach is to insert into a new array, maintaint a sorted array and then for each insertion we calculate/find the median
// Time Complexity - O(n^2)
//
// Better Solution - Augmented BST
//
// Efficient Solution - Use two separate Heaps one minHeap and other maxHeap,
// Put elements smaller than median into the minHeap and larger elements into maxHeap

void printMedian(vector<int>arr){
	priority_queue<int>s;
	priority_queue<int,vector<int>,greater<int>>q;
	s.push(arr[0]);
	cout<<arr[0]<<endl;
	for(int i=1;i<arr.size();i++)
	{
		int x=arr[i];
		if(s.size()>q.size()){
			if(s.top()>x){
				q.push(s.top());
				s.pop();
				s.push(x);
			}
			else
			q.push(x);
			cout<<((float)s.top()+q.top())/2<<endl;
		}
		else{
			if(x<=s.top())
				s.push(x);
			else{
				q.push(x);
				s.push(q.top());
				q.pop();
			}
			cout<<s.top()<<endl;
		}

	}
}
int main(){
	vector<int>arr={25,6,10,15,20};
	printMedian(arr);
	
}
