#include<bits/stdc++.h>
using namespace std;
// print the K largest Element in any order
// Naive approach sorting, Time complexity : O(nlogn+k)
// nlogn for sorting k for printing k items
int main(){
	// so build a maxHeap which will take only logn time and taking out k items will take k time so giving an overall time complexity of klogn and always k<n.
	// only worst cast k==n
	int arr[]={5,15,10,20,8};
	int k=3;
	priority_queue<int>pq(arr,arr+5); // will take O(n) time to build the maxHeap
	for(int i=0;i<k;i++)
	{
		int ele=pq.top();
		pq.pop();
		cout<<ele<<',';
	}
	// will take O(klogn) time to extract the items
	// giving us the overall time complexity of O(n+klogn) time
	cout<<endl;

}

// a better approach is using the minHeap
// put first k items into the minHeap, iterate starting from the k+1th item till the last of array
//  	1. Compare current element with top of heap, If smaller than top, ignore it.
//  	2. Else remove the top element and insert the current element in the minHeap
// Print contents of the minHeap
